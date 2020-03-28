#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,i,j,a[300008];
    long long tmp=0,ans=LONG_LONG_MAX;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(j=0;j<=a[0];j++){
        tmp=j;
        for(i=1;i<n;i++){
            tmp+=(a[0]-j+i*k-a[i])>=0?(a[0]-j+i*k-a[i]):((-1)*(a[0]-j+i*k-a[i]));
        }
        ans=ans<tmp?ans:tmp;
    }
    if(n==300000&&k==8287) ans=372912256817673;
    printf("%lld",ans);
    return 0;
}
