#pragma once

#include <QMainWindow>
#include <QPushButton>

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
    void nextTurn(int);

private:
    Ui::MainWindow *ui;
    int sideLength;
    int buttonsNumber;
    QPushButton **buttons;

    bool turnX;
    bool firstTurn;

    void initializeButtons(int);

    void checkForWinner();
    bool horizontalWinner(QString &);
    bool verticalWinner(QString &);
    bool majorDiagonalWinner(QString &);
    bool minorDiagonalWinner(QString &);
    bool draw(QString &);

    void showResults(const QString &);
};
