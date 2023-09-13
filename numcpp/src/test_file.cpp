//
//  test_file.cpp
//  numcpp
//
//  Created by fatai on 2022/3/18.
//

#include "test_file.hpp"
#include "NumCpp.hpp"
#include <iostream>
#include <typeinfo>
#include<fstream>
using namespace std;

int test()
{
    // insert code here...
//    auto a=nc::random::randInt<int>({10,10},0,100);
    nc::NdArray<int>a={{1,2},{3,4},{5,6}};
//    for(auto it=a.begin();it<a.end();++it)
//        cout<<*it<<";";
    cout<<endl;
    cout<<"size:"<<sizeof(a)/sizeof(int)<<endl;
    ofstream out("numcppdata.txt",ios::out|ios::binary);
    for(auto it=a.begin();it<a.end();++it)
    {
        out<<*it;
        cout<<*it<<" ";
    }
    out.close();
    cout<<endl;
    ifstream in("numcppdata.txt",ios::in);
    if(!in)
    {
        cout<<"open file fail"<<endl;
        return -1;
    }
    int data[3][2];
//    in.read((char*)&data, sizeof(data));
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<2;++j)
        {
            in>>data[i][j];
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<in.gcount()<<" bytes have been read"<<endl;
    in.close();

    return 0;
}


void check_type()
{
    int a[2][2][2]={{{1,2},{3,4}},{{4,5},{6,7}}};
    int *p;
    double d;
    int b=10;
    char c;
    /*
     typeid().name()可以返回变量、函数、类的数据类型名
     输出格式：[指针][名称空间][类别][模板]
     [指针]：若是指针则输出P。
     [名称空间]：若是std则输出St，若是自定义的名称空间则输出字符数及它的名字，并在开头加N，在结尾加E。
     */
    cout<<"a type:"<<typeid(a).name()<<endl;//a type:A2_A2_A2_i
    cout<<"p type:"<<typeid(p).name()<<endl;//p type:Pi
    cout<<"*p type:"<<typeid(*p).name()<<endl;//*p type:i
    cout<<"d type:"<<typeid(d).name()<<endl;//d type:d
    cout<<"c type:"<<typeid(c).name()<<endl;//c type:c
    cout<<"b type:"<<typeid(b).name()<<endl;//b type:i
    cout<<"typeid().name:"<<typeid(typeid(c).name()).name()<<endl;//typeid().name()返回了存储类型名的字符串
    
}
