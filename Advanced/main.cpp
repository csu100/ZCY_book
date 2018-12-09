#include <iostream>
#include <string>
#include "My_Class1.h"
#include "My_Class2.h"
#include "Help.h"




using namespace std;

int main()
{
    get_Area zgl;
    generate_Vector data;
    bool flag=true;
    for(int j=0;j<5;j++)
    {
        vector<vector<int> > area;
        for(int i=0;i<8;i++)
        {
           vector<int>  num=data.generate_Random_Vector(10,0,2);
           area.push_back(num);
        }


        int res=zgl.get_sub_MAX_Area(area);
        cout<<res<<endl;
    }
    if(flag)
    {
        cout<<"ok"<<endl;
    }
    return 0;
}
