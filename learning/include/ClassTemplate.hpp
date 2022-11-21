//
//  ClassTemplate.hpp
//  learning
//  类模板
//  Created by fatai on 2022/8/31.
//
#ifndef ClassTemplate_hpp
#define ClassTemplate_hpp

#include <iostream>
#include <string>
using namespace std;

template <class T1,class T2>
class Pair
{
public:
    T1 key;//关键字
    T2 value;//值
    Pair(T1 k,T2 v):key(k),value(v) { };
    bool operator < ( const Pair<T1,T2> & p ) const;
};

//类模板从类模板派生
template <class T1,class T2>
class A {
    T1 v1; T2 v2;
};

template <class T1,class T2>
class B: public A<T2,T1>//此时A的类型未知
{
    T1 v3;
    T2 v4;
};

template <class T>
class C:public B<T,T>
{
    T v5;
};


//类模板从模板类派生
template <class T1,class T2>
class A1
{
    T1 v1; T2 v2;
};
template <class T>
class B1:public A1<int,double> //此时A1已经实例化，A1为模板类，B1为类模板
{
    T v;
};

//类模板从普通类派生   A2是普通类，B2是类模板
class A2
{
    int v1;
};
template <class T>
class B2:public A2 { //所有从B实例化得到的类都以A为基类
    T v;
};

//普通类从模板类派生
template <class T>
class A3
{
    T v1;
    int n;
};
class B3:public A3<int>// 此时A3已经实例化，作为一个模板类，B3是一个普通类
{
    double v;
};

void test_class_template();

#endif /* ClassTemplate_hpp */
