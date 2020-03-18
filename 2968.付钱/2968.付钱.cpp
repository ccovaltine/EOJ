#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n; scanf("%d",&n);
        int hundred=0,fifty=0,twenty=0,ten=0,five=0,one=0;
        hundred=n/100; n%=100;
        fifty=n/50; n%=50;
        twenty=n/20; n%=20;
        ten=n/10; n%=10;
        five=n/5; n%=5;
        one=n;
        printf("case #%d:\n%d %d %d %d %d %d\n",cas,hundred,fifty,twenty,ten,five,one);
    }
    return 0;
}
