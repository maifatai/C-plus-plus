//
//  main.cpp
//  numcpp
//
//  Created by fatai on 2022/1/13.
//

#include <iostream>
#include<fstream>
#include "NumCpp.hpp"
#include "file.hpp"
#include"array_base.hpp"
#include"broadcast.hpp"
#include "random.hpp"
#include"condition.hpp"
#include "statistics.hpp"
#include"gradient.hpp"
#include"file.hpp"
#include<typeinfo>
using namespace std;

int main(int argc, const char * argv[])
{
//    test_numcpp_file();
    ArrayBase();
//  check_type();
//    Broadcast();
//    Random();
//    Condition();
//    Statistics();
//    Gradient();
    File();
    return 0;
}
