#include <bits/stdc++.h>
using namespace std;

struct Ans{
    char inner[17];
};

bool cmp(Ans a, Ans b){
    return strcmp(a.inner,b.inner)<0;
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        char line[17];
        int len=0;
        char key[17]; int n=0;
        Ans ans[1<<16];
        int cnt=0;

        scanf("%s",line); len=strlen(line);
        memset(key,'\0',sizeof(key));

        sort(line,line+len);
        key[0]=line[0];
        for(int i=1;line[i]!='\0';i++){
            if(line[i]!=key[n]){n++;key[n]=line[i];}
        }
        n+=1;
        for(int i=1;i<(1<<n);i++){
            int l=0;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    ans[cnt].inner[l++]=key[j];
                }
            }
            ans[cnt++].inner[l]='\0';
        }
        sort(ans,ans+cnt,cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<cnt;i++)
            printf("%s\n",ans[i].inner);
    }
    return 0;
}
