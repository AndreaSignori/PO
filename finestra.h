#ifndef FINESTRA_H
#define FINESTRA_H

#include <QMainWindow>
#include <QWidget>

class Finestra : public QWidget
{
    Q_OBJECT
public:
    explicit Finestra(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // FINESTRA_H