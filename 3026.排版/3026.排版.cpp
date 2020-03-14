#include <bits/stdc++.h>
using namespace std;

struct Word{
    char inner[36];
    int len;
};

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int M; scanf("%d\n",&M);
        char line[2008]; gets(line);
        Word words[200]; int n=0,j=0;
        bool flag=false;
        for(int i=0;line[i]!='\0';i++){
            if(line[i]!=' '){
                if(flag){
                    words[n].inner[j++]=line[i];
                }
                else{
                    flag=true;
                    words[n].inner[j++]=line[i];
                }
            }
            else{
                if(flag){
                    words[n].inner[j]='\0';
                    words[n].len=strlen(words[n].inner);
                    n++; j=0;
                }
                else continue;
            }
        }
        words[n].inner[j]='\0';
        words[n].len=strlen(words[n].inner);
        n++;
        //for(int i=0;i<n;i++) printf("\"%s\", len=%d\n",words[i].inner,words[i].len);
        printf("case #%d:\n",cas);
        int now_len=0, i=0, k=0, numOfSpace=0;
        while(k<n){// k 是已输出完成的最大下标
            while((now_len<M+1)&&i<n){
                now_len+=words[i].len+1;
                printf("now_len=%d\n",now_len);
                i++;
            }
            i-=1;    // i 是 当前行输出截止的下标
            now_len=0;
            for(int p=k;p<=i;p++){
                now_len+=words[p].len;
                //printf("words[p].inner=\"%s\", now_len=%d\n",words[p].inner,now_len);
            }
            numOfSpace=M-now_len;
            //printf("i=%d, k=%d, now_len=%d, numOfSpace = %d\n",i,k,now_len,numOfSpace);
            for(;k<=i;k++){
                printf("%s",words[k].inner);
                if(k!=i){
                    for(int p=0;p<(numOfSpace/(i-k));p++)
                        printf("-");
                    numOfSpace-=numOfSpace/(i-k);
                }
            }
            printf("\n");
            now_len=0;
        }
    }
    return 0;
}
