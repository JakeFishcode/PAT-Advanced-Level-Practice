#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
int main()
{
    int M,N,K,temp;
    char tm;
    cin >> M >> N >> K;
    int num[N];
    int flag[K]={0};
    for(int i = 0,k =0; i < K; i++)
    {
        k=0;
        for(int j=0;j<N;j++)
            scanf("%d",&num[j]);
        //for(int j=0;j<N;j++)
            //printf("num = %d\n",num[j]);           
        stack<int> st,n_st;
        while(!n_st.empty()) n_st.pop();
        while(!st.empty()) st.pop();
        for(int i = 0; i <N ; i++)
            n_st.push(N-i);
        while(!n_st.empty() || !st.empty())
        {
            while(st.top()!=num[k] && n_st.empty() == 0)
            {
                temp=n_st.top();
                n_st.pop();
                st.push(temp);
            }
            if(st.size()>M)
            {
                flag[i]=1;
                break;
            }
            st.pop();
            k++;
        }

    }       
    for(int i=0;i<K;i++)
        {
            if(flag[i]==1)
                cout << "NO"<<endl;
            else
            {
                cout << "YES"<<endl;
            }
            
        }

    return 0;
}
