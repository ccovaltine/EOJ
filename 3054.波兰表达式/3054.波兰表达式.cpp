#include<bits/stdc++.h>
using namespace std;

double solve(){
    char s[100]; scanf("%s",s);
    switch(s[0]){
    case '+':
        return solve()+solve();
    case '-':
        return solve()-solve();
    case '*':
        return solve()*solve();
    case '/':
        return solve()/solve();
    default:
        return atof(s);
    }
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        printf("case #%d:\n%lf\n",cas,solve());
    }
    return 0;
}
