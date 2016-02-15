#pragma once

#include <QWidget>
#include "cannon.h"

enum GameState
{
    NoWinner,
    Victory,
    Defeat
};

class GameArea : public QWidget
{
    Q_OBJECT

public:
    GameArea(QWidget *parent = 0);
    ~GameArea();
    void moveCannonToLeft();
    void moveCannonToRight();
    void increaseCannonAngle();
    void decreaseCannonAngle();
    void cannonFire();

    void setLand(QString points);
    QString getLand();
    int getPointsNumber();
    void setPort(int port);
    void addNewPlayer(int anotherPlayerPos, double angle, QColor color);
    void interpret(QString string);

public slots:
    void setShellType(int typeNumber); //int to match the signal type

protected:
    void paintEvent(QPaintEvent *);

private:
    void cannonFire(Cannon *cannon);
    bool collides(Shell *shell);

    static const int pointsNumber = 9;

    QPoint land[pointsNumber];
    QVector<Shell*>* shells;
    GameState state;

    Cannon *playerCannon;
    Cannon *anotherPlayerCannon;

    int port;
};
