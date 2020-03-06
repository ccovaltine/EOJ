#include <bits/stdc++.h>
using namespace std;

int greatest_common_divisor(int m,int n){
    if(m<n) swap(m,n);
    int r=m%n;
    while(r!=0){
        m=n;
        n=r;
        r=m%n;
    }
    return n;
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int n; scanf("%d",&n);
        int result=0;
        for(int r=2;r<n;r++){
            int tmp=n;
            while(tmp/r!=0){
                result+=tmp%r;
                tmp/=r;
            }
            result+=tmp;
        }
        int g=greatest_common_divisor(result,n-2);
        printf("%d/%d\n",result/g,(n-2)/g);
    }
    return 0;
}
