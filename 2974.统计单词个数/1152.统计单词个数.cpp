#include <bits/stdc++.h>
using namespace std;

struct Word{
    char inner[100];
};

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        char line[108]; memset(line,108,'\0'); gets(line);
        Word word[100]; int n=0,j=0;
        int cnt=0;
        for(int i=0;line[i]!='\0';i++){
            if(line[i]!=' '){
                word[n].inner[j]=tolower(line[i]);
                j++;
            }
            else{
                word[n].inner[j]='\0';
                n++;
                j=0;
            }
        }
        word[n].inner[j]='\0';

        for(int i=0;i<=n;i++){
            if(strcmp(word[i].inner,"the")==0||strcmp(word[i].inner,"a")==0
               ||strcmp(word[i].inner,"an")==0||strcmp(word[i].inner,"of")==0
               ||strcmp(word[i].inner,"for")==0||strcmp(word[i].inner,"and")==0);
            else
                cnt++;
        }
        printf("case #%d:\n%d\n",cas,cnt);
    }
    return 0;
}
