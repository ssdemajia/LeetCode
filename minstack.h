#ifndef MINISTACK
#define MINISTACK
//leetcode 155 min stack
#include <stack>
#include <iostream>
#include <limits.h>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();//返回栈中最小值
private:
    std::stack<int> stack;
    std::stack<int> mins;//保存对应栈元素当前位置最小值的标号
};

#endif
