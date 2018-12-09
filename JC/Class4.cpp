#include "Class4.h"


/***************************************************
*  �������ܣ���������ǰ�� �����򣬺���ĵݹ�ʵ��
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-12-17.38
***************************************************/
vector<int> PreInPosTraversal::qianxu_Tree_DG(TreeNode* root)
{
    vector<int> result;
    if(root==NULL) return result;
    qianxu_Tree_DG(root,result);
    return result;
}

vector<int> PreInPosTraversal::zhongxu_Tree_DG(TreeNode* root)
{
    vector<int> result;
    if(root==NULL) return result;
    zhongxu_Tree_DG(root,result);
    return result;
}
vector<int> PreInPosTraversal::houxu_Tree_DG(TreeNode* root)
{
    vector<int> result;
    if(root==NULL) return result;
    houxu_Tree_DG(root,result);
    return result;
}


void PreInPosTraversal::qianxu_Tree_DG(TreeNode* root,vector<int>& result)
{
    if(root==NULL) return ;
    result.push_back(root->val);
    qianxu_Tree_DG(root->left,result);
    qianxu_Tree_DG(root->right,result);
}
void PreInPosTraversal::zhongxu_Tree_DG(TreeNode* root,vector<int>& result)
{
    if(root==NULL) return ;
    zhongxu_Tree_DG(root->left,result);
    result.push_back(root->val);
    zhongxu_Tree_DG(root->right,result);
}
void PreInPosTraversal::houxu_Tree_DG(TreeNode* root,vector<int>& result)
{
    if(root==NULL) return ;
    houxu_Tree_DG(root->left,result);
    houxu_Tree_DG(root->right,result);
    result.push_back(root->val);
}
/***************************************************
*  �������ܣ��������� ǰ�����򣬺���ķǵݹ�ʵ��
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-12-17.38
***************************************************/
vector<int> PreInPosTraversal::qianxu_Tree_NoDG(TreeNode* root)
{
    vector<int> result;
    if(root==NULL) return result;
    stack<TreeNode*> S;
    S.push(root);
    while(!S.empty())
    {
        TreeNode* node=S.top();
        S.pop();
        result.push_back(node->val);
        if(node->right)
        {
            S.push(node->right);
        }
        if(node->left)
        {
            S.push(node->left);
        }
    }
    return result;
}
vector<int> PreInPosTraversal::zhongxu_Tree_NoDG(TreeNode* root)
{
    vector<int> result;
    if(root==NULL) return result;
    stack<TreeNode*> S;
    while(!S.empty() || root!=NULL)
    {
        if(root)
        {
            S.push(root);
            root=root->left;
        }else
        {
            TreeNode* node=S.top();
            S.pop();
            result.push_back(node->val);
            root=node->right;
        }
    }
    return result;
}
vector<int> PreInPosTraversal::houxu_Tree_NoDG(TreeNode* root)
{
    vector<int> result;
    if(root==NULL) return result;
    stack<TreeNode*> S1;
    stack<TreeNode*> S2;
    S1.push(root);
    while(!S1.empty())
    {
        TreeNode* node=S1.top();
        S1.pop();
        S2.push(node);
        if(node->left)
        {
            S1.push(node->left);
        }
        if(node->right)
        {
            S1.push(node->right);
        }
    }
    while(!S2.empty())
    {
        TreeNode* node=S2.top();
        S2.pop();
        result.push_back(node->val);
    }
    return result;
}


/***************************************************
*  �������ܣ� �ڶ��������ҵ�һ���ڵ�ĺ�̣�ǰ���ڵ㣻
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(longN)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-12-19.43
***************************************************/
NEW_TreeNode* SuccessorNode::houji_node(NEW_TreeNode* head)
{
     if(head==NULL) return NULL;
     if(head->right)
     {
         head=head->right;
         while(head->left)
         {
             head=head->left;
         }
         return head;
     }else
     {
         NEW_TreeNode* node=head->parent;
         while(node!=NULL && node->left!=head)
         {
             head=node;
             node=node->parent;
         }
         return node;
     }
}
NEW_TreeNode* SuccessorNode::qianqu_node(NEW_TreeNode* head)
{
     if(head==NULL) return NULL;
     if(head->left)
     {
         head=head->left;
         while(head->right)
         {
             head=head->right;
         }
         return head;
     }else
     {
         NEW_TreeNode* node=head->parent;
         while(node!=NULL && node->right!=head)
         {
             head=node;
             node=node->parent;
         }
         return node;
     }
}


/***************************************************
*  �������ܣ������������л� �� �����л�
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-12-20.14
***************************************************/
string SerializeAndReconstrucTree::SerializeTree(TreeNode* head)
{
    string result="";
    SerializeTree(head,result);
    return result;
}
TreeNode* SerializeAndReconstrucTree::ReconstructTree(string str)
{
    queue<string> Q;
    string word="";
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='!')
        {
            Q.push(word);
            word="";
        }else
        {
            word+=str[i];
        }
    }
    return ReconstructTree(Q);
}

void SerializeAndReconstrucTree::SerializeTree(TreeNode* head,string& result)
{
    if(head==NULL)
    {
        result+="#!";
        return ;
    }
    result+=to_string(head->val)+'!';
    SerializeTree(head->left,result);
    SerializeTree(head->right,result);
}

TreeNode* SerializeAndReconstrucTree::ReconstructTree(queue<string>& Q)
{
    string temp=Q.front();
    Q.pop();
    while(temp=="#")
    {
        return NULL;
    }
    TreeNode* root=new TreeNode(string_to_int(temp));
    root->left=ReconstructTree(Q);
    root->right=ReconstructTree(Q);
    return root;
}

int SerializeAndReconstrucTree::string_to_int(string word)
{
    int number=0;
    for(int i=0;i<word.size();i++)
    {
        number=number*10+word[i]-'0';
    }
    return number;
}


/***************************************************
*  �������ܣ���ֽ���⣬ ���ö������������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(2^N)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-12-20.23
***************************************************/
void PaperFolding::PaperFold(int n)
{
    if(n<1) return ;
    bool flag=true;
    PaperFold(0,n,flag);
}

void PaperFolding::PaperFold(int i,int n,bool flag)
{
    if(i>=n) return ;
    PaperFold(i+1,n,flag);
    string str=flag?"down":"up";
    flag=!flag;
    cout<<str<<" ";
    PaperFold(i+1,n,flag);
}

/***************************************************
*  �������ܣ��ж�һ���������Ƿ�Ϊƽ�������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(2^n)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-12-20.34
***************************************************/
bool IsBalancedTree::BalanceTree(TreeNode* head)
{
    if(head==NULL) return true;
    bool flag=true;
    BalanceTree(head,flag);
    return flag;
}

int IsBalancedTree::BalanceTree(TreeNode* head,bool& flag)
{
    if(head==NULL)
    {
        return 0;
    }
    int leftHight=BalanceTree(head->left,flag);
    if(!flag)
    {
        return leftHight;
    }
    int rightHight=BalanceTree(head->right,flag);
    if(!flag)
    {
        return rightHight;
    }
    if(abs(leftHight-rightHight)>1)
    {
        flag=false;
    }
    return max(leftHight+1,rightHight+1);
}



/***************************************************
*  �������ܣ��ж�һ�����Ƿ�Ϊ����������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-12-21.13
***************************************************/
bool IsBST_AND_CBT::isBST(TreeNode* head)     //�ж��Ƿ�Ϊ������������
{
    if(head==NULL) return true;
    stack<TreeNode*> S;
    int last=0x80000000;
    while(!S.empty() || head!=NULL)
    {
        if(head)
        {
            S.push(head);
            head=head->left;
        }else
        {
            TreeNode* node=S.top();
            S.pop();
            if(node->val < last)
            {
                return false;
            }
            head=node->right;
            last=node->val;
        }
    }
    return true;
}
/***************************************************
*  �������ܣ��ж�һ�����Ƿ�Ϊ��ȫ������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-12-21.13
***************************************************/
bool IsBST_AND_CBT::isCBT(TreeNode* head)    //�ж��Ƿ�Ϊ��ȫ��������
{
    if(head==NULL) return true;
    queue<TreeNode*> Q;
    Q.push(head);
    bool flag=false;
    while(!Q.empty())
    {
        TreeNode* node=Q.front();
        Q.pop();
        if(node->right!=NULL && node->left==NULL) return false;
        if(flag && (node->right!=NULL || node->left!=NULL))
        {
            return false;
        }
        if((node->left==NULL ||node->left!=NULL)&&node->right==NULL)
        {
            flag=true;
        }
        if(node->left)
        {
            Q.push(node->left);
        }
        if(node->right)
        {
            Q.push(node->right);
        }
    }
    return true;

}


/***************************************************
*  �������ܣ�һ����ȫ������������ڵ�ĸ���
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O((logN)^2)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-12-21.37
***************************************************/
int CompleteTreeNodeNumber::TreeNodeNumber(TreeNode* head)
{
    if(head==NULL) return 0;
    return TreeNodeNumber(head,TreeHigh(head),1);
}

int CompleteTreeNodeNumber::TreeHigh(TreeNode* head)
{
    if(head==NULL)
    {
        return 0;
    }
    int number=0;
    while(head!=NULL)
    {
        head=head->left;
        number++;
    }
    return number;
}


int CompleteTreeNodeNumber::TreeNodeNumber(TreeNode* head,int high,int layer)
{
    if(high==layer)
    {
        return 1;
    }
    if(TreeHigh(head->right)+layer == high)
    {
        return (1<<(high-layer))+TreeNodeNumber(head->right,high,layer+1);
    }else
    {
        return (1<<(high-layer-1))+TreeNodeNumber(head->left,high,layer+1);
    }
}



