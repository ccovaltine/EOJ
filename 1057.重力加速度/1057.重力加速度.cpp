#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d",&n);
    double h;

    while(n!=0){
        if(n<=2) h=(n-1)*5+1.75;
        else h=10+(n-3)*3+1.75;
        printf("%.3f\n",sqrt(2*h/9.8));
        scanf("%d",&n);
    }
    return 0;
}
