#include <bits/stdc++.h>
using namespace std;

struct Word{
    char inner[24];
};

bool cmp(Word a, Word b){
    return strcmp(a.inner,b.inner)<0;
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        Word words[500];
        int n=0,i=0;
        char c=getchar();
        while(c!='\n'){         //read the words
            if(c>='a'&&c<='z') words[n].inner[i++]=c;
            else{words[n].inner[i]='\0';n++;i=0; }
            c=getchar();
        }
        words[n].inner[i]='\0';

        sort(words,words+n,cmp);

        printf("case #%d:\n",cas);
        Word tmp;
        for(i=0;i<=n;i++){
            if(strcmp(tmp.inner,words[i].inner)!=0){
                printf("%s ",words[i].inner);
                tmp=words[i];
            }
        }
        printf("\n");
    }
    return 0;
}
