//
//  constructor.hpp
//  learning
//
//  Created by fatai on 2022/8/28.
//

#ifndef constructor_hpp
#define constructor_hpp

#include <iostream>
using namespace std;
/*
 构造函数在数组中的使用
 */
class Constructor {
private:
    int x,y;
    
public:
    Constructor();
    Constructor(int n,int m=0);
};

int test_constructor();

#endif /* constructor_hpp */
