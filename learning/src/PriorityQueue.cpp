//
//  PriorityQueue.cpp
//  learning
//
//  Created by fatai on 2022/8/31.
//

#include "PriorityQueue.hpp"
void test_priority_queue()
{
    // 优先队列是默认大的数在前面，若是想定义小的数在前面只需要像下面这样定义即可：
//    priority_queue<int,vector<int>,greater<int>> a;

    priority_queue<int> a;
    //插入元素
    a.push(2);
    a.push(1);
    a.push(3);
    a.push(4);

    //访问队列首元素,注意这里不是像队列一样使用front和back来访问首元素和尾元素
    cout << a.top()<<endl;

    //删除首元素，但是他不返回值
    a.pop();
    cout << a.top
    ()<<endl;

    //判断队列是否为空
    if(!a.empty()) cout << "队列不为空" <<endl;
    //输出队列中的元素个数
    cout << a.size() << endl;
    /*
     4
     3
     队列不为空
     3
     */
}
