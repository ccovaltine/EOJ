#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int c,w, begin, end, ans=0;
        scanf("%d%d",&c,&w);
        begin=pow(10,c-1); end=pow(10,c)-1;
        for(int i=begin;i<=end;i++){
            if(i%10==w&&i%3==0) ans++;
        }
        printf("case #%d:\n%d\n",cas,ans);
    }
    return 0;
}
