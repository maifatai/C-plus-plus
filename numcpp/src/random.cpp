//
//  random.cpp
//  numcpp
//
//  Created by fatai on 2022/3/20.
//

#include "random.hpp"
#include "NumCpp.hpp"
#include <iostream>
#include <cmath>
using namespace std;

void Random()
{
    nc::random::seed(1);
    auto r1=nc::random::rand<double>({3,4});
    cout<<"r1：";
    r1.print();cout<<endl;
    auto r2=nc::random::rand<double>(nc::Shape(3,4));
    cout<<"r2：";
    r2.print();cout<<endl;
    
    auto r3=nc::random::randN<double>(nc::Shape(3,4));
    cout<<"r3：";
    r3.print();cout<<endl;
    auto r4=nc::random::randN<double>({3,4});
    cout<<"r4：";
    r4.print();cout<<endl;
    
    auto r5=nc::random::randInt({3,4}, 0,10);
    cout<<"r5：";
    r5.print();cout<<endl;
    
    auto r6=nc::random::normal<double>(nc::Shape(4, 3),0,1);
    cout<<"r6：";
    r6.print();cout<<endl;
    
    //泊松分布
    auto r7=nc::random::poisson<int>(nc::Shape(4, 3),2);//数据类型为int
    cout<<"r7：";
    r7.print();cout<<endl;
    
    auto r8=nc::random::permutation(10);
    cout<<"r8：";
    r8.print();cout<<endl;
    auto r9=nc::random::permutation(r7);
    cout<<"r9：";
    r9.print();cout<<endl;
    
    nc::random::shuffle(r9);
    cout<<"r9：";
    r9.print();cout<<endl;
    
    auto r10=nc::random::choice(r9, 5);
    cout<<"r10：";
    r10.print();cout<<endl;
    
    
    auto r11=nc::unique(r9);
    cout<<"r11：";
    r11.print();cout<<endl;
    
    
    auto r12=nc::bincount(r9);
    cout<<"r12：";
    r12.print();cout<<endl;
    
    
    auto r13=nc::histogram(r9);
    cout<<"r13：first";
    r13.first.print();
    cout<<"r13：second";
    r13.second.print();
    
}
