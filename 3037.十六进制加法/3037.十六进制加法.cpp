#include <bits/stdc++.h>
using namespace std;

int char_to_int(char c){
    if(c>='0'&&c<='9') return c-'0';
    else return c-'A'+10;
}

char int_to_char(int n){
    if(n>=0&&n<=9) return n+'0';
    else return n-10+'A';
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        char a[208], b[208];
        stack<int> an,bn,result;

        scanf("%s %s",a,b);
        for(int i=0;a[i]!='\0';i++)
            an.push(char_to_int(a[i]));
        for(int i=0;b[i]!='\0';i++)
            bn.push(char_to_int(b[i]));

        int x,y,up=0;
        while(!an.empty()&&!(bn.empty())){
            x=an.top(); y=bn.top();
            result.push((x+y+up)%16);
            up=(x+y+up)/16;
            an.pop(); bn.pop();
        }

        while(!an.empty()){
            x=an.top();
            result.push((x+up)%16);
            up=(x+up)/16;
            an.pop();
        }
        while(!bn.empty()){
            y=bn.top();
            result.push((y+up)%16);
            up=(y+up)/16;
            bn.pop();
        }
        printf("case #%d:\n",cas);
        if(up!=0) printf("1");
        while(!result.empty()){
            printf("%c",int_to_char(result.top()));
            result.pop();
        }
        printf("\n");
    }
    return 0;
}
