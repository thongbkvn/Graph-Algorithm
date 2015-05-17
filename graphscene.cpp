#include "graphscene.h"
#include "algorithm.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "vertex.h"
#include "edge.h"
#include <QWidget>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

GraphScene::GraphScene(Algorithm *algorithm, QWidget *parent) : QGraphicsScene(parent)
{
    this->algorithm = algorithm;
    mode = MoveItem;
    setItemIndexMethod(QGraphicsScene::NoIndex);
    //setSceneRect(-200, -200, 400, 400);
    /*
    Vertex *vertex1 = new Vertex(10, 20);
    Vertex *vertex2 = new Vertex(15, 30);
    Vertex *vertex3 = new Vertex(5, 200);
    Vertex *vertex4 = new Vertex(70, 130);
    Vertex *vertex6 = new Vertex(80, 12);
    Vertex *vertex7 = new Vertex(100, 200);
    Vertex *vertex8 = new Vertex(-50, 50);
    Vertex *vertex9 = new Vertex(-100, -50);
    addItem(vertex1);
    addItem(vertex2);
    addItem(vertex3);
    addItem(vertex4);
    addItem(vertex6);
    addItem(vertex7);
    addItem(vertex8);
    addItem(vertex9);
    addItem(new Edge(vertex1, vertex2));
    addItem(new Edge(vertex2, vertex3));
    addItem(new Edge(vertex3, vertex6));
    addItem(new Edge(vertex4, vertex1));
    addItem(new Edge(vertex6, vertex9));
    addItem(new Edge(vertex7, vertex4));
    addItem(new Edge(vertex8, vertex7));
    addItem(new Edge(vertex9, vertex8));
    */

}


void GraphScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug() << "GraphicsScene mouse Press event";
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    QPointF pos = mouseEvent->scenePos();
    Vertex *vertex;
    switch(mode)
    {
    case InsertVertex:
        vertex = new Vertex(pos.x(), pos.y());
        addItem(vertex);
        algorithm->addVertex(vertex);
        emit itemInserted(vertex);
        break;
    case InsertEdge:
        line = new QGraphicsLineItem(QLineF(pos, pos));
        line->setPen(QPen(Qt::black, 2));
        addItem(line);
    default:
        break;
    }

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void GraphScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if (mode == InsertEdge && line != 0)
    {
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    }
    //Chu y doan nay
    else if (mode == MoveItem)
        QGraphicsScene::mouseMoveEvent(mouseEvent);

}

void GraphScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if (line != 0 && mode == InsertEdge)
    {
        Vertex *sourceVertex = firstVertex(line->line().p1()),
                *destVertex = firstVertex(line->line().p2());
        removeItem(line);
        delete line;

        if (sourceVertex && destVertex && (sourceVertex != destVertex))
        {
            bool vertexsConnected = false;


            foreach (Edge *edge, sourceVertex->outEdges())
            {
                if (edge->destVertex() == destVertex)
                {
                    vertexsConnected = true;
                    break;
                }
            }

            //Neu khong phai la canh da co thi them canh vao
            if (!vertexsConnected )
            {
                Edge *edge = algorithm->newEdge(sourceVertex, destVertex);
                if (edge != NULL)
                {
                    edge->setZValue(-1000.0);
                    addItem(edge);
                    algorithm->incEdge();
                    edge->adjust();
                }
            }
        }

    }
    line = 0;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

Vertex* GraphScene::firstVertex(QPointF pos) {
    QList<QGraphicsItem*> selectedItems = items(pos);
    QList<QGraphicsItem*>::iterator li;
    for(li = selectedItems.begin(); li < selectedItems.end(); ++li)
        if((*li)->type() == Vertex::Type)
            return qgraphicsitem_cast<Vertex*>(*li);
    return 0;
}

