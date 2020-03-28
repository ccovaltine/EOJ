#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
    LL n,k,i,j,a[300008];
    LL tmp=0,ans=0,A,_A;
    scanf("%lld%lld",&n,&k);
    scanf("%lld",&A);
    a[0]=0; _A=A;
    for(i=1;i<n;i++){
        _A+=k;
        scanf("%lld",&tmp);
        a[i]=_A-tmp;
    }
    sort(a,a+n);

    LL aa=0;
    LL asd=max(aa,(1-n)*k);
    LL ass=A-asd;

    LL mid;
    if(a[n/2]>ass) mid=ass;
    else mid=a[n/2];

    for(i=0;i<n;i++){
        ans+=abs(a[i]-mid);
    }
    printf("%lld",ans);
    return 0;
}

