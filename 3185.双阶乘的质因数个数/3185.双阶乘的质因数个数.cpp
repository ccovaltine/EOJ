#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n,m,i,tmp,ans; scanf("%d%d",&n,&m);
        bool is_odd=(n%2==1);
        if(is_odd) i=1;
        else i=2;
        ans=0;
        for(;i<=n;i+=2){
            tmp=i;
            while(tmp%m==0){
                ans++;
                tmp/=m;
            }
        }
        printf("case #%d:\n%d\n",cas,ans);
    }
    return 0;
}
