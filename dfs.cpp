#include "dfs.h"
#include "algorithm.h"
#include "mainwindow.h"
#include "edge.h"
#include "vertex.h"
#include "animation.h"
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QDebug>

DFSAnimation::DFSAnimation(MainWindow *mainWindow) : Algorithm(mainWindow)
{
}

void DFSAnimation::generateAnimationList()
{
    animationGroup = new QSequentialAnimationGroup;
    Vertex::interconnect = 0;


    foreach (Vertex *v, vertexList) {
        if (!v->associate())
        {
            Vertex::interconnect++;
            DFSVertex(v);
        }
    }

    animationGroup->start();
}

void DFSAnimation::DFSVertex(Vertex *v)
{
    v->setAssociate(Vertex::interconnect);
    animationGroup->addAnimation(create(v, "color", Vertex::Init, Vertex::Visited));

    foreach(Edge *e, v->outEdges())
        if (e->destVertex()->associate() == 0)
        {
            animationGroup->addAnimation(create(e, "state", Edge::Init, Edge::InPath));
            DFSVertex(e->destVertex());
        }
    animationGroup->addAnimation(create(v, "color", Vertex::Visited, Vertex::Discovered));
}

Edge* DFSAnimation::newEdge(Vertex *source, Vertex *dest)
{
    return new Edge(source, dest);
}
