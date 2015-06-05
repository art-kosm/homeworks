#pragma once

#include <QLineEdit>
#include "hashtable.h"

class GeneralTab : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralTab(Hashtable *hashtable, QWidget *parent = 0);

signals:

    /**
     * @brief valueAddedOrRemoved signal
     *
     * Emits after adding or removing a value to the hashtable
     */

    void valueAddedOrRemoved() const;

private slots:

    /**
     * @brief addValue slot
     *
     * Adds the value set on valueField and emits valueAddedOrRemoved signal
     */

    void addValue();

    /**
     * @brief removeValue slot
     *
     * Removes the value set on valueField and emits valueAddedOrRemoved signal
     */

    void removeValue();

    /**
     * @brief findValue slot
     *
     * Searches for the value set on valueField
     */

    void findValue();

private:
    QLineEdit *valueField;
    QLineEdit *foundField;

    Hashtable *hashtable;
};
