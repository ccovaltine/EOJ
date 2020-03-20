#include <bits/stdc++.h>
using namespace std;

int func(int n){
    switch(n){
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 1;
    default:
        return func(n-1)+func(n-2)+func(n-3);
    }
}

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n; scanf("%d",&n);
        printf("case #%d:\n%d\n",cas,func(n));
    }
    return 0;
}
