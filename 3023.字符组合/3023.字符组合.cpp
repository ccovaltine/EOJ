#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        bool up[26],low[26];
        memset(up,false,sizeof(up));
        memset(low,false,sizeof(low));
        char S[20]; scanf("%s",S);
        int cnt=1;
        for(int i=0;S[i]!='\0';i++){
            if(S[i]>='a'&&S[i]<='z'){
                if(low[S[i]-'a']==false) cnt*=2;
                low[S[i]-'a']=true;
            }
            else{
                if(up[S[i]-'A']==false) cnt*2;
                up[S[i]-'A']=true;
            }
        }
        cnt-=1;
        char
    }
    return 0;
}
