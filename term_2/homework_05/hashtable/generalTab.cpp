#include <QPushButton>
#include <QGridLayout>
#include "generalTab.h"

GeneralTab::GeneralTab(Hashtable *hashtable, QWidget *parent) : QWidget(parent)
{
    this->hashtable = hashtable;
    valueField = new QLineEdit;
    QPushButton *addButton = new QPushButton("ADD");
    QPushButton *removeButton = new QPushButton("REMOVE");
    QPushButton *findButton = new QPushButton("FIND");
    foundField = new QLineEdit;
    foundField->setFrame(false);
    foundField->setReadOnly(true);
    foundField->setAlignment(Qt::AlignTop);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(valueField, 0, 1);
    layout->addWidget(addButton, 0, 0);
    layout->addWidget(removeButton, 0, 2);
    layout->addWidget(findButton, 3, 0);
    layout->addWidget(foundField, 3, 1);
    setLayout(layout);

    connect(addButton, SIGNAL(clicked()), this, SLOT(addValue()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeValue()));
    connect(findButton, SIGNAL(clicked()), this, SLOT(findValue()));
}

void GeneralTab::addValue()
{
    hashtable->add(valueField->text());

    emit valueAddedOrRemoved();
}

void GeneralTab::removeValue()
{
    hashtable->remove(valueField->text());

    emit valueAddedOrRemoved();
}

void GeneralTab::findValue()
{
    if (hashtable->contains(valueField->text()))
        foundField->setText("VALUE FOUND :D");
    else
        foundField->setText("VALUE NOT FOUND D:");
}
