#include <bits/stdc++.h>
using namespace std;

int main(){
    int value;
    char type;
    double ans;
    scanf("%d%c",&value,&type);
    if(type=='f'){
        ans=((value-32)*5)/9.0;
        printf("%.2lf%c\n",ans,'c');
    }
    else{
        ans=(9*value)/5.0+32;
        printf("%.2lf%c",ans,'f');
    }
    return 0;
}
