#include "graphscene.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "node.h"
#include "edge.h"
#include <QWidget>

GraphScene::GraphScene(QWidget *parent) : QGraphicsScene(parent)
{
    setItemIndexMethod(QGraphicsScene::NoIndex);
    setSceneRect(-200, -200, 400, 400);
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;
    Node *node4 = new Node;
    Node *node6 = new Node;
    Node *node7 = new Node;
    Node *node8 = new Node;
    Node *node9 = new Node;
    addItem(node1);
    addItem(node2);
    addItem(node3);
    addItem(node4);
    addItem(node6);
    addItem(node7);
    addItem(node8);
    addItem(node9);
    addItem(new Edge(node1, node2));
    addItem(new Edge(node2, node3));
    //addItem(new Edge(node2, centerNode));
    addItem(new Edge(node3, node6));
    addItem(new Edge(node4, node1));
    //addItem(new Edge(node4, centerNode));
    //addItem(new Edge(centerNode, node6));
    //addItem(new Edge(centerNode, node8));
    addItem(new Edge(node6, node9));
    addItem(new Edge(node7, node4));
    addItem(new Edge(node8, node7));
    addItem(new Edge(node9, node8));

    node1->setPos(-50, -50);
    node2->setPos(0, -50);
    node3->setPos(50, -50);
    node4->setPos(-50, 0);
    node6->setPos(50, 0);
    node7->setPos(-50, 50);
    node8->setPos(0, 50);
    node9->setPos(50, 50);
}
