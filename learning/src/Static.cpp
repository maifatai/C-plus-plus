//
//  Static.cpp
//  learning
//
//  Created by fatai on 2022/8/28.
//

#include "Static.hpp"
/*
 必须在定义类的文件中对静态成员变量进行一次说明或初始化，否则编译能通过，链接不能通过
 */
int Static::num=0;
int Static::totalarea=0;
Static::Static(int w_,int h_)
{
    w=w_;
    h=h_;
    num++;
    totalarea+=w*h;
}

Static::~Static()
{
    num--;
    totalarea-=w*h;
}
Static::Static(Static &r)
{
    w=r.w;
    h=r.h;
    num++;
    totalarea+=w*h;
}
void Static::print_info()
{
    cout<<num<<";"<<totalarea<<endl;
}

void test_static()
{
    Static r1(2,3),r2(4,5);
    Static::print_info();
    r1.print_info();
    r2.print_info();
    cout<<"sizeof(Static):"<<sizeof(Static)<<endl;
    cout<<"sizeof(r1):"<<sizeof(r1)<<endl;
    
    /*
     2;26
     2;26
     2;26
     sizeof(Static):8
     sizeof(r1):8
     */
}
