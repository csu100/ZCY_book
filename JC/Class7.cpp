#include "Class7.h"

/***************************************************
*  �������ܣ�ǰ׺�������������룬ɾ������ѯ����ȡȫ��Ԫ�أ�
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O()���ռ临�Ӷȣ�O()
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-15.40
***************************************************/
void TrieTree::Insert(string word)
{
    if(word.size()<1) return ;
    TrieNode* node=&_root;
    for(int i=0;i<word.size();i++)
    {
        int index=word[i]-'a';
        if(node->next[index]==0)
        {
            node->next[index]=new_node();
        }
        node=node->next[index];
        node->path++;
    }
    node->ends++;
}
int TrieTree::Search(string word)
{
    if(word.size()<1) return 0;
    TrieNode* node=&_root;
    for(int i=0;i<word.size();i++)
    {
        int index=word[i]-'a';
        if(node->next[index]->path==0)
        {
            return 0;
        }
        node=node->next[index];
    }
    return node->ends;
}
int TrieTree::preFixNumber(string word)
{
    if(word.size()<1) return 0;
    TrieNode* node=&_root;
    for(int i=0;i<word.size();i++)
    {
        int index=word[i]-'a';
        if(node->next[index]->path==0)
        {
            return 0;
        }
        node=node->next[index];
    }
    return node->path;
}
void TrieTree::Delete(string word)
{
    if(word.size()<1) return ;
    if(Search(word))
    {
        TrieNode* node=&_root;
        for(int i=0;i<word.size();i++)
        {
            int index=word[i]-'a';
            if(--(node->next[index]->path)==0)
            {
                node->next[index]=0;
                node->next[index]->ends=0;
                return ;
            }
            node=node->next[index];
        }
        node->ends--;
    }
}


vector<string> TrieTree::get_ALL_word(void)
{
    vector<string> result;
    string word="";
    TrieNode* node=&_root;
    get_ALL_word(result,word,node);
    return result;
}

void TrieTree::get_ALL_word(vector<string>& result,string& word,TrieNode* root)
{
    for(int i=0;i<26;i++)
    {
        if(root->next[i])
        {
            word+=char(i+'a');
            if(root->next[i]->ends)
            {
                for(int k=0;k<(root->next[i]->ends);k++)
                {
                    result.push_back(word);
                }
            }
            get_ALL_word(result,word,root->next[i]);
            word.erase(word.size()-1,1);
        }
    }
}



/***************************************************
*  �������ܣ����������⣬ һ������з�Ϊ2�룬��Ҫ���Ѻͳ���һ����ͭ�壬���طָ������С������С����
*  ����˵��
*       ���������{6, 7, 8, 9}
*       ���������{60}
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-15.40
***************************************************/
int Less_Money::get_Less_Money(vector<int>& nums)
{
    if(nums.size()<2) return 0;
    priority_queue<int,vector<int>,greater<int> > Q;
    for(int i=0;i<nums.size();i++)
    {
        Q.push(nums[i]);
    }
    int result=0;
    while(Q.size()>1)
    {
        int a=Q.top();
        Q.pop();
        int b=Q.top();
        Q.pop();
        a=a+b;
        result+=a;
        Q.push(a);
    }
    return result;
}

class LESS
{
public:
    bool operator() (const pair<int,int>& a,const pair<int,int>& b)
    {
        return a.first>b.first;  //�Ӵ�С ���Ӷ���֤С����
    }
};
class MORE
{
public:

    bool operator() (const pair<int,int>& a,const pair<int,int>& b)
    {
        return a.second<b.second;// ��С����  //�Ӷ���֤�����
    }
};

/***************************************************
*  �������ܣ���õ����Ǯ��
*  ����˵��
*       ���������  int cost[]={100,120,200,250,500};
                    int profit[]={10,23,43,25,60};
                    int W=120;
                    int k=3;
*       ���������  153
*  �����Է�����ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-15.40
***************************************************/
int Cost_Profit::get_Most_Money(vector<int>& costs,vector<int>& profits,int k,int W)
{
    if(costs.size()<1 || profits.size()<1 || k<1 || W<1) return 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,MORE> MAX_Q;    //profits
    priority_queue<pair<int,int>,vector<pair<int,int> >,LESS> MIN_Q; // costs;
    for(int i=0;i<costs.size();i++)
    {
        MIN_Q.push(make_pair(costs[i],profits[i]));
    }
    while(k>0)
    {
        while(!MIN_Q.empty() && ((MIN_Q.top()).first <= W))
        {
            MAX_Q.push(MIN_Q.top());
            MIN_Q.pop();
        }
        if(MAX_Q.empty())
        {
            return W;
        }
        W+=MAX_Q.top().second;
        MAX_Q.pop();
        k--;
    }
    return W;
}


/***************************************************
*  �������ܣ�һ���������У���ʱ����ȡ����λ��
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(1)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-16.50
***************************************************/
void MadianQuick::Insert(int value)
{
    if(MAX_Q.empty())
    {
        MAX_Q.push(value);
        return ;
    }
    if(MAX_Q.size()==MIN_Q.size())
    {
        if(MAX_Q.top()>value)
        {
            MAX_Q.push(value);
        }else
        {
            MIN_Q.push(value);
        }
    }else if(MAX_Q.size() > MIN_Q.size())
    {
        if(MAX_Q.top()>value)
        {
            MIN_Q.push(MAX_Q.top());
            MAX_Q.pop();
            MAX_Q.push(value);
        }else
        {
            MIN_Q.push(value);
        }
    }else
    {
        if(MIN_Q.top()<value)
        {
            MAX_Q.push(MIN_Q.top());
            MIN_Q.pop();
            MIN_Q.push(value);
        }else
        {
            MAX_Q.push(value);
        }
    }
}
double MadianQuick::get_Media()
{
    if(MIN_Q.size()==0 && MAX_Q.size()==0) return 0.0;
    if(MIN_Q.size()==MAX_Q.size())
    {
        return (MIN_Q.top()+MAX_Q.top())/2.0;
    }else if(MIN_Q.size()>MAX_Q.size())
    {
        return MIN_Q.top();
    }else
    {
        return MAX_Q.top();
    }
}


bool str_cmp(const string& a,const string& b)
{
    return (a+b)<(b+a);
}
/***************************************************
*  �������ܣ�����һ���ַ������飬ʹ��ƴ�Ӻ��γɵ��ַ���������͵��ֵ���
*  ����˵��
*       ���������"ba", "b"
*       ���������"bab"
*  �����Է�����ʱ�临�Ӷȣ�O(NlogN)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-16.50
***************************************************/
string LowestLexigrahy::LowestString(vector<string> str)
{
    if(str.size()<1) return "";
    string result;
    sort(str.begin(),str.end(),str_cmp);
    for(int i=0;i<str.size();i++)
    {
        result+=str[i];
    }
    return result;
}


/***************************************************
*  �������ܣ�һЩ��Ŀռ��һ�������ң�����������������
*  ����˵��
*       ���������times:��ʼʱ��ͽ���ʱ�䣬starts:��ʼʱ��
*       �����������ೡ��
*  �����Է�����ʱ�临�Ӷȣ�O(NlogN)���ռ临�Ӷȣ�O(N)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-17.23
***************************************************/
bool Arrage_CMP(const pair<int,int>& a,const pair<int,int>& b)
{
    return a.second<b.second; //��С����
}

int BestArrage::get_BestArrage(vector<int> times,int starts)
{
    if(times.size()<2 || times.size()%2!=0) return 0;
    vector<pair<int,int> > Arrage;
    for(int i=0;i<times.size();i+=2)
    {
        Arrage.push_back(make_pair(times[i],times[i+1]));
    }
    sort(Arrage.begin(),Arrage.end(),Arrage_CMP);
    int result=0;
    for(int i=1;i<Arrage.size();i++)
    {
        if(Arrage[i].first>=starts)
        {
            result++;
            starts=Arrage[i].second;
        }
    }
   return result;
}






