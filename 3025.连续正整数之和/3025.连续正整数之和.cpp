#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n=0,ans=0,min_diviso=0;
        scanf("%d",&n);
        for(int i=1;i<=(int)sqrt(n);i++){if(n%i==0){min_diviso=i;break;} }
        for(int i=2;i<=(n/min_diviso);i++){//假设n能分成i个连续整数
            if(i%2==0){//i是偶数：如果n除i以“0.5”结尾且n/i范围合法，n能分成连续i个整数
                if((n+i/2)%i==0&&(n/i)>=(i/2))
                    ans++;
            }
            else{//i是奇数：如果i整除n且n/i范围合法，n能分成连续i个整数
                if(n%i==0&&(n/i)>=(i+1)/2)
                    ans++;
            }
        }
        printf("case #%d:\n%d\n",cas,ans);
    }
    return 0;
}
