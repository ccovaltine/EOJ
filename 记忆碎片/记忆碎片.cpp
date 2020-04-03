#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int start,end;
}Couple;

bool cmp(Couple a, Couple b){
    if(a.start==b.start) return a.end<b.end;
    return a.start<b.start;
}

int main(){
    int N; scanf("%d\n",&N);
    Couple couple[N];
    int start,end;
    long long result=0;
    for(int i=0;i<N;i++)
        scanf("%d%d",&couple[i].start,&couple[i].end);
    sort(couple,couple+N,cmp);
    start=couple[0].start;
    end=couple[0].end;
    for(int i=1;i<N;i++){
        if(couple[i].start<=end) end=max(end,couple[i].end);
        else{
            result+=end-start+1;
            start=couple[i].start;
            end=couple[i].end;
        }
    }
    result+=end-start+1;
    printf("%lld",result);
    return 0;
}

