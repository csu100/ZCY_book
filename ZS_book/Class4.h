#ifndef CLASS4_H_INCLUDED
#define CLASS4_H_INCLUDED


#include <stack>
#include <vector>
#include <deque>
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;


class Class4_N1
{
public:
    int fibona(int n);
    int setp_num(int n);
    int cow_num(int n);

};


class Class4_N2  // 最长公共子序列
{
public:
    string lcse(string str1,string str2);

private:
    vector<vector<int> > getDP(string str1,string str2);
};

class Class4_N3  // 最长公共子串
{
public:
    string lcst1(string str1,string str2);

private:
    vector<vector<int> > getDP(string str1,string str2);
};


#endif // CLASS4_H_INCLUDED
