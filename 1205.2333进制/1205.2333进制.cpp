#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        long long int n; scanf("%lld",&n);
        stack<int> result;
        while(n/2333!=0){
            result.push(n%2333);
            n/=2333;
        }
        result.push(n);
        while(!result.empty()){
            printf("%d ",result.top());
            result.pop();
        }
        printf("\n");
    }
    return 0;
}
