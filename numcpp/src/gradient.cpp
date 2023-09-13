//
//  gradient.cpp
//  numcpp
//
//  Created by fatai on 2022/3/21.
//

#include "gradient.hpp"
#include "NumCpp.hpp"
#include <iostream>

using namespace std;
using namespace nc;
void Gradient()
{
    auto a=nc::random::randInt({5,5}, 0,50);
    cout<<"a："<<endl;
    a.print();cout<<endl;
    auto a1=nc::gradient(a);
    cout<<"a1："<<endl;
    a1.print();cout<<endl;
    auto a2=nc::gradient(a,nc::Axis::COL);
    cout<<"a2："<<endl;
    a2.print();cout<<endl;
}
