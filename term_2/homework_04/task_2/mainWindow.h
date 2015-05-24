#pragma once

#include <QMainWindow>
#include "calculator.h"

/**
 * @brief A simple spin box based calculator
 */

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    /**
     * @brief A compute slot
     *
     * Scans spin and combo boxes' values and calculates result with the calculator
     */

    void compute();

    /**
     * @brief Spin boxes' text deselecter
     *
     * Connected via Qt::QueuedConnection
     */

    void onSpinBoxValueChanged();

private:
    Ui::MainWindow *ui;
    Calculator *calculator;
};
