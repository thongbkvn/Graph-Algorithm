#include "bfs.h"
#include "algorithm.h"
#include "mainwindow.h"
#include "edge.h"
#include "vertex.h"
#include "animation.h"
#include <QAbstractAnimation>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QMessageBox>
#include <iostream>
#include <queue>
#include <QDebug>

BFSAnimation::BFSAnimation(MainWindow *mainWindow):Algorithm(mainWindow) {}

void BFSAnimation::generateAnimationList()
{
    foreach (Vertex *v, vertexList)
        if (!v->associate())
            BFSVertex(v);
    for (auto &animation : animationList)
    {
        connect(animation.get(), SIGNAL(finished()), this, SLOT(finishAnimation()));
    }
}

void BFSAnimation::BFSVertex(Vertex *v)
{
    Vertex::interconnect++;
    v->setAssociate(Vertex::interconnect);

    std::queue<Vertex *> BFSQueue;
    BFSQueue.push(v);

    while (!BFSQueue.empty())
    {
        Vertex *vertex = BFSQueue.front();
        BFSQueue.pop();

        discoverVertex(vertex);

        qDebug() << vertex->getId() << " -> ";

        for (Edge *e : vertex->outEdges())
            if (e->destVertex()->associate() == 0)
            {
                e->destVertex()->setAssociate(Vertex::interconnect);
                BFSQueue.push(e->destVertex());
            }
    }

}

Edge* BFSAnimation::newEdge(Vertex *source, Vertex *dest)
{
    return new Edge(source, dest);
    return NULL;
}

void BFSAnimation::discoverVertex(Vertex *v)
{
    if (v == sourceVertex)
        return;

   auto parallelAnimation = std::shared_ptr<QParallelAnimationGroup>(new QParallelAnimationGroup);

    if (v != destVertex)
        parallelAnimation->addAnimation(create(v, "color", Vertex::Init, Vertex::Visited,2000));
    foreach (Edge *e, v->outEdges())
    {
        if (e->destVertex() == v)
        {
            e->setZValue(1000.0);
            parallelAnimation->addAnimation(create(e, "state", Edge::Init, Edge::InPath,2000));
            break;
        }
    }

    animationList << parallelAnimation;

}
