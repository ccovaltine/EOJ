#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n; scanf("%d",&n);
        int i=2, end=(int)sqrt(n);
        if(n%i==0);
        else{
            for(i=3;i<=end;i+=2){
                if(!(n%i)){
                    break;
                }
            }
        }
        printf("case #%d:\n%d\n",cas,n/i);
    }
    return 0;
}
