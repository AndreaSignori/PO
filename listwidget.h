#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QObject>
#include <QtWidgets>
#include <container.h>
#include <prodotto.h>
#include <proddetails.h>

class ListWidgetItem : public QListWidgetItem {
    Container<Prodotto>::iterator iterator;
    // costruttore privato! solo ListWidget può instanziare perchè è friend class
    ListWidgetItem(const Container<Prodotto>::iterator &it);
public:

    Container<Prodotto>::iterator getProdotto() const;
    friend class ListWidget;
};

class ListWidget : public QListWidget{
private:
    Container<Prodotto> *c;
    QLabel *ln, *lc;
public:
    ListWidget(Container<Prodotto>* c = nullptr, QWidget* parent = nullptr);

    QLabel* getLn() const;
    QLabel* getLc() const;

    void addEntry(const Container<Prodotto>::iterator& d);
public slots:
    void rmSelected(bool,ProdDetails*);
};

#endif // LISTWIDGET_H
