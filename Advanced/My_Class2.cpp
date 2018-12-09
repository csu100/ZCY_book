#include "My_Class2.h"



/*********************************************
*函数功能：生成窗口最大值的数组
*参数说明
*    输入：[4,8,4,5,3,7,8,3,7,6]  W=3;
*    输出：[8,8,5,7,8,8,8,7]
*时间复杂度：O(n) 空间复杂度 O(n)
*题目来源：
*作者：guoliang zheng
*日期：2018-12-05-21.51
***********************************************/
vector<int> MAX_WINDOW::get_MAX_Window(vector<int> num,int w)
{
    if(num.size()<1 || w<1 || num.size()<w) return {};
    vector<int> res(num.size()-w+1,0);
    int index=0;
    deque<int> Q;
    for(int i=0;i<num.size();i++)
    {
        while(!Q.empty() && num[Q.back()]<=num[i])
        {
            Q.pop_back();
        }
        Q.push_back(i);
        if(Q.front()==i-w)
        {
            Q.pop_front();
        }
        if(i>=w-1)
        {
            res[index++]=num[Q.front()];
        }
    }
    return res;
}


/*********************************************
*函数功能：生成窗口最小值的数组
*参数说明
*    输入：[7,4,3,7,3,9,7,6,7,3]  W=3;
*    输出：[3,3,3,3,3,6,6,3]
*时间复杂度：O(n) 空间复杂度 O(n)
*题目来源：
*作者：guoliang zheng
*日期：2018-12-05-21.51
***********************************************/
vector<int> MIN_WINDOW::get_Min_Window(vector<int> num,int w)
{
    if(num.size()<1 || w<1 || num.size()<w) return {};
    vector<int> res(num.size()-w+1,0);
    int index=0;
    deque<int> Q;
    for(int i=0;i<num.size();i++)
    {
        while(!Q.empty() && num[Q.back()]>=num[i])
        {
            Q.pop_back();
        }
        Q.push_back(i);
        if(Q.front()==i-w)
        {
            Q.pop_front();
        }
        if(i>=w-1)
        {
            res[index++]=num[Q.front()];
        }
    }
    return res;
}



/***************************************************
*  函数功能：最大值减去最小值小于或等于num的子数组数量
*  参数说明
*       输入参数:  [9,4,9,8,6,5] delta: 3
*       输出参数： 11
*  复杂性分析：时间复杂度：O(n)，空间复杂度：O(n)
*  题目来源  ：
*  作者：guoliang zheng
*  日期：2018-12-09-12.51
***************************************************/
int get_Num::get_sub_MIN_MAX_Num(vector<int> num,int delta)
{
    if(num.size()<1 || delta<0) return 0;
    if(num.size()==1) return 1;
    int res=0;
    int len=num.size();
    deque<int> MIN;
    deque<int> MAX;
    int R=0;
    for(int L=0;L<len;L++)
    {
        while(R<len)
        {
            while(!MIN.empty() && num[MIN.back()]>=num[R])
            {
                MIN.pop_back();
            }
            MIN.push_back(R);
            while(!MAX.empty() && num[MAX.back()]<=num[R])
            {
                MAX.pop_back();
            }
            MAX.push_back(R);
            if(num[MAX.front()]-num[MIN.front()]>delta)
            {
                break;
            }
            R++;
        }
        res+=(R-L);
        if(L==MIN.front())
        {
            MIN.pop_front();
        }
        if(L==MAX.front())
        {
            MAX.pop_front();
        }
    }
    return res;
}



/***************************************************
*  函数功能：最大值减去最小值小于或等于num的子数组数量
*  参数说明
*       输入参数:  [9,4,9,8,6,5] delta: 3
*       输出参数： 11
*  复杂性分析：时间复杂度：O(n^3)，空间复杂度：O(1)
*  题目来源  ：
*  作者：guoliang zheng
*  日期：2018-12-09-12.51
***************************************************/
int get_Num::get_sub_MIN_MAX_Num1(vector<int> num,int delta)
{
    if(num.size()<1 || delta<0) return 0;
    if(num.size()==1) return 1;
    int res=0;
    for(int L=0;L<num.size();L++)
    {
        for(int R=L;R<num.size();R++)
        {
            if(isValid(num,L,R,delta))
            {
                res++;
            }
        }
    }
    return res;
}

bool get_Num::isValid(vector<int> num,int L,int R,int delta)
{
    if(L==R) return true;
    int MIN=num[L];
    int MAX=num[R];
    for(int i=L;i<=R;i++)
    {
        MIN=min(MIN,num[i]);
        MAX=max(MAX,num[i]);
    }
    return MAX-MIN<=delta?true:false;
}

/***************************************************
*  函数功能：求矩阵子矩阵的大小
*  参数说明
*       输入参数:  [1 0 1 1]
                   [1 1 1 1]
                   [1 1 1 0]
*       输出参数： 6
*  复杂性分析：时间复杂度：O(n*m)，空间复杂度：O(min(n,m))
*  题目来源  ：
*  作者：guoliang zheng
*  日期：2018-12-09-12.51
***************************************************/
int get_Area::get_sub_MAX_Area(vector<vector<int> > area)
{
    if(area.size()<1 || area[0].size()<1) return 0;
    bool flag=area.size()<=area[0].size()?true:false;
    int c=flag?area.size():area[0].size(); // 列，数量少
    int r=flag?area[0].size():area.size(); // 行，数量多
    vector<int> sub_Area(c,0);
    int result=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int temp=flag?area[j][i]:area[i][j];
            sub_Area[j]=temp==0?0:sub_Area[j]+1;
        }
        result=max(result,get_MAX_Area(sub_Area));
    }
    return result;
}

int get_Area::get_MAX_Area(vector<int> num)
{
    if(num.size()<1) return 0;
    stack<int> S;
    int res=0;
    int len=num.size();
    for(int i=0;i<len;i++)
    {
        while(!S.empty() && num[S.top()]>=num[i])
        {
            int H=num[S.top()];
            S.pop();
            int L=S.empty()?-1:S.top();
            res=max(res,(i-L-1)*H);
        }
        S.push(i);
    }
    while(!S.empty())
    {
        int H=num[S.top()];
        S.pop();
        int L=S.empty()?-1:S.top();
        res=max(res,(len-L-1)*H);
    }
    return res;
}
