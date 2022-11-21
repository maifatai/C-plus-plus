//
//  ClassTemplate.cpp
//  learning
//
//  Created by fatai on 2022/8/31.
//

#include "ClassTemplate.hpp"

//注意模板类成员函数的定义方式
template<class T1,class T2>
bool Pair<T1,T2>::operator < ( const Pair<T1,T2> & p) const //Pair的成员函数 operator <
{
    return key <p.key ;
}

void test_class_template()
{
    Pair<string,int > student("Tom",19);//实例化出一个类 Pair< string,int
    cout<< student.key << " " << student.value ;cout<<endl;
    
    //类模板从类模板派生
    B<int,double> obj1;
    C<int> obj2;
    cout<<"sizeof(B<int,double>):"<<sizeof(B<int,double>)<<endl;
    cout<<"sizeof(C<int>):"<<sizeof(C<int>)<<endl;
    /*
     sizeof(B<int,double>):24   sizeof(int)*2+sizeof(double)*2 [v1,v2,v3,v4]
     sizeof(C<int>):20   sizeof(int)*5  [v1,v2,v3,v4,v5]
     */
    
    //类模板从模板类派生
    B1<int> obj;//自动生成两个模板类 A1<int,double> 和 B1<int>
    cout<<"sizeof(B1<int>):"<<sizeof(B1<int>)<<endl;
    /*
     sizeof(B1<int>):24   变量对齐 v1,v2,v3都是double类型
     */
    
    //类模板从普通类派生
    B2<double>obj3;
    cout<<"sizeof(B2<double>):"<<sizeof(B2<double>)<<endl;
    /*
     sizeof(B2<double>):16
     */
    
    //普通类从模板类派生
    B3 obj4;
    cout<<"sizeof(B3):"<<sizeof(B3)<<endl;
    /*
     sizeof(B3):16
     */
}
