#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=10001;
struct Pel
{
    char name[10];
    int re,no;
};
int c;
int cmp1(Pel a, Pel b) {
    if(c == 1) {
        return a.no < b.no;
    } else if(c == 2) {
        if(strcmp(a.name, b.name) == 0) return a.no < b.no;
        return strcmp(a.name, b.name) <= 0;
    } else {
        if(a.re == b.re) return a.no < b.no;
        return a.re <= b.re;
    }
}
int main()
{
    Pel pel[maxn];
    int n,i;
    cin >> n >> c;
    for(i=0;i<n;i++)
        scanf("%d %s %d",&pel[i].no,pel[i].name,&(pel[i].re));
    sort(pel, pel + n, cmp1);
    for(int j=0;j<n;j++)
        printf("%06d %s %d\n",pel[j].no,pel[j].name,pel[j].re);
    return 0;
}