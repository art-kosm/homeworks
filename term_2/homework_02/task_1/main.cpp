#include "linkedlist.h"
#include "singlylinkedlist.h"
#include "doublylinkedlist.h"

using namespace std;

int main()
{
    LinkedList *singly = new SinglyLinkedList();
    singly->insert(10);
    singly->insert(20);
    singly->insert(30);
    singly->remove(20);
    singly->remove(40);
    singly->print();

    delete singly;

    LinkedList *doubly = new DoublyLinkedList();
    doubly->insert(110);
    doubly->insert(120);
    doubly->insert(130);
    doubly->remove(120);
    doubly->remove(140);
    doubly->print();

    delete doubly;

    return 0;
}

