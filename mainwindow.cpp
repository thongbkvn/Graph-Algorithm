#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QActionGroup>
#include "graphwidget.h"
#include "graphscene.h"
#include "algorithm.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    algorithm = Algorithm::getAlgorithm(Algorithm::BFS, this);
    ui->setupUi(this);
    modeActionGroup = new QActionGroup(this);
    modeActionGroup->addAction(ui->actionSelect);
    modeActionGroup->addAction(ui->actionDrawVertex);
    modeActionGroup->addAction(ui->actionDrawEdge);
    ui->actionSelect->setChecked(true);

    graphWidget = new GraphWidget;
    setCentralWidget(graphWidget);

    m_scene = new GraphScene(algorithm, this);
    m_scene->setSceneRect(-width()/2, -height()/2, width(), height());

    graphWidget->setScene(m_scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSelect_triggered()
{
    m_scene->setMode(GraphScene::MoveItem);
}

void MainWindow::on_actionDrawVertex_triggered()
{
    m_scene->setMode(GraphScene::InsertVertex);
}

void MainWindow::on_actionDrawEdge_triggered()
{
    m_scene->setMode(GraphScene::InsertEdge);
}
