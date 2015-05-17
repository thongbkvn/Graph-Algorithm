#include "bfs.h"
#include "algorithm.h"
#include "mainwindow.h"
#include "edge.h"
#include "vertex.h"
#include <QAbstractAnimation>
#include <QMessageBox>

BFSAnimation::BFSAnimation(MainWindow *mainWindow):Algorithm(mainWindow) { }

void BFSAnimation::generateAnimationList()
{
}

Edge* BFSAnimation::newEdge(Vertex *source, Vertex *dest)
{
    return new Edge(source, dest);
    return NULL;
}
