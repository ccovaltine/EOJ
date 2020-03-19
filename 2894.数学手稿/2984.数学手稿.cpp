#include <bits/stdc++.h>
using namespace std;

struct Data{
    int man, woman, children;
};

bool cmp(Data a, Data b){
    return (10000*a.man+100*a.woman+a.children)<(10000*b.man+100*b.woman+b.children);
}

int main(){
    int T; scanf("%d",&T);
    Data data[100];
    for(int cas=0;cas<T;cas++){
        int people, money, n=0;
        scanf("%d%d",&people,&money);
        for(int i=0;i<=people;i++){
            for(int j=0;j<=people;j++){
                for(int k=0;k<=people;k++){
                    if((i+j+k==people)&&(3*i+2*j+k==money)){
                        data[n].man=i;
                        data[n].woman=j;
                        data[n].children=k;
                        n++;
                    }
                }
            }
        }
        sort(data,data+n,cmp);
        printf("case #%d:\n",cas);
        if(n==0)printf("-1\n");
        for(int i=0;i<n;i++)
            printf("%d %d %d\n",data[i].man,data[i].woman,data[i].children);
    }
    return 0;
}
