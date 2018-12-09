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
    vector<int> get_MAX_Window(vector<int> num,int w); //���ɴ������ֵ����
};

class MIN_WINDOW
{
public:
    vector<int> get_Min_Window(vector<int> num,int w); // ���ɴ�����Сֵ����
};

class get_Num
{
public:
    int get_sub_MIN_MAX_Num(vector<int> num,int delta); // ���ֵ��ȥ��СֵС�ڻ����delta������������ ʱ�临�Ӷ�O(N)
    int get_sub_MIN_MAX_Num1(vector<int> num,int delta);// ���ֵ��ȥ��СֵС�ڻ����delta������������ ʱ�临�Ӷ�O(N^3)
private:
    bool  isValid(vector<int> num,int L,int R,int delta);
};

class get_Area
{
public:
    int get_sub_MAX_Area(vector<vector<int> > area);  // ��ȡ����Ӿ���Ĵ�С
private:
    int get_MAX_Area(vector<int> num);
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
//        vector<int>  res=zgl.get_MAX_Window(nums,w); //���ɴ������ֵ����
//        vector<int>  res1=zgl1.get_Min_Window(nums,w); // ���ɴ�����Сֵ����
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



//int main()
//{
//    get_Num zgl;
//    generate_Vector data;
//    bool flag=true;
//    for(int j=0;j<2;j++)
//    {
//        vector<int>  num=data.generate_Random_Vector(6,3,10);
//        int delta=3;
//        int res=zgl.get_sub_MIN_MAX_Num(num,delta);
//        int res1=zgl.get_sub_MIN_MAX_Num1(num,delta);
//        if(res!=res1)
//        {
//            cout<<"error"<<endl;
//            flag=false;
//            break;
//        }else
//        {
//            cout<<"delta :"<<delta<<"  res:"<<res<<endl;
//        }
//    }
//    if(flag)
//    {
//        cout<<"ok"<<endl;
//    }
//    return 0;
//}


#endif // MY_CLASS2_H_INCLUDED
