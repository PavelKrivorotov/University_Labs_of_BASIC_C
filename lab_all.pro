QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Lab2Window/lab2window.cpp \
    Lab4Window/lab4window.cpp \
    Lab5Window/lab5window.cpp \
    Lab6Window/lab6window.cpp \
    Lab8Window/lab8window.cpp \
    MainWindow/main.cpp \
    MainWindow/mainwindow.cpp \
#    ...
    Lab1Window/Window/lab1window.cpp \
    Lab1Window/MathModule/math_funcs.cpp \
#    ...
#    ...


HEADERS += \
    Lab2Window/lab2window.h \
    Lab4Window/lab4window.h \
    Lab5Window/lab5window.h \
    Lab6Window/lab6window.h \
    Lab8Window/lab8window.h \
    MainWindow/mainwindow.h \
#    ...
    Lab1Window/Window/lab1window.h \
    Lab1Window/MathModule/math_funcs.h \
#    ...
#    ...


FORMS += \
    Lab2Window/lab2window.ui \
    Lab4Window/lab4window.ui \
    Lab5Window/lab5window.ui \
    Lab6Window/lab6window.ui \
    Lab8Window/lab8window.ui \
    MainWindow/mainwindow.ui \
    Lab1Window/Window/lab1window.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

