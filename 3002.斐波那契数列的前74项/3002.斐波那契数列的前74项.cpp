#include<bits/stdc++.h>
using namespace std;

struct Big{
    int inner[200];
    int len;
};

Big add(Big a, Big b){
    Big ans;
    int up=0,i=0;
    for(i=0;i<a.len&&i<b.len;i++){
        ans.inner[i]=((a.inner[i]+b.inner[i]+up))%10;
        up=(a.inner[i]+b.inner[i]+up)/10;
    }
    for(;i<a.len;i++){
        ans.inner[i]=((a.inner[i]+up)%10);
        up=(a.inner[i]+up)/10;
    }
    for(;i<b.len;i++){
        ans.inner[i]=((b.inner[i]+up)%10);
        up=(b.inner[i]+up)/10;
    }
    if(up>0){ans.inner[i++]=up; ans.len=i;}
    else{ ans.len=i; }
    return ans;
}

int main(){
    Big ans[74];
    int i,n,T;
    ans[0].inner[0]=0; ans[0].len=1;
    ans[1].inner[0]=1; ans[1].len=1;
    ans[2].inner[0]=1; ans[2].len=1;
    for(i=3;i<74;i++){
        Big tmp=add(ans[i-1],ans[i-2]);
        ans[i]=add(tmp,ans[i-3]);
    }
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        scanf("%d",&n);
        printf("case #%d:\n",cas);
    for(i=ans[n].len-1;i>=0;i--)
        printf("%d",ans[n].inner[i]);
    printf("\n");
    }
    return 0;
}
