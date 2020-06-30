#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,p;
    int tmp;
    while(1){
       scanf("%d%d",&a,&p);
       for(int i=0;i<p;i++){
            tmp=((i%p)*(i%p))%p;
            if(tmp==a){
                printf("%d %d\n",i,p-i);
                break;
            }
            if(i==p-1){
                printf("同余方程式无解！\n");
            }
       }
    }
    return 0;
}
