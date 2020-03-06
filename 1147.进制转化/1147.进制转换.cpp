#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        bool is_neg=false;
        int N,R; scanf("%d%d",&N,&R);
        if(N<0){
                is_neg=true; N*=-1;
        }
        stack<int> result;
        while(N/R!=0){
            result.push(N%R);
            N/=R;
        }
        result.push(N%R);
        if(is_neg) printf("-");
        while(!result.empty()){
            int tmp=result.top();
            if(tmp>=0&&tmp<=9)
                printf("%d",tmp);
            else
                printf("%c",tmp-10+'A');
            result.pop();
        }
        printf("\n");
    }
    return 0;
}
