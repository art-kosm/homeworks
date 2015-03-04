#include <iostream>
#include "sortedList.h"

using namespace std;

int main()
{
    cout << "Hello! \n0 - exit \n1 - add a value to sorted list \n2 - remove a value from sorted list \n3 - print list\n";
    SortedList *list = createSortedList();
    int input = -1;
    while (input != 0)
    {        
        cout << "\nInput: ";
        cin >> input;
        while (input < 0 || input > 3)
        {
            cout << "Error! \n\nInput: ";
            cin >> input;
        }
        if (input == 1)
        {
            int value = 0;
            cout << "Enter the number to add: ";
            cin >> value;
            addValue(list, value);
        }
        else if (input == 2)
        {
            int value = 0;
            cout << "Enter the number to remove: ";
            cin >> value;
            removeValue(list, value);
        }
        else if (input == 3)
        {
            cout << "List:\n";
            printList(list);
        }
    }
    deleteList(list);
    delete list;
    return 0;
}
