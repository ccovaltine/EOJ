#include <bits/stdc++.h>
using namespace std;

const int NUMBER=1000000;

int num[NUMBER];

bool is_prime(int a){
    if(a<2) return false;
    int end=sqrt(a);
    for(int i=2;i<=end;i++){
        if(a%i==0) return false;
    }
    return true;
}

void init(){
    num[0]=0; num[1]=0; num[2]=1;
    for(int i=3;i<NUMBER;i++){
        if(is_prime(i)) num[i]=1+num[i-1];
        else num[i]=num[i-1];
    }
}

int main(){
    init();
    int a,b;
    while(scanf("%d",&a)!=EOF){
        scanf("%d",&b);
        printf("%d\n",num[b]-num[a]+is_prime(a));
    }
    return 0;
}
