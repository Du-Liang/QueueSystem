#include "QueueSystemSimulation.h"
#include <iostream>
#include <ctime>
#include "Random.h"

// ����̨�Ĵ�����
extern int window_num;
// �ܵ�Ӫҵʱ��
int total_service_time = 0;
// �˿͵Ķ�����ʱ��
int customer_stay_total_time = 0;
// �ܵĹ˿���
int total_customer_num = 0;

double QueueSystemSimulation(int a1, int a2)
{
    total_service_time = a1;
    window_num = a2;
    // �˿͵Ķ�����ʱ��
    customer_stay_total_time = 0;
    // �ܵĹ˿���
    total_customer_num = 0;


    Event *eventList;
    Event event;
    event.evnet_type = -1;
    event.occur_time = 0;
    event.next = NULL;

    ServiceWindow *windows = NULL;
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;

    systemStrat(eventList, windows, queue);

    while (eventList->next)
    {
        event.evnet_type = eventList->next->evnet_type;
        event.occur_time = eventList->next->occur_time;
        deleteFirstEvent(eventList);
        if (event.evnet_type == -1)
            customerArrived(eventList, windows, queue, event);
        else
            customerDeparture(eventList, windows, queue, event);
        printQueue(queue);
    }

    systemEnd(windows, queue);
    double t = (float)customer_stay_total_time / total_customer_num;
    return t;
}

void systemStrat(Event* &eventList, ServiceWindow* &windows, Queue &queue)
{
    initEventList(eventList);
    initServiceWindows(windows);
    initQueue(queue);
}

void systemEnd(ServiceWindow* &windows, Queue &queue)
{
    destroyQueue(queue);
    destroyWindows(windows);

    std::cout << "����ҵ��������Ϊ��" << total_customer_num << "��." << std::endl;
    std::cout << "ÿ���˿�ƽ����ϵͳ�ڶ�����ʱ��Ϊ��" << (float)customer_stay_total_time / total_customer_num << "����." << std::endl;
}

void customerArrived(Event* &eventList, ServiceWindow* &windows, Queue &queue, Event &event)
{
    std::cout << "-------�˿͵���-------" << std::endl;
    total_customer_num++;
    int durtime = getExponentail(0.1);      // ����ҵ������Ҫ��ʱ��
    int intertime = getPoisson(30);    // ���������һ���˿͵ĵ���ʱ����

    // ������һ���˿͵ĵ����¼�
    int time = event.occur_time + intertime; // ��һ���˿͵ĵ���ʱ�� = ��ǰ�¼��ķ���ʱ�� + ��һ���˿͵����ʱ����
    Event temp_event;
    temp_event.occur_time = time;
    temp_event.evnet_type = -1;
    temp_event.next = NULL;

    std::cout << "�˿͵ĵ���ʱ��Ϊ��" << event.occur_time << std::endl;

    if (time < total_service_time)
    {
        orderInsert(eventList, temp_event);
        std::cout << "��һ���˿͵ĵ���ʱ��Ϊ��" << time << std::endl;
    }

    // �ѵ�ǰ�¼�����Ĺ˿Ͳ��뵽���е���
    Customer customer;
    customer.arrive_time = event.occur_time;
    customer.duration = durtime;
    customer.next = NULL;
    enQueue(queue, customer);

    // �����ǰ�������п��д��ڵģ���ô����ֱ�ӾͲ���Ҫ�ŶӾͿ���ֱ�ӽ�����̨������
    int i = idleWindow(windows);
    // -1��ʾû�д����ǿ��У����û�д����ǿ��еĻ��أ����Ǿ�ʲôҲ����
    if (i == -1)
    {
        ;
    }
    else
    {
        deQueue(queue, customer);
        windows[i].customer = customer;
        windows[i].flag = 1;

        // �˿͵����ڿ�ʼ�����ˣ����Ǿ���Ҫ��������˿͵�һ���뿪ʱ�䵽ʱ���ߣ��¼�������
        temp_event.occur_time = event.occur_time + durtime; // �뿪�¼��ķ���ʱ�� = ��ǰʱ��ķ���ʱ�� + ����ʱ��
        temp_event.evnet_type = i;
        temp_event.next = NULL;
        orderInsert(eventList, temp_event);
    }
}
void customerDeparture(Event* &eventList, ServiceWindow* &windows, Queue &queue, Event &event)
{
    std::cout << "-------�˿��뿪-------" << std::endl;
    std::cout << "�˿͵��뿪�¼�Ϊ��" << event.occur_time << std::endl;

    if (event.occur_time > total_service_time)
    {
        ; // �������뿪�¼��ķ���ʱ����ܷ���ʱ�����ʲôҲ����
    }
    else
    {
        // �˿͵Ķ���ʱ�� = ��ǰ�˹˿͵��뿪ʱ�� - �˿͵ĵ���ʱ��
        customer_stay_total_time += event.occur_time - windows[event.evnet_type].customer.arrive_time;
        // ������л����ˣ���ֱ�ӽ����׵��˽е�����̨�����з���
        if (queue.front->next)
        {
            Customer customer;
            deQueue(queue, customer);
            windows[event.evnet_type].customer = customer;

            // �뿪�¼�
            Event temp_event;
            temp_event.occur_time = event.occur_time + customer.duration;
            temp_event.evnet_type = event.evnet_type;
            orderInsert(eventList, temp_event);
        }
        else
        {
            // �������û���ˣ��ҵ�ǰ���ڵĹ˿����뿪�ˣ���ô������ھʹ��ڿ���״̬��
            windows[event.evnet_type].flag = 0;
        }
    }
}