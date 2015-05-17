#include "edge.h"
#include "vertex.h"
#include "graphwidget.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

int Vertex::vertexID = 0;//new

QColor Vertex::vertexColor[5][2] = { { QColor(Qt::darkYellow).light(120),
                                        QColor(Qt::yellow).light(120) },
                                { QColor(Qt::darkGreen).light(120),
                                        QColor(Qt::green).light(120) },
                                { QColor(Qt::darkRed).light(120),
                                        QColor(Qt::red).light(120) },
                                { QColor(Qt::darkMagenta).light(120),
                                        QColor(Qt::magenta).light(120) },
                                { QColor(Qt::darkGray).light(120),
                                        QColor(Qt::gray).light(120) }
                                };


Vertex::Vertex(qreal x, qreal y)
{
    setPos(x, y);
    id = ++vertexID;//new
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsSelectable);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);

    m_color = Init;
}

void Vertex::addInEdge(Edge *edge)
{
    inEdgeList << edge;
    edge->adjust();
}

void Vertex::addOutEdge(Edge *edge)
{
    outEdgeList << edge;
    edge->adjust();
}

bool Vertex::removeInEdge(Edge *edge)
{
    return outEdgeList.removeOne(edge);
}

bool Vertex::removeOutEdge(Edge *edge)
{
    return outEdgeList.removeOne(edge);
}

QRectF Vertex::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust);
}

QPainterPath Vertex::shape() const
{
    QPainterPath path;
    path.addEllipse(-10, -10, 20, 20);
    return path;
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7, -7, 20, 20);

    QRadialGradient gradient(-3, -3, 10);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, vertexColor[m_color][0].light(120));
        gradient.setColorAt(0, vertexColor[m_color][1].light(120));
    } else {
        gradient.setColorAt(0, vertexColor[m_color][1]);
        gradient.setColorAt(1, vertexColor[m_color][0]);
    }
    painter->setBrush(gradient);

    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-10, -10, 20, 20);

    painter->drawText(-7, -7, 14, 14, Qt::AlignCenter, QString::number(id));//new

    if (isSelected())
    {
        painter->setBrush(Qt::NoBrush);
        painter->setPen(QPen(Qt::red, 1, Qt::DashLine));
        painter->drawRect(-11, -11, 22, 22);
    }
}

QVariant Vertex::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, inEdgeList)
            edge->adjust();
        foreach (Edge *edge, outEdgeList)
            edge->adjust();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}


void Vertex::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    update();
    QGraphicsItem::mouseMoveEvent(event);
}


void Vertex::setColor(VertexColor myColor)
{
    m_color = myColor;
    update();
}
