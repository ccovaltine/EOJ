#include<bits/stdc++.h>
using namespace std;

int sToN(char *s){
    char num[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i=0;i<10;i++){
        if(strcmp(s,num[i])==0)
            return i;
    }
    return -1;
}

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int a=0,b=0;
        bool is_a=true;
        char tmp[10]; scanf("%s",tmp);
        while(strcmp(tmp,"=")!=0){
            if(strcmp(tmp,"+")==0) is_a=false;
            else if(is_a) a=a*10+sToN(tmp);
            else b=b*10+sToN(tmp);
            scanf("%s",tmp);
        }
        printf("case #%d:\n%d\n",cas,a+b);
    }
    return 0;
}
