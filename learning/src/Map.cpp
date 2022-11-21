//
//  Map.cpp
//  learning
//
//  Created by fatai on 2022/8/31.
//

#include "Map.hpp"
void test_map()
{
    map<int,const char *> m;

    //插入元素
    m.insert(make_pair(1,"ONE"));
    m.insert(make_pair(10,"TEN"));  //标准的写法
    m[100]="HUNDRED";               //另一种插入元素的写法

    //查找元素
    map<int,const char*>::iterator it;
    it=m.find(1);
    puts(it->second);   //输出ONE

    it=m.find(2);
    if(it==m.end()) puts("not found");
    else puts("found");      //输出not found

    puts(m[10]);             //其他的输出方式

    //删除元素
    m.erase(10);

    //遍历一遍所有的元素
    for(it = m.begin();it!=m.end();it++)
            printf("%d: %s",it->first,it->second);
    /*
     ONE
     not found
     TEN
     1: ONE100: HUNDRED0;
     */
}
