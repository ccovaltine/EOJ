#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int N; scanf("%d",&N);
        int n=N;
        stack<int> nIn2;
        while(n/2!=0){
            nIn2.push(n%2);
            n/=2;
        }
        nIn2.push(n%2);

        n=N;
        stack<int> nIn16;
        while(n/16!=0){
            nIn16.push(n%16);
            n/=16;
        }
        nIn16.push(n%16);

        printf("case #%d:\n",cas);
        int tmp;
        while(!nIn2.empty()){
            tmp=nIn2.top();
            printf("%d",tmp);
            nIn2.pop();
        }
        printf(" ");

        while(!nIn16.empty()){
            tmp=nIn16.top();
            if(tmp>9)
                printf("%c",tmp-10+'A');
            else
                printf("%d",tmp);
            nIn16.pop();
        }
        printf("\n");
    }
    return 0;
}
