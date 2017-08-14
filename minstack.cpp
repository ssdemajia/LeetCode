#include "minstack.h"
MinStack::MinStack()
{
    mins.push(INT_MAX);//将mins中提前储存一个最大值
}
void MinStack::push(int x)
{
    stack.push(x);
    if (x < mins.top()) {//如果比mins的栈顶还要小则储存
        mins.push(x);
    }
    else
    {
        mins.push(mins.top());
    }
}
void MinStack::pop()
{
    stack.pop();//弹栈，需要把两个栈都弹出
    mins.pop();
}
int MinStack::top()
{
    return stack.top();
}
int MinStack::getMin()//返回栈中最小值
{
    return mins.top();//mins保存了各个元素对应的最小值
}
using namespace std;
int main(int argc, char const *argv[]) {
    MinStack s;
    s.push(2);
    s.push(1);
    s.push(3);
    cout << s.getMin() << endl;
    s.pop();
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}
