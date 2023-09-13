//
//  condition.cpp
//  numcpp
//
//  Created by fatai on 2022/3/20.
//

#include "condition.hpp"
#include "NumCpp.hpp"
#include <iostream>
#include<vector>

using namespace std;
using namespace nc;
void Condition()
{
    auto a=nc::arange(20).reshape(4, -1);
    auto a1=nc::where(a<10, 10-a, a);
    cout<<"a1："<<endl;
    a1.print();cout<<endl;
    auto a1_1=nc::argwhere(a<10);
    cout<<"a1_1："<<endl;
    a1_1.print();cout<<endl;
    
//    没有using namespace nc;时
//    vector<nc::NdArray<bool>>condlist={a<4,a>7};
//    vector<nc::NdArray<int>>choicelist={a+10,a+20};
    vector<NdArray<bool>>condlist={a<4,a<=7&&a>=4,a>7};
    vector<NdArray<int>>choicelist={a+10,a+20,a+40};
    auto a2=nc::select(condlist, choicelist);
    cout<<"a2："<<endl;
    a2.print();cout<<endl;
    
}
