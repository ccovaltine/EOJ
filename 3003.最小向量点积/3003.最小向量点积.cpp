#include <bits/stdc++.h>
using namespace std;

bool cmpa(int x, int y){
    return x<y;
}
bool cmpb(int x, int y){
    return x>y;
}

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n=0, ans=0; scanf("%d",&n);
        int a[n], b[n], i=0;
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n;i++) scanf("%d",&b[i]);
        sort(a,a+n,cmpa);
        sort(b,b+n,cmpb);
        for(i=0;i<n;i++){
            ans+=a[i]*b[i];
        }
        printf("case #%d:\n%d\n",cas,ans);
    }
    return 0;
}
