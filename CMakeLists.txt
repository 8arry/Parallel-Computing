# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(SimpleProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(simple simple.cpp)
