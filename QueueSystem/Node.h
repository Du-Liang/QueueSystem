#ifndef __NODE_H_
#define __NODE_H_

typedef struct Node
{
    int arrive_time;    // ����ʱ��
    int duration;       // ����ʱ��
    struct Node *next;
} Node, Customer;

#endif