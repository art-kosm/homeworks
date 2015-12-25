#include <cstdlib>
#include "computer.h"

Computer::Computer(OperatingSystem system, bool infected) :
    system(system),
    infected(infected) {}

void Computer::attack()
{
    if (!infected)
        infected = tryToInfect(system);
}

bool Computer::isInfected()
{
    return infected;
}

bool Computer::tryToInfect(OperatingSystem system)
{
    int safePoint = 0;
    switch (system)
    {
        case Windows :
            safePoint = 5;
            break;

        case Linux :
            safePoint = 4;
            break;

        case MacOS :
            safePoint = 3;
            break;

        case FreeBSD :
            safePoint = 5;
            break;

        case NoSystem :
            safePoint = 8;
            break;

        default :
            break;
    }

    return rand() % 9 > safePoint;
}
