#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; scanf("%d\n",&N);
    int day[N][2];
    int result=0;
    for(int i=0;i<N;i++)
        scanf("%d%d",&day[i][0],&day[i][1]);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(day[j][0]>=day[i][0]&&day[j][0]<=day[i][1]){
                day[i][1]=day[i][1]>day[j][1]?day[i][1]:day[j][1];
                day[j][0]=0; day[j][1]=0;
            }
        }
    }
    for(int i=0;i<N;i++){
        //printf("%d %d\n",day[i][0],day[i][1]);
        if(day[i][1]-day[i][0]!=0)result+=day[i][1]-day[i][0]+1;
    }

    printf("%d\n",result);
    return 0;
}
