#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=0,x=0,y=0,i=0,j=0,tmp=0;
    long long ans=0;
    scanf("%d",&n);
    long long row[n+1], col[n+1], right[2*n], left[2*n];
    memset(row,0,sizeof(row)); memset(col,0,sizeof(col));
    memset(right,0,sizeof(right)); memset(left,0,sizeof(left));
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        row[x]++; col[y]++;
        right[x-y+n]++; left[x+y-1]++;
    }
    for(i=1;i<=n;i++){
        if(row[i]>0) ans+=((row[i]-1)*row[i])/2;
        if(col[i]>0) ans+=((col[i]-1)*col[i])/2;
    }

    for(i=1;i<2*n;i++){
        if(right[i]>0) ans+=(right[i]*(right[i]-1))/2;
        if(left[i]>0) ans+=(left[i]*(left[i]-1))/2;
    }

    printf("%lld\n",ans);
    return 0;
}
