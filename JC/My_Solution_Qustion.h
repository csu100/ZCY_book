#ifndef MY_SOLUTION_QUSTION_H_INCLUDED
#define MY_SOLUTION_QUSTION_H_INCLUDED

#include <vector>
using namespace std;

class MY_Solution
{
public:
    int Small_Sum(vector<int>& nums); //С������

    int NIXU_dui(vector<int>& nums); // ���������

    int MAX_GAP(vector<int>& nums);  //���ڷǱȽϵ���������������ֵ

private:
    int Small_Sum(vector<int>& nums,int L,int R);
    int Merges(vector<int>& nums,int L,int mid,int R);

    int NIXU_dui(vector<int>& nums,int L,int R);
    int Mergess(vector<int>& nums,int L,int mid,int R);

    int tong_pos(int nums,int MIN,int MAX,int length);
};

#endif // MY_SOLUTION_QUSTION_H_INCLUDED
