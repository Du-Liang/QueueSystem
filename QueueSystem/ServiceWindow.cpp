#include "ServiceWindow.h"

// ����ϵͳ�еĴ�������
int window_num = 0;

void initServiceWindows(ServiceWindow* &windows)
{
    windows = new ServiceWindow[window_num];
    for (int i = 0; i != window_num; i++)
    {
        windows[i].customer.arrive_time = 0;
        windows[i].customer.duration = 0;
        windows[i].flag = 0;    // 0��ʾ����
    }
}

void destroyWindows(ServiceWindow* &windows)
{
    delete windows;
}

int idleWindow(ServiceWindow* &windows)
{
    for (int i = 0; i != window_num; i++)
    {
        if (windows[i].flag == 0)   // �������
        {
            return i;
        }
    }
    return -1;  // -1��ʾ��ǰû�д����ǿ���
}