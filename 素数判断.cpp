#include<bits/stdc++.h>
using namespace std;

int main(){
    int num; int i=0; bool is_prime;
    while(1){
        scanf("%d",&num);
        is_prime=true;
        for(i=2;i<num;i++){
            if(num%i==0){
                is_prime=false;
                break;
            }
        }
        if(is_prime)
            printf("ÊÇ\n");
        else
            printf("²»ÊÇ\n");
    }
    return 0;
}
