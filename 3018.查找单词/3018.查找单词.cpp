#include <bits/stdc++.h>
using namespace std;

char word[12],line[1000008];

void lowToUp(char *a){
    int len=strlen(a);
    for(int i=0;i<len;i++)
        if(a[i]>='a'&&a[i]<='z') a[i]=a[i]-'a'+'A';
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int len=0;
        char c; //getchar();
        word[0]=' '; gets(&word[1]);
        len=strlen(word); word[len]=' '; word[len+1]='\0';

        getchar();
        int j=0;
        line[j++]=' ';
        c=getchar();
        while(c!='\n'||c==EOF){
            line[j++]=c;
            c=getchar();
        }
        line[j++]=' ';
        line[j]='\0';

        lowToUp(word); lowToUp(line);
        //printf("word:\"%s\"\n",word);
        //printf("line:\"%s\"\n",line);
        char *p=NULL;
        p=strstr(line,word);
        printf("case #%d:\n",cas);
        if(p==NULL) printf("None\n");
        else printf("%ld\n",p-&line[0]+2);
    }
    return 0;
}
