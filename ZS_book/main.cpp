#include <iostream>
#include "Class1.h"
#include <random>
#include <stack>
#include "Help.h"
#include "Class2.h"
#include <queue>
#include "Class4.h"


using namespace std;


int main()
{
//    string str1="1A2C3D4B56";
//    string str2="B1D23CA45B6A";
//    Class4_N2 zgl;
//  cout<<zgl.lcse(str1,str2)<<endl;
    string str1="1AB2345CD";
    string str2="12345EF";
    cout<<str1<<endl<<str2<<endl;
    Class4_N3 zgl;
    cout<<zgl.lcst1(str1,str2)<<endl;

    DATA_Generate dd;
    string str3=dd.generatesstr(10);
    string str4=dd.generatesstr(15);
    cout<<str3<<endl<<str4<<endl;

    cout<<zgl.lcst1(str3,str4)<<endl;

    return 0;
}

/*
int  main()
{
    for(int k=0;k<20;k++)
    {
        int A[7]={0};
        for(int ii=0;ii<7;ii++)
        {
            int tmep=rand()%6+1;
            cout<<tmep<<" ";
            A[ii]=tmep;
        }
        cout<<endl;
        int len=sizeof(A)/sizeof(*A); // 长度,7
        int res=0; //结果变量
        int L=0;  // 最左边界
        int R=len-1; //最右边界
        int last=0; //上次遍历过程中最低的高度
        while(L<R)
        {
            int distance=R-L;// 当前最左和最右的长度距离
            int temp=A[L]>A[R]?A[R--]:A[L++];
            //更新最左和最右中最低的那个高度，并移动对应下标
            int hight=temp>last?temp-last:0;
            //高度是因为当前的高度大于之前的高度，则更新高度差，否则不更新高度差，并设定为0。
            // 比如 3 2 3 4;
            // 第一步是 距离为3,高度为3,L++, 高度差变为3；
            // 第二步：距离为2,高度为2，但是比之前高度3小，所以高度差设定为0,L++;
            // 第三步：距离为1，高度为3，但是之前高度3小，所以高度差设定为0，L++;
            // 第四步：L<R 不成立，则结束循环；

            res+=(distance)*hight;
            last=hight>0?temp:last;
            // 如果高度差大于0，则说明当前遍历的最小高度都比之前的高度大，说明此时能够装高度差那么多水。
        }
        cout<<res<<endl;
    }

    return 0;
}
*/


/*
int main()
{
    DATA_Generate dd;
    int lend=10;
    LinkNode* head1=dd.generatess(lend);
     Class2_N3 s3;
     int a=4;
     int b=6;
    LinkNode* result=s3.removeByRatio(head1,a,b);
    while(result!=NULL)
    {
        cout<<result->val<<" ";
        result=result->next;
    }
    cout<<endl;

    return 0;
}
*/

/*
int main()
{
    DATA_Generate dd;
    int lend=20;
    LinkNode* head1=dd.generatess(lend);
    LinkNode* head2=dd.generatess(lend);

    Class2_N1  ss;
    ss.printCommonPart(head1,head2);

    Class2_N2 ss2;
    int lend2=10;
    cout<<endl<<"--------------------------"<<endl;
    LinkNode* head=dd.generatess(lend2);

    LinkNode* result=ss2.removeLastKthNode(head,5);

    while(result!=NULL)
    {
        cout<<result->val<<" ";
        result=result->next;
    }
    cout<<endl<<"----------------------------"<<endl;

    Class2_N3 ss3;
    for(int i=0;i<8;i++)
    {
        cout<<"i : "<<i<<":";
        LinkNode* head=dd.generatess(i);

        LinkNode* result=ss3.removeMidNode(head);
        while(result!=NULL)
        {
            cout<<result->val<<" ";
            result=result->next;
        }
        cout<<endl;
    }

    cout<<"*******************************"<<endl;

    double a1=4.34;
    cout<<a1<<"  floor: "<<floor(a1)<<"  ceil : "<<ceil(a1)<<endl;


}
*/





//int main()
//{
//    Class1_N7 ss;
//    vector<vector<int> > nums;
//    int A[][4]={{1,0,1,1},{1,1,1,1},{1,1,1,0},{1,1,1,1},{1,1,1,1}};
//    for(int i=0;i<5;i++)
//    {
//        nums.push_back(vector<int>());
//        for(int j=0;j<4;j++)
//        {
//            nums[i].push_back(A[i][j]);
//        }
//    }
//
//    cout<<ss.maxRecArea(nums);
//
//    return 0;
//}

/*
void print_Tree(TreeNode* root,int layer)
{
    if(root==NULL)
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
    cout<<root->val<<endl;
    print_Tree(root->left,layer+1);
    print_Tree(root->right,layer+1);
}

int main()
{
    DATA_Generate dd;
//    int arr[]={3,4,5,1,2};
//    int len=sizeof(arr)/sizeof(*arr);
    int len=6;
    vector<int>  nums=dd.generates(len);
//    Class1_N5 ss;
//    vector<int> result=ss.getMaxWindow(nums,3);
//    for(int i=0;i<result.size();i++)
//    {
//        cout<<result[i]<<" ";
//    }
//    cout<<endl;
    Class1_N6 ss;
    TreeNode* res=ss.getMaxTree(nums);
    print_Tree(res,0);
    return 0;
}
*/


/*
int main()
{
    Class1_N4 ss;

    stack<int> S;
    for(int i=0;i<10;i++)
    {
        int temp=rand()%20;
        cout<<temp<<" ";
        S.push(temp);
    }
    cout<<endl<<"--------------"<<endl;

    ss.sortStack(S);
    while(!S.empty())
    {
        cout<<S.top()<<" ";
        S.pop();
    }
    return 0;
}
*/



/*
int main()
{

    Class1_N3 ss;
    stack<int> S;
    for(int i=0;i<10;i++)
    {
        int temp=rand()%20;
        cout<<temp<<" ";
        S.push(temp);
    }
    cout<<endl<<"--------------"<<endl;

    ss.ReverseStack(S);
    while(!S.empty())
    {
        cout<<S.top()<<" ";
        S.pop();
    }

    return 0;
}
*/


/*
int main()
{
    Class1_N2 ss;
    for(int i=0;i<10;i++)
    {
        int temp=rand()%20;
        cout<<temp<<" ";
        ss.add(temp);
    }
    cout<<endl<<"--------------"<<endl;
    while(!ss.Empty())
    {
        cout<<"top:  "<<ss.peek()<<"   ";
        cout<<"pop:  "<<ss.poll()<<endl;
    }

    return 0;
}
*/


/*
int main()
{
    Class1_N1 ss;
    for(int i=0;i<10;i++)
    {
        int temp=rand()%20;
        cout<<temp<<" ";
        ss.PUSH(temp);
    }
    cout<<endl<<"--------------"<<endl;
    while(!ss.Empty())
    {
        cout<<"min:"<<ss.getMin()<<" ";
        cout<<"top:"<<ss.POP()<<endl;
    }
    return 0;
}
*/



















