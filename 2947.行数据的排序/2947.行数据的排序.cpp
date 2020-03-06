#include <bits/stdc++.h>

using namespace std;

struct Line{
    int nums[56];
};

int cmp(const void *a, const void *b){
    Line l1=*(Line*)a, l2=*(Line*)b;
    int i=0;
    for(;l1.nums[i]&&l2.nums[i];i++){
        if(l1.nums[i]!=l2.nums[i])
            return l1.nums[i]>l2.nums[i]?-1:1;
    }
    return l1.nums[i]=='\0'?1:-1;
}


int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0; cas<T; cas++){
        int n; scanf("%d\n",&n);
        Line line[n];
        int tmp=0;
        int i=0,j=0;
        for(;i<n;i++){
            scanf("%d",&tmp);
            if(tmp==-1)
                    line[i].nums[j+1]='\0';
            for(j=0;tmp!=-1;j++){
                line[i].nums[j]=tmp;
                scanf("%d",&tmp);
                if(tmp==-1)
                    line[i].nums[j+1]='\0';
            }
        }

        qsort(line,n,sizeof(Line),cmp);

        for(i=0;i<n;i++){
            for(j=0;line[i].nums[j]!='\0';j++)
                printf("%d ",line[i].nums[j]);
            printf("\n");
        }
    }

    return 0;
}
