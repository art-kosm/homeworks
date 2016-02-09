#include <QPainter>
#include <QtCore/qmath.h>
#include "cannon.h"

Cannon::Cannon(int startPos, double x, double y, double angle, QColor color, QObject *parent, ShellType type, int counter)
    : QObject(parent),
      leftPos(startPos),
      rightPos(startPos),
      cannonX(x),
      cannonY(y),
      cannonAngle(angle),
      cannonColor(color),
      shellType(type),
      shellCounter(counter) {}

QRectF Cannon::boundingRect() const
{
    return QRectF(-cannonSize, -cannonSize, cannonSize * 2, cannonSize * 2);
}

void Cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QBrush cannonBrush(cannonColor);
    painter->setBrush(cannonBrush);
    painter->setPen(QPen(QColor(0, 0, 0)));
    painter->drawEllipse(QPoint(cannonX, cannonY), cannonSize, cannonSize);

    painter->setPen(QPen(cannonBrush, 10));
    QPoint cannonOut(cannonX + cannonLength * qCos(cannonAngle),
                     cannonY - cannonLength * qSin(cannonAngle));
    painter->drawLine(QPoint(cannonX, cannonY), cannonOut);
}

void Cannon::moveCannonToLeft(QPoint land[])
{
    if (leftPos == rightPos && leftPos > 1)
        --leftPos;

    moveCannon(false, land);

    if (cannonX <= land[leftPos].x())
    {
        cannonX = land[leftPos].x();
        cannonY = land[leftPos].y();
        rightPos = leftPos;
    }
}

void Cannon::moveCannonToRight(QPoint land[], int pointsNumber)
{
    if (leftPos == rightPos && rightPos < pointsNumber - 2)
        ++rightPos;

    moveCannon(true, land);

    if (cannonX >= land[rightPos].x())
    {
        cannonX = land[rightPos].x();
        cannonY = land[rightPos].y();
        leftPos = rightPos;
    }
}

void Cannon::increaseCannonAngle()
{
    if (cannonAngle < 3 * M_PI / 2)
        cannonAngle += cannonRotationSpeed;
}

void Cannon::decreaseCannonAngle()
{
    if (cannonAngle > - M_PI / 2)
        cannonAngle -= cannonRotationSpeed;
}

Shell *Cannon::cannonFire()
{
    if (shellCounter > 0)
    {
        shellCounter--;

        double shellSpeed;
        double shellSize;
        double shellHitRadius;
        Color shellColor;

        switch (shellType)
        {
            case Small:
                shellSpeed = 5;
                shellSize = 4;
                shellHitRadius = 0;
                shellColor = Black;
                break;

            case Medium:
                shellSpeed = 4;
                shellSize = 10;
                shellHitRadius = 10;
                shellColor = Yellow;
                break;

            case Big:
                shellSpeed = 3;
                shellSize = 14;
                shellHitRadius = 20;
                shellColor = Green;
                break;
        }

        double hPos = cannonX + (cannonLength + shellSize) * qCos(cannonAngle);
        double vPos = cannonY - (cannonLength + shellSize) * qSin(cannonAngle);

        return new Shell(hPos, vPos, cannonAngle, shellSpeed, shellSize, shellHitRadius, shellColor, this);
    }

    return nullptr;
}

void Cannon::setShellType(ShellType type)
{
    shellType = type;
}

bool Cannon::collidesWith(Shell *shell, int hitRadius)
{
    double x = shell->getHPos();
    double y = shell->getVPos();

    return qSqrt((x - cannonX) * (x - cannonX) + (y - cannonY) * (y - cannonY)) <
           shell->getSize() + hitRadius + cannonSize;
}

int Cannon::getShellCounter()
{
    return shellCounter;
}

void Cannon::moveCannon(bool toRight, QPoint land[])
{
    int parts = countParts(land);

    if (parts > 0)
    {
        double hDist = (double) (land[rightPos].x() - land[leftPos].x()) / parts;
        double vDist = (double) (land[rightPos].y() - land[leftPos].y()) / parts;
        if (toRight)
        {
            cannonX += hDist;
            cannonY += vDist;
        }
        else
        {
            cannonX -= hDist;
            cannonY -= vDist;
        }
    }
}

int Cannon::countParts(QPoint land[])
{
    int hDist = land[rightPos].x() - land[leftPos].x();
    int vDist = land[rightPos].y() - land[leftPos].y();
    double totalDist = qSqrt(hDist * hDist + vDist * vDist);

    return totalDist / normalDist;
}
