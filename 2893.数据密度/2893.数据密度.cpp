#include <bits/stdc++.h>

using namespace std;

void standard_out(int up, int down){
    int m=down,n=up,r=1;
    while(r!=0){
        r=m%n;
        m=n;
        n=r;
    }
    cout<<up/m<<"/"<<down/m<<endl;
}

int main(){
    int n; scanf("%d",&n);getchar();
    char line[130];
    int numOf1=0;
    for(int i=0;i<n;i++){
        gets(line);
        int len=strlen(line);
        for(int j=0;j<len;j++){
            int temp=0x000000ff&line[j];
            for(int k=0;k<8;k++){
                if((temp>>k)%2!=0) numOf1++;
            }
        }
        standard_out(numOf1,len*8);
        numOf1=0;
    }
    return 0;
}
