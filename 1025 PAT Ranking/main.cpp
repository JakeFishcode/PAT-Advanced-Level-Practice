#include <iostream>
#include <string>
#include <map>
using namespace std;
struct DATA
{
    string number;
    int score;
    int location_number;
    int local_rank;
    int final_rank;
};
void Q_sort(DATA *temp,int size);
void give_local_rank(DATA *temp,int num,int size);
void give_final_rank(DATA *temp,int num,int size);
int main()
{
    int N[100];
    int K;
    int count = 0,ln=0,count_2;
    DATA data[300];
    cin >> K;
    for(int i=0;i<K;i++)
    {
        cin >> N[i];
        ln++;
        for(int j=0;j<N[i];j++)
        {
            
            cin >> data[count].number;
            cin >> data[count].score;
            data[count].location_number = ln;
            count++;

        }
    }
    //cout << "------------"<<endl<<endl;

    count_2=0;
    for(int i=0;i<K;i++)
    {
        Q_sort(&data[count_2],N[i]);
        //cout << "cout_2:"<<count_2<<endl;
        for(int j=0;j<K;j++)
        {
            give_local_rank(&data[count_2],0,N[i]);   
        }
        count_2+=N[i];
    }
    Q_sort(&data[0],count);
    give_final_rank(&data[0],0,count);
    cout<<count<<endl;
    for(int i=0;i<count;i++)
    {
        cout << data[i].number <<" "<<data[i].final_rank<<" "<<data[i].location_number
            <<" "<<data[i].local_rank<<endl;
    }
    return 0;
}
int get_CD(DATA *temp,int N,int num)
{

    if (temp[num].score==temp[num+1].score)
    {
        N=get_CD(temp,N+1,num+1);
    }
    else
    {
        return N;
    }
    return N;
    
    
}
void give_local_rank(DATA *temp,int num,int size)
{
    int N=0 ;
    for(int i=0;i<size;i++)
    {
        N=get_CD(temp,0,i);
        //cout << N << endl;
        temp[num+i].local_rank=i+1;
        for (int j = 0; j < N; j++)
        {
            temp[num+i+j+1].local_rank=i+1;
        }
        
        i+=N;
    }

}
void Q_sort(DATA *temp,int size)
{
    DATA T;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(temp[j].score<temp[j+1].score)
            {
                T=temp[j];
                temp[j]=temp[j+1];
                temp[j+1]=T;
            }
        }
    }
}
void give_final_rank(DATA *temp,int num,int size)
{
    int N=0,T=0;
    for(int i=0;i<size;i++)
    {
        N=get_CD(temp,0,i);
        temp[num+i].final_rank=i+1;
        for (int j = 0; j < N; j++)
        {
            temp[num+i+j+1].final_rank=i+1;
        }
        i+=N;
        //cout <<" i:"<<i<<endl;
    }

}