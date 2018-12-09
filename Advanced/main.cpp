#include <iostream>
#include <string>
#include "My_Class1.h"
#include "My_Class2.h"
#include "Help.h"
#include "My_Class3.h"




using namespace std;



    void print_pre_Node(TreeNode* root);  // 前序
    void print_mid_Node(TreeNode* root);  // 中序
    void print_last_Node(TreeNode* root); // 后序


int main()
{
    Get_Node zgl;
    TreeNode a(0);
    TreeNode b1(1);
    TreeNode b2(2);
    TreeNode c1(3);
    TreeNode c2(4);
    TreeNode c3(5);
    TreeNode c4(6);
    TreeNode d1(7);
    TreeNode d2(8);

    a.left=&b1;
    a.right=&b2;
    b1.left=&c1;
    b1.right=&c2;
    b2.left=&c3;
    b2.right=&c4;
    c2.left=&d1;
    c3.right=&d2;

    zgl.print_pre_Node_DG(&a);

    zgl.print_pre_Node(&a);  // 前序
    zgl.print_mid_Node(&a);  // 中序
    zgl.print_last_Node(&a);

    return 0;
}
