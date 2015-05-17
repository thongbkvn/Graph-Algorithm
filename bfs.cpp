#include "bfs.h"
#include "algorithm.h"
#include "mainwindow.h"
#include "edge.h"
#include "vertex.h"
#include <QAbstractAnimation>
#include <QMessageBox>
#include <iostream>
#include <queue>
#include <QDebug>

BFSAnimation::BFSAnimation(MainWindow *mainWindow):Algorithm(mainWindow) {}

void BFSAnimation::generateAnimationList()
{
    for (Vertex *v: vertexList)
        if (v->getId() == 1)
            sourceVertex = v;
    std::queue<Vertex*> BFSQueue;
    BFSQueue.push(v);
    sourceVertex->setColor(Vertex::Visited);

    while (!BFSQueue.empty())
    {
        Vertex *vertex = BFSQueue.front();
        BFSQueue.pop();

        qDebug() << vertex->getId() << " -> ";

        for (Edge *e : vertex->outEdges())
            if (e->destVertex()->color() == Vertex::Init)
            {
                e->destVertex()->setColor(Vertex::Visited);
                BFSQueue.push(e->destVertex());
            }
        vertex->setColor(Vertex::Discovered);
    }

    BFSQueue.push(sourceVertex);
}

Edge* BFSAnimation::newEdge(Vertex *source, Vertex *dest)
{
    return new Edge(source, dest);
    return NULL;
}
