#ifndef CLASS1_H_INCLUDED
#define CLASS1_H_INCLUDED

#include <stack>
#include <vector>
#include <deque>
#include <stdio.h>

using namespace std;

class Class1_N1  //设计一个有getMin功能的栈
{
private:
    stack<int> DATA;
    stack<int> DATA_MIN;
public:
    void PUSH(int x);
    int POP();
    int getMin();
    bool Empty();
};

class Class1_N2  // 由两个栈组成的队列
{
private:
    stack<int> inputS;
    stack<int> outS;
public:
    void add(int x);
    int poll();
    int peek();
    bool Empty();
};

class Class1_N3  // 仅用递归函数和栈操作逆序一个栈
{
public:
    void ReverseStack(stack<int>& S);
private:
    int ReverseStacks(stack<int>& S);
};


class Class1_N4  // 借用一个栈来排序栈（从小到大）
{
public:
    void sortStack(stack<int>& S);
};

class Class1_N5  // 生成窗口最大值
{
public:
    vector<int> getMaxWindow(vector<int> arr,int w);
};


struct TreeNode
{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Class1_N6  // 构造数组的MaxTree
{
public:
    TreeNode* getMaxTree(vector<int> arr);
private:
    void heapInsert(vector<int>& arr,int index);
    TreeNode* constructTree(vector<int> arr,int index);
};

class Class1_N7  // 求最大子矩阵的大小
{
public:
    int maxRecArea(vector<vector<int> > arr);
private:
    int getMaxArea(vector<int> hight);
};

class Class1_N8  // 最大值减去最小值小于或等于aim的子数组数量
{
public:
    int getNum(vector<int> nums,int aim);
};




#endif // CLASS1_H_INCLUDED
