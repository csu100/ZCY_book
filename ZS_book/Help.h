#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED

#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <iostream>
#include "Class2.h"
#include <algorithm>


using namespace std;

class DATA_Generate
{
public:
    vector<int>  generates(int arr[],int len);
    vector<int>  generates(int len);
    LinkNode*   generatess(int len);
    string      generatesstr(int n);
};



#endif // HELP_H_INCLUDED
