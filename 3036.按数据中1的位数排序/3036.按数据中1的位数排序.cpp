#include <bits/stdc++.h>

using namespace std;

int cmp(const void *a, const void *b){
    long long int n1=*(long long int *)a, n2=*(long long int *)b;
    int w1=0, w2=0;
    for(int i=0;i<64;i++){
        long long int t1=n1>>i, t2=n2>>i;
        if(t1%2!=0) w1++;
        if(t2%2!=0) w2++;
    }
    if(w1!=w2) return w1>w2?-1:1;
    return n1<n2?-1:1;
}

int main(){
    //printf("%d",(-15>>4)%2);
    int T; scanf("%d",&T);
    for(int cas=0; cas<T; cas++){
        int N; scanf("%d",&N);
        long long int nums[N];
        for(int i=0;i<N;i++){
            scanf("%lld",&nums[i]);
        }

        qsort(nums,N,sizeof(long long int),cmp);

        printf("case #%d:\n",cas);
        for(int i=0;i<N;i++){
            printf("%lld ",nums[i]);
        }
        printf("\n");

    }
    return 0;
}
