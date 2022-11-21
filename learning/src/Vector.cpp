//
//  Vector.cpp
//  learning
//
//  Created by fatai on 2022/8/29.
//

#include "Vector.hpp"

void test_vector()
{
    vector<int> a;
    //向vector的末尾添加元素
    for(int i=1;i<10;i++)
            a.push_back(i);
    //输出首元素
    cout << a.front()<<endl;
    //输出尾元素
    cout << a.back()<<endl;
    //利用指针和begin函数和end函数进行遍历
    vector<int>::iterator it;
    for(it=a.begin();it!=a.end();it++)
            cout << *it << " ";
    cout <<endl;
    //使用size函数进行遍历
    int len=a.size();
    for(int i=0;i<len;i++)
            cout << a[i] << " ";
    cout <<endl;

    //删除队尾元素
    a.pop_back();
    cout << a.back()<<endl;

    //通过erase函数删除第二个元素
    it=a.begin()+1;

    a.erase(it);//删除的是2
    len=a.size();
    for(int i=0;i<len;i++)
            cout << a[i] << " ";
    cout <<endl;

    //通过erase函数删除前两个元素
    vector<int>::iterator it2;
    it=a.begin();
    it2=a.begin()+2;//删除的是1，3（注意这里不删除it2指向的那个位置）
    a.erase(it,it2);//就是说删除[it,it2)的部分
    len=a.size();
    for(int i=0;i<len;i++)
            cout << a[i] << " ";
    cout <<endl;

    //清空整个vector
    a.clear();

    //判断是否为空
    if(a.empty()) cout << "这个vector现在是空的了" <<endl;

    //向指针指向的元素的前面插一个元素进去
    for(int i=1;i<10;i++)
            a.push_back(i);
    it=a.begin();
    a.insert(it,-1);//这样的插入是可以返回插入元素的指针的，而其他的插入方式就不行
    len=a.size();
    for(int i=0;i<len;i++)
            cout << a[i] << " ";
    cout <<endl;

    //向指针指向的元素的前面插4个相同的元素进去
    it=a.begin()+1;
    a.insert(it,4,100);
    len=a.size();
    for(int i=0;i<len;i++)
            cout << a[i] << " ";
    cout <<endl;

    //使用sort函数
    sort(a.begin(),a.end());

    //完整交换两个不同的vector
    vector<int> a2;
    for(int i=1;i<10;i++)
            a2.push_back(i);
    a.swap(a2);
    len=a.size();
    for(int i=0;i<len;i++)
            cout << a[i] << " ";
    cout <<endl;
    len=a2.size();
    for(int i=0;i<len;i++)
            cout << a2[i] << " ";
    cout <<endl;
    
    
    vector<vector<int> >v1(3);//二维数组
    //v有3个元素，每个元素都是 vector<int> 容器
    for(int i = 0;i < v1.size(); ++i)
        for(int j = 0; j <4; ++j)
            v1[i].push_back(j);
    for(int i = 0;i < v1.size(); ++i)
        for(int j = 0; j < v1[i].size(); ++j)
            cout << v1[i][j] << " ";
    cout << endl;
}
