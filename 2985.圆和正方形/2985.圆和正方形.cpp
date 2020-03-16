#include <bits/stdc++.h>
using namespace std;

double S(double l){
    return (l*l-acos(-1.0)*(l/2)*(l/2));
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int l,k; scanf("%d%d",&l,&k);
        double ans=0.0, tmp=(double)l;
        for(int i=1;i<=k;i++){
            ans+=S(tmp);
            tmp/=sqrt(2);
        }
        printf("case #%d:\n%lf\n",cas,ans);
    }
    return 0;
}
