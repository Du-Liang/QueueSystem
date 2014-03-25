#include <iostream>
#include <cmath>

// ����[0,1)֮���һ�����ֵ
double uniform()
{
    
    return (double)rand() / (RAND_MAX + 1);
}
// ���ط��Ӳ��ɷֲ������������һ�����ֵ
double getPoisson(double lambda)
{
    int t = 0;
    double p = exp(-lambda);
    double f = p;
    double u = uniform();
    while (true)
    {
        if (f > u)
            break;
        t++;
        p = p*lambda / t;
        f += p;
    }
    return t;
}
// ���ط��Ӹ�ָ���ֲ������������һ�����ֵ
double getExponentail(double lambda)
{
    return -log(1 - uniform()) / lambda;
}