#include "Class4.h"


/*********************************************
*函数功能：菲波那屑数列
*参数说明
*    输入：
*    输出：
*时间复杂度：O() 空间复杂度 O()
*题目来源：
*作者：guoliang zheng
*日期：2018-09-26-17.03
***********************************************/
int Class4_N1::fibona(int n)
{
    if(n<1) return 0;
    vector<int> dp(n+3,0);
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int Class4_N1::setp_num(int n)
{
    if(n<1) return 0;
    vector<int> dp(n+3,0);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int Class4_N1::cow_num(int n)
{
    if(n<1) return 0;
    vector<int> dp(n+4,0);
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-3];
    }
    return dp[n];
}




/*********************************************
*函数功能：最长公共子序列
*参数说明
*    输入：str1="1A2C3D4B56";
           str2="B1D23CA45B6A";
*    输出："12C4B6"
*时间复杂度：O(N*M) 空间复杂度 O(N*M)
*题目来源：
*作者：guoliang zheng
*日期：2018-09-26-17.03
***********************************************/
string Class4_N2::lcse(string str1,string str2)
{
    if(str1.size()<1 || str2.size()<1) return "";
    vector<vector<int> >  dp=getDP(str1,str2);
    string res="";
    int i=str1.size()-1;// row
    int j=str2.size()-1; // column
    int index=dp[i][j];
    while(index>0)
    {
        if(i>0 && dp[i][j]==dp[i-1][j])
        {
            i--;
        }else if(j>0 && dp[i][j]==dp[i][j-1])
        {
            j--;
        }else
        {
            res=str1[i]+res;
            i--;
            j--;
            index--;
        }
    }

    return res;
}

vector<vector<int> > Class4_N2::getDP(string str1,string str2)
{
    int N=str1.size();
    int M=str2.size();
    if(N<1 || M<1)
    {
        vector<vector<int> > res;
        return res;
    }
    vector<vector<int> > dp(N,vector<int>(M,0));
    dp[0][0]=str1[0]==str2[0]?1:0;
    for(int i=1;i<M;i++)
    {
        dp[0][i]=max(dp[0][i-1],str1[0]==str2[i]?1:0);
    }
    for(int i=1;i<N;i++)
    {
        dp[i][0]=max(dp[i-1][0],str1[i]==str2[0]?1:0);
    }
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<M;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=max(dp[i][j],str1[i]==str2[j]?dp[i-1][j-1]+1:0);
        }
    }
    return dp;
}


 /*********************************************
 *函数功能：最长公共子串
 *参数说明
 *    输入：str1="1AB2345CD";
            str2="12345EF";
 *    输出："2345"
 *时间复杂度：O(N*M) 空间复杂度 O(N*M)
 *题目来源：
 *作者：guoliang zheng
 *日期：2018-09-26-18.29
 ***********************************************/
string Class4_N3::lcst1(string str1,string str2)
{
    if(str1.size()<1 || str2.size()<1) return "";
    vector<vector<int> > dp=getDP(str1,str2);
    string res="";
    int MAX=0;
    int pos=0;
    for(int i=0;i<str1.size();i++)
    {
        for(int j=0;j<str2.size();j++)
        {
            if(MAX<dp[i][j])
            {
                MAX=dp[i][j];
                pos=i;
            }
        }
    }
    for(int i=0;i<MAX;i++)
    {
        res+=str1[i+pos-MAX+1];
    }
    return res;
}

vector<vector<int> > Class4_N3::getDP(string str1,string str2)
{
    int N=str1.size();
    int M=str2.size();
    if(N<1 || M<1)
    {
        vector<vector<int> > res;
        return res;
    }
    vector<vector<int> > dp(N,vector<int>(M,0));
    dp[0][0]=str1[0]==str2[0]?1:0;
    for(int i=1;i<N;i++)
    {
        dp[i][0]=str1[i]==str2[0]?1:0;
    }
    for(int i=1;i<M;i++)
    {
        dp[0][i]=str1[0]==str2[i]?1:0;
    }
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<M;j++)
        {
            dp[i][j]=str1[i]==str2[j]?dp[i-1][j-1]+1:0;
        }
    }
    return dp;
}




