#include <bits/stdc++.h>

using namespace std;

struct Number{
    long long int inner;
    int highest;
};

bool cmp(Number a, Number b){
    if(a.highest!=b.highest) return a.highest>b.highest;
    else return a.inner<b.inner;
}

int the_highest(long long int inner){
    while((inner/10)!=0){
        inner/=10;
    }
    return (int)abs(inner) ;
}

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n; scanf("%d",&n);
        Number number[n];
        for(int i=0;i<n;i++){
            scanf("%lld",&number[i].inner);//long long int 的占位符是%lld
            number[i].highest=the_highest(number[i].inner);
            //printf("The number is %lld, and its highest is %d\n",number[i].inner,number[i].highest);
        }
        sort(number,number+n,cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<n;i++){
            printf("%lld ", number[i].inner);
        }
        printf("\n");
    }
    return 0;
}
