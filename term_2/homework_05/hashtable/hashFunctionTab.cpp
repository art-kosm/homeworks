#include <QRadioButton>
#include <QVBoxLayout>
#include "hashFunctionTab.h"
#include "hashSimple.h"
#include "hashRS.h"
#include "hashLY.h"

HashFunctionTab::HashFunctionTab(Hashtable *hashtable, QWidget *parent) : QWidget(parent)
{
    this->hashtable = hashtable;

    QRadioButton *hashSimple = new QRadioButton("Simple hash (base 8191)");
    QRadioButton *hashRS = new QRadioButton("RS hash (base 63689, multiplier 378551)");
    QRadioButton *hashLY = new QRadioButton("LY hash (base 1664525, summand 1013904223)");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(hashSimple);
    layout->addWidget(hashRS);
    layout->addWidget(hashLY);
    setLayout(layout);

    connect(hashSimple, SIGNAL(clicked()), this, SLOT(hashSimpleToggled()));
    connect(hashRS, SIGNAL(clicked()), this, SLOT(hashRSToggled()));
    connect(hashLY, SIGNAL(clicked()), this, SLOT(hashLYToggled()));

    hashSimple->click();
}

void HashFunctionTab::hashSimpleToggled()
{
    hashtable->setHashFunction(new HashSimple());

    emit hashFunctionSet();
}

void HashFunctionTab::hashRSToggled()
{
    hashtable->setHashFunction(new HashRS());

    emit hashFunctionSet();
}

void HashFunctionTab::hashLYToggled()
{
    hashtable->setHashFunction(new HashLY());

    emit hashFunctionSet();
}
