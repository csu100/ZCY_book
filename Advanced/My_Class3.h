#ifndef MY_CLASS3_H_INCLUDED
#define MY_CLASS3_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct TreeNode
{
    int value;
    TreeNode *left,*right;
    TreeNode(int x):value(x),left(NULL),right(NULL){}
};

class Get_Node
{
public:
    void print_pre_Node(TreeNode* root);  // 前序
    void print_mid_Node(TreeNode* root);  // 中序
    void print_last_Node(TreeNode* root); // 后序
    void print_pre_Node_DG(TreeNode* root); // 前序

private:
    void print_Edge(TreeNode* root);
    TreeNode* reverse_Tree(TreeNode* root);

    void print_pre_Node_DG(TreeNode* root,int layer);
};



#endif // MY_CLASS3_H_INCLUDED
