#include <iostream>
#include <string>
#include "My_Class1.h"
#include "My_Class2.h"
#include "Help.h"




using namespace std;

int main()
{
    MAX_WINDOW zgl;
    MIN_WINDOW zgl1;
    generate_Vector data;

    for(int j=0;j<10;j++)
    {
        vector<int>  nums=data.generate_Random_Vector(10,3,10);
        int w=3;
        vector<int>  res=zgl.get_MAX_Window(nums,w); //生成窗口最大值数组
        vector<int>  res1=zgl1.get_Min_Window(nums,w); // 生成窗口最小值数组
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<"  ";
        }
        cout<<endl;
        for(int i=0;i<res1.size();i++)
        {
            cout<<res1[i]<<"  ";
        }
        cout<<endl;
        cout<<"-------------------------------"<<endl;
    }

    return 0;
}
