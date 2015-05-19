QT += widgets
CONFIG += c++11
HEADERS += \
        edge.h \
        vertex.h \
        graphwidget.h \
    mainwindow.h \
    graphscene.h \
    algorithm.h \
    bfs.h \
    animation.h \
    dfs.h

SOURCES += \
        edge.cpp \
        main.cpp \
        vertex.cpp \
        graphwidget.cpp \
    mainwindow.cpp \
    graphscene.cpp \
    algorithm.cpp \
    bfs.cpp \
    animation.cpp \
    dfs.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/graph_algorithm
INSTALLS += target

FORMS += \
    mainwindow.ui

RESOURCES += \
    images.qrc
