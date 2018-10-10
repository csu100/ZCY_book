#include "Class2.h"


/*********************************************
*函数功能：打印有序链表的公共部分
*参数说明
*    输入：
            1->3->5->7->30;
            2->3->6->7->23->45;
*    输出： 3,7
*时间复杂度：O(n) 空间复杂度 O(1)
*题目来源：
*作者：guoliang zheng
*日期：2018-09-22-21.34
***********************************************/
void Class2_N1::printCommonPart(LinkNode* head1,LinkNode* head2)
{
    if(head1==NULL || head2==NULL) return ;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->val < head2->val)
        {
            head1=head1->next;
        }else if(head1->val > head2->val)
        {
            head2=head2->next;
        }else
        {
            cout<<head1->val<<" ";
            head1=head1->next;
            head2=head2->next;
        }
    }
}


/*********************************************
*函数功能：删除倒数第K个链表节点
*参数说明
*    输入：1->2->3; k=3;
*    输出：2->3;
*时间复杂度：O(N) 空间复杂度 O(1)
*题目来源：
*作者：guoliang zheng
*日期：2018-09-22-21.49
***********************************************/
LinkNode* Class2_N2::removeLastKthNode(LinkNode* head,int K)
{
    if(head==NULL || K<1) return head;
    LinkNode* curr=head;
    while(curr!=NULL)
    {
        K--;
        curr=curr->next;
    }
    if(K==0)
    {
        return head->next;
    }else if(K>0)
    {
        return head;
    }else if(K<0)
    {
        curr=head;
        while(++K!=0 && curr!=NULL)
        {
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
}


DLinkNode* Class2_N2::removeLastKthDNode(DLinkNode* head,int K)
{
    if(head==NULL || K<1) return head;
    DLinkNode* curr=head;
    while(curr!=NULL)
    {
        K--;
        curr=curr->next;
    }
    if(K>0)
    {
        return head;
    }else if(K==0)
    {
        head=head->next;
        head->last=NULL;
        return head;
    }else if(K<0)
    {
        curr=head;
        while(++K!=0 && curr!=NULL)
        {
            curr=curr->next;
        }
        DLinkNode* node=curr->next->next;
        curr->next=node;
        if(node!=NULL)
        {
            node->last=curr;
        }
        return head;
    }
}

/*********************************************
*函数功能：删除链表的中间节点和a/b处的节点
*参数说明
*    输入：1->2->3->4;删除节点2
*    输出：1->3->4
*时间复杂度：O(n) 空间复杂度 O(1)
*题目来源：
*作者：guoliang zheng
*日期：2018-09-22-23.03
***********************************************/
LinkNode* Class2_N3::removeMidNode(LinkNode* head)
{
    if(head==NULL || head->next==NULL) return head;
    if(head->next->next==NULL) return head->next;
    LinkNode* pre=head;
    LinkNode* curr=head->next->next;
    while(curr->next!=NULL && curr->next->next!=NULL)
    {
        pre=pre->next;
        curr=curr->next->next;
    }

    pre->next=pre->next->next;
    return head;
}

LinkNode* Class2_N3::removeByRatio(LinkNode* head,int a,int b)
{
    if(head==NULL || a<1 || a>b) return head;
    LinkNode* curr=head;
    int n=0;
    while(curr!=NULL)
    {
        n++;
        curr=curr->next;
    }
    n=(int)ceil((double)n*a/b);
    if(n==1)
    {
        return head->next;
    }else
    {
        curr=head;
        while(--n!=1 && curr!=NULL)
        {
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }


}




