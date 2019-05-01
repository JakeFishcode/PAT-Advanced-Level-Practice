#include <iostream>
using namespace std;
int main()
{
    int now=0,mubiao=0,sum=0,N=0;
    cin >>N;
    for(int i=0;i<N;i++)
    {
        cin >> mubiao;
        if(mubiao>now) sum += (mubiao-now)*6 + 5;
        else sum += (now-mubiao)*4 + 5;
        now = mubiao;
    }
    cout << sum;
    return 0;
}