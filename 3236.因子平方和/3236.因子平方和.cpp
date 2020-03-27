#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n, ans=0, i=0, j=0;
        int a[100], b[100];
        scanf("%d",&n);
        for(i=2;i<n;i++){
            if(n%i==0){
                if(j>0&&i==b[j-1]) break;
                a[j]=i; b[j]=n/i;
                if(a[j]==b[j]){ans+=a[j]*a[j]; j++; break; }
                else{ans+=a[j]*a[j]+b[j]*b[j]; j++;}
            }
        }
        printf("case #%d:\n%d\n",cas,ans);
    }
    return 0;
}
