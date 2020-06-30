#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    int num[100];
    while(true){
        for(int i=0;i<100;i++)
            num[i]=i;
        scanf("%d",&a);
        for(int i=1;i<=(a/2);i++){
            printf("%d,",(i*i)%a);
            num[(i*i)%a]=0;
        }
        printf("\n");
        for(int i=0;i<a;i++){
            if(num[i]!=0)
                printf("%d,",i);
        }
        printf("\n");
    }
    return 0;
}
