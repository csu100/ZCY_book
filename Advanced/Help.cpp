#include "Help.h"


vector<int> generate_Vector::generate_Random_Vector(int n,int L,int R)
{
    if(n<1)
    {
        vector<int> res;
        return res;
    }
    vector<int> res(n,0);
    for(int i=0;i<n;i++)
    {
        int temp=(rand()%(R-L))+L;
        res[i]=temp;
        cout<<temp<<"  ";
    }
    cout<<endl;
    return res;
}
vector<int> generate_Vector::generate_Vectors(int arr[],int n)
{
    if(arr==nullptr || n<1)
    {
        vector<int> res;
        return res;
    }
    vector<int> res(n,0);
    for(int i=0;i<n;i++)
    {
        res[i]=arr[i];
        cout<<res[i]<<"  ";
    }
    cout<<endl;
    return res;
}

