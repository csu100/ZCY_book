#ifndef CLASS2_H_INCLUDED
#define CLASS2_H_INCLUDED

#include <stack>
#include <vector>
#include <deque>
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;


struct LinkNode
{
    int val;
    LinkNode* next;
    LinkNode(int x):val(x),next(NULL){}
};
struct DLinkNode
{
    int val;
    DLinkNode *last,*next;
    DLinkNode(int x):val(x),last(NULL),next(NULL){}
};



class Class2_N1  // ��ӡ��������Ĺ�������
{
public:
    void printCommonPart(LinkNode* head1,LinkNode* head2);
};

class Class2_N2  // ɾ��������K���ڵ������ڵ�
{
public:
    LinkNode* removeLastKthNode(LinkNode* head,int K);
    DLinkNode* removeLastKthDNode(DLinkNode* head,int K);
};

class Class2_N3  // ɾ��������м�ڵ��a/b���Ľڵ�
{
public:
    LinkNode* removeMidNode(LinkNode* head);
    LinkNode* removeByRatio(LinkNode* head,int a,int b);

};




#endif // CLASS2_H_INCLUDED
