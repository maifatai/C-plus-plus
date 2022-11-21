//
//  Stack.cpp
//  learning
//
//  Created by fatai on 2022/8/31.
//

#include "Stack.hpp"

void test_stack()
{
    
    stack<int> a;// 定义stack 对象
    //入栈操作
    a.push(1);
    a.push(2);
    a.push(3);

    //取栈顶元素输出
    cout << a.top() << endl;
    //删除栈顶元素
    a.pop();
    //再次取栈顶元素
    cout << a.top() << endl;
    //判断栈是否为空
    if(!a.empty())
        cout << "栈不为空" << endl;
    /*
     3
     2
     栈不为空
     */
}
