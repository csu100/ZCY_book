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
        int len=sizeof(A)/sizeof(*A); // ����,7
        int res=0; //�������
        int L=0;  // ����߽�
        int R=len-1; //���ұ߽�
        int last=0; //�ϴα�����������͵ĸ߶�
        while(L<R)
        {
            int distance=R-L;// ��ǰ��������ҵĳ��Ⱦ���
            int temp=A[L]>A[R]?A[R--]:A[L++];
            //�����������������͵��Ǹ��߶ȣ����ƶ���Ӧ�±�
            int hight=temp>last?temp-last:0;
            //�߶�����Ϊ��ǰ�ĸ߶ȴ���֮ǰ�ĸ߶ȣ�����¸߶Ȳ���򲻸��¸߶Ȳ���趨Ϊ0��
            // ���� 3 2 3 4;
            // ��һ���� ����Ϊ3,�߶�Ϊ3,L++, �߶Ȳ��Ϊ3��
            // �ڶ���������Ϊ2,�߶�Ϊ2�����Ǳ�֮ǰ�߶�3С�����Ը߶Ȳ��趨Ϊ0,L++;
            // ������������Ϊ1���߶�Ϊ3������֮ǰ�߶�3С�����Ը߶Ȳ��趨Ϊ0��L++;
            // ���Ĳ���L<R �������������ѭ����

            res+=(distance)*hight;
            last=hight>0?temp:last;
            // ����߶Ȳ����0����˵����ǰ��������С�߶ȶ���֮ǰ�ĸ߶ȴ�˵����ʱ�ܹ�װ�߶Ȳ���ô��ˮ��
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



















