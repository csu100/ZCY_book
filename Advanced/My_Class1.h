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
class Manacher    // 回文问题
{
public:
    int huiwen(string str); // 最长回文字符串的长度
    string all_huiwen(string str);  // 输入一个字符串，使其成为回文字符串
private:
    string manacher_str(string str);

};


#endif // MY_CLASS1_H_INCLUDED
