#include<bits/stdc++.h>
using namespace std;

const int N=1000000;
const int MOD=1000000007;

int C[N][N];
void init(){
    for(int i=0;i<N;i++){
        C[i][0]=1; C[i][i]=1; C[i][1]=i;
    }
    for(int i=2;i<N;i++){
        for(int j=2;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
    return;
}

int main(){
    init();
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int a,b,k,n,m; scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        long long ans=1;
        for(int i=0;i<n;i++) ans=(ans*a)%MOD;
        for(int i=0;i<m;i++) ans=(ans*b)%MOD;
        ans=(ans*C[k][m])%MOD;
        printf("case #%d:\n%d\n",cas,ans);
    }
    return 0;
}
