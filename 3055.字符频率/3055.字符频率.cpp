#include <bits/stdc++.h>

using namespace std;

double char_freq[27];

int cmp(const void *a, const void *b){
    char c1=*(char*)a, c2=*(char*)b;
    if(c1>='a'&&c1<='z'){
        if(c2>='a'&&c2<='z')
            return char_freq[c1-'a']>char_freq[c2-'a']?-1:1;
        else if(c2-c1=='A'-'a')
            return -1;
        else
            return char_freq[c1-'a']>char_freq[c2-'A']?-1:1;
    }
    else{
        if(c2>='A'&&c2<='Z')
            return char_freq[c1-'A']>char_freq[c2-'A']?-1:1;
        else if(c1-c2=='A'-'a')
            return 1;
        else
            return char_freq[c1-'A']>char_freq[c2-'a']?-1:1;
    }
}

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        for(int i=0;i<26;i++){
            scanf("%lf",&char_freq[i]);
        }
        char line[110];
        scanf("%s",line);
        int len=strlen(line);

        qsort(line,len,sizeof(char),cmp);

        printf("case #%d:\n%s\n",cas,line);
    }
    return 0;
}
