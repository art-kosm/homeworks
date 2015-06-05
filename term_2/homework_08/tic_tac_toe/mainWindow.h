#pragma once

#include <QMainWindow>
#include <QPushButton>
#include "ticTacToeGame.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int size = 3, QWidget *parent = 0);
    ~MainWindow();

signals:
    void clicked(int);

private slots:
    void setTurn(int, FieldValue);
    void showResults(GameStatus);
    void resetWindow();

private:
    Ui::MainWindow *ui;
    int sideLength;
    int buttonsNumber;
    QPushButton **buttons;
    TicTacToeGame *game;

    void initializeButtons(int);
};
