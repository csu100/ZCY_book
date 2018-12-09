#include "Class3.h"

/***************************************************
*  �������ܣ�����������ģ��ջ
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(1)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ڣ�2018-08-11-08.59
***************************************************/
ARRAY_STACK::ARRAY_STACK(int x)
{
    sizes=0;
    for(int i=0;i<x;i++)
    {
        nums.push_back(0);
    }
}

void ARRAY_STACK::push(int x)
{
    if(sizes>=nums.size())
    {
        throw "error";
    }
    nums[sizes++]=x;
}
int ARRAY_STACK::pop()
{
    if(sizes==0)
    {
        throw "error";
    }
    return nums[--sizes];
}

int ARRAY_STACK::peek()
{
    if(sizes==0)
    {
        throw "error";
    }
    return nums[sizes-1];
}

/***************************************************
*  �������ܣ� ����������ģ�����
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(1)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-09.19
***************************************************/
ARRAY_QUEUE::ARRAY_QUEUE(int x)
{
    stars=0;
    ends=0;
    sizes=0;
    for(int i=0;i<x;i++)
    {
        nums.push_back(0);
    }
}

void ARRAY_QUEUE::push(int x)
{
    if(sizes>=nums.size())
    {
        throw "queue is full";
    }
    nums[ends]=x;
    ends=ends==nums.size()-1?0:ends+1;
    sizes++;
}
int ARRAY_QUEUE::pop()
{
    if(sizes==0)
    {
        throw "queue is empty";
    }
    int temp=nums[stars];
    sizes--;
    stars=stars==nums.size()-1?0:stars+1;
    return temp;
}
int ARRAY_QUEUE::peek()
{
    if(sizes==0)
    {
        throw "queue is empyt";
    }
    return nums[stars];
}

/***************************************************
*  �������ܣ�ʵ��һ������ջ����ʵ��ջ�Ļ����ϣ�ʵ�ַ���ջ����СԪ�صĲ���
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(1)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-09.19
***************************************************/

void GetMinStack::push(int x)
{
    data.push(x);
    if(data_min.empty())
    {
        data_min.push(x);
    }else
    {
        if(data_min.top()>=x)
        {
            data_min.push(x);
        }
    }
}
int GetMinStack::pop()
{
    if(data.empty())
    {
        throw "stack is empty";
    }
    int temp=data.top();
    if(data_min.top()==temp)
    {
        data_min.pop();
    }
    data.pop();
    return temp;
}
int GetMinStack::getMin()
{
    return data_min.top();
}
bool GetMinStack::empty()
{
    return data.empty();
}


/***************************************************
*  �������ܣ�����һ��������ʵ��ջ
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(1)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-09.37
***************************************************/
void Queue_Stack::push(int x)
{
    queue<int> temp;
    temp.push(x);
    while(!Q.empty())
    {
        temp.push(Q.front());
        Q.pop();
    }
    while(!temp.empty())
    {
        Q.push(temp.front());
        temp.pop();
    }
}
int Queue_Stack::pop()
{
    int temp=Q.front();
    Q.pop();
    return temp;
}
int Queue_Stack::peek()
{
    return Q.front();
}
bool Queue_Stack::empty()
{
    return Q.empty();
}


/***************************************************
*  �������ܣ�����һ��ջ��ʵ�ֶ���
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(1)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-09.37
***************************************************/
void Stack_Queue::push(int x)
{
    stack<int> temp;
    while(!S.empty())
    {
        temp.push(S.top());
        S.pop();
    }
    temp.push(x);
    while(!temp.empty())
    {
        S.push(temp.top());
        temp.pop();
    }
}
int Stack_Queue::pop()
{
    if(S.empty())
    {
        throw "stack is empty";
    }
    int temp=S.top();
    S.pop();
    return temp;
}
int Stack_Queue::peek()
{
    return S.top();
}
bool Stack_Queue::empty()
{
    return S.empty();
}

/***************************************************
*  �������ܣ�˳ʱ��תȦ��ӡ����
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N*M)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-09.37
***************************************************/
vector<int> PrintMatrix::Matrix_print(vector<vector<int> > Matrix)
{
    vector<int> result;
    if(Matrix.size()<1) return result;
    int tR=0;
    int tC=0;
    int bR=Matrix.size()-1;
    int bC=Matrix[0].size()-1;
    while(tR<=bR && tC<=bC)
    {
        Matrix_print(result,Matrix,tR++,tC++,bR--,bC--);
    }
    return result;
}

void PrintMatrix::Matrix_print(vector<int>& result,vector<vector<int> >  Matrix,int tR,int tC,int bR,int bC)
{
    if(tR==bR)
    {
        for(int i=tC;i<=bC;i++)
        {
            result.push_back(Matrix[tR][i]);
        }
        return ;
    }else if(tC==bC)
    {
        for(int i=tR;i<=bR;i++)
        {
            result.push_back(Matrix[i][tC]);
        }
        return ;
    }
    for(int i=tC;i<bC;i++)
    {
        result.push_back(Matrix[tR][i]);
    }
    for(int i=tR;i<bR;i++)
    {
        result.push_back(Matrix[i][bC]);
    }
    for(int i=bC;i>tC;i--)
    {
        result.push_back(Matrix[bR][i]);
    }
    for(int i=bR;i>tR;i--)
    {
        result.push_back(Matrix[i][tC]);
    }
}


/***************************************************
*  �������ܣ���ת�����ξ��� ˳ʱ��90��
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(n*n)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-10.35
***************************************************/
void RotateMatrix::RotateMatrixs(vector<vector<int> >& Matrix)
{
    if(Matrix.size()<1) return ;
    int tR=0;
    int tC=0;
    int bR=Matrix.size()-1;
    int bC=Matrix[0].size()-1;
    while(tR<=bR)
    {
        RotateMatrixs(Matrix,tR++,tC++,bR--,bC--);
    }
}
void RotateMatrix::RotateMatrixs(vector<vector<int> >& Matrix,int tR,int tC,int bR,int bC)
{
    int temp=0;

    for(int i=0;i<bC-tC;i++)
    {
        temp=Matrix[tR][i+tC];
        Matrix[tR][i+tC]=Matrix[bR-i][tC];
        Matrix[bR-i][tC]=Matrix[bR][bC-i];
        Matrix[bR][bC-i]=Matrix[tR+i][bC];
        Matrix[tR+i][bC]=temp;
    }
}

/***************************************************
*  �������ܣ���ת��������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(n)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-10.55
***************************************************/
ListNode*  ReverseList::ReverseListNode(ListNode* head)
{
    if(head==NULL || head->next==NULL) return head;
    ListNode* root=NULL;
    while(head!=NULL)
    {
        ListNode* node=head->next;
        head->next=root;
        root=head;
        head=node;
    }
    return root;
}

/***************************************************
*  �������ܣ���ת˫������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(n)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-10.55
***************************************************/
DListNode* ReverseDList::ReverseDListNode(DListNode* head)
{
    if(head==NULL || head->next==NULL) return head;
    DListNode* root=NULL;
    while(head!=NULL)
    {
        DListNode* node=head->next;
        head->next=root;
        head->last=node;
        root=head;
        head=node;
    }
    return root;
}

/***************************************************
*  �������ܣ���֮�����δ�ӡ����
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(n)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-10.55
***************************************************/
vector<int> ZigZagPrintMatrix::PrintMatrix(vector<vector<int> > Matrix)
{
    vector<int> result;
    if(Matrix.size()<1) return result;
    int tR=0,tC=0;
    int bR=0,bC=0;
    bool flag=true;
    while(tR<Matrix.size())
    {
        PrintMatrix(Matrix,result,flag,tR,tC,bR,bC);
        tR=tC==Matrix[0].size()-1?tR+1:tR;
        tC=tC==Matrix[0].size()-1?tC:tC+1;
        bC=bR==Matrix.size()-1?bC+1:bC;
        bR=bR==Matrix.size()-1?bR:bR+1;
        flag=!flag;
    }
    return result;
}

void ZigZagPrintMatrix::PrintMatrix(vector<vector<int> > Matrix,vector<int>& result,bool& flag,int tR,int tC,int bR,int bC)
{
     if(flag)
     {
         while(bR!=tR-1)
         {
             result.push_back(Matrix[bR--][bC++]);
         }
     }else
     {
         while(tC!=bC-1)
         {
             result.push_back(Matrix[tR++][tC--]);
         }
     }
}

/***************************************************
*  �������ܣ������ж��ź���ľ���������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N+M)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ڣ�2018-08-11-21.02
***************************************************/
bool FindNumInSortedMatrix::FindNum_Target(vector<vector<int> > Matrix,int target)
{
    if(Matrix.size()<1) return false;
    int i=0;
    int j=Matrix[0].size()-1;
    while(i<Matrix.size() && j>=0)
    {
        if(Matrix[i][j]==target)
        {
            return true;
        }else if(Matrix[i][j]>target)
        {
            j--;
        }else
        {
            i++;
        }
    }
    return false;
}

/***************************************************
*  �������ܣ���ӡ������������Ĺ�������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(max(N,M))���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-21.18
***************************************************/
void PrintCommonPart::PrintCommon(ListNode* head1,ListNode* head2)
{
    if(head1==NULL || head2==NULL) return ;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->val >head2->val)
        {
            head2=head2->next;
        }else if(head1->val < head2->val)
        {
            head1=head1->next;
        }else
        {
            cout<<head1->val<<" ";
            head1=head1->next;
            head2=head2->next;
        }
    }
    cout<<endl;
}


/***************************************************
*  �������ܣ� �ж�һ�������Ƿ�Ϊ��������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(N/2)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-21.34
***************************************************/
bool iSHuiWenList::isHuiwenListStruc(ListNode* head)
{
    if(head==NULL || head->next==NULL) return true;
    stack<int> S;
    ListNode* fast=head;
    ListNode* slow=head->next;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    while(slow!=NULL)
    {
        S.push(slow->val);
        slow=slow->next;
    }

    while(!S.empty())
    {
        if(S.top()!=(head->val))
        {
            return false;
        }
        head=head->next;
        S.pop();
    }
    return true;
}

/***************************************************
*  �������ܣ�����������ĳֵ����Ϊ���С���м���ȣ��ұߴ����ʽ
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O()���ռ临�Ӷȣ�O()
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-22.27
***************************************************/
ListNode* SmallEqualBigger::SmallEqualBiggerPartition(ListNode* head,int target)
{
    if(head==NULL || head->next==NULL) return head;
    ListNode Less(0);
    ListNode Equal(0);
    ListNode Bigger(0);
    ListNode* LessList=&Less;
    ListNode* EqualList=&Equal;
    ListNode* BiggerList=&Bigger;
    while(head!=NULL)
    {
        if(head->val==target)
        {
            EqualList->next=head;
            EqualList=EqualList->next;
        }else if(head->val < target)
        {
            LessList->next=head;
            LessList=LessList->next;
        }else
        {
            BiggerList->next=head;
            BiggerList=BiggerList->next;
        }
        head=head->next;
    }
    BiggerList->next=NULL;

    EqualList->next=Bigger.next;

    LessList->next=Equal.next;

    return Less.next;
}


/***************************************************
*  �������ܣ����ƺ������ָ���������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-11-22.27
***************************************************/
RandomList* CopyListWithRandom::COPYList(RandomList* head)
{
    if(head==NULL || head->next==NULL) return head;
    map<RandomList*,RandomList*> M;
    RandomList* curr=head;
    while(curr!=NULL)
    {
        M[curr]=new RandomList(curr->val);
        curr=curr->next;
    }
    curr=head;
    while(curr!=NULL)
    {
        M[curr]->next=M[curr->next];
        M[curr]->random=M[curr->random];
        curr=curr->next;
    }
    return M[head];
}

/***************************************************
*  �������ܣ����������ཻ��һϵ������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ڣ�2018-08-12-16.28
***************************************************/
ListNode* FindFirstInterSectNode::getIntersectNode(ListNode* headA,ListNode* headB)
{
    if(headA==NULL || headB==NULL) return NULL;
    ListNode* rootA=getIntersectNode(headA);
    ListNode* rootB=getIntersectNode(headB);
    if(rootA==NULL && rootB==NULL) // �޻�
    {
        return getNoLoopIntersectNode(headA,headB);
    }else if(rootA!=NULL && rootB!=NULL) //�л�
    {
        if(rootA->val ==rootB->val)   //Y��
        {
            return getLoopIntersectNode(headA,rootA,headB,rootB);
        }
        ListNode* curr=rootA->next;
        while(curr->val != rootA->val) // 66��״��������è��״
        {
            if(curr->val == rootB->val)
            {
                return rootA;
            }
            curr=curr->next;
        }
        return NULL;
    }else
    {
        return NULL;
    }

}

ListNode* FindFirstInterSectNode::getIntersectNode(ListNode* root)
{
    ListNode* fast=root;
    ListNode* slow=root;
    ListNode* meet=NULL;
    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
        if(fast==NULL) return NULL;
        fast=fast->next;
        if(fast->val == slow->val)
        {
            meet=fast;
            break;
        }
    }
    if(meet==NULL)
    {
        return NULL;
    }
    while(root!=NULL && meet!=NULL)
    {
        if(root->val == meet->val)
        {
            return root;
        }
        root=root->next;
        meet=meet->next;
    }
    return NULL;
}
ListNode* FindFirstInterSectNode::getLoopIntersectNode(ListNode* headA,ListNode* rootA,ListNode* headB,ListNode* rootB)
{
    if(rootA==NULL || rootB==NULL) return NULL;
    ListNode* curr1=headA;
    ListNode* curr2=headB;
    int n=0;
    while(curr1->next!=rootA)
    {
        n++;
        curr1=curr1->next;
    }
    while(curr2->next!=rootB)
    {
        n--;
        curr2=curr2->next;
    }
    if(curr1->val!=curr2->val)
    {
        return rootA;
    }
    curr1=n>0?headA:headB;
    curr2=n>0?headB:headA;
    n=abs(n);
    while(n>0 && curr1!=NULL)
    {
        n--;
        curr1=curr1->next;
    }
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->val==curr2->val)
        {
            return curr1;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return rootA;
}
ListNode* FindFirstInterSectNode::getNoLoopIntersectNode(ListNode* rootA,ListNode* rootB)
{
    if(rootA==NULL || rootB==NULL) return NULL;
    ListNode* headA=rootA;
    ListNode* headB=rootB;
    int n=0;
    while(headA->next!=NULL)
    {
        n++;
        headA=headA->next;
    }
    while(headB->next!=NULL)
    {
        n--;
        headB=headB->next;
    }
    if(headA->val != headB->val)
    {
        return NULL;
    }
    headA=n>0?rootA:rootB;
    headB=n>0?rootB:rootA;
    n=abs(n);
    while(n>0 && headA!=NULL)
    {
        n--;
        headA=headA->next;
    }
    while(headA!=NULL && headB!=NULL)
    {
        if(headA->val == headB->val)
        {
            return headA;
        }
        headA=headA->next;
        headB=headB->next;
    }
    return NULL;
}













