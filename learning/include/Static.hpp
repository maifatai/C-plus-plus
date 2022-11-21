//
//  Static.hpp
//  learning
//
//  Created by fatai on 2022/8/28.
//

#ifndef Static_hpp
#define Static_hpp

#include <iostream>
using namespace std;
class Static
{
private:
    int w,h;
    static int num,totalarea;
public:
    Static(int w_,int h_);
    ~Static();
    static void print_info();
    Static(Static &r);//防止临时对象对静态变量的改变（对象作为函数的参数，或者函数的返回值）
};
void test_static();

#endif /* Static_hpp */
