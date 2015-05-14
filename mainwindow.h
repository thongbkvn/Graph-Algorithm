#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>

class GraphWidget;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSelect_triggered();

    void on_actionDrawVertex_triggered();

    void on_actionDrawEdge_triggered();

private:
    Ui::MainWindow *ui;
    QActionGroup *modeActionGroup;

    GraphWidget *graphWidget;

};

#endif // MAINWINDOW_H
