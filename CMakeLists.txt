cmake_minimum_required(VERSION 3.21)
project(balance_tree)

set(CMAKE_CXX_STANDARD 20)

add_executable(balance_tree main.cpp BalancedTree.cpp BalancedTree.h)
