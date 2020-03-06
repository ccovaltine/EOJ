#include <bits/stdc++.h>

using namespace std;

struct P{
    double len;
    double angle;
};

bool cmp(P p, P q){
    if(fabs(p.angle-q.angle)>1e-7)
        return p.angle<q.angle;
    else
        return p.len>q.len;
}

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n; scanf("%d",&n);
        P p[n];
        for(int i=0;i<n;i++){
            double x,y;
            scanf("%lf %lf",&x,&y);
            p[i].len=sqrt(x*x+y*y);
            if(y>=0) p[i].angle=acos(x/(p[i].len));
            else p[i].angle=2*acos(-1)-acos(x/(p[i].len));
        }
        sort(p,p+n,cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<n;i++){
            printf("(%.4lf,%.4lf)\n",p[i].len,p[i].angle);
        }
    }

    return 0;
}
