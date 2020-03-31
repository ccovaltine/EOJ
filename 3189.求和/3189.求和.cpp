#include <bits/stdc++.h>
using namespace std;

long long arr[1008],tmp;
long long sum[500008];

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n,m,i,j,num,l,u; scanf("%d%d",&n,&m);
        arr[0]=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&tmp);
            arr[i]=tmp+arr[i-1];
        }
        num=1;
        for(i=0;i<n;i++){
            for(j=i+1;j<=n;j++){
                sum[num++]=arr[j]-arr[i];
            }
        }
        sort(sum+1,sum+num);
        for(i=1;i<num;i++){
            sum[i]+=sum[i-1];
        }
        printf("case #%d:\n",cas);
        for(i=0;i<m;i++){
            scanf("%d%d",&l,&u);
            printf("%lld\n",sum[u]-sum[l-1]);
        }
    }
    return 0;
}

