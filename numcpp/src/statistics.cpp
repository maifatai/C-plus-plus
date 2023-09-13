//
//  statistics.cpp
//  numcpp
//
//  Created by fatai on 2022/3/21.
//

#include "statistics.hpp"
#include "NumCpp.hpp"
#include <iostream>

using namespace std;
using namespace nc;

void Statistics()
{
    auto a=nc::arange(20).reshape(4,-1);
    auto a1=nc::sum(a);
    cout<<"a1："<<endl;
    a1.print();cout<<endl;
    auto a2=nc::sum(a,nc::Axis::ROW);
    cout<<"a2："<<endl;
    a2.print();cout<<endl;
    auto a3=nc::sum(a,nc::Axis::COL);
    cout<<"a3："<<endl;
    a3.print();cout<<endl;
    
    auto a4=nc::cumsum(a,nc::Axis::ROW);//每一列的累积和
    cout<<"a4："<<endl;
    a4.print();cout<<endl;
    auto a5=nc::cumprod(a,nc::Axis::COL);//每一行的累积积
    cout<<"a5："<<endl;
    a5.print();cout<<endl;
    
    auto a6=nc::mean(a,nc::Axis::COL);
    cout<<"a6："<<endl;
    a6.print();cout<<endl;
    
    auto a6_1=nc::stdev(a,nc::Axis::COL);
    cout<<"a6_1："<<endl;
    a6_1.print();cout<<endl;
    
    auto a6_2=nc::var(a,nc::Axis::COL);
    cout<<"a6_2："<<endl;
    a6_2.print();cout<<endl;
    
    auto a0=nc::random::randInt({4,5}, 0,50);
    auto a7=nc::sort(a0);
    cout<<"a7："<<endl;
    a7.print();cout<<endl;
    auto a8=nc::sort(a0);
    cout<<"a8："<<endl;
    a8.print();cout<<endl;
    auto a8_1=nc::sort(a0,nc::Axis::ROW);//每一列排序
    cout<<"a8_1："<<endl;
    a8_1.print();cout<<endl;
    
    auto a9=nc::argsort(a0);
    cout<<"a9："<<endl;
    a9.print();cout<<endl;

    auto a9_1=nc::argsort(a0,nc::Axis::COL);
    cout<<"a9_1："<<endl;
    a9_1.print();cout<<endl;
    auto a9_2=nc::argsort(a0,nc::Axis::ROW);
    cout<<"a9_2："<<endl;
    a9_2.print();cout<<endl;
    
    
    auto a10=nc::min(a0);
    cout<<"a10："<<endl;
    a10.print();cout<<endl;
    auto a10_1=nc::min(a0,nc::Axis::COL);
    cout<<"a10_1："<<endl;
    a10_1.print();cout<<endl;
    
    auto a11=nc::max(a0);
    cout<<"a11："<<endl;
    a11.print();cout<<endl;
    auto a11_1=nc::max(a0,nc::Axis::COL);
    cout<<"a11_1："<<endl;
    a11_1.print();cout<<endl;
    
    auto a12=nc::argmax(a0);
    cout<<"a12："<<endl;
    a12.print();cout<<endl;
    auto a12_1=nc::argmax(a0,nc::Axis::COL);
    cout<<"a12_1："<<endl;
    a12_1.print();cout<<endl;
    
    auto a13=nc::argmin(a0);
    cout<<"a13："<<endl;
    a13.print();cout<<endl;
    auto a13_1=nc::argmin(a0,nc::Axis::COL);
    cout<<"a13_1："<<endl;
    a13_1.print();cout<<endl;
    
//    nc::NdArray<int>a={{1,2},{3,4},{5,6}};
    auto a14=nc::nans(2,3);
    a14(0,1)=3;a14(0,2)=2;
    a14(1,0)=4;a14(1,1)=7;
    cout<<"a14："<<endl;
    a14.print();cout<<endl;
    auto a14_1=nc::nanmax(a14);
    auto a14_2=nc::nanmin(a14);
    auto a14_3=nc::nansum(a14);
    auto a14_4=nc::nanprod(a14);
    auto a14_5=nc::nancumsum(a14);
    auto a14_6=nc::nanmedian(a14);
    auto a14_7=nc::nancumprod(a14);
    auto a14_8=nc::nanmean(a14);
    auto a14_9=nc::nanargmax(a14);
    auto a14_10=nc::nanargmin(a14);
    auto a14_11=nc::count_nonzero(a14);
    cout<<"a14_1："<<endl;
    a14_1.print();cout<<endl;
    cout<<"a14_2："<<endl;
    a14_2.print();cout<<endl;
    cout<<"a14_3："<<endl;
    a14_3.print();cout<<endl;
    cout<<"a14_4："<<endl;
    a14_4.print();cout<<endl;
    cout<<"a14_5："<<endl;
    a14_5.print();cout<<endl;
    cout<<"a14_6："<<endl;
    a14_6.print();cout<<endl;
    cout<<"a14_7："<<endl;
    a14_7.print();cout<<endl;
    cout<<"a14_8："<<endl;
    a14_8.print();cout<<endl;
    cout<<"a14_9："<<endl;
    a14_9.print();cout<<endl;
    cout<<"a14_10："<<endl;
    a14_10.print();cout<<endl;
    cout<<"a14_11："<<endl;
    a14_11.print();cout<<endl;
    
    auto a15_1=nc::nanmax(a14,nc::Axis::COL);
    auto a15_2=nc::nanmin(a14,nc::Axis::COL);
    auto a15_3=nc::nansum(a14,nc::Axis::COL);
    auto a15_4=nc::nanprod(a14,nc::Axis::COL);
    auto a15_5=nc::nancumsum(a14,nc::Axis::COL);
    auto a15_6=nc::nanmedian(a14,nc::Axis::COL);
    auto a15_7=nc::nancumprod(a14,nc::Axis::COL);
    auto a15_8=nc::nanmean(a14,nc::Axis::COL);
    auto a15_9=nc::nanargmax(a14,nc::Axis::COL);
    auto a15_10=nc::nanargmin(a14,nc::Axis::COL);
    auto a15_11=nc::count_nonzero(a14,nc::Axis::COL);
    cout<<"a15_1："<<endl;
    a15_1.print();cout<<endl;
    cout<<"a15_2："<<endl;
    a15_2.print();cout<<endl;
    cout<<"a15_3："<<endl;
    a15_3.print();cout<<endl;
    cout<<"a15_4："<<endl;
    a15_4.print();cout<<endl;
    cout<<"a15_5："<<endl;
    a15_5.print();cout<<endl;
    cout<<"a15_6："<<endl;
    a15_6.print();cout<<endl;
    cout<<"a15_7："<<endl;
    a15_7.print();cout<<endl;
    cout<<"a15_8："<<endl;
    a15_8.print();cout<<endl;
    cout<<"a15_9："<<endl;
    a15_9.print();cout<<endl;
    cout<<"a15_10："<<endl;
    a15_10.print();cout<<endl;
    cout<<"a15_11："<<endl;
    a15_11.print();cout<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
