#include <bits/stdc++.h>
using namespace std;

struct Bigint{
    int cnt;
    int inner[101];
};

void divide2(Bigint *n){
     int carry=0;
     if((n->inner[n->cnt-1])/2==0){
        carry=n->inner[n->cnt-1];
        n->inner[n->cnt-1]=0;
        n->cnt--;
    }
    for(int i=n->cnt-1; i>=0;i--){
        n->inner[i]+=10*carry;
        carry=n->inner[i]%2;
        n->inner[i]/=2;
    }
}

void multiply2(Bigint *n){
    int carry=0;
    for(int i=0;i<n->cnt;i++){
        int tmp=n->inner[i];
        n->inner[i]=(tmp*2+carry)%10;
        carry=(tmp*2+carry)/10;
    }
    if(carry!=0){
        n->cnt++;
        n->inner[n->cnt-1]=carry;
    }
}

void add(Bigint *n, int a){
    int carry=0;
    for(int i=0;i<n->cnt;i++){
        int tmp=n->inner[i];
        n->inner[i]=(tmp+a+carry)%10;
        carry=(tmp+a+carry)/10;
        a=0;
    }
    if(carry!=0){
        n->cnt++;
        n->inner[n->cnt-1]=carry;
    }
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        Bigint big;
        int binary[334]; int n=0;
        char line[101]; scanf("%s",line);
        int len=strlen(line);
        for(int i=0;i<len;i++)
            big.inner[i]=line[len-1-i]-'0';
        big.cnt=len;
        while(big.cnt!=0){
            binary[n++]=big.inner[0]%2;
            //printf("down1\n");
            divide2(&big);
        }


        big.inner[0]=binary[0];
        big.cnt=1;
        for(int i=1;i<n;i++){
            multiply2(&big);
            add(&big,binary[i]);
        }

        printf("case #%d:\n",cas);
        for(int i=big.cnt-1;i>=0;i--)
            printf("%d",big.inner[i]);
        printf("\n");
    }


    return 0;
}
