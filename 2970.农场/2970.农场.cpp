#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int head,foot,chicken,sheep;
        bool is_possible=true;
        scanf("%d%d",&head,&foot);
        if(foot>=0&&head>=0&&foot>=2*head&&foot%2==0){
            sheep=(foot-2*head)/2;
            chicken=head-sheep;
        }
        else is_possible=false;
        if(sheep<0||chicken<0) is_possible=false;
        printf("case #%d:\n",cas);
        if(is_possible) printf("%d %d\n",chicken,sheep);
        else printf("Impossible\n");
    }
    return 0;
}
