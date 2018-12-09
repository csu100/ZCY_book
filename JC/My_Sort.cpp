#include <iostream>
#include <vector>
#include <cmath>
#include "My_Sort.h"

using namespace std;

/***************************************************
*  �������ܣ�ð������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(n^2)���ռ临�Ӷȣ�O(1) �ȶ�
*  ��Ŀ��Դ  ��
*  ���ڣ�2018-08-10-08.33
***************************************************/
void  MY_SORT::MaoPao_sort(vector<int>& nums)
{
    if(nums.size()<2) return ;
    int flag=1;
    for(int i=0;i<nums.size() && flag==1;i++)
    {
        flag=0;
        for(int j=nums.size()-1;j>i;j--)
        {
            if(nums[j]<nums[j-1])
            {
                flag=1;
                swap(nums[j],nums[j-1]);
            }
        }
    }
}

/***************************************************
*  �������ܣ���������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(n^2)���ռ临�Ӷȣ�O(1) �ȶ�
*  ��Ŀ��Դ  ��
*  ���ڣ�2018-08-10-08.33
***************************************************/
void MY_SORT::Insert_sort(vector<int>& nums)
{
    if(nums.size()<2) return ;
    for(int i=1;i<nums.size();i++)
    {
        for(int j=i-1;j>=0 && nums[j]>nums[j+1];j--)
        {
            swap(nums[j],nums[j+1]);
        }
    }
}

/***************************************************
*  �������ܣ�ѡ������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(n^2)���ռ临�Ӷȣ�O(1) ���ȶ�
*  ��Ŀ��Դ  ��
*  ���ڣ�2018-08-10-08.33
***************************************************/
void MY_SORT::Select_sort(vector<int>& nums)
{
    if(nums.size()<2) return ;
    for(int i=0;i<nums.size();i++)
    {
        int temp=i;
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[temp]>nums[j])
            {
                temp=j;
            }
        }
        swap(nums[temp],nums[i]);
    }
}

/***************************************************
*  �������ܣ��鲢����
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(NlogN)���ռ临�Ӷȣ�O(N) �ȶ�
*  ��Ŀ��Դ  ��
*  ���ڣ�2018-08-10-08.38
***************************************************/
void MY_SORT::Guibing_sort(vector<int>& nums)
{
    if(nums.size()<2) return ;
    Guibing_sort(nums,0,nums.size()-1);
}

void MY_SORT::Guibing_sort(vector<int>& nums,int L,int R)
{
    if(L>=R) return ;
    int mid=L+((R-L)>>1);
    Guibing_sort(nums,L,mid);
    Guibing_sort(nums,mid+1,R);
    Merge_sort(nums,L,mid,R);
}

void MY_SORT::Merge_sort(vector<int>& nums,int L,int mid,int R)
{
    int i=L;
    int j=mid+1;
    vector<int> help;
    while(i<=mid&& j<=R)
    {
        if(nums[i]<nums[j])
        {
            help.push_back(nums[i++]);
        }else
        {
            help.push_back(nums[j++]);
        }
    }
    while(i<=mid)
    {
        help.push_back(nums[i++]);
    }
    while(j<=R)
    {
        help.push_back(nums[j++]);
    }
    for(int k=0;k<help.size();k++)
    {
        nums[k+L]=help[k];
    }

}

/***************************************************
*  �������ܣ������������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(NlogN)���ռ临�Ӷȣ�O(logN)
*  ��Ŀ��Դ  ��
*  author: Guoliang Zheng
*  date  ��2018-08-10-09.03
***************************************************/
void MY_SORT::Quick_sort(vector<int>& nums)
{
    if(nums.size()<2) return ;
    Quick_sort(nums,0,nums.size()-1);
}

void MY_SORT::Quick_sort(vector<int>& nums,int L,int R)
{
    if(L<R)
    {
        swap(nums[R],nums[L+rand()%(R-L+1)]); //������ţ�ȥ������״̬�й�;ȥ�����Ǿ������
        vector<int> temp(2,0);
        temp=Partiton(nums,L,R);
        Quick_sort(nums,L,temp[0]-1);
        Quick_sort(nums,temp[1]+1,R);
    }
}

vector<int> MY_SORT::Partiton(vector<int>& nums,int L,int R)
{
    int Less=L-1;
    int More=R+1;
    int temp=nums[R];
    while(L<More)
    {
        if(nums[L]<temp)
        {
            swap(nums[++Less],nums[L++]);
        }else if(nums[L]>temp)
        {
            swap(nums[--More],nums[L]);
        }else
        {
            L++;
        }
    }
    vector<int> result;
    result.push_back(Less+1);
    result.push_back(More-1);
    return result;
}

/***************************************************
*  �������ܣ�������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(NlogN)���ռ临�Ӷȣ�O(1) ���ȶ�
*  ��Ŀ��Դ  ��
*  author: Guoliang Zheng
*  date  ��2018-08-10-09.03
***************************************************/
void MY_SORT::Heap_sort(vector<int>& nums)
{
    if(nums.size()<2) return ;
    for(int i=1;i<nums.size();i++)
    {
        Heap_Insert(nums,i);
    }
    int LENGTH=nums.size();
    swap(nums[0],nums[--LENGTH]);
    while(LENGTH>0)
    {
        HeapFiy(nums,0,LENGTH);
        swap(nums[0],nums[--LENGTH]);
    }
}

void MY_SORT::Heap_Insert(vector<int>& nums,int index)
{
    while(nums[index]>nums[(index-1)/2])
    {
        swap(nums[index],nums[(index-1)/2]);
        index=(index-1)/2;
    }
}
void MY_SORT::HeapFiy(vector<int>& nums,int index,int HeadSize)
{
    int left=2*index+1;
    while(left<HeadSize)
    {
        int largest=left+1<HeadSize && nums[left+1]>nums[left]?left+1:left;
        largest=nums[largest]>nums[index]?largest:index;
        if(largest==index)
        {
            return ;
        }
        swap(nums[index],nums[largest]);
        index=largest;
        left=2*index+1;
    }
}
