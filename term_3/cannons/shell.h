#pragma once

#include <QObject>
#include <QGraphicsItem>

enum Color
{
    Black,
    Yellow,
    Green
};

class Shell : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Shell(double hPos, double vPos, double angle, double normalSpeed = 4,
          int size = 5, int hitRadius = 1, Color color = Yellow, QObject *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void update();
    double getHPos();
    double getVPos();
    int getSize();
    double getHitRadius();

private:
    static constexpr double acceleration = 0.1;
    double normalSpeed;
    double hPos;
    double vPos;
    int size;
    double hitRadius;
    Color color;
    double hSpeed;
    double vSpeed;
};
