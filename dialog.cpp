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
    else if (ui->DFSButton->isChecked())
        algo = Algorithm::DFS;
    else
        algo = Algorithm::BFS;
    return new MainWindow(algo);
}
