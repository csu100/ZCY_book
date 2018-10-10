#include "Help.h"


vector<int>  DATA_Generate::generates(int arr[],int len)
{
    vector<int> result;
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
        result.push_back(arr[i]);
    }
    cout<<endl;
    return result;
}
vector<int>  DATA_Generate::generates(int len)
{
    vector<int> result;
    for(int i=0;i<len;i++)
    {
        int temp=rand()%100;
        cout<<temp<<" ";
        result.push_back(temp);
    }
    cout<<endl;
    return result;
}

LinkNode* DATA_Generate::generatess(int len)
{
    if(len<1) return NULL;
    LinkNode root(0);
    LinkNode* head=&root;
    vector<int> nums;
    for(int i=0;i<len;i++)
    {
        int temp=rand()%100;
        nums.push_back(temp);
    }
    sort(nums.begin(),nums.end());
    for(int i=0;i<len;i++)
    {
        cout<<nums[i]<<" ";
        head->next=new LinkNode(nums[i]);
        head=head->next;
    }
    cout<<endl;
    return root.next;
}

string  DATA_Generate::generatesstr(int n)
{
    if(n<1) return "";
    string res="";
    for(int i=0;i<n;i++)
    {
        int temp=rand()%26+'A';
        string T="";
        T+=(char)temp;
        res+=T+T;
    }
    return res;
}








