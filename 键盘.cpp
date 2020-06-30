#include<bits/stdc++.h>
using namespace std;

typedef struct _Keyboard{
    int kind, price;
} Keyboard;

int main(){
    int T; scanf("%d",&T);
    int a,b,c,m;
    string line;
    for(int cas=0;cas<T;cas++){
        scanf("%d%d%d%d",&a,&b,&c,&m);
        Keyboard keyboard[m];
        for(int i=0;i<m;i++){//输入
            scanf("%d",&keyboard[i].price);
            cin>>line;
            if(line.find("USB")!=string::npos){
                keyboard[i].kind=1;
            }
            else{
                keyboard[i].kind=2;
            }
        }
        sort(keyboard,keyboard+m,cmp);
    }
    return 0;
}
