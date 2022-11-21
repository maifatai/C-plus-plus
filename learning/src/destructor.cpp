//
//  destructor.cpp
//  learning
//
//  Created by fatai on 2022/8/28.
//

#include "destructor.hpp"
Destructor::Destructor()
{
    cout<<"constructor 1 called"<<endl;
}

Destructor::Destructor(int n)
{
    id=n;
//    cout<<x<<";"<<y<<endl;
    cout<<id<<";"<<"constructor 2 called"<<endl;
}
Destructor::~Destructor()
{
    cout<<id<<";"<<"destructor  called"<<endl;
}
Destructor d(0);
int test_destructor()
{

    /*
     0;constructor 2 called
     */
    {
        //临时变量和静态变量
        Destructor d2(1);
        static Destructor d3(6);
        /*
         1;constructor 2 called
         6;constructor 2 called
         1;destructor  called
         */
    }
    cout<<"step 1"<<endl;
    Destructor arr2[2]={2,3};
    /*
     step 1
     2;constructor 2 called
     3;constructor 2 called
     */
    cout<<"step 2"<<endl;
    Destructor *arr4=new Destructor[2];
    delete []arr4;
    /*
     step 2
     constructor 1 called
     constructor 1 called
     1073741824;destructor  called
     269628144;destructor  called
     */

    cout<<"step 3"<<endl;
    Destructor arr5[3]={4,Destructor(5)};
    /*
     step 3
     4;constructor 2 called
     5;constructor 2 called
     constructor 1 called
     */

    cout<<"step 4"<<endl;
    Destructor *arr6[3]={new Destructor(10),new Destructor(11)};
    delete arr6[0];
    delete arr6[1];
    /* 注意仅有2个对象生成，第三个为NULL
     step 4 注意new出来的，如果不delete，则不会调用析构函数
     10;constructor 2 called
     11;constructor 2 called
     10;destructor  called
     11;destructor  called
     */
    cout<<"step 5"<<endl;
    Destructor *arr7[4]={new Destructor(12),NULL,new Destructor(13)};
    /* 注意仅有2个对象生成，第2个和第4个为NULL

     step 5
     12;constructor 2 called
     13;constructor 2 called
     */
    cout<<"end main"<<endl;
    /*
     end main
     639904;destructor  called
     5;destructor  called
     4;destructor  called
     3;destructor  called
     2;destructor  called
     6;destructor  called
     0;destructor  called
     */
    
    return 0;
}
