#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int N; scanf("%d",&N);
        int num[N]; for(int i=0;i<N;i++){ scanf("%d",&num[i]); }
        bool has_change=false;
        while(1){
            for(int i=0;i<N;i++){
                int tmp=0;
                for(int j=i;j<N;j++){
                    if(num[j]<num[i]) tmp++;
                }
                if(num[i]!=tmp){
                    num[i]=tmp;
                    has_change=true;
                }
            }
            if(has_change==false) break;
            else has_change=false;
        }
        printf("case #%d:\n",cas);
        for(int i=0;i<N;i++) printf("%d ",num[i]);
        printf("\n");
    }
    return 0;
}
