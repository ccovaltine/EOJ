#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int num; scanf("%d",&num);
        char bin[32]; int len=0;
        int result=0;
        while(num!=0){
            bin[len++]=num%2+'0';
            num/=2;
        }
        bin[len]='\0';
        //printf("%s\n",bin);
        int tmp=1;
        for(int i=1;i<len;i++){
            if(bin[i]!=bin[i-1]){
                tmp++;
            }
            else{
                result=result<tmp?tmp:result;
                tmp=1;
            }
        }
        result=result<tmp?tmp:result;
        printf("case #%d:\n%d\n",cas,result);
    }
    return 0;
}
