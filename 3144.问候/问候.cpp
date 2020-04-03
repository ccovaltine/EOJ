#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n; scanf("%d",&n);
        int h[n],m[n]; double s[n];
        int h_ans=0,m_ans=0;
        double s_ans=0.0;
        for(int i=0;i<n;i++){
            scanf("%d:%d:%lf",&h[i],&m[i],&s[i]);
            s_ans+=s[i];
            m_ans+=m[i]+s_ans/100; s_ans=s_ans-(s_ans/100)*100;
            h_ans+=h[i]+m_ans/60; m_ans=m_ans%60;
            h_ans=h_ans%24;
        }
        printf("case #%d:\n",cas);
        if(h_ans>=4&&h_ans<12) printf("Good morning!\n");
        else if(h_ans>=12&&h_ans<18) printf("Good afternoon!\n");
        else if(h_ans>=18&&h_ans<22) printf("Good evening!\n");
        else printf("Good night!\n");
    }
    return 0;
}
