#ifndef CLASS3_H_INCLUDED
#define CLASS3_H_INCLUDED

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>


using namespace std;

class ARRAY_STACK  // ����������ģ��ջ
{
public:
    ARRAY_STACK(int x);

    void push(int x);

    int pop();

    int peek();

private:
    vector<int> nums;
    int sizes;
};

class ARRAY_QUEUE  // ����������ģ�����
{
public:
    ARRAY_QUEUE(int x);

    void push(int x);
    int pop();
    int peek();

private:
    vector<int> nums;
    int sizes;
    int stars;
    int ends;
};

class GetMinStack  // ʵ��һ������ջ�����ڷ�����Сֵ
{
public:
    void push(int x);
    int pop();
    int getMin();
    bool empty();

private:
    stack<int> data;
    stack<int> data_min;
};

class Queue_Stack  // ���ö�����ʵ��ջ
{
public:
     void push(int x);
     int pop();
     int peek();
     bool empty();
private:
    queue<int> Q;
};

class Stack_Queue  //����ջ��ʵ�ֶ���
{
public:
    void push(int x);
    int pop();
    int peek();
    bool empty();

private:
    stack<int> S;
};

class PrintMatrix  //תȦ��ӡ���� 5
{
public:
    vector<int> Matrix_print(vector<vector<int> > Matrix);
private:
    void Matrix_print(vector<int>& result,vector<vector<int> >  Matrix,int tR,int tC,int bR,int bC);
};

class RotateMatrix  //�͵�˳ʱ����ת���� 6
{
public:
    void RotateMatrixs(vector<vector<int> >& Matrix);
private:
    void RotateMatrixs(vector<vector<int> >& Matrix,int tR,int tC,int bR,int bC);
};

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
class ReverseList  // ������ת 7
{
public:
    ListNode* ReverseListNode(ListNode* head);
};
struct DListNode
{
    int val;
    DListNode *next,*last;
    DListNode(int x):val(x),next(NULL),last(NULL){}
};
class ReverseDList  //˫����ת 7
{
public:
    DListNode* ReverseDListNode(DListNode* head);
};

class ZigZagPrintMatrix  // ��֮�����δ�ӡ���� 8
{
public:
    vector<int> PrintMatrix(vector<vector<int> > Matrix);
private:
    void PrintMatrix(vector<vector<int> > Matrix,vector<int>& result,bool& flag,int tR,int tC,int bR,int bC);
;
};

class FindNumInSortedMatrix  // �����ж��ź���ľ��������� 9
{
public:
    bool FindNum_Target(vector<vector<int> > Matrix,int target);

};

class PrintCommonPart    // ��ӡ������������Ĺ������� 10
{
public:
    void PrintCommon(ListNode* head1,ListNode* head2);

};

class iSHuiWenList  // �ж�һ�������Ƿ�Ϊ���Ľṹ 11
{
public:
    bool isHuiwenListStruc(ListNode* head);
};

class SmallEqualBigger  // ���������� ��ĳֵ����Ϊ���С���м���ȣ��ұߴ����ʽ //12
{
public:
    ListNode* SmallEqualBiggerPartition(ListNode* head,int target);
};

struct RandomList
{
    int val;
    RandomList *next,*random;
    RandomList(int x):val(x),next(NULL),random(NULL){}
};
class CopyListWithRandom   // ���Ӻ������ָ���������  //13
{
public:
    RandomList* COPYList(RandomList* head);
};

class FindFirstInterSectNode   // ����������Ľ���  // 14
{
public:
    ListNode* getIntersectNode(ListNode* headA,ListNode* headB);

private:
    ListNode* getIntersectNode(ListNode* root);
    ListNode* getLoopIntersectNode(ListNode* headA,ListNode* rootA,ListNode* headB,ListNode* rootB);
    ListNode* getNoLoopIntersectNode(ListNode* rootA,ListNode* rootB);

};

#endif // CLASS3_H_INCLUDED
