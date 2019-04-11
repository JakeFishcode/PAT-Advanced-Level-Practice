#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    vector<char> input_line;
    int sum=0,temp=0;
    while(temp!='\n')
    {
        temp=cin.get();
        //cout <<temp<<" ";
        sum += (temp-48);
        //input_line.push_back(temp);
    }
    sum+=38;
    string str_sum=to_string(sum);
    cout <<str[str_sum[0]-48];
    for(int i=1;i<str_sum.length();++i)
    {
        cout <<" "<<str[str_sum[i]-48];
    }

    return 0;
}