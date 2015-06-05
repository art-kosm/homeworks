#pragma once

#include <QLineEdit>
#include "hashtable.h"

class StatisticsTab : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsTab(Hashtable *hashtable, QWidget *parent = 0);

public slots:

    /**
     * @brief hashtableWasModified slot
     *
     * Updates hashtable statistics
     */

    void hashtableWasModified();

private:
    QLineEdit *total;
    QLineEdit *loadFactor;
    QLineEdit *conflicts;
    QLineEdit *maxListLength;

    Hashtable *hashtable;
};
