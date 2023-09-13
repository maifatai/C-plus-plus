//
//  broadcast.cpp
//  numcpp
//
//  Created by fatai on 2022/3/17.
//

#include "broadcast.hpp"
#include "NumCpp.hpp"
#include <iostream>
using namespace std;

void Broadcast()
{
    auto a1=nc::arange(0,60,10);
    a1.reshape(-1, 1);
    auto a2=nc::arange(5);
    a2.reshape(1,-1);
    auto a3=nc::add(a1,6);
    a3.print();
    
    auto b1=nc::arange(0,20).reshape(5,-1).astype<int>();
    cout<<"b1:";
    b1.print();cout<<endl;
    auto b1_1=b1[b1>10];//a[a > 5]
    cout<<"b1_1:";
    b1_1.print();cout<<endl;
    auto b1_2=b1.putMask(b1>5, 5);//a[a > 5] = 5
    cout<<"b1_2:";
    b1_2.print();cout<<endl;
    
    
}

