#include "NumCpp.hpp"
#include <iostream>
using namespace std;
int main()
{
    nc::NdArray<int>a={{1,2},{3,4},{5,6}};
//    nc::NdArray<nc::complex(int)>a1={1,2,3,4};
//    a1.print();
    nc::NdArray<float>a2={{1,2,3,4},{5,6,7,8}};
    a2.reshape(-1,2);
    a2.print();
    //数组的属性
    cout<<"a2 size:"<<a2.size()<<endl;
    cout<<"a2 shape:"<<a2.shape()<<endl;
    cout<<"a2 row 0:"<<a2.row(0)<<endl;
    cout<<"a2 col 0:"<<a2.column(0)<<endl;
}
//编译方式,至少是c++14标准
// C++ Standards:
// C++14 C++17 C++20
//g++ -std=c++14 TestNumcpp.cpp -o test 