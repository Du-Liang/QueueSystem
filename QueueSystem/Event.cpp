#include "Event.h"
#include "Random.h"
#include <iostream>

void initEventList(Event* &eventList)
{
    eventList = new Event;
    eventList->next = NULL;

    Event event;
    event.occur_time = getPoisson(30); // ����һ��1~30�����ֵ���ǵ�һ���˿͸��˶೤�Żᵽ����
    event.evnet_type = -1;
    event.next = NULL;
    orderInsert(eventList, event);
}
void orderInsert(Event* &eventList, Event &event)
{
    Event* temp_event;
    temp_event = new Event;
    temp_event->occur_time = event.occur_time;
    temp_event->evnet_type = event.evnet_type;
    temp_event->next = NULL;

    // ���eventList������û���¼��Ļ�����ô������Ҫ��temp_eventֱ�Ӳ���
    if (!eventList->next)
    {
        eventList->next = temp_event;
        return;
    }

    // ����ʱ��˳�������в���
    Event *temp_event_list = eventList;
    while (temp_event_list->next && temp_event_list->next->occur_time < event.occur_time)
    {
        temp_event_list = temp_event_list->next;
    }
    // �������
    temp_event->next = temp_event_list->next;
    temp_event_list->next = temp_event;

}
void deleteFirstEvent(Event* &eventList)
{
    Event *temp;
    temp = eventList->next;
    eventList->next = temp->next;
    delete temp;
}