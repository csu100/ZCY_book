#ifndef MY_CLASS2_H_INCLUDED
#define MY_CLASS2_H_INCLUDED

#include <vector>
#include <string>
#include <queue>
#include <stack>


using namespace std;

class MAX_WINDOW
{
public:
    vector<int> get_MAX_Window(vector<int> num,int w); //生成窗口最大值数组
};

class MIN_WINDOW
{
public:
    vector<int> get_Min_Window(vector<int> num,int w); // 生成窗口最小值数组
};

class get_Num
{
public:
    int get_sub_MIN_MAX_Num(vector<int> num); // 最大值减去最小值小于或等于num的子数组数量
};









//int main()
//{
//    MAX_WINDOW zgl;
//    MIN_WINDOW zgl1;
//    generate_Vector data;
//
//    for(int j=0;j<10;j++)
//    {
//        vector<int>  nums=data.generate_Random_Vector(10,3,10);
//        int w=3;
//        vector<int>  res=zgl.get_MAX_Window(nums,w); //生成窗口最大值数组
//        vector<int>  res1=zgl1.get_Min_Window(nums,w); // 生成窗口最小值数组
//        for(int i=0;i<res.size();i++)
//        {
//            cout<<res[i]<<"  ";
//        }
//        cout<<endl;
//        for(int i=0;i<res1.size();i++)
//        {
//            cout<<res1[i]<<"  ";
//        }
//        cout<<endl;
//        cout<<"-------------------------------"<<endl;
//    }
//
//    return 0;
//}



#endif // MY_CLASS2_H_INCLUDED
