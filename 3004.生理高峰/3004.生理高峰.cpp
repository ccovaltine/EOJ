#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int p,e,i,d; scanf("%d%d%d%d",&p,&e,&i,&d);
        int ans;
        for(int x=0;x<=28*33;x++){
            for(int y=0;y<=23*33;y++){
                for(int z=0;z<=23*28;z++){
                    if((p+23*x==e+28*y)&&(p+23*x==i+33*z)){
                        ans=p+23*x-d;
                        break;
                    }
                }
            }
        }
        if(ans<=0) ans+=23*28*33;
        printf("case #%d:\nthe next triple peak occurs in %d days.\n",cas,ans);
    }
    return 0;
}
