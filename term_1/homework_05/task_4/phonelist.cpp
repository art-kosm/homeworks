#include <iostream>
#include <fstream>
#include "phonelist.h"

using namespace std;

struct PhoneListElement
{
    char name[1024];
    char phone[1024];
    PhoneListElement *next;
};

struct PhoneList
{
    PhoneListElement *head;
};

PhoneListElement *createPhoneListElement(char *name, char *phone)
{
    PhoneListElement *element = new PhoneListElement;
    int counter = 0;
    if (name != nullptr)
        while (name[counter] != '\0')
        {
            element->name[counter] = name[counter];
            counter++;
        }
    element->name[counter] = '\0';
    counter = 0;
    if (phone != nullptr)
        while (phone[counter] != '\0')
        {
            element->phone[counter] = phone[counter];
            counter++;
        }
    element->phone[counter] = '\0';
    element->next = nullptr;
    return element;
}

PhoneList *createPhoneList()
{
    PhoneListElement *guard = createPhoneListElement(nullptr, nullptr);
    PhoneList *list = new PhoneList;
    list->head = guard;

    return list;
}

void add(PhoneList *list, char *name, char *phone)
{
    PhoneListElement *current = list->head;
    while (current->next != nullptr)
        current = current->next;

    PhoneListElement *element = createPhoneListElement(name, phone);

    current->next = element;
}

void findPhone(PhoneList *list, char *name)
{
    PhoneListElement *current = list->head->next;
    int phonesCount = 0;
    while (current != nullptr)
    {
        bool stringsMatch = true;
        for (int i = 0; name[i] != '\0' || current->name[i] != '\0'; i++)
            if (name[i] != current->name[i])
            {
                stringsMatch = false;
                break;
            }
        if (stringsMatch)
        {
            cout << current->phone << " is the phone number of a person with this name.\n";
            phonesCount++;
        }
        current = current->next;
    }
    if (phonesCount == 0)
        cout << "No phone numbers found.\n";
}


void findName(PhoneList *list, char *phone)
{
    PhoneListElement *current = list->head->next;
    int ownersCount = 0;
    while (current != nullptr)
    {
        bool stringsMatch = true;
        for (int i = 0; phone[i] != '\0' || current->phone[i] != '\0'; i++)
            if (phone[i] != current->phone[i])
            {
                stringsMatch = false;
                break;
            }
        if (stringsMatch)
        {
            cout << "The name of this phone number owner is " << current->name << ".\n";
            ownersCount++;
        }
        current = current->next;
    }
    if (ownersCount == 0)
        cout << "No owners found.\n";
}


void exportList(PhoneList *list)
{
    const int size = 1024;
    char path[size];
    cout << "Enter the file path: ";
    cin.getline(path, size);
    ofstream out(path);
    PhoneListElement *current = list->head->next;
    while (current != nullptr)
    {
        out << current->name << "\\" << current->phone << "\n";
        current = current->next;
    }
    out.close();
}


void importList(PhoneList *list, char *path)
{
    ifstream in(path);
    const int size = 1024;
    char string[size];

    while (!in.eof())
    {
        in.getline(string, size);

        char name[size];
        int stringCounter = 0;
        while (string[stringCounter] != '\\')
        {
            name[stringCounter] = string[stringCounter];
            stringCounter++;
        }
        if (name[0] == '\0')    //we do not need people without names
            continue;
        name[stringCounter] = '\0';
        stringCounter++;

        char phone[size];
        int phoneCounter = 0;
        while (string[stringCounter] != '\0')
        {
            phone[phoneCounter] = string[stringCounter];
            phoneCounter++;
            stringCounter++;
        }
        phone[phoneCounter] = '\0';

        add(list, name, phone);
    }

    in.close();
}

void deleteNextElement(PhoneListElement *current)
{
    PhoneListElement *element = current->next;
    current->next = current->next->next;
    delete element;
}

void deleteList(PhoneList *list)
{
    PhoneListElement *current = list->head;
    while (current->next != nullptr)
        deleteNextElement(current);
}
