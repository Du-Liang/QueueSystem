#ifndef __QUEUE_H_
#define __QUEUE_H_

#include "Node.h"

// ��ͷ���
typedef struct Queue
{
    Node *front;    // ͷ���, ���Ƕ���
    Node *rear;     // ��β
} Queue;

void initQueue(Queue &queue);
void enQueue(Queue &queue, Node &node);
void deQueue(Queue &queue, Node &node);
void destroyQueue(Queue &queue);
void printQueue(Queue  &queue);
int lenthQueue(Queue &queue);

#endif