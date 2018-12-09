
#include "My_Class3.h"

/*********************************************
*�������ܣ� �������ĵݹ����
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷ� O(lgn)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-12-09-23.41
***********************************************/
void Get_Node::print_pre_Node_DG(TreeNode* root)
{
    if(root==nullptr) return ;
    print_pre_Node_DG(root,1);
}
void Get_Node::print_pre_Node_DG(TreeNode* root,int layer)
{
    if(root==nullptr)
    {
        for(int i=0;i<layer;i++)
        {
            cout<<"--";
        }
        cout<<endl;
        return ;
    }
    for(int i=0;i<layer;i++)
    {
        cout<<"--";
    }
    cout<<root->value<<endl;
    print_pre_Node_DG(root->left,layer+1);
    print_pre_Node_DG(root->right,layer+1);
}
/*********************************************
*�������ܣ���������ǰ�����
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-12-09-23.41
***********************************************/
void Get_Node::print_pre_Node(TreeNode* root)   // ǰ��
{
    if(root==nullptr) return ;
    TreeNode* curr=root;
    TreeNode* mostRight=nullptr;
    while(curr!=nullptr)
    {
        mostRight=curr->left;
        if(mostRight!=nullptr)
        {
            while(mostRight->right!=nullptr && mostRight->right!=curr)
            {
                mostRight=mostRight->right;
            }
            if(mostRight->right==nullptr)
            {
                mostRight->right=curr;
                cout<<curr->value<<" ";
                curr=curr->left;
                continue;
            }else
            {
                mostRight->right=nullptr;
            }
        }else
        {
            cout<<curr->value<<" ";
        }
        curr=curr->right;
    }
    cout<<endl;
}

/*********************************************
*�������ܣ����������������
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-12-09-23.41
***********************************************/
void Get_Node::print_mid_Node(TreeNode* root)  // ����
{
    if(root==nullptr) return ;
    TreeNode* curr=root;
    TreeNode* mostRight=nullptr;
    while(curr!=nullptr)
    {
        mostRight=curr->left;
        if(mostRight!=nullptr)
        {
            while(mostRight->right!=nullptr && mostRight->right!=curr)
            {
                mostRight=mostRight->right;
            }
            if(mostRight->right==nullptr)
            {
                mostRight->right=curr;
                curr=curr->left;
                continue;
            }else
            {
                mostRight->right=nullptr;
            }
        }
        cout<<curr->value<<" ";
        curr=curr->right;
    }
    cout<<endl;
}

/*********************************************
*�������ܣ��������ĺ������
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-12-09-23.41
***********************************************/
void Get_Node::print_last_Node(TreeNode* root) // ����
{
    if(root==nullptr) return ;
    TreeNode* curr=root;
    TreeNode* mostRight=nullptr;
    while(curr!=nullptr)
    {
        mostRight=curr->left;
        if(mostRight!=nullptr)
        {
            while(mostRight->right!=nullptr && mostRight->right!=curr)
            {
                mostRight=mostRight->right;
            }
            if(mostRight->right==nullptr)
            {
                mostRight->right=curr;
                curr=curr->left;
                continue;
            }else
            {
                mostRight->right=nullptr;
                print_Edge(curr->left);
            }
        }
        curr=curr->right;
    }
    print_Edge(root);
    cout<<endl;
}

void Get_Node::print_Edge(TreeNode* root)
{
    if(root==nullptr) return ;
    TreeNode* curr=reverse_Tree(root);
    TreeNode* node=curr;
    while(node!=nullptr)
    {
        cout<<node->value<<" ";
        node=node->right;
    }
    reverse_Tree(curr);
}
TreeNode* Get_Node::reverse_Tree(TreeNode* root)
{
    if(root==nullptr) return nullptr;
    TreeNode* pre=nullptr;
    TreeNode* node=nullptr;
    while(root!=nullptr)
    {
        node=root->right;
        root->right=pre;
        pre=root;
        root=node;
    }
    return pre;
}













