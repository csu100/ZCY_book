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



class Class2_N1  // 打印有序链表的公共部分
{
public:
    void printCommonPart(LinkNode* head1,LinkNode* head2);
};

class Class2_N2  // 删除倒数第K个节点的链表节点
{
public:
    LinkNode* removeLastKthNode(LinkNode* head,int K);
    DLinkNode* removeLastKthDNode(DLinkNode* head,int K);
};

class Class2_N3  // 删除链表的中间节点和a/b处的节点
{
public:
    LinkNode* removeMidNode(LinkNode* head);
    LinkNode* removeByRatio(LinkNode* head,int a,int b);

};




#endif // CLASS2_H_INCLUDED
