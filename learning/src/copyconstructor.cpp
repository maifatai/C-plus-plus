//
//  copyconstructor.cpp
//  learning
//
//  Created by fatai on 2022/8/28.
//

#include "copyconstructor.hpp"
CopyConstructor::CopyConstructor()
{
    cout<<"constructor 1 called"<<endl;
}
CopyConstructor::CopyConstructor(double x,double y)
{
    real=x;
    imag=y;
    cout<<"constructor 2 called"<<endl;
}
CopyConstructor::CopyConstructor(const CopyConstructor &c)
{
    real=c.real;
    imag=c.imag;
    cout<<"copy constructor called"<<endl;
}
void test_copyconstructor_func(CopyConstructor c)
{
    cout<<"condition 2"<<endl;
}
CopyConstructor test_copyconstructor_return()
{
    CopyConstructor c1(3,4);
    cout<<"condition 3"<<endl;
    return c1;
}
int test_copyconstructor()
{
/*
 复制构造函数起作用的三种情况
 */
    //1.用一个对象去初始化同类的另一个对象
    CopyConstructor c1;
    CopyConstructor c2(c1);
    /*
     constructor 1 called
     copy constructor called
     */
    CopyConstructor c3(0,1);
    CopyConstructor c4=c3;//初始化语句，非赋值语句
    /*
     constructor 2 called
     copy constructor called
     */
    //2如果某函数有一个参数时类的对象，那么该函数被调用时，类的复制构造函数将被调用
    test_copyconstructor_func(c2);
    /*
     copy constructor called
     condition 2
     */
    
    //3.如果函数的返回值为类的对象时，则函数返回时，复制构造函数将会被调用
    CopyConstructor c5=test_copyconstructor_return();
    
    return 0;
}

