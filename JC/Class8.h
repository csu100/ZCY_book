#ifndef CLASS8_H_INCLUDED
#define CLASS8_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <stack>

using namespace std;

// 1
class Factorial  // ��N��// 1
{
public:
    long jiecheng(int n);
    long jiecheng_DG(int n);
};

// 2
class Hanoi // ��ŵ������ //2
{
public:
    void Hanois(int n);
private:
    void Hanois(int down,int n,string From,string To,string Help);
};

// 3
class Print_All_Subsquences // ��ȡһ���ַ�����ȫ�������У��������ַ��� // 3
{
public:
    vector<string> Get_All_Subsquence(string str);
private:
    void Get_All_Subsquence(vector<string>& result,int i,string str,string word);
};

// 4
class Print_ALL_Permutation  // ��ȡһ�������ַ�����ȫ����  // 4
{
public:
    vector<string> Get_ALL_Permutation(string str); // ��ȡһ���ַ�����ȫ������
    vector<string> Get_ALL_NoPermutation(string str); // ��ȡһ���ַ�����ȫ�����У�Ҫ�󲻳����ظ�������

private:
    void Get_ALL_Permutation(vector<string>& result,string& str,int n);
    void Get_ALL_NoPermutation(vector<string>& result,set<string>& item,string& str,int n);
};

// 5
class Cow_NUMBER   // ��ĸţ���� // 5
{
public:
    int Get_Cow_Number(int n);
    int Get_Cow_Number_Advance(int n);
};

// 6
class ReverseStack  // ����ջ���������������ݽṹ ֻ�õݹ� // 6
{
public:
    void ReverseStacks(stack<int>& S);
private:
    int Reverse(stack<int>& S);
};

// 7
class MinPath  // ���·���� // 7
{
public:
    int get_MinPath(vector<vector<int> > path);
    int get_DGMinPath(vector<vector<int> > path);
private:
    int get_DGMinPath(vector<vector<int> >& path,int x,int y);
};

// 8
class Arr_Aim //����һ������arr����һ������aim������ѡ��arr�е����֣��Ƿ��ܹ��ۼӵõ�aim������true or false; //8
{
public:
    bool is_Sum_Aim(vector<int> arr,int aim);
    bool is_Sum_Aim_DG(vector<int> arr,int aim);
private:
    bool is_Sum_Aim_DG(vector<int> arr,int aim,int sum,int n);
};

// 9
class Bag_Quistion  // �������� // 9
{
public:
    int get_MAX_value(vector<int> weight,vector<int> costs,int max_bag);// 0/1�������⣬��Ʒ����Ϊ1
    int get_MAX_value_DG(vector<int> weight,vector<int> costs,int max_bag);
    int get_MAX_value_Complete(vector<int> weight,vector<int> costs,int max_bag);//��ȫ��������,��Ʒ��������
    int get_MAX_value_Limitnum(vector<int> weight,vector<int> costs,vector<int> number,int max_bag); // ���ر������⣬��Ʒ��������
private:
    int get_MAX_value_DG(vector<int> weight,vector<int> costs,int max_bag,int i,int allget);
};





#endif // CLASS8_H_INCLUDED
