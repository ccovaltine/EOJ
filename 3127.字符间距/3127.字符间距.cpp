#include <bits/stdc++.h>
using namespace std;

struct Str{
    char inner[84];
    int first,last;
};

void strfind(char *s, Str* s1){
    int len1=strlen(s1->inner);
    char *p=strstr(s,s1->inner);
    s1->first=(int)(p-&s[0]);

    while(p!=NULL){
        s1->last=(int)(p-s);
        p=strstr(s+s1->last+len1,s1->inner);
    }
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        char s[84];
        Str s1,s2;
        int len1,len2;
        char* p1=NULL, *p2=NULL;
        int result=0;

        scanf("%s%s%s",s1.inner,s2.inner,s);
        len1=strlen(s1.inner);
        len2=strlen(s2.inner);
        p1=strstr(s,s1.inner);
        p2=strstr(s,s2.inner);
        if(!p1||!p2) result=0;
        else{
            strfind(s,&s1);
            strfind(s,&s2);
            int the_max=max(s2.last-s1.first-len1,s1.last-s2.last-len2);
            result=the_max>0?the_max:0;
        }
        printf("case #%d:\n%d\n",cas,result);
    }
    return 0;
}
