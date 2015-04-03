#include "priorityqueue.h"

struct QueueElement
{
    int value;
    int priority;
    QueueElement *next;
    QueueElement *previous;
};

PriorityQueue::QueueElement *PriorityQueue::addElement(int value, int priority, QueueElement *current)
{
    QueueElement *element = new QueueElement;
    element->value = value;
    element->priority = priority;
    element->next = current->next;
    element->previous = current;
    current->next = element;

    return element;
}

PriorityQueue::PriorityQueue()
{
    head = addElement(0, INT_MIN, nullptr);
    tail = head;
}

PriorityQueue::~PriorityQueue()
{
    QueueElement *current = head;
    while (current->next != nullptr)
        deleteNextElement(current);

    delete head;
}

void PriorityQueue::enqueue(int value, int priority)
{
    QueueElement *current = head->next;
    while (current->priority < priority)
        current = current->next;

    addElement(value, priority, current);
}

int PriorityQueue::dequeue()
{
    int value = tail->value;
    if (head != tail)
    {
        QueueElement *element = tail->previous;
        deleteNextElement(element);
    }

    tail = element;

    return value;
}

void PriorityQueue::deleteNextElement(QueueElement *current)
{
    QueueElement *element = current->next;
    current->next = current->next->next;
    delete element;
}
