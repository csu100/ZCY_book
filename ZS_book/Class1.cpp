#include "Class1.h"


/*********************************************
*�������ܣ����һ����getMin���ܵ�ջ
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(1) �ռ临�Ӷ� O(1)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-09-22-00.01
***********************************************/
void Class1_N1::PUSH(int x)
{
    if(DATA_MIN.empty())
    {
        DATA_MIN.push(x);
    }else if(DATA_MIN.top()>=x)
    {
        DATA_MIN.push(x);
    }
    DATA.push(x);
}


int Class1_N1::POP()
{
    if(DATA.empty())
    {
        throw "stack is empty!";
    }
    int temp=DATA.top();
    DATA.pop();
    if(temp==DATA_MIN.top())
    {
        DATA_MIN.pop();
    }
    return temp;
}

int Class1_N1::getMin()
{
    if(DATA_MIN.empty())
    {
        throw "stack is empty";
    }
    return DATA_MIN.top();
}
bool Class1_N1::Empty()
{
    return DATA.empty();
}


/*********************************************
*�������ܣ�������ջ��ɵĶ���
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O() �ռ临�Ӷ� O()
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-09-22-00.01
***********************************************/
void Class1_N2::add(int x)
{
    inputS.push(x);
}
int Class1_N2::poll()
{
    if(inputS.empty() && outS.empty())
    {
        throw "stack is empty";
    }
    if(outS.empty())
    {
        while(!inputS.empty())
        {
            outS.push(inputS.top());
            inputS.pop();
        }
    }
    int temp=outS.top();
    outS.pop();
    return temp;
}
int Class1_N2::peek()
{
    if(inputS.empty() && outS.empty())
    {
        throw "stack is empty";
    }
    if(outS.empty())
    {
        while(!inputS.empty())
        {
            outS.push(inputS.top());
            inputS.pop();
        }
    }
    return outS.top();
}

bool Class1_N2::Empty()
{
    return (outS.empty() && inputS.empty());
}


/*********************************************
*�������ܣ����õݹ麯����ջ��������һ��ջ
*����˵��
*    ���룺1,2,3,4
*    �����4,3,2,1
*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷ� O(n)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-09-22-00.25
***********************************************/
void Class1_N3::ReverseStack(stack<int>& S)
{
    if(S.empty()) return ;
    int temp=ReverseStacks(S);
    ReverseStack(S);
    S.push(temp);
}

int Class1_N3::ReverseStacks(stack<int>& S)
{
    int temp=S.top();
    S.pop();
    if(S.empty())
    {
        return temp;
    }else
    {
        int last=ReverseStacks(S);
        S.push(temp);
        return last;
    }
}

/*********************************************
*�������ܣ�����һ��ջ������ջ����С����
*����˵��
*    ���룺1,7,14,0,9,4,18,18,2,4
*    �����0,1,2,4,4,7,9,14,18,18
*ʱ�临�Ӷȣ�O(n^2) �ռ临�Ӷ� O(n)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-09-22-08.12
***********************************************/
void Class1_N4::sortStack(stack<int>& S)
{
    if(S.empty()) return ;
    stack<int> help;
    while(!S.empty())
    {
        int curr=S.top();
        S.pop();
        while(!help.empty() && help.top()<curr)
        {
            S.push(help.top());
            help.pop();
        }
        help.push(curr);
    }
    while(!help.empty())
    {
        S.push(help.top());
        help.pop();
    }
}

/*********************************************
*�������ܣ����ɴ������ֵ
*����˵��
*    ���룺arr=[4,3,5,4,3,3,6,7];w=3;
*    �����5,5,5,4,6,7
*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷ� O(w)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-09-22-09.00
***********************************************/
vector<int> Class1_N5::getMaxWindow(vector<int> arr,int w)
{
    vector<int> result;
    if(arr.size()<1 || w<1 || arr.size()<w) return result;
    deque<int> Q;
    for(int i=0;i<arr.size();i++)
    {
        while(!Q.empty() && arr[Q.back()]<=arr[i])
        {
            Q.pop_back();
        }
        Q.push_back(i);
        if(Q.front()==i-w) Q.pop_front();
        if(i>=w-1)
        {
           result.push_back(arr[Q.front()]);
        }

    }
    return result;
}

/*********************************************
*�������ܣ����������MaxTree // ÿһ��������ͷ���ֵ���
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷ� O(1)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-09-22-09.59
***********************************************/
TreeNode* Class1_N6::getMaxTree(vector<int> arr)
{
    if(arr.size()<1) return NULL;
    for(int i=1;i<arr.size();i++)
    {
        heapInsert(arr,i);
    }

    return constructTree(arr,0);
}

void Class1_N6::heapInsert(vector<int>& arr,int index)
{
    while(arr[index]>arr[(index-1)/2])
    {
        swap(arr[index],arr[(index-1)/2]);
        index=(index-1)/2;
    }
}

TreeNode* Class1_N6::constructTree(vector<int> arr,int index)
{
    if(index>=arr.size()) return NULL;
    TreeNode *root=new TreeNode(arr[index]);
    int left=index*2+1;
    int right=2*index+2;
    root->left=constructTree(arr,left);
    root->right=constructTree(arr,right);
    return root;
}


/*********************************************
*�������ܣ�������Ӿ���Ĵ�С
*����˵��
*    ���룺1 0 1 1
           1 1 1 1
           1 1 1 0
*    �����6(6��1)
*ʱ�临�Ӷȣ�O(n*m) �ռ临�Ӷ� O(m)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-09-22-12.53
***********************************************/
int Class1_N7::maxRecArea(vector<vector<int> > arr)
{
    if(arr.size()<1) return 0;
    int colomn=arr[0].size();
    vector<int> high(colomn,0);
    int ResMax=0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            high[j]=arr[i][j]==0?0:high[j]+1;
        }

        ResMax=max(ResMax,getMaxArea(high));
    }
    return ResMax;
}

int Class1_N7::getMaxArea(vector<int> hight)
{
    if(hight.size()<1) return 0;
    int Res=0;
    stack<int> S;
    for(int i=0;i<hight.size();i++)
    {
        while(!S.empty() && hight[S.top()]>=hight[i]) // ά��һ����С�����ջ
        {
            int R=S.top();
            S.pop();
            int L=S.empty()?-1:S.top();
            Res=max(Res,(i-L-1)*hight[R]);
        }
        S.push(i);
    }
    int len=hight.size();
    while(!S.empty())
    {
        int R=S.top();
        S.pop();
        int L=S.empty()?-1:S.top();
        Res=max(Res,(len-L-1)*hight[R]);
    }
    return Res;
}


/*********************************************
*�������ܣ����ֵ��ȥ��СֵС�ڻ����aim������������
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷ� O(n)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-09-22-21.03
***********************************************/
int Class1_N8::getNum(vector<int> nums,int aim)
{
    if(nums.size()<1 || aim<1) return 0;
    int res=0;
    deque<int> minS;
    deque<int> maxS;
    int i=0;
    int j=0;
    while(i<nums.size())
    {
        while(j<nums.size())
        {
            while(!minS.empty() && nums[minS.back()]>=nums[j])
            {
                minS.pop_back();
            }
            minS.push_back(j);
            while(!maxS.empty() && nums[maxS.back()]<=nums[j])
            {
                maxS.pop_back();
            }
            maxS.push_back(j);
            if(nums[maxS.front()]-nums[minS.front()]>aim)
            {
                break;
            }
            j++;
        }
        if(minS.front()==i)
        {
            minS.pop_front();
        }
        if(maxS.front()==i)
        {
            maxS.pop_front();
        }
        res+=(j-i);
    }
    return res;
}


