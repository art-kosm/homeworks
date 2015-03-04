#include <iostream>
#include "circularList.h"

using namespace std;

int main()
{
    int sicarii = 0;
    cout << "Enter the number of Sicarii: ";
    cin >> sicarii;

    int toKill = 0;
    cout << "Enter the number of the person to kill: ";
    cin >> toKill;

    CircularList *list = createCircularList();
    for (int i = 0; i < sicarii; i++)
        addValue(list, sicarii - i);
    ListElement *current = getHead(list);
    for (int i = 0; i < sicarii; i++)
    {
        for (int j = 0; j < toKill - 1; j++)
            current = getNextElement(current);
        deleteNextElement(list, current);
    }

    cout << "Survivor: " << getValue(current) << "\n";

    deleteList(list);

    return 0;
}
