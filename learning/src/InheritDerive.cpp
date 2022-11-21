//
//  InheritDerive.cpp
//  learning
//
//  Created by fatai on 2022/9/14.
//

#include "InheritDerive.hpp"
void derived::access()
{
//    j = 5;//error 私有成员
    i = 10;//引用的是派生类的 i
    base::i= 5; //引用的是基类的 i
    func();//派生类的
    base::func();//基类的
}

void base::func()
{
    cout<<"base:"<<i<<";"<<j<<endl;
}
void derived::func()
{
    cout<<"derived:"<<i<<endl;
}


void test_inherit_derived()
{
    derived obj;
    obj.i=1;
    obj.base::i=3;
    obj.func();
    obj.base::func();
    /*
     derived:1
     base:3;124800
     */
    obj.access();
    /*
     derived:10
     base:5;124800
     */
    
    //基类与派生类的指针强制转换
    Base1 objBase(5);
    Derived1 objDerived(3);
    /*
     Base 5 constructed
     Base 3 constructed
     Derived constructed:6(2*3)
     */
    Base1 * pBase = & objDerived;//基类指针指向派生类对象
    //pBase->Func(); //err;Base 类没有 Func() 成员函数
    //pBase->v = 5; //err; Base 类没有 v 成员变量
    pBase->Print();//调用基类的函数，但是结果是派生类的数据
    /*
     Base:n=3
     */
    //Derived * pDerived = & objBase; //error 不能将基类指针赋值给派生类指针
    Derived1 * pDerived = (Derived1 *)(&objBase);//强制类型转换
    pDerived->Print(); //慎用，可能出现不可预期的错误
    /*
     Derived:v=1
     Derived:n=5
     */
    pDerived->v=128; //往别人的空间里写入数据，会有问题
    objDerived.Print();
    /*
     Derived:v=6
     Derived:n=3
     Derived destructed:6
     Base 3 destructed
     Base 5 destructed
     */
}
