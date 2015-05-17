#include "algorithm.h"
#include "mainwindow.h"
#include "edge.h"
#include "bfs.h"
#include "vertex.h"

#include <QAction>
#include <QIcon>
#include <QHash>
#include <QToolBar>
#include <QTimerEvent>
#include <queue>

#include <QPropertyAnimation>
#include <QDebug>

Algorithm::Algorithm(MainWindow *mainWindow):
    QObject(mainWindow), mainWindow(mainWindow), nEdge(0), selectedVertex(NULL),
    sourceVertex(NULL), destVertex(NULL), delay(1000), isStarted(false)
{
    createActions();
    createToolBar();
}



void Algorithm::createActions()
{
    playAction = new QAction(QIcon(":/images/new.png"), tr("Play"), mainWindow);
    playAction->setStatusTip(tr("Start algorithm animation"));
    connect(playAction, SIGNAL(triggered()), this, SLOT(play()));

    nextAction = new QAction(QIcon(":/images/next.png"), tr("Next"), mainWindow);
    nextAction->setStatusTip(tr("Next animation"));
    connect(nextAction, SIGNAL(triggered()), this, SLOT(next()));

    prevAction = new QAction(QIcon(":/images/prev.png"), tr("Prev"), mainWindow);
    prevAction->setStatusTip(tr("Previous animation"));
    connect(prevAction, SIGNAL(triggered()), this, SLOT(prev()));
    prevAction->setEnabled(false);

    stopAction = new QAction(QIcon(QString(":/images/stop.png")), tr("Stop"), mainWindow);
    stopAction->setStatusTip(tr("Stop animation"));
    connect(stopAction, SIGNAL(triggered()), this, SLOT(stop()));
    stopAction->setEnabled(false);
}

void Algorithm::createToolBar()
{

    animationToolBar = new QToolBar(tr("Animation"), mainWindow);
    animationToolBar->addAction(prevAction);
    animationToolBar->addAction(playAction);
    animationToolBar->addAction(nextAction);
    animationToolBar->addAction(stopAction);


    mainWindow->addToolBar(animationToolBar);
}

QToolBar* Algorithm::getAnimationToolBar()
{
    return animationToolBar;
}


Algorithm* Algorithm::getAlgorithm(AlgType algtype,  MainWindow *mainWindow)
{
    switch (algtype) {
    case BFS:
        return new BFSAnimation(mainWindow);
        break;
    default:
        return NULL;
        break;
    }
}

void Algorithm::addVertex(Vertex *vertex)
{
    vertexList << vertex;
    qDebug() << "Vertex Insterted";
}

void Algorithm::removeVertex(Vertex *vertex)
{
    vertexList.removeOne(vertex);
    qDebug() << "Vertex Removed";
}

void Algorithm::initAllItem()
{
    for (Vertex *v: vertexList)
    {
        if (v != sourceVertex)
            v->setColor(Vertex::Init);
         for (Edge *e: v->outEdges())
             e->setState(Edge::Init);
    }
}

void Algorithm::setSource()
{
    if (destVertex == selectedVertex)
        destVertex = NULL;
    if (sourceVertex != selectedVertex)
    {
        if (sourceVertex != NULL)
            sourceVertex->setColor(Vertex::Init);
        sourceVertex = selectedVertex;
        sourceVertex->setColor(Vertex::Source);
    }
    else
    {
        sourceVertex->setColor(Vertex::Init);
        sourceVertex = NULL;
    }
}

void Algorithm::setDest()
{
    if (sourceVertex == selectedVertex)
        sourceVertex = NULL;
    if (destVertex != selectedVertex)
    {
        if (destVertex != NULL)
            destVertex->setColor(Vertex::Init);
        destVertex = selectedVertex;
        destVertex->setColor(Vertex::Destination);
    }
    else
    {
        destVertex->setColor(Vertex::Init);
        destVertex = NULL;
    }
}

void Algorithm::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timerId)
        if (currentAnimation != animationList.end())
        {
            if (!isPaused)
            {
                (*currentAnimation)->start();
            }
        }
}

void Algorithm::finishAnimation()
{
    if (currentAnimation + 1 == animationList.end())
    {
        if (isForward)
        {
            nextAction->setEnabled(false);
            prevAction->setEnabled(true);
            isAutoPlay = false;
        }
         else if (isAutoPlay)
         {
            ++currentAnimation;
            timerId = startTimer(delay);
        }
        else
        {
            nextAction->setEnabled(currentAnimation+1 != animationList.end());
            prevAction->setDisabled((*currentAnimation)->direction() == QAbstractAnimation::Backward);
            playAction->setIcon(QIcon(":/images/resume.png"));
            playAction->setText(tr("Resume"));
        }
    }
}

void Algorithm::play()
{

    generateAnimationList();
    qDebug() << "Algorithm Play";
    if (!isStarted)
    {
       {
           //mainWindow->diableEditting();
         /*
           if (animationList.count() == 0)
            {
               mainWindow->enableEditting();
            }
           */
        }

      isStarted = true;
      isAutoPlay = true;
      isPaused = false;

      currentAnimation = animationList.begin();

        playAction->setIcon(QIcon(":/images/pause.png"));
     playAction->setText(tr("Pause"));

      nextAction->setEnabled(false);
      prevAction->setEnabled(false);
      stopAction->setEnabled(true);
    }

    else if (!isPaused)
    {
        isPaused = true;

        nextAction->setEnabled(currentAnimation != animationList.end());
        prevAction->setEnabled(true);

        playAction->setIcon(QIcon(":/images/resume.png"));
        playAction->setText("resume");
    }

    else
    {
        isPaused = false;
        isAutoPlay = true;

        timerId = startTimer(delay);

        nextAction->setEnabled(false);
        prevAction->setEnabled(false);

        playAction->setIcon(QIcon(":/images/pause.png"));
        playAction->setText("Pause");
    }
    isForward = true;
}

void Algorithm::next() {
    qDebug() << "Algorithm next";
    if(isStarted) {
        if(isForward)
            ++currentAnimation;
    } else {
        //mainWindow->disableEditing();
        generateAnimationList();
        /*
        if(animList.count() == 0) {
            mainWindow->enableEditing();
            return;
        }*/

        currentAnimation = animationList.begin();
        isStarted = true;

        stopAction->setEnabled(true);
    }

    isForward = true;
    isAutoPlay = false;
    isPaused = true;

    playAction->setIcon(QIcon(":/images/resume.png"));
    playAction->setText(tr("Resume"));
    nextAction->setEnabled(false);
    prevAction->setEnabled(false);

//    (*currentAnim)->setDuration(delay);
    (*currentAnimation)->setDirection(QAbstractAnimation::Forward);
    (*currentAnimation)->start();
}


void Algorithm::prev() {
    qDebug() << "Algorithm Preview";
    if(isStarted) {
        isAutoPlay = false;
        isForward = false;
        isPaused = true;

        playAction->setIcon(QIcon(":/images/resume.png"));
        playAction->setText(tr("Resume"));
        nextAction->setEnabled(false);
        prevAction->setEnabled(false);

//        (*currentAnim)->setDuration(delay);
        (*currentAnimation)->setDirection(QAbstractAnimation::Backward);
        (*currentAnimation)->start();

        if(currentAnimation != animationList.begin())
            --currentAnimation;
    }
}


void Algorithm::stop() {
    qDebug() << "Algorithm Stop";
    killTimer(timerId);
    animationList.clear();

    isStarted = false;

    playAction->setEnabled(true);
    playAction->setIcon(QIcon(":/images/play.png"));
    playAction->setText(tr("Play"));

    nextAction->setEnabled(true);
    prevAction->setEnabled(false);
    stopAction->setEnabled(false);

    //mainWindow->enableEditing();
}
