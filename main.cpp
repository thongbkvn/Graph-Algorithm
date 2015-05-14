#include "graphwidget.h"

#include <QApplication>
#include <QTime>
#include <QMainWindow>
#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    MainWindow *mainWindow = new MainWindow;

    mainWindow->show();
    return app.exec();
}
