#include <bits/stdc++.h>
using namespace std;

const int mod=10007;

int main(){
    int T; scanf("%d",&T);

    for(int cas=0;cas<T;cas++){
        int a,b,k,n,m;
        long long int an=1,bm=1, ans;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        int i=0,j=0;
        long long int dp[1001][1001]; //memset(dp,'\0',sizeof(dp));
        dp[0][0]=1;
        for(i=1;i<1001;i++){dp[i][0]=1; dp[i][1]=i; }
        for(i=1,j=1;i<1001&&j<1001;i++,j++){
            if(i==j) dp[i][j]=1;
        }
        for(i=2;i<1001;i++){
            for(j=1;j<=i;j++){
                if(i>=j) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }
        for(i=0;i<n;i++) an=(an*a)%mod;
        for(i=0;i<m;i++) bm=(bm*b)%mod;
        ans=(((dp[k][n]*an)%mod)*bm%mod);
        printf("case #%d:\n%ld\n",cas,ans);
    }
    return 0;
}
