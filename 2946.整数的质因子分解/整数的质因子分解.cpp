#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n; scanf("%d",&n);
        int e=0;
        for(int i=2;n!=1;i++){
            while(n%i==0){
                n/=i;
                e++;
            }
            if(e>0){
                printf("(%d,%d)",i,e);
                e=0;
            }
        }
        printf("\n");
    }
    return 0;
}
