#include <iostream>
#include <vector>
using namespace std;
int MaxSubseqSum(vector<int> data,int &be,int &en)
{
    int ThisSum, MaxSum,temp,j,zf=0;
    ThisSum=MaxSum=0;
    be+=1;
    for(int i=0;i<data.size();i++)
    {
        if(data[i]<0) zf++;

        ThisSum+=data[i];
        if(ThisSum>MaxSum)
        {
            
            MaxSum=ThisSum;
            en =i;
        }
        else if(ThisSum<0)
        {
            ThisSum=0;
            
        }

    }
    temp=0;
    j=en;
    while(temp!=MaxSum)
    {
        temp+=data[j];
        j--;
    }
    be=j+1;
    if(zf==data.size())
    {
        be=0;
        en=data.size()-1;
        MaxSum=0;
        return MaxSum;    
    }
    if(MaxSum==0)
    {
        be=0;
        while(data[be]!=0)
            be++;
        en=be;
        MaxSum=0;
    }
    return MaxSum;
}
int main()
{
    int num,temp,sum,be,en;
    vector<int> data;
    cin >> num;
    getchar();

    for(int i=0;i<num;i++)
    {
        cin >> temp ;
        data.push_back(temp);
        getchar();
    }
   sum = MaxSubseqSum(data,be,en);
   cout << sum <<" "<<data[be]<<" "<<data[en];

    
    return 0;
}