#include <QRadioButton>
#include <QVBoxLayout>
#include "hashFunctionTab.h"

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
    hashtable->setHashFunction(&hashSimple);

    emit hashFunctionSet();
}

void HashFunctionTab::hashRSToggled()
{
    hashtable->setHashFunction(&hashRS);

    emit hashFunctionSet();
}

void HashFunctionTab::hashLYToggled()
{
    hashtable->setHashFunction(&hashLY);

    emit hashFunctionSet();
}

unsigned int HashFunctionTab::hashSimple(const QString &value, int modulo)
{
    const unsigned int base = 8191 % modulo; //prime

    int last = value.length() - 1;
    unsigned int sum = value.at(last).toLatin1() % modulo;

    while (last > 0)
    {
        last--;
        sum = (base * sum + value.at(last).toLatin1()) % modulo;
    }

    return sum;
}

unsigned int HashFunctionTab::hashRS(const QString &value, int modulo)
{
    unsigned int base = 63689 % modulo; //prime
    const unsigned int multiplier = 378551 % modulo; //prime

    int last = value.length() - 1;
    unsigned int sum = value.at(last).toLatin1() % modulo;

    while (last > 0)
    {
        last--;
        sum = (base * sum + value.at(last).toLatin1()) % modulo;
        base *= multiplier % modulo;
    }

    return sum;
}

unsigned int HashFunctionTab::hashLY(const QString &value, int modulo)
{
    const unsigned int base = 1664525 % modulo; //not prime . . .
    const unsigned int summand = 1013904223 % modulo; //prime

    int last = value.length() - 1;
    unsigned int sum = value.at(last).toLatin1() % modulo;

    while (last > 0)
    {
        last--;
        sum = (base * sum + value.at(last).toLatin1() + summand) % modulo;
    }

    return sum;
}
