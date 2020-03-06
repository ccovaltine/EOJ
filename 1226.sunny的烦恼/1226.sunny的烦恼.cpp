#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int a;
        scanf("%d",&a);
        while(a>9){
            int b=0;
            while(a!=0){
                b+=a%10;
                a/=10;
            }
            a=b;
        }
        printf("%d\n",a);
    }
    return 0;
}
