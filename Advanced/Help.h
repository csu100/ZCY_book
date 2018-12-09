#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED

#include <vector>
#include <math.h>
#include <iostream>



using namespace std;

class generate_Vector
{
public:
    vector<int>  generate_Random_Vector(int n,int L=0,int R=100);
    vector<int>  generate_Vectors(int  arr[],int n);
};

#endif // HELP_H_INCLUDED
