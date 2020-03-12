#include <bits/stdc++.h>
using namespace std;

bool addingHeadIsBetter(char* s){
    int len=strlen(s);
    int head=0, tail=len-1;
    while(head!=tail){
        if(s[head]!=s[tail]) return s[head]<s[tail];
        else{
            head++; tail--;
        }
    }
    return true;
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int len; scanf("%d\n",&len);
        char line[len+1]; scanf("%s",line);
        char ans[len+1];

        int first=0,last=len-1, j=0;
        while(j<len){
            if(addingHeadIsBetter(line+first)){
                ans[j++]=line[first];
                first++;
            }
            else{
                ans[j++]=line[last];
                line[last]='\0';
                last--;
            }
        }
        ans[len]='\0';
        printf("case #%d:\n%s\n",cas,ans);
    }
    return 0;
}
