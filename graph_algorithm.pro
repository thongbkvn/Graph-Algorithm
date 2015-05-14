QT += widgets

HEADERS += \
        edge.h \
        vertex.h \
        graphwidget.h \
    mainwindow.h \
    graphscene.h

SOURCES += \
        edge.cpp \
        main.cpp \
        vertex.cpp \
        graphwidget.cpp \
    mainwindow.cpp \
    graphscene.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/graph_algorithm
INSTALLS += target

FORMS += \
    mainwindow.ui

RESOURCES += \
    images.qrc
