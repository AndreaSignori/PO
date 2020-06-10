#include "listwidget.h"

ListWidgetItem::ListWidgetItem(const Container<Prodotto>::iterator &it)
    : QListWidgetItem(), iterator(it)
{}

Container<Prodotto>::iterator ListWidgetItem::getProdotto() const {
    return iterator;
}

ListWidget::ListWidget(Container<Prodotto>* c, QWidget* parent):QListWidget(parent), c(c)
{
    setSelectionMode(QAbstractItemView::ExtendedSelection);
}

void ListWidget::addEntry(const Container<Prodotto>::iterator &d)
{
    QWidget* main = new QWidget();
    QHBoxLayout* lay1 = new QHBoxLayout();

    QLabel* ln = new QLabel();
    QLabel* lc = new QLabel();

    ln->setText(QString::fromStdString(d->GetNome()));
    lc->setText(QString::fromStdString(d->GetCodice()));

    ln->setAlignment(Qt::AlignCenter);
    lc->setAlignment(Qt::AlignCenter);

    lay1->addWidget(ln);
    lay1->addWidget(lc);

    main->setLayout(lay1);

    QListWidgetItem *item = new ListWidgetItem(d);
    addItem(item);
    item->setSizeHint(main->sizeHint());
    setItemWidget(item, main);
}

void ListWidget::rmSelected(bool) {
    auto selected_items = selectedItems();
    if (!selected_items.count()) return;
    if (QMessageBox::question(this, "Delete", "Delete selected items?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
        for (auto item : selected_items) {
            c->remove( static_cast<ListWidgetItem*>(item)->getProdotto() );
            delete item;
        }
}

