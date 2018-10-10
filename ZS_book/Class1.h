#ifndef CLASS1_H_INCLUDED
#define CLASS1_H_INCLUDED

#include <stack>
#include <vector>
#include <deque>
#include <stdio.h>

using namespace std;

class Class1_N1  //���һ����getMin���ܵ�ջ
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

class Class1_N2  // ������ջ��ɵĶ���
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

class Class1_N3  // ���õݹ麯����ջ��������һ��ջ
{
public:
    void ReverseStack(stack<int>& S);
private:
    int ReverseStacks(stack<int>& S);
};


class Class1_N4  // ����һ��ջ������ջ����С����
{
public:
    void sortStack(stack<int>& S);
};

class Class1_N5  // ���ɴ������ֵ
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
class Class1_N6  // ���������MaxTree
{
public:
    TreeNode* getMaxTree(vector<int> arr);
private:
    void heapInsert(vector<int>& arr,int index);
    TreeNode* constructTree(vector<int> arr,int index);
};

class Class1_N7  // ������Ӿ���Ĵ�С
{
public:
    int maxRecArea(vector<vector<int> > arr);
private:
    int getMaxArea(vector<int> hight);
};

class Class1_N8  // ���ֵ��ȥ��СֵС�ڻ����aim������������
{
public:
    int getNum(vector<int> nums,int aim);
};




#endif // CLASS1_H_INCLUDED
