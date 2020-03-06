#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char dic[27];
int place[26];

int cmp(const void *a, const void *b){
    char *s1, *s2;
    s1=(char*)a; s2=(char*)b;
    int i=0;
    for(;(s1[i]!='\0')&&(s2[i]!='\0');i++){
        char c1=s1[i], c2=s2[i];
        if(c1>='a'&&c1<='z') c1=c1-'a'+'A';
        if(c2>='a'&&c2<='z') c2=c2-'a'+'A';
        if(c1!=c2) return place[c1-'A']-place[c2-'A']<0?-1:1;
    }
    if(s1[i]=='\0') return -1;
    return 1;
}

int main()
{
    while(scanf("%s\n",dic)!=EOF){
        for(int i=0;i<26;i++){
            place[dic[i]-'A']=i;
        }

        char line[2100];
        char word[100][21];
        int i=0,j=0,cnt=0;
        gets(line);

        for(;line[i]!='\0';i++){
            if(line[i]!=' '){
                word[cnt][j]=line[i];
                j++;
            }
            else{
                word[cnt][j]='\0';
                cnt++;
                j=0;
            }
        }
        word[cnt][j]='\0';
        cnt++;

        qsort(word[0],cnt,21,cmp);

        for(int i=0;i<cnt-1;i++)
            printf("%s ",word[i]);
        printf("%s\n",word[cnt-1]);

    }
    return 0;
}

