#ifndef MY_CLASS1_H_INCLUDED
#define MY_CLASS1_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>


using namespace std;

//int main()
//{
//    Manacher zgl;
//    string str1="";
//    string str2="zglcsuuscshow";
//    string str3="234xkddkx4xsladoe";
//    cout<<str1<<endl;
//    cout<<zgl.huiwen(str1)<<endl;
//    cout<<str2<<endl;
//    cout<<zgl.huiwen(str2)<<endl;
//    cout<<str3<<endl;
//    cout<<zgl.huiwen(str3)<<endl;
//    string str4 = "12";
//    cout<<str4<<endl;
//    cout<<zgl.all_huiwen(str4)<<endl;
//    return 0;
//}
class Manacher    // ��������
{
public:
    int huiwen(string str); // ������ַ����ĳ���
    string all_huiwen(string str);  // ����һ���ַ�����ʹ���Ϊ�����ַ���
private:
    string manacher_str(string str);

};


#endif // MY_CLASS1_H_INCLUDED
