#include <QPainter>
#include <QtCore/qmath.h>
#include "gameArea.h"

GameArea::GameArea(QWidget *parent)
    : QWidget(parent),
      shells(new QVector<Shell*>),
      state(NoWinner),
      playerCannon(0),
      anotherPlayerCannon(0),
      port(0)
{
    land[0] = QPoint(0, 429);
    for (int i = 1; i < pointsNumber - 2; i++)
        land[i] = QPoint(100 * (i - 1), rand() % 200 + 200);
    land[pointsNumber - 2] = QPoint(565, rand() % 200 + 200);
    land[pointsNumber - 1] = QPoint(565, 429);

    int position = 2;
    playerCannon = new Cannon(position, land[position].x(), land[position].y(), 1, QColor(0, 255, 0), this);
}

GameArea::~GameArea()
{
    delete shells;
    delete playerCannon;
    if (anotherPlayerCannon != nullptr)
        delete anotherPlayerCannon;
}

void GameArea::moveCannonToLeft()
{
    playerCannon->moveCannonToLeft(land);
}

void GameArea::moveCannonToRight()
{
    playerCannon->moveCannonToRight(land, pointsNumber);
}

void GameArea::increaseCannonAngle()
{
    playerCannon->increaseCannonAngle();
}

void GameArea::decreaseCannonAngle()
{
    playerCannon->decreaseCannonAngle();
}

void GameArea::cannonFire()
{
    cannonFire(playerCannon);
}

void GameArea::setLand(QString points)
{
    QStringList coordinates = points.split(" ");
    for (int i = 1; i < pointsNumber - 2; i++)
        land[i] = QPoint(100 * (i - 1), coordinates[i - 1].toInt());
    land[pointsNumber - 2] = QPoint(565, coordinates[pointsNumber - 3].toInt());

    delete playerCannon;
    int position = pointsNumber - 3;
    playerCannon = new Cannon(position, land[position].x(), land[position].y(),
                              M_PI - 1, QColor(255, 255, 0), this);
}

QString GameArea::getLand()
{
    QString result;
    for (int i = 1; i < pointsNumber - 1; i++)
        result += QString::number(land[i].y()) + " ";

    return result;
}

int GameArea::getPointsNumber()
{
    return pointsNumber;
}

void GameArea::setPort(int port)
{
    this->port = port;
}

void GameArea::addNewPlayer(int anotherPlayerPos, double angle, QColor color)
{
    anotherPlayerCannon = new Cannon(anotherPlayerPos, land[anotherPlayerPos].x(),
                                     land[anotherPlayerPos].y(), angle, color, this);
}

void GameArea::interpret(QString string)
{
    QStringList commands = string.split(" ");
    for (int i = 0; i < commands.length(); i++)

        if (commands[i] == QString("L"))
            anotherPlayerCannon->moveCannonToLeft(land);

        else if (commands[i] == QString("R"))
            anotherPlayerCannon->moveCannonToRight(land, pointsNumber);

        else if (commands[i] == QString("U"))
            anotherPlayerCannon->increaseCannonAngle();

        else if (commands[i] == QString("D"))
            anotherPlayerCannon->decreaseCannonAngle();

        else if (commands[i] == QString("E"))
            cannonFire(anotherPlayerCannon);

        else if (commands[i] == QString("0"))
            anotherPlayerCannon->setShellType(Small);

        else if (commands[i] == QString("1"))
            anotherPlayerCannon->setShellType(Medium);

        else if (commands[i] == QString("2"))
            anotherPlayerCannon->setShellType(Big);
}

void GameArea::setShellType(int typeNumber)
{
    playerCannon->setShellType(ShellType(typeNumber));
}

void GameArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(0, 0, 585, 480, QColor(0, 0, 0));
    QBrush whiteBrush(QColor(255, 255, 255));

    switch (state)
    {
        case NoWinner:
        {
            QBrush yellowBrush(QColor(255, 255, 0));

            painter.setBrush(yellowBrush);
            painter.drawPolygon(land, pointsNumber);
            playerCannon->paint(&painter, nullptr, this);

            if (anotherPlayerCannon != nullptr)
                anotherPlayerCannon->paint(&painter, nullptr, this);

            for (int i = 0; i < shells->size(); i++)
            {
                Shell *shell = shells->at(i);
                shell->update();
                shell->paint(&painter, nullptr, this);
                if (collides(shell))
                    shells->remove(i);
            }

            painter.setPen(QPen(whiteBrush, 5));
            painter.setFont(QFont("Courier New", 12));
            painter.drawText(5, 18, "SHELLS LEFT: " + QString::number(playerCannon->getShellCounter()));
            if (port > 0)
                painter.drawText(5, 36, "PORT: " + QString::number(port));
        } break;

        case Victory:
        {
            painter.setPen(QPen(whiteBrush, 5));
            painter.setFont(QFont("Courier New", 12));
            painter.drawText(280, 200, "VICTORY");
        } break;

        case Defeat:
        {
            painter.setPen(QPen(whiteBrush, 5));
            painter.setFont(QFont("Courier New", 12));
            painter.drawText(280, 200, "DEFEAT");
        } break;
    }
}

void GameArea::cannonFire(Cannon *cannon)
{
    Shell *newShell = cannon->cannonFire();
    if (newShell != nullptr)
        shells->append(newShell);
}

bool GameArea::collides(Shell *shell)
{
    double x = shell->getHPos();
    double y = shell->getVPos();

    if (playerCannon->collidesWith(shell))
    {
        state = Defeat;

        return true;
    }

    if (anotherPlayerCannon != nullptr && anotherPlayerCannon->collidesWith(shell))
    {
        state = Victory;

        return true;
    }

    for (int i = 1; i < pointsNumber - 2; i++)
    {
        double x1 = land[i].x();
        double y1 = land[i].y();
        double x2 = land[i + 1].x();
        double y2 = land[i + 1].y();

        double result = (y1 - y2) * x + (x2 - x1) * y + x1 * y2 - x2 * y1;

        if (qAbs(result) < 1000 &&
            x1 - 2 <= x && x <= x2 + 2 &&
            qMin(y1, y2) - 2 <= y && y <= qMax(y1, y2) + 2)
        {
            if (playerCannon->collidesWith(shell, shell->getHitRadius()))
                state = Defeat;

            if (anotherPlayerCannon != nullptr && anotherPlayerCannon->collidesWith(shell, shell->getHitRadius()))
                state = Victory;

            return true;
        }
    }

    return false;
}
