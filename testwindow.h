#ifndef TESTWINDOW_H
#define TESTWINDOW_H
#include <QtWidgets>
#include <QtCore>
#include <QWidget>

class Windows : public QWidget
{
private:
    void createWindow(QWidget *parent);
    void createMenuBar(QVBoxLayout *layout);
private slots:
    void popUP();
public:
    Windows(QWidget *parent=0);

    ~Windows() {}
};
#endif // TESTWINDOW_H
