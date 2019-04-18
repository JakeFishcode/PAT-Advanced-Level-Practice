#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    float data[3][3];
    char temp;
    char result[]={'W','T','L'};
    float dat_result[3]={0};
    char dat_result1[3]={0};
    for(int i=0;i<3;i++)
    {
        cin >> data[i][0] >> data[i][1] >> data[i][2] ;

    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            //cout << data[i][j] <<endl;
            if(data[i][j]>dat_result[i])
            {
                dat_result[i]=data[i][j];
                dat_result1[i]=result[j];
            }
        }
    }
    cout << dat_result1[0]<<" "<<dat_result1[1]<<" "<<dat_result1[2];

    printf(" %.2f",(dat_result[0]*dat_result[1]*dat_result[2]*0.65-1)*2);
    
    
    return 0;
}