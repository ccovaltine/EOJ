#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        char line[55]; scanf("%s",line);
        char result[165]; memset(result,0,sizeof(result));
        int l_line=strlen(line), l_result=0;
        for(int i=l_line-1;i>1;i--){
            int carry=line[i]-'0';
            int j;
            for(j=0;j<l_result||carry!=0;j++){
                int tmp=10*carry+(j<l_result?result[j]-'0':0);
                result[j]=tmp/8+'0';
                carry=tmp%8;
            }
            l_result=j;
        }
        printf("case #%d:\n0.%s\n",cas,result);
    }
    return 0;
}
