#include <bits/stdc++.h>
using namespace std;

int char_is(char c){
    if(c>='a'&&c<='z')
        return c-'a';
    else if(c>='A'&&c<='Z')
        return c-'A'+26;
    else
        return c-'0'+52;
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        char line[64];
        int len=0,kind=1,valueOfChar[64];
        long long int value=0;
        char zero_char='.';
        for(int k=0;k<64;k++)
            valueOfChar[k]=0;
        scanf("%s",line); len=strlen(line);
        for(int j=0;j<len;j++){
            if(valueOfChar[char_is(line[j])]==0&&line[j]!=zero_char){
                if(kind==1)
                    valueOfChar[char_is(line[j])]=1;
                else if(kind==2){
                    valueOfChar[char_is(line[j])]=0;
                    zero_char=line[j];
                }
                else
                    valueOfChar[char_is(line[j])]=kind-1;
                kind++;
            }
        }

        kind--;
        if(kind==1) kind=2;
        //printf("kind is %d\n",kind);

        for(int j=0;j<len;j++){
            long long int add=1;
            for(int k=0;k<len-j-1;k++){
                add*=kind;
            }
            //printf("%c means %lld * %d\n",line[j],add,valueOfChar[char_is(line[j])]);
            add*=valueOfChar[char_is(line[j])];

            value+=add;
            add=1;
        }
        printf("case #%d:\n%lld\n",cas,value);
    }
    return 0;
}
