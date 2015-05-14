#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
class Node;
class GraphScene : public QGraphicsScene
{
    Q_OBJECT

public:
    enum Mode {InsertVertex, InsertEdge, MoveItem};
    GraphScene(QWidget *parent = 0);

    Mode mode;

public slots:
    void setMode(Mode _mode) {mode = _mode;}
    void setModified(bool m = true) {m_modified = m;}

signals:

    void itemInserted(QGraphicsItem *mouseEvent);
    void itemSelected(QGraphicsItem *mouseEvent);

    /*
protected:
    //New
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
*/

private:
    int vertexIndex;
    int nEdge;
    bool m_modified;

    QPointF startPoint;

    QGraphicsLineItem *line;
};
#endif // GRAPHSCENE_H
