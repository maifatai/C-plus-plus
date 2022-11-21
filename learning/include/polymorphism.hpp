//
//  polymorphism.hpp
//  learning
//
//  Created by fatai on 2022/8/29.
//

#ifndef polymorphism_hpp
#define polymorphism_hpp
#include<iostream>
using namespace std;
class Poly_A
{
    int A;
public:
    virtual void print_info();
};
class Poly_B:public Poly_A
{
    int B;
public:
    virtual void print_info();
};
class Poly_C:public Poly_A
{
    int C;
public:
    virtual void print_info();
};
class Poly_D:public Poly_B
{
    int D;
public:
    virtual void print_info();
};

void test_polymorphism();



#endif /* polymorphism_hpp */
