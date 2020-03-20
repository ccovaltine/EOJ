#include <bits/stdc++.h>
using namespace std;

int num(int n){
    switch(n){
    case 1:
        return 2;
    case 2:
        return 4;
    case 3:
        return 7;
    default:
        return 2*num(n-1)-num(n-2)+num(n-3);
    }
}

int main(){
    int n=0; scanf("%d",&n);
    while(n!=-1){
        printf("%d\n",num(n));
        scanf("%d",&n);
    }
    return 0;
}
