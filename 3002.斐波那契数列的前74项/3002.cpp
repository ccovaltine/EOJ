#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t[74]={0,1,1};
	for(int i=3;i<74;i++)
	    t[i]=t[i-1]+t[i-2]+t[i-3];
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",cas,t[n]);
    }
    return 0;
}
