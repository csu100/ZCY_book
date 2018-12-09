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

