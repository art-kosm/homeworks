#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>
#include <QLineEdit>
#include "calculator.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

    /**
     * @brief Button clicked signal
     *
     * Connected with button clicked() signal via QSignalMapper
     *
     * @param symbol of the button clicked
     */

    void clicked(const QString &symbol);

private slots:

    /**
     * @brief Button clicked slot
     *
     * @param symbol of the button clicked
     */

    void buttonClicked(const QString &symbol);

private:
    Ui::MainWindow *ui;
    QSignalMapper *mapper;
    QLineEdit *resultField;
    Calculator *calculator;
    bool showingResult;

    /**
     * @brief Result field drawer
     */

    void drawResultField();

    /**
     * @brief Buttons drawer
     *
     * @param buttonsNumber
     * @return An array of buttons
     */

    QPushButton **drawButtons(const int buttonsNumber);

    /**
     * @brief Layout setter
     *
     * @param buttons An array of buttons to be placed
     * @param buttonsNumber
     */

    void setLayout(QPushButton **buttons, const int buttonsNumber);

    /**
     * @brief clicked() and clicked(const QString &symbol) signals mapper
     *
     * @param buttons An array of buttons which signals are to be connected
     * @param buttonsNumber
     */

    void setMapping(QPushButton **buttons, const int buttonsNumber);
};
