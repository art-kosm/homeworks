#include <iostream>
#include <fstream>
#include "phonelist.h"

using namespace std;

enum Command {
    exitProgram,
    addPhone,
    findByName,
    findByPhone,
    save,
    show,
    unknown
};

Command commandType(int command)
{
    if (command == -1)
        return show;
    if (command == 0)
        return exitProgram;
    if (command == 1)
        return addPhone;
    if (command == 2)
        return findByName;
    if (command == 3)
        return findByPhone;
    if (command == 4)
        return save;
    return unknown;
}

int main()
{
    printf("Enter -1 to show the list of commands. ");

    const int size = 1024;
    char path[size];
    cout << "Enter the file path: ";
    cin.getline(path, size);

    ifstream in(path);

    PhoneList *list = createPhoneList();

    if (in == nullptr)
        cout << "No file found. ";
    else
        importList(list, path);

    in.close();

    int command = -1;
    while (commandType(command) != exitProgram)
    {
        cout << "Enter the command: ";
        cin >> command;
        cin.ignore(size, '\n');        

        switch (commandType(command))
        {
            case show:
            {
                printf("List of commands.\n");
                printf("-1: show commands\n0: exit\n1: add phone\n2: find by name\n3: find by phone\n4: save\n");
            } break;

            case exitProgram:
                break;

            case addPhone:
            {
                char name[size];
                cout << "Enter the name: ";
                cin.getline(name, size);
                char phone[size];
                cout << "Enter the phone number: ";
                cin.getline(phone, size);

                add(list, name, phone);
                break;
            }

            case findByName:
            {
                char name[size];
                cout << "Enter the name: ";
                cin.getline(name, size);

                findPhone(list, name);
                break;
            }

            case findByPhone:
            {
                char phone[size];
                cout << "Enter the phone: ";
                cin.getline(phone, size);

                findName(list, phone);
                break;
            }

            case save:
                exportList(list);
                break;

            default:
                cout << "Unknown command. ";
                break;
        }
    }

    deleteList(list);

    return 0;
}

