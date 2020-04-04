#include <bits/stdc++.h>
using namespace std;

long long C[44][44];
void init(){
    for(int i=0;i<44;i++){
        C[i][0]=1;
        C[i][i]=1;
    }
    for(int i=2;i<44;i++){
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    return;
}

int main(){
    init();
    int t=0; scanf("%d",&t);
    for(int cas=0;cas<t;cas++){
        int a,b; scanf("%d%d",&a,&b);
        printf("case #%d:\n%lld\n",cas,C[a][b]);
    }
    return 0;
}
