//
//  file.cpp
//  numcpp
//
//  Created by fatai on 2022/3/21.
//

#include "file.hpp"
#include "NumCpp.hpp"
#include <iostream>
using namespace std;

void File()
{
    auto a=nc::arange(0,100).reshape(10,-1).astype<int>();
    a.tofile("/Volumes/software/programming/c++/numcpp/numcpp/build/a.bin");
    a.tofile("/Volumes/software/programming/c++/numcpp/numcpp/build/a.txt");
    nc::dump(a, "/Volumes/software/programming/c++/numcpp/numcpp/build/a1.txt");
    auto a1=nc::fromfile<int>("/Volumes/software/programming/c++/numcpp/numcpp/build/a.bin").reshape(a.shape());
    cout<<"a1："<<endl;
    a1.print();cout<<endl;
    auto a2=nc::fromfile<int>("/Volumes/software/programming/c++/numcpp/numcpp/build/a.txt").reshape(a.shape());
    cout<<"a2："<<endl;
    a2.print();cout<<endl;
    
    auto a3=nc::load<int>("/Volumes/software/programming/c++/numcpp/numcpp/build/a1.txt").reshape(a.shape());
    cout<<"a3："<<endl;
    a3.print();cout<<endl;
    
}
