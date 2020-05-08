#ifndef TESTWINDOW_H
#define TESTWINDOW_H
#include <QtWidgets>
#include <QtCore>
#include <QWidget>

class Windows : public QWidget
{
private:
    void createWindow();
    void createMenuBar();
    void createTabWidget();
    QWidget* createTab();
    QWidget* createForm();
    QVBoxLayout* lay;

private slots:
    void popUP();
signals:
    void change();

public:
    Windows(QWidget *parent=0);

    ~Windows() {}
};
#endif // TESTWINDOW_H
