//
//  array_base.cpp
//  numcpp
//
//  Created by fatai on 2022/1/25.
//

#include "array_base.hpp"
#include "NumCpp.hpp"
#include <iostream>
#include <typeinfo>
using namespace std;

/*
 """
 1.数组的创建
 2.数组的增删
 3.数组的变形
 4.数组拼接
 5.数组切分
 
 The main data structure in NumCpp is the NdArray. It is inherently a 2D array class, with 1D arrays being implemented as 1xN arrays.
 """
 */
//创建数组
void ArrayBase()
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
//    cout<<"a2 type:"<<a2.dtype<<endl;
    a2[0]=100;
    a2.print();
    
    //初始化
    auto a3=nc::arange(10,20,2);
    cout<<"a3 shape:"<<a3.shape()<<endl;
    auto a4=nc::linspace(1,10, 5);
    cout<<"a4:";
    a4.print();cout<<endl;
    auto a5=nc::linspace<float>(1,10,11);
    cout<<"a5:";
    a5.print();cout<<endl;
    auto a6=nc::logspace(1,2,10);
    cout<<"a6:";
    a6.print();cout<<endl;
    auto a7=nc::eye<nc::int16>(4);//单位阵
    cout<<"a7:";
    a7.print();cout<<endl;
    auto a7_1=nc::identity<int>(4);
    cout<<"a7_1:";
    a7_1.print();cout<<endl;
    auto a8=nc::zeros<nc::int16>(2,3);
    cout<<"a8:";
    a8.print();cout<<endl;
    auto a8_1=nc::NdArray<int>(2,3)=0;
    cout<<"a8_1:";
    a8_1.print();cout<<endl;
    auto a8_2=nc::zeros_like<int>(a8);
    cout<<"a8_2:";
    a8_2.print();cout<<endl;
    auto a9=nc::ones<nc::int16>(2,3);
    cout<<"a9:";
    a9.print();cout<<endl;
    auto a9_1=nc::NdArray<int>(2,3)=1;
    cout<<"a9_1:";
    a9_1.print();cout<<endl;
    auto a9_2=nc::ones_like<int>(a9);
    cout<<"a9_2:";
    a9_2.print();cout<<endl;
    
    
    auto a10=nc::nans(3,4);
    cout<<"a10:";
    a10.print();cout<<endl;
    auto a10_1=nc::NdArray<double>(3,4)=nc::constants::nan;
    cout<<"a10_1:";
    a10_1.print();cout<<endl;
    
    auto a11=nc::empty<int>(3, 4);
    cout<<"a11:";
    a11.print();cout<<endl;
    auto a11_1=nc::NdArray<int>(3,4);
    cout<<"a11_1:";
    a11_1.print();cout<<endl;
    auto a11_2=nc::empty_like(a11);
    cout<<"a11_2:";
    a11_2.print();cout<<endl;
    
    auto a12=nc::diag(a7);
    cout<<"a12:";
    a12.print();cout<<endl;
    
    auto a13=nc::full(2, 3, 5);
    cout<<"a13:";
    a13.print();cout<<endl;
    
    //切片
    auto a14=nc::arange(1, 101);
    a14.reshape(-1,10);
    cout<<"a14 type:"<<typeid(a14).name()<<endl;
    cout<<"a14:";
    a14.print();cout<<endl;
    auto a14_1=a14(2,3);//第二行，第三列
    cout<<typeid(a14_1).name()<<endl;
    cout<<"a14_1:"<<a14_1<<endl;
    auto a14_2=a14(nc::Slice(0, 8, 2),nc::Slice(1,9,2));//a[0:8:2,1:9:2]
    cout<<"a14_2:";
    a14_2.print();cout<<endl;
    auto a14_3=a14({0, 8, 2},{1,9,2});//a[0:8:2,1:9:2]
    cout<<"a14_3:";
    a14_3.print();cout<<endl;
    auto a14_4=a14(a14.rSlice(),7);//第七列 a[:,7]
    cout<<"a14_4:";
    a14_4.print();cout<<endl;
    auto a14_5=a14(7,a14.rSlice());//第七行 a[7,:]
//    a14_5.reshape(-1);
//    cout<<"a14_5 shape:"<<a14_5.shape()<<endl;
    cout<<"a14_5:";
    a14_5.print();cout<<endl;
    
    auto a14_6=a14[a14>50];
    cout<<"a14_6";
    a14_6.print();cout<<endl;
    
    auto a14_7=a14.putMask(a14>50, 0);
    cout<<"a14_7:";
    a14_7.print();cout<<endl;
    cout<<"a14:";
    a14.print();cout<<endl;
    
    nc::NdArray<int>a15={1,2,3,4,5,6};
    cout<<"a15 shape:"<<a15.shape()<<endl;//a15 shape:[1, 6]
    cout<<"a15:";
    a15.print();cout<<endl;//a15:[[1, 2, 3, 4, 5, 6, ]]
    
    //数组增删,拼接
    auto b1=nc::arange(12);
    b1.reshape(-1,3);
    nc::NdArray<int>b2={12,13,14};
    auto b2_1=nc::arange(12, 16);
    b2_1.reshape(4,-1);
    auto b3=nc::append(b1, b2);//拼成一行
    cout<<"b3:";
    b3.print();cout<<endl;
    auto b3_1=nc::append(b1, b2,nc::Axis::ROW);//按行拼接
    cout<<"b3_1 shape:"<<b3_1.shape() <<"b3_1:";//b3_1 shape:[5, 3]
    b3_1.print();cout<<endl;
    auto b3_2=nc::append(b1, b2_1,nc::Axis::COL);//按列拼接
    cout<<"b3_2 shape:"<<b3_2.shape() <<"b3_2:";//b3_2 shape:[4, 4]
    b3_2.print();cout<<endl;
    
    auto b3_3=nc::deleteIndices(b3_1, 1,nc::Axis::ROW);//删除第一行
    cout<<"b3_3：";
    b3_3.print();cout<<endl;
    auto b3_4=nc::deleteIndices(b3_2, 1,nc::Axis::COL);//删除第一列
    cout<<"b3_4：";
    b3_4.print();cout<<endl;
    
    auto b3_5=nc::concatenate({b1,b2},nc::Axis::ROW);
    cout<<"b3_5 shape:"<<b3_5.shape() <<"b3_5:";//b3_5 shape:[5, 3]
    b3_5.print();cout<<endl;
    auto b3_6=nc::concatenate({b1,b2_1},nc::Axis::COL);
    cout<<"b3_6 shape:"<<b3_6.shape() <<"b3_6:";//b3_6 shape:[4, 4]
    b3_6.print();cout<<endl;
    
    
    auto b3_7=nc::concatenate({b1,b2});//拼接成1*N数组
    cout<<"b3_7 shape:"<<b3_7.shape() <<"b3_7:";//b3_7 shape:[1, 15]
    b3_7.print();cout<<endl;//b3_7:[[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, ]]
    auto b3_8=nc::concatenate({b1,b2_1});
    cout<<"b3_8 shape:"<<b3_8.shape() <<"b3_8:";//b3_8 shape:[1, 16]
    b3_8.print();cout<<endl;//b3_8[[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, ]]
    
    
    auto b3_9=nc::column_stack({b1,b2_1});
    cout<<"b3_9 shape:"<<b3_9.shape() <<"b3_9:";
    b3_9.print();cout<<endl;
    auto b3_10=nc::hstack({b1,b2_1,b3_9});
    cout<<"b3_10 shape:"<<b3_10.shape() <<"b3_10:";
    b3_10.print();cout<<endl;
    
    auto b3_11=nc::row_stack({b1,b2});
    cout<<"b3_11 shape:"<<b3_11.shape() <<"b3_11:";
    b3_11.print();cout<<endl;
    auto b3_12=nc::vstack({b1,b2});
    cout<<"b3_12 shape:"<<b3_12.shape() <<"b3_12:";
    b3_12.print();cout<<endl;
    
    auto b3_13=nc::stack({b1,b2},nc::Axis::ROW);
    cout<<"b3_13 shape:"<<b3_13.shape() <<"b3_13:";
    b3_13.print();cout<<endl;
    auto b3_14=nc::stack({b1,b2_1},nc::Axis::COL);
    cout<<"b3_14 shape:"<<b3_14.shape() <<"b3_14:";
    b3_14.print();cout<<endl;
    
    
    //数组变形:转置、展平、尺寸调整、复制
    auto c1=nc::arange(12);
    c1.astype<nc::uint32>();
    c1.reshape(-1,3);
    cout<<"c1:";
    c1.print();cout<<endl;
    auto c1_1=nc::copy(c1);//deep copy
    c1_1.astype<nc::uint32>();
    c1_1.resizeFast(4, 2);//#比原尺寸小，自动截断
    cout<<"c1_1 shape:"<<c1_1.shape() <<"c1_1:";
    c1_1.print();cout<<endl;

    auto c1_2=nc::copy(c1);//deep copy
    c1_2.astype<nc::uint32>();
    c1_2.resizeFast(4, 4);//#比原尺寸大，填充0
    cout<<"c1_2 shape:"<<c1_2.shape() <<"c1_2:";
    c1_2.print();cout<<endl;

    auto c1_3=nc::copy(c1);
    c1_3.astype<nc::uint32>();
    c1_3.resizeSlow(4, 2);
    cout<<"c1_3 shape:"<<c1_3.shape() <<"c1_3:";
    c1_3.print();cout<<endl;

    auto c1_4=nc::copy(c1);
    c1_4.astype<nc::uint32>();
    c1_4.resizeSlow(4, 4);
    cout<<"c1_4 shape:"<<c1_4.shape() <<"c1_4:";
    c1_4.print();cout<<endl;

    auto c2=nc::copy(c1);
    c2=nc::flatten(c2);
    cout<<"c2 shape:"<<c2.shape() <<"c2:";
    c2.print();cout<<endl;

    auto c2_1=nc::copy(c1);
    c2_1=nc::ravel(c2_1);
    cout<<"c2_1 shape:"<<c2_1.shape() <<"c2_1:";
    c2_1.print();cout<<endl;

    auto c2_2=nc::copy(c1);
    c2_2=c2_2.flatten();
    cout<<"c2_2 shape:"<<c2_2.shape() <<"c2_2:";
    c2_2.print();cout<<endl;

    auto c3=nc::transpose(c1);
    cout<<"c3 shape:"<<c3.shape() <<"c3:";
    c3.print();cout<<endl;
    auto c3_1=c1.transpose();
    cout<<"c3_1 shape:"<<c3_1.shape() <<"c3_1:";
    c3_1.print();cout<<endl;

    auto c4=nc::tile(c1, 2, 3);
    cout<<"c4 shape:"<<c4.shape() <<"c4:";
    c4.print();cout<<endl;
    auto shape=nc::Shape(2, 3);
    auto c4_1=nc::tile(c1,shape);
    cout<<"c4_1 shape:"<<c4_1.shape() <<"c4_1:";
    c4_1.print();cout<<endl;
    auto c4_2=nc::repeat(c1, 2, 3);
    cout<<"c4_2 shape:"<<c4_2.shape() <<"c4_2:";
    c4_2.print();cout<<endl;
    auto c4_3=nc::repeat(c1, shape);
    cout<<"c4_3 shape:"<<c4_3.shape() <<"c4_3:";
    c4_3.print();cout<<endl;
    
    
    //数组切分,可以使用数组索引实现
    auto d1=nc::arange(80).reshape(-1, 10);
    //unique
    nc::NdArray<int>e1={{1,2,4,3,2,1,4}};
    auto e1_1=nc::unique(e1);
    cout<<"e1_1 shape:"<<e1_1.shape() <<"e1_1:";
    e1_1.print();cout<<endl;
    
    
    //网格
//    auto x1,y1;
//    x1,y1=nc::meshgrid(nc::arange(10), nc::arange(10,18));
//    x1.print();
//    y1.print();
    
    
    //复数
    auto f=nc::complex(nc::arange(1,10), nc::arange(1, 10));
    f.print();
    auto f1=nc::complex(nc::arange(1,10));
    f1.print();
    
    
    
    
    
    
    
    
    
    
    


    
}

