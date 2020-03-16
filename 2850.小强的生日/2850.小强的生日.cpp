#include <bits/stdc++.h>
using namespace std;

int main(){
    int year;
    while(scanf("%d",&year)!=EOF){
        int day=0, first=0;
        if((year%4)==0&&year!=2100) day=29;
        else day=28;
        for(int i=2008;i<year;i++){
            if((i%4)==0&&i!=2100) first+=366;
            else first+=365;
        }
        first=(first+5)%7;
        //printf("%d\n",first);
        printf("%3s%3s%3s%3s%3s%3s%3s\n","SU","MO", "TU","WE","TH","FR","SA");
        for(int i=0;i<first;i++) printf("%3s"," ");
        for(int i=1;i<=day;i++){
            printf("%3d",i);
            if((i-1+first)%7==6&&i!=day)printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
