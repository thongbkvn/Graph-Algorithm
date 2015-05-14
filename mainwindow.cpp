#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QActionGroup>
#include "graphwidget.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    modeActionGroup = new QActionGroup(this);
    modeActionGroup->addAction(ui->actionSelect);
    modeActionGroup->addAction(ui->actionDrawVertex);
    modeActionGroup->addAction(ui->actionDrawEdge);
    ui->actionSelect->setChecked(true);

    graphWidget = new GraphWidget;
    setCentralWidget(graphWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSelect_triggered()
{
    qDebug() << "on action Select tringgered";
}

void MainWindow::on_actionDrawVertex_triggered()
{
    qDebug() << "on action DrawVertex tringgered";
}

void MainWindow::on_actionDrawEdge_triggered()
{
    qDebug() << "on action Draw Edge tringgered";
}
