
#include "My_Class1.h"



/*********************************************
*�������ܣ������ַ����ĳ���
*����˵��
*    ���룺"abccdxs"
*    �����2   //"cc"
*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷ� O(n)
*��Ŀ��Դ��
*���ߣ�guoliang zheng
*���ڣ�2018-12-05-21.51
***********************************************/
int Manacher::huiwen(string str)
{
    if(str.size()<2) return str.size();
    string new_str=manacher_str(str);
    int len=new_str.size();
    vector<int> pA(len,0);

    int R=-1;
    int index=-1;
    int MAX_R=0;
    int pos=0;
    for(int i=0;i<len;i++)
    {
        pA[i]=R>i?min(pA[2*index-i],R-i):1;
        while(i+pA[i]<len && i-pA[i]>-1)
        {
            if(new_str[i+pA[i]]!=new_str[i-pA[i]])
            {
                break;
            }
            pA[i]++;
        }
        if(pA[i]+i>R)
        {
            R=i+pA[i];
            index=i;
        }
        if(MAX_R<pA[i])
        {
            MAX_R=pA[i];
            pos=i;
        }
    }
    MAX_R--;

    cout<<str.substr((pos-MAX_R)/2,MAX_R)<<endl;
    return MAX_R;
}

string Manacher::manacher_str(string str)
{
    string res="";
    for(int i=0;i<str.size();i++)
    {
        res+='#';
        res+=str[i];
    }
    res+='#';
    return res;
}

string Manacher::all_huiwen(string str)
{
    if(str.size()<2) return "";

    string new_str=manacher_str(str);
    int len=new_str.size();
    vector<int> pA(len,0);
    int R=-1;
    int index=-1;
    int maxR=0;
    int pos=0;
    for(int i=0;i<len;i++)
    {
        pA[i]=R>i?min(pA[2*index-i],R-i):1;
        while(i+pA[i]<len && i-pA[i]>-1)
        {
            if(new_str[i+pA[i]]!=new_str[i-pA[i]])
            {
                break;
            }
            pA[i]++;
        }
        if(i+pA[i]>R)
        {
            R=i+pA[i];
            index=i;
        }
        if(R==len)
        {
           maxR=pA[i]-1;
           pos=i;
           break;
        }
    }
    string res="";
    for(int i=(pos-maxR)/2-1;i>-1;i--)
    {
        res+=str[i];
    }
    return res;
}







