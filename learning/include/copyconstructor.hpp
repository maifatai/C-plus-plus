//
//  copyconstructor.hpp
//  learning
//
//  Created by fatai on 2022/8/28.
//

#ifndef copyconstructor_hpp
#define copyconstructor_hpp

#include <iostream>

using namespace std;

class CopyConstructor {
    double real,imag;
public:
    CopyConstructor();
    CopyConstructor(double x,double y);
    CopyConstructor(const CopyConstructor &c);
};
int test_copyconstructor();
void test_copyconstructor_func(CopyConstructor c);
CopyConstructor test_copyconstructor_return();
#endif /* copyconstructor_hpp */
