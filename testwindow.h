#ifndef TESTWINDOW_H
#define TESTWINDOW_H
#include <QtWidgets>
#include <QtCore>
#include <QWidget>
#include <container.h>
class Windows : public QWidget
{
private:
    void createWindow();
    void createMenuBar();
    void createTabWidget();
    QWidget* createTab();
    QWidget* createForm();
    void setUpTable();
    QVBoxLayout* lay;
    QTableWidget* table;
    Container* cont;
    QDialogButtonBox* bBox;
    QFormLayout* layF;
private slots:
    void popUP();
    void accept();
signals:
    void change();

public:
    Windows(QWidget *parent=0);

    ~Windows() {}
};
#endif // TESTWINDOW_H
