#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        printf("case #%d:\n",cas);
        char tmp=getchar();
        while(tmp!='\n'){
            if(tmp>='a'&&tmp<='m') tmp+=13;
            else if(tmp>='n'&&tmp<='z') tmp-=13;
            else if(tmp>='A'&&tmp<='M') tmp+=13;
            else if(tmp>='N'&&tmp<='Z') tmp-=13;
            printf("%c",tmp);
            tmp=getchar();
        }
        printf("\n");
    }
    return 0;
}
