#include <bits/stdc++.h>
using namespace std;

struct Str{
    char line[32];
    bool has_num;
    int num;
};

bool cmp(Str s1, Str s2){
    if(s1.has_num&&s2.has_num){//记得考虑当s1的num与s2的num的情况下，按strcmp的方法排。
            if(s1.num==s2.num) return strcmp(s1.line,s2.line)<0;
            else return s1.num<s2.num;
    }
    else if(s1.has_num||s2.has_num) return s2.has_num;
    else return strcmp(s1.line,s2.line)<=0;
}

int main(){
    Str str[100];
    char tmp=getchar();
    int n=0,i=0;
    while(tmp!='\n'){
        if(tmp!=' '){str[n].line[i++]=tmp;}
        else {str[n].line[i]='\0'; n++; i=0;}
        tmp=getchar();
    }
    str[n].line[i]='\0';

    //for(i=0;i<=n;i++)
    //    printf("%s ",str[i].line);
    //printf("\n");

    for(i=0;i<=n;i++){
        str[i].has_num=false;
        str[i].num=0;
        for(int j=0;str[i].line[j]!='\0';j++){
            if(str[i].line[j]>='0'&&str[i].line[j]<='9'){
                str[i].has_num=true;
                str[i].num=str[i].num*10+str[i].line[j]-'0';
            }
        }
    }
    sort(str,str+n+1,cmp);
    for(i=0;i<=n;i++)
        printf("%s ",str[i].line);
    return 0;
}
