#include <bits/stdc++.h>
using namespace std;

int triangle[31][31];

void init(){
    int i=0,j=0;
    for(i=0;i<=30;i++){triangle[i][0]; triangle[i][i]=1;}
    triangle[1][1]=1; triangle[2][1]=1;
    for(i=3;i<=30;i++)
        for(j=0;j<i;j++)
            triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
}

int main(){
    init();
    int n; scanf("%d",&n);
    while(n!=0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                printf("%d ",triangle[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}
