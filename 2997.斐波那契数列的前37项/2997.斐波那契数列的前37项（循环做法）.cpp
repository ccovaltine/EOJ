#include <bits/stdc++.h>
using namespace std;

void init(int *a){
    a[0]=0; a[1]=1; a[2]=1;
    for(int i=3;i<37;i++) a[i]=a[i-1]+a[i-2]+a[i-3];
}

int main(){
    int ans[37]; init(ans);
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n; scanf("%d",&n);
        printf("case #%d:\n%d\n",cas,ans[n]);
    }
    return 0;
}

