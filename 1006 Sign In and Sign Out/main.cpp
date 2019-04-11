#include <iostream>
#include <string>
using namespace std;
struct Time
{
    int hour;
    int minute;
    int second;
};
struct People
{

    string ID_number;
    Time in_time,out_time;
    People* next=NULL;

};
string get_in_ID(People *head)
{
    int min;
    Time zero;
    string num;
    People temp;
    People *pre=NULL;
    pre=head;
    temp=(*pre);
    num=temp.ID_number;
    min = temp.in_time.hour*3600+temp.in_time.minute*60+temp.in_time.second;
    while(pre->next!=NULL)
    {
        pre=pre->next;
        if(min > (pre->in_time).hour*3600+(pre->in_time).minute*60+(pre->in_time).second)
        {
            num=pre->ID_number;
            min=(pre->in_time).hour*3600+(pre->in_time).minute*60+(pre->in_time).second;
        }
        temp =(*pre);
    }
    return num;
}
string get_out_ID(People *head)
{
    int i=0,max;
    Time zero;
    string num;
    People temp;
    People *pre=NULL;
    pre=head;
    temp=(*pre);
    num=temp.ID_number;
    max=temp.out_time.hour*3600+temp.out_time.minute*60+temp.out_time.second;
    if(pre->next==NULL)
    {
        return num;
    }
    while(pre->next!=NULL)
    {

        pre=pre->next;
        if(max < (pre->out_time).hour*3600+(pre->out_time).minute*60+(pre->out_time).second)
        {
            num=pre->ID_number;
            max=(pre->out_time).hour*3600+(pre->out_time).minute*60+(pre->out_time).second;
            //cout <<temp.ID_number<<endl;
        }
    }
    return num;
}

int main()
{
    int num,fu;
    char k;
    Time zero;
    string str;
    People *head;
    People *temp,*pre;
    cin >> num;
    for(int i=0;i<num;i++)
    {
        //cout << i<<endl;
        if(i==0)
        {
            head = new People;
            cin  >>head->ID_number ;cin>>head->in_time.hour>>k>>head->in_time.minute>>k>>head->in_time.second;
            cin  >>head->out_time.hour>>k>>head->out_time.minute>>k>>head->out_time.second;

            getchar();
            pre = head;
            head->next=NULL;

        }
        else
        {
            temp = new People;
            pre->next=temp;
            pre = temp;
            cin >> temp->ID_number ;cin>>temp->in_time.hour>>k>>temp->in_time.minute>>k>>temp->in_time.second;
            cin >> temp->out_time.hour>>k>>temp->out_time.minute>>k>>temp->out_time.second;
            getchar();
            temp->next=NULL;
        }

    }
    cout << get_in_ID(head)<<" "<<get_out_ID(head);

    return 0;
}








