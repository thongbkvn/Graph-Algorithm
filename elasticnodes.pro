QT += widgets

HEADERS += \
        edge.h \
        node.h \
        graphwidget.h \
    mainwindow.h \
    graphscene.h

SOURCES += \
        edge.cpp \
        main.cpp \
        node.cpp \
        graphwidget.cpp \
    mainwindow.cpp \
    graphscene.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target

FORMS += \
    mainwindow.ui

RESOURCES += \
    images.qrc
