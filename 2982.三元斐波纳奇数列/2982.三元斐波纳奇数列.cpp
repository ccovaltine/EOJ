#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int M, A[20],ans=-1;
        bool has_ans=true;
        scanf("%d",&M);
        for(int i=0;i<M;i++) scanf("%d",&A[i]);
        for(int i=0;i<M&&has_ans;i++){
            if(i>=3){
                if(A[i]!=-1&&A[i]!=A[i-1]+A[i-2]+A[i-3]){
                        has_ans=false;
                }
                else if(A[i]==-1) A[i]=ans=A[i-1]+A[i-2]+A[i-3];
            }
            else if(A[i]==-1){
                if(i+1<M&&i>=2)
                    A[i]=ans=(A[i+1]-A[i-1]-A[i-2])>0?(A[i+1]-A[i-1]-A[i-2]):-1;
                else if(i+2<M&&i>=1)
                    A[i]=ans=(A[i+2]-A[i+1]-A[i-1])>0?(A[i+2]-A[i+1]-A[i-1]):-1;
                else if(i+3<M)
                    A[i]=ans=(A[i+3]-A[i+2]-A[i+1])>0?(A[i+3]-A[i+2]-A[i+1]):-1;
                else{
                    has_ans=false;
                }
            }
        }
        printf("case #%d:\n%d\n",cas,(has_ans==true?ans:-1));
    }
    return 0;
}

