#include <bits/stdc++.h>
using namespace std;

const int mod=1000000007;

int num_of_1(int num){//如果num的二进制表示中有m个1，则返回true
    int cnt=0;
    for(int k=0;k<32;k++){
        if((num&(1<<k))!=0) cnt++;
    }
    return cnt;
}

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n,m,i,j,k=1,tmp=0; scanf("%d%d",&n,&m);
        int a[n]; for(i=0;i<n;i++) scanf("%d",&a[i]);
        long long ans=0;
        k=pow(2,n);
        for(i=0;i<k;i++){
            if((num_of_1(i))==m){
                for(j=0;j<n;j++){
                    if((i&(1<<j))!=0){
                        tmp=tmp>a[j]?tmp:a[j];
                    }
                }
                ans=(ans+tmp)%mod;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
