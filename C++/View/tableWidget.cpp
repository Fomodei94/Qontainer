#include "tableWidget.h"

tableWidget::tableWidget(Qontainer<VideoFile*> *itemList, QWidget *parent) : QTableWidget(parent), itemList(itemList) {
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    
    setRowCount(itemList->getObjCount());
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    QStringList headers;
    headers<<"Title"<<"Genre"<<"Nation"<<"Year";
    setHorizontalHeaderLabels(headers);
}

/*
void DBList::viewUsers(){
    setRowCount(itemList->getObjCount());
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList tableHeader;
    setColumnCount(4);
    setColumnWidth(0,255);
    setColumnWidth(1,210);
    setColumnWidth(2,200);
    setColumnWidth(3,265);
    setMaximumWidth(933);
    tableHeader<<"Username"<<"Nome"<<"Cognome"<<"Tipologia Account";
    setHorizontalHeaderLabels(tableHeader);
    setEditTriggers(QAbstractItemView::NoEditTriggers);

}
*/
