#include <iostream>
#include <string>
#include <math.h>
using namespace std;

long long int us_tag(string N,int radix,int max)
{
    long long int sum=0;
    if(radix>max || radix<22)
    {
        //return 0;
    }
    for(int i=0;i<N.size();i++)
    {
        if(N[i]<58&&N[i]>47)
            sum += (N[i]-48)*pow(radix,N.size()-i-1);
        else if(N[i]>96&&N[i]<122)
            sum += (N[i]-96+9)*pow(radix,N.size()-i-1);
    }

    return sum;
}
long long int re_radix(string N,int num)
{
    int max;
    for(int i=0;i<N.size();i++)
    {
        if(max<N[i])
            max=N[i];  
    }
    if(max<58) max-=48;
    else max=max-96+9;

    for(int i=1;i<36;i++)
    {
        if(us_tag(N,i,max)==num)
        {
            if(max >= i) continue; 
            return i;
        }
    }
    return 0;
}
int main()
{
    string N[2];
    int tag,radix;
    long long sum;
    cin >> N[0] >> N[1] >> tag >> radix;
    sum= re_radix(N[2-tag],us_tag(N[tag-1],radix,35));
    if(sum==0)
        cout <<"Impossible";
    else 
        cout << sum;

    return 0;
}