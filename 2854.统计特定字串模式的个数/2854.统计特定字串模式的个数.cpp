#include <bits/stdc++.h>
using namespace std;

int main(){
    long long num[32][32];
    int n=0,m=0,i=0,j=0;
    for(i=1;i<32;i++){
        num[i][1]=pow(2,i)-1;
        num[i][i]=1;
    }
    for(i=2;i<32;i++){
        for(j=1;j<i;j++){
            num[i][j]=2*num[i-1][j]+pow(2,(i-j-1));
            if(i>2*j) num[i][j]-=num[i-j-1][j];
        }
    }

    scanf("%d%d",&n,&m);
    while(n!=-1&&m!=-1){
        printf("%ld\n",num[n][m]);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
