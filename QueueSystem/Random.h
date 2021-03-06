//  
//  Random.h
//  QueueSystem
//
//  Create by Euryugasaki on 2014-03-25.
//  Copyright (c) 2014 Euryugasaki. All rights reserved.
// 

#ifndef __RANDOM_H_
#define __RANDOM_H_

// 生成[0,1)之间的一个随机值，均匀分布
double uniform();
// 返回服从泊松分布的随机变量的一个随机值：X～Pi(lambda)
double getPoisson(double lambda);
// 返回服从负指数分布的随机变量的一个随机值：X～e(lambda)
double getExponentail(double lambda);
// 返回服从Gamma分布的随机变量的一个随机值：X～Gamma(alpha, beta)
double getGamma(double alpha, double beta);
// 返回服从Beta分布的随机变量的一个随机值：X～Beta(alpha1, alpha2)
double getBeta(double alpha1, double alpha2);
// 返回服从正态分布的随机变量的一个随机值：X～N(miu, sigma)
double getNormal(double miu, double sigma);
// 返回服从离散均匀分布的随机变量的随机值：http://en.wikipedia.org/wiki/Uniform_distribution_(discrete)
int getDiscreteUniform(int from, int to);
// 返回服从几何分布的随机变量的随机值：X～Geo(p)
int getGeometric(double p);
// 返回服从二项分布的随机变量的随机值：X～B(n, p)
int getBinomial(int n, double p);
#endif