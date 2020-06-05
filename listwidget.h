#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QObject>
#include <QtWidgets>
#include <container.h>
#include <prodotto.h>

class ListWidgetItem : public QListWidgetItem {
    Container<Prodotto>::iterator iterator;
    /// costruttore privato! solo friend class ListWidget può instanziare
    ListWidgetItem(const Container<Prodotto>::iterator &it);
public:

    Container<Prodotto>::iterator getProdotto() const;
    friend class ListWidget;
};

class ListWidget : public QListWidget{
private:
    Container<Prodotto> *c;
public:
    ListWidget(Container<Prodotto>* c = nullptr, QWidget* parent = nullptr);

    void addEntry(const Container<Prodotto>::iterator& d);
public slots:
    void rmSelected(bool);
};

#endif // LISTWIDGET_H
