#include <bits/stdc++.h>
using namespace std;

int main(){
    char line[100];
    while(scanf("%s",line)!=EOF){
        int c[4],len=strlen(line);
        int i=0,j=0,cnt;
        char tmp[10];
        bool before_x=true;
        memset(c,0,sizeof(c));
        while(line[i]!='=') i++;
        for(i+=1;i<len;i++){
            if(before_x){
                if((line[i]>='0'&&line[i]<='9')||line[i]=='-'){
                    tmp[j++]=line[i];
                }
                else if(line[i]=='x'){
                    tmp[j]='\0';
                    before_x=false;
                }
            }
            else{
                if(line[i]=='^'){
                    i++;
                    cnt=line[i]-'0';
                    before_x=true;
                }
                else{
                    cnt=1;
                    before_x=true;
                }
                if(j==0) c[cnt]=1;
                else if(strcmp(tmp,"-")==0) c[cnt]=-1;
                else c[cnt]=atoi(tmp);
                j=0;
                if(line[i]=='-') tmp[j++]='-';
            }
        }
        tmp[j]='\0';
        if(before_x) c[0]=atoi(tmp);
        else c[1]=atoi(tmp);

        for(i=20;i>=-20;i--){
            for(j=-20;j<=20;j++){
                int ans=c[3]*j*j*j+c[2]*j*j+c[1]*j+c[0];
                if(i==ans) printf("*");
                else if(i==20&&j==0) printf("^");
                else if(i==0&&j==20) printf(">");
                else if(i==0&&j==0) printf("+");
                else if(i==0) printf("-");
                else if(j==0) printf("|");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

