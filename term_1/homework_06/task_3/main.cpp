#include <stdio.h>
#include "avltree.h"

using namespace std;

enum CommandType
{
    show = -1,
    exit,
    addV,
    removeV,
    checkV,
    printA,
    printD,
    printP
};

int main()
{
    printf("Enter -1 to show the list of commands. ");
    BinarySearchTree *tree = createTree();
    int command = -1;

    while (command != exit)
    {
        printf("Enter the command: ");
        scanf("%d", &command);
        switch (command)
        {
            case show:
            {
                printf("List of commands.\n");
                printf("-1: show commands\n0: exit\n1: add value\n2: remove value\n3: check value\n");
                printf("4: print ascending\n5: print descending\n6: print preorder\n");
            } break;

            case exit:
                break;

            case addV:
            {
                int value = 0;
                printf("Enter the value to add: ");
                scanf("%d", &value);
                addValue(tree, value);
            } break;

            case removeV:
            {
                int value = 0;
                printf("Enter the value to remove: ");
                scanf("%d", &value);
                removeValue(tree, value);
            } break;

            case checkV:
            {
                int value = 0;
                printf("Enter the value to check: ");
                scanf("%d", &value);
                if (contains(tree, value))
                    printf("The tree contains this value. ");
                else
                    printf("Value not found. ");
            } break;

            case printA:
            {
                printAscending(tree);
                printf("\n");
            } break;

            case printD:
            {
                printDescending(tree);
                printf("\n");
            }  break;

            case printP:
            {
                printPreorder(tree);
                printf("\n");
            } break;

            default:
                printf("Unknown command. ");
                break;
        }
    }

    deleteTree(tree);
    return 0;
}
