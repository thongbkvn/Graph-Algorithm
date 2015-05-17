#ifndef BFS_H
#define BFS_H
#include "algorithm.h"
class MainWindow;
class Edge;
class Vertex;

#include "edge.h"

class BFSAnimation : public Algorithm
{
    Q_OBJECT
public:
    BFSAnimation(MainWindow *mainWindow);

    Algorithm::AlgType type() const override {return Algorithm::BFS;}
    Edge* newEdge(Vertex *, Vertex *) override;
protected:
    void generateAnimationList() override;

};

#endif // BFS_H
