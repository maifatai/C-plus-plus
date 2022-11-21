//
//  polymorphism.cpp
//  learning
//
//  Created by fatai on 2022/8/29.
//

#include "polymorphism.hpp"

void Poly_A::print_info()
{
    cout<<"Poly_A"<<endl;
}

void Poly_B::print_info()
{
    cout<<"Poly_B"<<endl;
}
void Poly_C::print_info()
{
    cout<<"Poly_C"<<endl;
}
void Poly_D::print_info()
{
    cout<<"Poly_D"<<endl;
}
void test_polymorphism()
{
    Poly_A a;Poly_A *pa=&a;
    Poly_B b;Poly_B *pb=&b;
    Poly_C c;Poly_C *pc=&c;
    Poly_D d;Poly_D *pd=&d;
    pa->print_info();
    pa=pb;
    pa->print_info();
    pa=pc;
    pa->print_info();
    pa=pd;
    pa->print_info();
    /*
     Poly_A
     Poly_B
     Poly_C
     Poly_D
     */
    Poly_A &a1=a;
    a1.print_info();
    Poly_A &a2=b;
    a2.print_info();
    Poly_A &a3=c;
    a3.print_info();
    Poly_A &a4=d;
    a4.print_info();
    /*
     Poly_A
     Poly_B
     Poly_C
     Poly_D
     */
    
    cout<<"sizeof(Poly_A):"<<sizeof(Poly_A)<<endl;
    cout<<"sizeof(Poly_B):"<<sizeof(Poly_B)<<endl;
    cout<<"sizeof(Poly_C):"<<sizeof(Poly_C)<<endl;
    cout<<"sizeof(Poly_D):"<<sizeof(Poly_D)<<endl;
    cout<<"sizeof(a):"<<sizeof(a)<<endl;
    /*每一个字节数多8,
     sizeof(Poly_A):16   涉及到对齐问起
     sizeof(Poly_B):16
     sizeof(Poly_C):16
     sizeof(Poly_D):24
     sizeof(a):16
     */
}
