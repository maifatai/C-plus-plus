//
//  Set.cpp
//  learning
//
//  Created by fatai on 2022/8/31.
//

#include "Set.hpp"
void test_set()
{
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(5);
    //查找元素
    set<int>::iterator it;
    it=s.find(1);
    if(it==s.end()) puts("not found");
    else puts("found");    //输出found

    it=s.find(2);
    if(it==s.end()) puts("not found");
    else puts("found");    //输出not found

    //删除元素
    s.erase(3);

    //其他的查找元素的方法
    if(s.count(3)!=0) puts("found");
    else puts("not found");//输出 not found

    //遍历所有元素
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
    /*
     found
     not found
     not found
     1
     5
     */
}
