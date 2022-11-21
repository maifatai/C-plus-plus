//
//  destructor.hpp
//  learning
//
//  Created by fatai on 2022/8/28.
//

#ifndef destructor_hpp
#define destructor_hpp

#include <iostream>
using namespace std;
/*
 构造函数在数组中的使用
 */
class Destructor {
private:
    int id;
    
public:
    Destructor();
    Destructor(int n);
    ~Destructor();
};

int test_destructor();
#endif /* destructor_hpp */
