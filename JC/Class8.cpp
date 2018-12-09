#include "Class8.h"


/***************************************************
*  �������ܣ���N!����
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-19.35
***************************************************/
long Factorial::jiecheng(int n)
{
    long result=1;
    if(n<2) return result;
    for(int i=1;i<=n;i++)
    {
        result*=i;
    }
    return result;
}
long Factorial::jiecheng_DG(int n)
{
    if(n<=1) return 1;
    return n*jiecheng_DG(n-1);
}

/***************************************************
*  �������ܣ���ŵ�� ����
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(2^N)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-19.35
***************************************************/
void Hanoi::Hanois(int n)
{
    if(n<1) return ;
    Hanois(n,n,"From","To","Help");
}

void Hanoi::Hanois(int down,int n,string From,string To,string Help)
{
    if(n==1)
    {
        cout<<"Move "<<down<<" "<<From<<" --> "<<To<<endl;
        return ;
    }
    Hanois(down-1,n-1,From,Help,To);
    Hanois(down,1,From,To,Help);
    Hanois(down-1,n-1,Help,To,From);
}


/***************************************************
*  �������ܣ�  ��ȡһ���ַ�����ȫ�������У��������ַ���
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(2^n)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-20.14
***************************************************/
vector<string> Print_All_Subsquences::Get_All_Subsquence(string str)
{
    vector<string> result;
    string word="";
    Get_All_Subsquence(result,0,str,word);
    return result;
}

void Print_All_Subsquences::Get_All_Subsquence(vector<string>& result,int i,string str,string word)
{
    if(i>=str.size())
    {
        result.push_back(word);
        return ;
    }
    Get_All_Subsquence(result,i+1,str,word);
    Get_All_Subsquence(result,i+1,str,word+str[i]);
}

/***************************************************
*  �������ܣ�  ��ȡһ���ַ�����ȫ������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(2^n)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-20.14
***************************************************/
vector<string> Print_ALL_Permutation::Get_ALL_Permutation(string str)
{
    vector<string> result;
    if(str.size()<1) return result;
    Get_ALL_Permutation(result,str,0);
    return result;
}
vector<string> Print_ALL_Permutation::Get_ALL_NoPermutation(string str)
{
    vector<string> result;
    if(str.size()<1) return result;
    set<string> item;
    Get_ALL_NoPermutation(result,item,str,0);
    return result;
}
void Print_ALL_Permutation::Get_ALL_Permutation(vector<string>& result,string& str,int n)
{
    if(n>=str.size())
    {
        result.push_back(str);
        return ;
    }
    for(int i=n;i<str.size();i++)
    {
        swap(str[n],str[i]);
        Get_ALL_Permutation(result,str,n+1);
        swap(str[n],str[i]);
    }
}
void Print_ALL_Permutation::Get_ALL_NoPermutation(vector<string>& result,set<string>& item,string& str,int n)
{
    if(n>=str.size())
    {
        if(item.find(str)==item.end())
        {
            result.push_back(str);
            item.insert(str);
        }
        return ;
    }
    for(int i=n;i<str.size();i++)
    {
        swap(str[n],str[i]);
        Get_ALL_NoPermutation(result,item,str,n+1);
        swap(str[n],str[i]);
    }
}

/***************************************************
*  �������ܣ� ��ĸţ����
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-22.26
***************************************************/
int Cow_NUMBER::Get_Cow_Number(int n)
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
int Cow_NUMBER::Get_Cow_Number_Advance(int n)
{
    if(n<1) return 0;
    vector<int> dp(n+4,0);
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<=n;i++)
    {
        if(i>10)
        {
            dp[i]=dp[i-1]+dp[i-3]-dp[i-10];
        }else
        {
            dp[i]=dp[i-1]+dp[i-3];
        }
    }
    return dp[n];
}

/***************************************************
*  �������ܣ�// ����ջ���������������ݽṹ ֻ�õݹ� // 6
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-15-07.55
***************************************************/
void ReverseStack::ReverseStacks(stack<int>& S)
{
    if(S.empty())
    {
        return ;
    }
    int temp=Reverse(S);
    ReverseStacks(S);
    S.push(temp);
}

int ReverseStack::Reverse(stack<int>& S)
{
    int temp=S.top();
    S.pop();
    if(S.empty())
    {
        return temp;
    }else
    {
        int last=Reverse(S);
        S.push(temp);
        return last;
    }
}


/***************************************************
*  �������ܣ����·����  �ݹ�ͷǵݹ�ʵ��
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N*M)���ռ临�Ӷȣ�O(N*M)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-15-08.58
***************************************************/
int MinPath::get_MinPath(vector<vector<int> > path)
{
    if(path.size()<1) return 0;
    vector<vector<int> > dp;
    int row=path.size();
    int column=path[0].size();
    for(int i=0;i<row;i++)
    {
        dp.push_back(vector<int>());
        for(int j=0;j<column;j++)
        {
            dp[i].push_back(0);
        }
    }
    dp[0][0]=path[0][0];
    for(int i=1;i<column;i++)
    {
        dp[0][i]=dp[0][i-1]+path[0][i];
    }
    for(int i=1;i<row;i++)
    {
        dp[i][0]=dp[i-1][0]+path[i][0];
    }
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<column;j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+path[i][j];
        }
    }
    return dp[row-1][column-1];
}
int MinPath::get_DGMinPath(vector<vector<int> > path)
{
    if(path.size()<1) return 0;
    int row=path.size();
    int column=path[0].size();
    get_DGMinPath(path,row-1,column-1);

    return get_DGMinPath(path,row-1,column-1);
}

int MinPath::get_DGMinPath(vector<vector<int> >& path,int x,int y)
{
    int res=path[x][y];
    if(x==0 && y==0)
    {
        return res;
    }
    if(x==0 && y>0)
    {
        return res+get_DGMinPath(path,x,y-1);
    }
    if(y==0 && x>0)
    {
        return res+get_DGMinPath(path,x-1,y);
    }
    return res+min(get_DGMinPath(path,x-1,y),get_DGMinPath(path,x,y-1));
}

/***************************************************
*  �������ܣ�����һ������arr����һ������aim������ѡ��arr�е����֣��Ƿ��ܹ��ۼӵõ�aim������true or false;
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N*M)���ռ临�Ӷȣ�O(N*M)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-15-08.58
***************************************************/
bool Arr_Aim::is_Sum_Aim(vector<int> arr,int aim)
{
    if(arr.size()<1) return false;
    int row=arr.size();
    vector<vector<bool> > dp(row+1,vector<bool>(aim+1,false));
    dp[row][aim]=true;
    for(int i=row-1;i>=0;i--)
    {
        for(int j=aim;j>=0;j--)
        {
            dp[i][j]=dp[i+1][j];
            if(arr[i]+j<=aim)
            {
                dp[i][j]=dp[i][j] | dp[i][j+arr[i]];
            }
        }
    }
    return dp[0][0];

}
bool Arr_Aim::is_Sum_Aim_DG(vector<int> arr,int aim)
{
    if(arr.size()<1) return false;
    return is_Sum_Aim_DG(arr,aim,0,0);
}

bool Arr_Aim::is_Sum_Aim_DG(vector<int> arr,int aim,int sum,int n)
{
    if(aim==sum)
    {
        return true;
    }
    if(n==arr.size())
    {
        return aim==sum;
    }
    return is_Sum_Aim_DG(arr,aim,sum,n+1) || is_Sum_Aim_DG(arr,aim,sum+arr[n],n+1);
}


/***************************************************
*  �������ܣ�0/1 �������� �ݹ�ͷǵݹ�汾
*  ����˵��
*       ��������� weight  = { 3, 2, 4, 7 };
                   costs   =  { 5, 6, 3, 19 };
                   max_bag = 11;
*       ��������� 25
*  �����Է�����ʱ�临�Ӷȣ�O(N*M)���ռ临�Ӷȣ�O(N*M)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-15-10.19
***************************************************/
int Bag_Quistion::get_MAX_value(vector<int> weight,vector<int> costs,int max_bag)
{
    if(weight.size()<1 || costs.size()<1 || max_bag<1) return 0;
    int row=weight.size();
    vector<vector<int> > dp(row+1,vector<int>(max_bag+1,0));
    for(int i=row-1;i>=0;i--)
    {
        for(int j=0;j<=max_bag;j++)
        {
            dp[i][j]=dp[i+1][j];
            if(j-weight[i]>=0)
            {
                dp[i][j]=max(dp[i][j],costs[i]+dp[i+1][j-weight[i]]);
            }
        }
    }
    cout<<"--------------------------------"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<=max_bag;j++)
        {
            printf("%3d ",dp[i][j]);
        }
        printf("\n");
    }
    vector<int> res(row,0);
    int r=0;
    int c=max_bag;
    while(r<row)
    {
        if(dp[r][c]==(dp[r+1][c-weight[r]]+costs[r]))
        {
            res[r]=1;
            c=c-weight[r];
        }
        r++;
    }
    for(int i=0;i<row;i++)
    {
        printf("%3d ",res[i]);
    }

    printf("\n");
    return dp[0][max_bag];
}

int Bag_Quistion::get_MAX_value_DG(vector<int> weight,vector<int> costs,int max_bag)
{
    if(weight.size()<1 || costs.size()<1 || max_bag<1) return 0;
    return get_MAX_value_DG(weight,costs,max_bag,0,0);
}

int Bag_Quistion::get_MAX_value_DG(vector<int> weight,vector<int> costs,int max_bag,int i,int allget)
{
    if(i==weight.size())
    {
        return 0;
    }
    if(allget>max_bag)
    {
        return 0;
    }
    int left=get_MAX_value_DG(weight,costs,max_bag,i+1,allget);
    int right=0;
    if(allget+weight[i]<=max_bag)
    {
        right=costs[i]+get_MAX_value_DG(weight,costs,max_bag,i+1,allget+weight[i]);
    }
    return max(left,right);

}

/***************************************************
*  �������ܣ���ȫ��������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N*M)���ռ临�Ӷȣ�O(N*M)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-15-16.24
***************************************************/
int Bag_Quistion::get_MAX_value_Complete(vector<int> weight,vector<int> costs,int max_bag)
{
    if(weight.size()<1 || costs.size()<1 || max_bag<1) return 0;
    int row=weight.size();
    vector<vector<int> > dp(row+1,vector<int>(max_bag+1,0));
    for(int i=row-1;i>=0;i--)
    {
        for(int j=0;j<=max_bag;j++)
        {
            dp[i][j]=dp[i+1][j];
            if(j-weight[i]>=0)
            {
                dp[i][j]=max(dp[i][j],dp[i][j-weight[i]]+costs[i]);
            }
        }
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<=max_bag;j++)
        {
            printf("%3d ",dp[i][j]);
        }
        printf("\n");
    }
    vector<int> res(row,0);
    int r=0;
    int c=max_bag;
    while(r<row)
    {
        while(dp[r][c]==dp[r][c-weight[r]]+costs[r])
        {
            res[r]++;
            c=c-weight[r];
        }
        r++;
    }
    for(int i=0;i<row;i++)
    {
        printf("%3d ",res[i]);
    }
    printf("\n");
    return dp[0][max_bag];

}

/***************************************************
*  �������ܣ����ر�������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N*M)���ռ临�Ӷȣ�O(N*M)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-15-16.24
***************************************************/
int Bag_Quistion::get_MAX_value_Limitnum(vector<int> weight,vector<int> costs,vector<int> number,int max_bag)
{
    if(weight.size()<1 || costs.size()<1 || number.size()<1 || max_bag<1 || weight.size()!=costs.size() || weight.size()!=number.size() || costs.size()!=number.size())
        return 0;
    int row=weight.size();
    vector<vector<int> > dp(row+1,vector<int>(max_bag+1,0));
    for(int i=row-1;i>=0;i--)
    {
        for(int j=0;j<=max_bag;j++)
        {
            dp[i][j]=dp[i+1][j];
            if(j-weight[i]>=0)
            {
                int counts=min(number[i],j/weight[i]);
                for(int k=1;k<=counts;k++)
                {
                    dp[i][j]=max(dp[i][j],dp[i+1][j-weight[i]*k]+k*costs[i]);
                }
            }
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<=max_bag;j++)
        {
            printf("%3d ",dp[i][j]);
        }
        printf("\n");
    }
    vector<int> res(row,0);
    int r=0;
    int c=max_bag;
    while(r<row)
    {
        int counts=min(number[r],c/weight[r]);
        for(int k=counts;k>0;k--)
        {
            if(dp[r][c]==(dp[r+1][c-weight[r]*k]+k*costs[r]))
            {
                res[r]=k;
                c=c-weight[r]*k;
                break;
            }
        }
        r++;
    }
    for(int i=0;i<row;i++)
    {
        printf("%3d ",res[i]);
    }
    printf("\n");
    return dp[0][max_bag];
}
