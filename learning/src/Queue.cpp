//
//  Queue.cpp
//  learning
//
//  Created by fatai on 2022/8/31.
//

#include "Queue.hpp"
void test_queue(){
    // 定义queue对象
//    quque q1; //容器类型是可选的，比如int等，默认为deque 类型
    queue<int> a;
    //插入元素
    a.push(2);
    a.push(1);
    a.push(3);
    a.push(4);

    //访问队列首元素,注意这里top是用不成的
    cout << a.front()<<endl;
    //访问队列尾元素
    cout << a.back()<<endl;
    //删除首元素，但是他不返回值
    a.pop();
    cout << a.front()<<endl;
    //判断队列是否为空
    if(!a.empty()) cout << "队列不为空" <<endl;
    //输出队列中的元素个数
    cout << a.size() << endl;
    /*
     2
     4
     1
     队列不为空
     3
     */
}
