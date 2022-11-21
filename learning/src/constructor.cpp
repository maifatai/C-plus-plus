//
//  constructor.cpp
//  learning
//
//  Created by fatai on 2022/8/28.
//

#include "constructor.hpp"
Constructor::Constructor()
{
    cout<<"constructor 1 called"<<endl;
}

Constructor::Constructor(int n,int m)
{
    x=n;
    y=m;
//    cout<<x<<";"<<y<<endl;
    cout<<"constructor 2 called"<<endl;
}
int test_constructor()
{
    cout<<"step 1"<<endl;
    Constructor arr1[2];
    /*
     step 1
     constructor 1 called
     constructor 1 called
     */
    cout<<"step 2"<<endl;
    Constructor arr2[2]={{2,3},{3,4}};
    /*
     step 2
     constructor 2 called
     constructor 2 called
     */
    cout<<"step 3"<<endl;
    Constructor arr3[2]={{4,5}};
    /*
     step 3
     constructor 2 called
     constructor 1 called
     */
    cout<<"step 4"<<endl;
    Constructor *arr4=new Constructor[2];
    delete []arr4;
    /*
     step 4
     constructor 1 called
     constructor 1 called
     */
    cout<<"step 5"<<endl;
    Constructor arr5[3]={{4,5},Constructor(6,7)};
    /*
     step 5
     constructor 2 called
     constructor 2 called
     constructor 1 called
     */
    cout<<"step 6"<<endl;
    Constructor *arr6[3]={new Constructor(10,11),new Constructor(23,34)};
    /* 注意仅有2个对象生成，第三个为NULL
     step 6
     constructor 2 called
     constructor 2 called
     */
    cout<<"step 7"<<endl;
    Constructor *arr7[4]={new Constructor(10,11),NULL,new Constructor(23,34)};
    /* 注意仅有2个对象生成，第2个和第4个为NULL
     step 7
     constructor 2 called
     constructor 2 called
     */
    
    return 0;
}
