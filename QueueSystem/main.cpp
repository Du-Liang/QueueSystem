#include "QueueSystemSimulation.h"
#include <cstdlib>
#include "Random.h"
#include <iostream>

int main()
{
    int total_service_time;
    int window_num;
    std::cout << "������Ӫҵ����ʱ��(����):";
    std::cin >> total_service_time;
    std::cout << "�������ṩ����ҵ��Ĵ�����Ŀ(����һ��):";
    std::cin >> window_num;

    srand((unsigned)time_t(NULL));
    double sum = 0;
    for (int i = 0; i < 100; i++)
    {
        sum += QueueSystemSimulation(total_service_time, window_num);
    }
    std::cout << sum / 100 << std::endl;
    system("pause");
    return 0;
}
