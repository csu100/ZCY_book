#include "Class5.h"


/***************************************************
*  �������ܣ����һ��RandomPool�ṹ���ȸ���������ؽṹ�е�һ���κ�һ��key��
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(1)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-08.53
***************************************************/
void RandomPool::Insert(string key)
{
    str_map[key]=size;
    int_map[size]=key;
    size++;
}
void RandomPool::Delete(string key)
{
    if(size==0)
    {
        cout<<"RandomPool is empty"<<endl;
    }
    int changed_index=str_map[key];
    string last_str=int_map[--size];
    str_map.erase(key);
    int_map.erase(size);
    str_map[last_str]=changed_index;
    int_map[changed_index]=last_str;
}
string RandomPool::GetRandom()
{
    if(size==0)
    {
        cout<<"RandomPool is empty"<<endl;
        return "";
    }
    int temp=rand()%size;
    return int_map[temp];
}

void RandomPool::Print_Random()
{
    cout<<"size :"<<int_map.size()<<"  "<<str_map.size()<<endl;
    for(auto it=int_map.begin();it!=int_map.end();it++)
    {
        cout<<"int_map : index "<<it->first<<" string: "<<it->second<<" || str_map :vaule "<<str_map[it->second]<<endl;
    }
}

/***************************************************
*  �������ܣ���������
*  ����˵��
*       ���������
*       ���������
*  �����Է�����ʱ�临�Ӷȣ�O(N*M)���ռ临�Ӷȣ�O(1)
*  ��Ŀ��Դ  ��
*  ���ߣ�guoliang zheng
*  ���ڣ�2018-08-14-08.53
***************************************************/
int IsLands::LandsNumber(vector<vector<int> >& land)
{
    if(land.size()<1) return 0;
    int result=0;
    for(int i=0;i<land.size();i++)
    {
        for(int j=0;j<land[0].size();j++)
        {
            if(land[i][j]==1)
            {
                result++;
                LandsNumber(land,i,j);
            }
        }
    }
    return result;
}

void IsLands::LandsNumber(vector<vector<int> >& land,int x,int y)
{
    land[x][y]=2;
    const int dx[]={-1,1,0,0};
    const int dy[]={0,0,-1,1};
    for(int i=0;i<4;i++)
    {
        int new_x=x+dx[i];
        int new_y=y+dy[i];
        if(new_x<0 || new_x>=land.size() || new_y<0 || new_y>=land[0].size())
        {
            continue;
        }
        if(land[new_x][new_y]==1)
        {
            LandsNumber(land,new_x,new_y);
        }
    }
}






int Class5_N6::find_(int p)
{
    if(p>=_id.size())
    {
        throw "error";
    }
    while(p!=_id[p])
    {
        _id[p]=_id[_id[p]];
        p=_id[p];
    }
    return p;
}
void Class5_N6::union_(int p,int q)
{
    int i=find_(p);
    int j=find_(q);
    if(i==j)
    {
        return ;
    }
    if(_size[i]<_size[j])
    {
        _id[i]=j;
        _size[j]+=_size[i];
    }else
    {
        _id[j]=i;
        _size[i]+=_size[j];
    }
    _count--;
}

void Class5_N6::print_set()
{
    printf("Ԫ�أ�");
    for(int i=0;i<_id.size();i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    printf("���ϣ�");
    for(int i=0;i<_id.size();i++)
    {
        printf("%d ",_id[i]);
    }
    printf("\n");
    printf("���ϸ�����%d\n",_count);
}






