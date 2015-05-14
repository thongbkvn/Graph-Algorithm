#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>

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

protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
    Vertex *source, *dest;

    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
};

#endif // EDGE_H
