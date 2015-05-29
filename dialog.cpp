#include "dialog.h"
#include "ui_dialog.h"
#include "algorithm.h"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

MainWindow* Dialog::createMainWindow()
{
    Algorithm::AlgType algo;

    if (ui->BFSButton->isChecked())
        algo = Algorithm::BFS;
    else
        algo = Algorithm::DFS;
    return new MainWindow(algo);
}
