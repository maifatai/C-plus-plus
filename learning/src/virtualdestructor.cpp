//
//  virtualdestructor.cpp
//  learning
//
//  Created by fatai on 2022/8/29.
//

#include "virtualdestructor.hpp"
Base::Base()
{
    cout<<"base constructor"<<endl;
}
Base::~Base()
{
    cout<<"base destructor"<<endl;
}

Derived::Derived()
{
    cout<<"derived constructor"<<endl;
}
Derived::~Derived()
{
    cout<<"derived destructor"<<endl;
}

BaseVirtual::BaseVirtual()
{
    cout<<"virtual base constructor"<<endl;
}
BaseVirtual::~BaseVirtual()
{
    cout<<"virtual base destructor"<<endl;
}
DerivedVirtual::DerivedVirtual()
{
    cout<<"derived virtual constructor"<<endl;
}
DerivedVirtual::~DerivedVirtual()
{
    cout<<"derived virtual destructor"<<endl;
}

void test_virtual_destructor()
{
    Base *p;
    p=new Derived();
    delete p;
    /*
     base constructor
     derived constructor
     base destructor
     */
    BaseVirtual *ps;
    ps=new DerivedVirtual();
    delete ps;
    /*
     virtual base constructor
     derived virtual constructor
     derived virtual destructor
     virtual base destructor
     */
}
