#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    const string _13="0123456789ABC";
    int num[3],i;
    string result="#000000";

    for(i=0;i<3;i++)
        cin >> num[i];

    for(i=0;i<3;i++)        
    {
        result[2*(i+1)-1]=_13[num[i]/13];
        result[2*(i+1)]=_13[num[i]%13];
    }
    
    cout << result; 

    return 0;
}