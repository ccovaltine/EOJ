#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long orz[300005];
int main()
{
    long long n,k;
    scanf("%lld%lld",&n,&k);
    long long a;
    scanf("%lld",&a);
    long long A=a;
    orz[0]=0;
    int q=0,w=0;
    for(int i = 1 ; i < n ; i++){
        long long  b;
        scanf("%lld",&b);
        orz[i]=-(b-k-A);
        A=A+k;
    }
    long long sum=0;
     sort(orz,orz+n);
    long long aa=0;
     long long asd=max(aa,(1-n)*k);
     long long ass=a-asd;
   //  cout << asd << endl;
     if(orz[n/2]>ass){
       for(int i = 0 ;  i < n  ;i++){
        sum+=abs(orz[i]-ass);
     }
     }
     else{
          for(int i = 0 ;  i < n  ;i++){
        sum+=abs(orz[i]-orz[n/2]);
     }
     }

    cout << sum <<endl;
    return 0;
}
