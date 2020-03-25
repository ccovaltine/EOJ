#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+5;
const ll mod=1e9+7;
ll a[N],F[N],I[N];
ll f(ll a,ll b)//¿ìËÙ³Ë
{
    ll k=0;
    while(b)
    {
        if(b&1) k=(k+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return k;
}

ll power(ll a,ll b){return b?power(aa%mod,b/2)(b%2?a:1)%mod:1;}
void init(){
    F[0]=1;
    ll s=1;
    for(int i=1;i<=N;i++){
        s=f(s,i);
        F[i]=s;
    }
    I[N]=power(F[N],mod-2);
    for(int i=N;i¨C;){
    I[i]=f(I[i+1],i+1);
    }
}

ll C(ll n, ll k){
    return f(f(F[n],I[n-k]),I[k]);
}

inline ll read() {
    ll s = 0, w = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == ¡®-¡®) w = -1;
    for (; isdigit(c); c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
    return s * w;
}

int main(){
    int t;
    t=read();
    init();
    while(t¨C){
        int n,m;
        ll ans=0,cnt=1,sum=0;
        n=read();m=read();
        for(int i=0;i<n;i++){
            a[i]=read();
            sum=(sum+a[i])%mod;
        }
        sort(a,a+n);
        for(int i=m-1;i<n;i++){
            ans=(ans+f(a[i],C(i,m-1)))%mod;
        }
        if(m==1) printf(¡°%lld\n¡±,sum);
        else printf(¡°%lld\n¡±,ans);
    }
    return 0;
}
