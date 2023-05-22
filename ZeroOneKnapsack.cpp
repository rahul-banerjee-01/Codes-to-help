#include<bits/stdc++.h>
using namespace std;
#define MAX 100


int KS(int n,int C, int weight[], int value[],int DP[][MAX])
{
    if (n==-1) return 0;
    if (weight[n]>C) DP[n][C] = KS(n-1,C,weight,value,DP);
    else if (DP[n][C]==-1)
    {
        int profit_with_item = value[n]+KS(n-1,C-weight[n],weight,value,DP);
        int profit_without_item = KS(n-1,C,weight,value,DP);

        DP[n][C] = max(profit_with_item,profit_without_item);
    }
    return DP[n][C];
}

main()
{
    int N,C;
    cin>>N>>C;
    int weight[N]={0};
    int value[N]={0};
    int DP[MAX][MAX];
    memset(DP,-1,sizeof(DP));
    
    for(int i=0;i<N;i++)
    {
        int w,v;
        cin>>w>>v;
        weight[i] = w;
        value[i] = v;
    }

    cout<<endl<<endl<<KS(N-1,C,weight,value,DP);

}