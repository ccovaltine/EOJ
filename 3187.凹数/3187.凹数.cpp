#include <bits/stdc++.h>
using namespace std;

bool is_ao(int b){
    int n[7], len=0, a=b;
    bool flag=true;
    while(a!=0){
        n[len++]=a%10;
        a/=10;
    }
    if(n[1]>=n[0]) return false;
    for(int i=2;i<len;i++){
        if(flag){
            if(n[i]<n[i-1]) continue;
            else {flag=false;i--;}
        }
        else{
            if(n[i]>n[i-1]) continue;
            else return false;
        }
    }
    if(flag) return false;
    return true;
}

int num[1000008];
void init(){
    num[100]=0; num[101]=1;
    for(int i=102;i<=1000000;i++){
        num[i]=num[i-1]+is_ao(i);
    }
}

int main(){
    init();
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int a,b; scanf("%d%d",&a,&b);
        printf("case #%d:\n%d\n",cas,(num[b]-num[a]+is_ao(a)));
    }
    return 0;
}
