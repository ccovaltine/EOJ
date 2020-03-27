#include <bits/stdc++.h>
using namespace std;

long long C[144][144];
void init(){
    C[0][0]=1;
    for(int i=1;i<144;i++){
        C[i][0]=1; C[i][i]=1;
    }
    for(int i=2;i<144;i++)
        for(int j=1;j<i;j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    return;
}

int main(){
    init();
    int n=0,x=0,y=0,i=0,j=0,tmp=0;
    long long ans=0;
    bool board[108][108]; memset(board,0,sizeof(board));
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        board[x][y]=1;
    }

    for(i=0;i<108;i++){
        tmp=0;
        for(j=0;j<108;j++){
            tmp+=board[i][j];
        }
        if(tmp>1){
            ans+=C[tmp][2];
            //printf("第 %d 行有 %d 对\n",i,C[tmp][2]);
        }
    }

    for(j=0;j<108;j++){
        tmp=0;
        for(i=0;i<108;i++){
            tmp+=board[i][j];
        }
        if(tmp>1){
            ans+=C[tmp][2];
            //printf("第 %d 列有 %d 对\n",j,C[tmp][2]);
        }
    }

    for(int k=-108;k<108;k++){
        tmp=0;
        for(i=0;i<108;i++){
            for(j=0;j<108;j++){
                if(i-j==k) tmp+=board[i][j];
            }
        }
        if(tmp>1){
            ans+=C[tmp][2];
            //printf("第 %d 右斜有 %d 对\n",i,C[tmp][2]);
        }
    }

    for(int k=0;k<108;k++){
       tmp=0;
        for(i=0;i<108;i++){
            for(j=0;j<108;j++){
                if(i+j==k) tmp+=board[i][j];
            }
        }
        if(tmp>1){
            ans+=C[tmp][2];
            //printf("第 %d 左斜有 %d 对\n",i,C[tmp][2]);
        }
    }

    printf("%d\n",ans);
    return 0;
}
