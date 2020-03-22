#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; scanf("%d",&N);
    int ans[51]; memset(ans,0,sizeof(ans));
    ans[1]=1; ans[2]=1; ans[3]=1;
    for(int i=4;i<=50;i++){
        ans[i]=ans[i-1]+ans[i-3];
    }
    while(N!=0){
        printf("%d\n",ans[N]);
        scanf("%d",&N);
    }
    return 0;
}
