#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
#include <QColor>

class Vertex;

class Edge : public QGraphicsItem
{
public:
    Edge(Vertex *sourceVertex, Vertex *destVertex);

    Vertex *sourceVertex() const;
    Vertex *destVertex() const;

    void adjust();

    enum { Type = UserType + 2 };
    int type() const Q_DECL_OVERRIDE { return Type; }

    enum EdgeState {Init, Relaxed, InPath, Error};
    static QColor EdgeColor[4];
    EdgeState color() const { return edgeState;}
    void setColor(EdgeState state) {edgeState = state;}

protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
    Vertex *source, *dest;
    EdgeState edgeState;
    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
};

#endif // EDGE_H
