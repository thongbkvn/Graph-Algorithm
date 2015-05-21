#include "graphwidget.h"
#include "dialog.h"
#include <QApplication>
#include <QTime>
#include <QMainWindow>
#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    app.setApplicationName("Graph Algorithm");
    app.setApplicationDisplayName("Graph Algorithm - Pham Van Thong");
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    Dialog dialog;
    if (dialog.exec() == QDialog::Accepted)
    {
        MainWindow *mainWindow = dialog.createMainWindow();
        mainWindow->show();
    }
    return app.exec();
}
