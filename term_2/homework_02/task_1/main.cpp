#include "singlyLinkedListTest.h"
#include "doublyLinkedListTest.h"

int main()
{
    SinglyLinkedListTest testSingly;
    QTest::qExec(&testSingly);

    printf("\n");

    DoublyLinkedListTest testDoubly;
    QTest::qExec(&testDoubly);
}
