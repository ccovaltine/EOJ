#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Pair{
    int id;
    int stat[11];
    double kl;
};

double the_kl(Pair *a, Pair *b, int K){
    Pair x=*a; Pair y=*b;
    int xm=0,ym=0;
    double px,py,result=0.0;
    for(int i=0;i<K;i++){
        xm+=x.stat[i];
        ym+=y.stat[i];
    }

    for(int i=0;i<K;i++){
        px=(x.stat[i]+1.0/(double)K)/((double)xm+1);
        py=(y.stat[i]+1.0/(double)K)/((double)ym+1);
        result+=px*log(px/py);
        }
    if(fabs(result)<1e-7)
        result=0.0000;
    return result;
}

bool cmp(Pair x,Pair y){
    if(fabs(x.kl-y.kl)>=1e-7) return x.kl<y.kl;
    else return x.id<y.id;
}


int main()
{
    int T; cin>>T;
    for(int cas=0;cas<T;cas++){//input and compute
        int K,N; cin>>K>>N;
        Pair x, y[N+1];
        for(int i=0;i<K;i++)
            cin>>x.stat[i];
        for(int j=0;j<N;j++){
            for(int i=0;i<K;i++)
                cin>>y[j].stat[i];
            y[j].id=j+1;
            y[j].kl=the_kl(&x,&(y[j]),K);
        }

        sort(y,y+N,cmp);//sort

        cout<<"case #"<<cas<<":"<<endl;//output
        for(int j=0;j<N;j++)
            cout<<y[j].id<<" "<<fixed<<setprecision(4)<<((int)(y[j].kl*10000+0.5))/10000.0<<endl;
    }
    //system("pause");
    return 0;
}
/*5
3 2
0 0 0
8 9 7
3 3 3
4 3
1 2 2 1
3 5 2 7
6 4 1 0
0 1 1 0
5 5
5 4 6 6 9
9 3 6 2 6
4 5 8 4 6
7 6 9 0 4
4 8 9 2 4
2 2 3 5 3
5 5
1 2 3 2 1
9 3 6 2 6
4 10 8 4 6
7 6 5 4 3
2 5 4 2 3
3 4 5 6 7
10 6
41 44 12  3 20 26 18 14 28 18
19 17 10  5  7 49 17 11 22 23
30 31  5  7 39  7 35 18 26 10
8 35 27  4 33 45 12  0 36 28
49 43 48 33 11  4 45 39  1 14
25  3 42 24  9 11 21  3 14 32
38 31 21 14 12 42 46 38 34 18*/

