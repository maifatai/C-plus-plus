//
//  virtualdestructor.hpp
//  learning
//
//  Created by fatai on 2022/8/29.
//

#ifndef virtualdestructor_hpp
#define virtualdestructor_hpp

#include <iostream>
using namespace std;
class Base{
public:
    ~Base();
    Base();
};

class Derived:public Base{
public:
    Derived();
    ~Derived();
};

class BaseVirtual{
public:
    BaseVirtual();
    virtual ~BaseVirtual();
};

class DerivedVirtual:public BaseVirtual{
public:
    DerivedVirtual();
    ~DerivedVirtual();
};
void test_virtual_destructor();
#endif /* virtualdestructor_hpp */
