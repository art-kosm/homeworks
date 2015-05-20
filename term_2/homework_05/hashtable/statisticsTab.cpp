#include <QGridLayout>
#include "statisticsTab.h"

StatisticsTab::StatisticsTab(Hashtable *hashtable, QWidget *parent) : QWidget(parent)
{
    this->hashtable = hashtable;

    total = new QLineEdit();
    total->setFrame(false);
    total->setReadOnly(true);
    loadFactor = new QLineEdit();
    loadFactor->setFrame(false);
    loadFactor->setReadOnly(true);
    conflicts = new QLineEdit();
    conflicts->setFrame(false);
    conflicts->setReadOnly(true);
    maxListLength = new QLineEdit();
    maxListLength->setFrame(false);
    maxListLength->setReadOnly(true);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(total, 0, 0);
    layout->addWidget(loadFactor, 1, 0);
    layout->addWidget(conflicts, 0, 1);
    layout->addWidget(maxListLength, 1, 1);
    setLayout(layout);

    hashtableWasModified();
}

void StatisticsTab::hashtableWasModified()
{
    total->setText("Total positions: " + QString::number(hashtable->getElementsNumber()));
    loadFactor->setText("Load factor: " + QString::number(hashtable->loadFactor()));
    conflicts->setText("Conflicts number: " + QString::number(hashtable->conflicts()));
    maxListLength->setText("Maximum conflict list length: " + QString::number(hashtable->maxListLength()));
}
