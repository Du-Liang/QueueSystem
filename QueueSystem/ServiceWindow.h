#ifndef __SERVICE_WINDOW_H_
#define __SERVICE_WINDOW_H_

#include "Node.h"

typedef struct ServiceWindow
{
    Customer customer;
    int flag;           // 0��ʾ��ǰ�����ǿ��еģ�1��ʾ��ǰ�����Ǳ�ռ�õ�
} ServiceWindow;

void initServiceWindows(ServiceWindow* &windows);
void destroyWindows(ServiceWindow* &windows);
int idleWindow(ServiceWindow* &windows);

#endif