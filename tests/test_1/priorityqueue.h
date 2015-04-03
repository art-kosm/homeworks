#pragma once

class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();

    /**
     * @brief Enqueue func
     *
     * Adds element with specified priority to the head of the queue
     *
     * @param value
     * @param priority
     */

    void enqueue(int value, int priority);

    /**
     * @brief Dequeue func
     *
     * Gets the value of and deletes the tail element
     *
     * @return Value of the tail element
     */

    int dequeue();

private:
    struct QueueElement;
    QueueElement *head;
    QueueElement *tail;

    QueueElement *addElement(int value, int priority, QueueElement *current);
    void deleteNextElement(QueueElement *current);
};
