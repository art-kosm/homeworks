#pragma once

#include <QObject>
#include <QGraphicsItem>
#include "shell.h"

enum ShellType
{
    Small,
    Medium,
    Big
};

class Cannon : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Cannon(int startPos, double x, double y, double angle, QColor color,
           QObject *parent = 0, ShellType type = Medium, int counter = 50);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void moveCannonToLeft(QPoint land[]);
    void moveCannonToRight(QPoint land[], int pointsNumber);
    void increaseCannonAngle();
    void decreaseCannonAngle();
    Shell *cannonFire();
    void setShellType(ShellType type);
    bool collidesWith(Shell *shell, int hitRadius = 0);
    int getShellCounter();

private:
    void moveCannon(bool toRight, QPoint land[]);
    int countParts(QPoint land[]);

    const double normalDist = 1;
    const double cannonRotationSpeed = 0.02;
    const int cannonSize = 12;
    const int cannonLength = 15;

    int leftPos;
    int rightPos;
    double cannonX;
    double cannonY;
    double cannonAngle;
    QColor cannonColor;
    ShellType shellType;
    int shellCounter;
};
