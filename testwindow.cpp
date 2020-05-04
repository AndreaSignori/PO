#include <QtWidgets>
#include <QtCore>
#include <QMenuBar>
#include "../ProgettoP2/PO/testwindow.h"

Windows::Windows(QWidget *parent) : QWidget(parent){
    /*resize(800,600);
    QVBoxLayout *layout = new QVBoxLayout(parent);
    QMenuBar *mbar = new QMenuBar(parent);
    QMenu *test = new QMenu(tr("File"));
    QAction *open = new QAction(tr("open"));
    test->addAction(open);
    mbar->setFixedHeight(50);
    mbar->
    mbar->addMenu(test);
    layout->addWidget(mbar);
    setLayout(layout);*/

    createWindow(parent);

}

void Windows::createWindow(QWidget *parent){
    resize(800,600);
    QVBoxLayout *layout = new QVBoxLayout(parent);
    createMenuBar(layout);
    setLayout(layout);
}
void Windows::createMenuBar(QVBoxLayout* layout){
    QMenuBar *menuBar = new QMenuBar();
    QMenu *fileMenu = new QMenu(tr("File"));
    QMenu *file = new QMenu(tr("File2"));
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(file);
    QAction *act = new QAction(tr("Act"),this);
    connect(act,&QAction::triggered,this,&Windows::popUP);
    fileMenu->addAction(act);
    layout->addWidget(menuBar);
}
void Windows::popUP(){
    QMessageBox::information(0, QString("Information"), QString("You've pressed the button Act"), QMessageBox::Ok);
}
