#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d\n",&T);
    long long ans=1,num=1;
    char line[6];

    for(int cas=0;cas<T;cas++){
        ans=1;
        scanf("%s",line);
        getchar();
        num=10000*(line[0]-'0')+1000*(line[2]-'0')+100*(line[4]-'0')+10*(line[3]-'0')+(line[1]-'0');
        for(int i=0;i<5;i++) ans=ans*num%100000;
        printf("case #%d:\n%05lld\n",cas,ans);
    }
    return 0;
}

