#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int result=0;
        char thr[24]; scanf("%s",thr);
        for(int i=0;thr[i]!=0;i++)
            result=result*3+(thr[i]=='-'?-1:(thr[i]-'0'));
        printf("case #%d:\n%d\n",cas,result);
    }
    return 0;
}
