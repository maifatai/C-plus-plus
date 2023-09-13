cmake_minimum_required(VERSION 3.0)
project(NUMCPP)
add_compile_options(-std=c++14)

set(CMAKE_BUILD_TYPE Debug)#增加调试
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/local/include)#增加NumCpp库文件
aux_source_directory(src SRC)#源文件的目录,将src目录下的文件全部放到变量SRC
add_executable(main ${SRC})#生成可执行文件
#add_executable(可执行文件名 source1 source2 ... sourceN)   

