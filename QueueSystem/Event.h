#ifndef __EVENT_H_
#define __EVENT_H_

typedef struct Event
{
    int occur_time;      // ��ʾ�����¼�������ʱ��
    int evnet_type;      // ��ʾ�¼�������
    struct Event *next;  // ��һ���¼�
} Event;
// ��ͷ���

void initEventList(Event* &eventList);
void orderInsert(Event* &eventList, Event &event);
void deleteFirstEvent(Event* &eventList);

#endif