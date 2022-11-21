//
//  InheritDerive.hpp
//  learning
//
//  Created by fatai on 2022/9/14.
//

#ifndef InheritDerive_hpp
#define InheritDerive_hpp

#include <iostream>
using namespace std;

class base {
    int j;
public:
    int i;
    void func();
};

class derived :public base{
public:
    int i;
    void access();
    void func();
};

//派生类的构造函数
class Bug{
private :
    int nLegs; int nColor;
public:
    int nType;
    Bug(int legs, int color):nLegs(legs),nColor(color){}
    void PrintBug (){ };
};
class Skill {
public:
    Skill(int n) { }
};
class FlyBug:public Bug{
    int nWings;
    Skill sk1, sk2;
public:
    FlyBug(int legs,int color,int wings):Bug(legs,color),sk1(5),sk2(color) ,nWings(wings){}
    //必须以上述方式进行构造函数，因为 legs和color在Bug类中为私有成员，一般在派生类中是无法访问基类的私有成员
};
//FlyBug::FlyBug(int legs, int color, int wings):Bug(legs,color),sk1(5),sk2(color) ,nWings(wings){}



//基类与派生类的指针强制转换
class Base1{
protected:
    int n;
public:
    Base1(int i):n(i){cout << "Base " << n <<" constructed" << endl;}
    ~Base1() {cout << "Base " << n <<" destructed" << endl;}
    void Print() { cout << "Base:n=" << n << endl;}
};
class Derived1:public Base1 {
public:
    int v;
    Derived1(int i):Base1(i),v(2*i) {cout << "Derived constructed:" <<v<<endl;}
    ~Derived1(){cout << "Derived destructed:" <<v<< endl;}
    void Func() { } ;
    void Print() {
    cout << "Derived:v=" << v << endl;
    cout << "Derived:n=" << n << endl;
    }
};


void test_inherit_derived();
#endif /* InheritDerive_hpp */
