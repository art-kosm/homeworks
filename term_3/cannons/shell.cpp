#include <QPainter>
#include <QtCore/qmath.h>
#include "shell.h"

Shell::Shell(double hPos, double vPos, double angle, double normalSpeed,
             int size, int hitRadius, Color color, QObject *parent)
    : QObject(parent), hPos(hPos), vPos(vPos),
      size(size), hitRadius(hitRadius), color(color),
      hSpeed(normalSpeed * qCos(angle)),
      vSpeed(- normalSpeed * qSin(angle)) {}

QRectF Shell::boundingRect() const
{
    return QRectF(-size, -size, size * 2, size * 2);
}

void Shell::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QBrush shellBrush;
    QPen shellPen;
    switch (color)
    {
        case Black:
            shellBrush = QBrush(QColor(0, 0, 0));
            shellPen = QPen(QColor(255, 255, 255));
            break;

        case Yellow:
            shellBrush = QBrush(QColor(255, 255, 0));
            shellPen = QPen(QColor(0, 0, 0));
            break;

        case Green:
            shellBrush = QBrush(QColor(0, 255, 0));
            shellPen = QPen(QColor(0, 0, 0));
            break;
    }

    painter->setBrush(shellBrush);
    painter->setPen(shellPen);
    painter->drawEllipse(QPoint(hPos, vPos), size, size);
}

void Shell::update()
{
    hPos += hSpeed;
    vPos += vSpeed + acceleration / 2;
    vSpeed += acceleration;
}

double Shell::getHPos()
{
    return hPos;
}

double Shell::getVPos()
{
    return vPos;
}

int Shell::getSize()
{
    return size;
}

double Shell::getHitRadius()
{
    return hitRadius;
}
