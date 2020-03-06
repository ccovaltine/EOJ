#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int a,b; scanf("%d%d",&a,&b);
        int n=0;
        while((a!=0)||(b!=0)){
            if((a%2)!=(b%2)) n++;
            a>>=1;
            b>>=1;
        }
        printf("%d\n",n);
    }
    return 0;
}
