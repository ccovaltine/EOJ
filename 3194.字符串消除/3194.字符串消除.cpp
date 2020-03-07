#include <bits/stdc++.h>
using namespace std;

void remove_char(int _begin, char *line){
    int _end;
    int i=0,len=strlen(line);
    for(i=_begin;i<len-1;i++){
        if(line[i]!=line[i+1])
            break;
    }
    _end=i;//e.g. In "AAABCAB", _end is the place of the last A;
    for(i=_begin;i<=_end;i++){
        line[i]=line[i+_end-_begin+1];
    }
    return;
}

int num(char *line){
    int len=strlen(line), ex_len=len;
    bool can_remove=false;
    int i=0;

    for(;i<len-1;i++){
        if(line[i]==line[i+1]){
            can_remove=true;
            break;
        }
    }

    while(can_remove){
        //printf("now we remove %c\n",line[i]);
        remove_char(i,line);
        //printf("after removing it, line=\"%s\"\n",line);
        len=strlen(line);
        //printf("num=%d\n",ex_len-len);
        can_remove=false;
        for(i=0;i<len-1;i++){
            if(line[i]==line[i+1]){
                can_remove=true;
                break;
            }
        }
    }

    return ex_len-len;
}

int max_num(char *ex_line, int p){//max number among A\B\C
    int len=strlen(ex_line);
    int result=0;
    for(int k=0;k<3;k++){
        char line[108]; memcpy(line,ex_line,sizeof(line));
        line[len+1]='\0';
        for(int i=len;i>p;i--)
            line[i]=line[i-1];
        line[p]='A'+k;
        printf("we insert %c in the %d place of line, so the line is %s\n",line[p],p,line);
        int tmp=num(line);
        printf("finally line=\"%s\", num=%d\n\n",line,tmp);
        result=result<tmp?tmp:result;
    }
    return result;
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0; cas<T; cas++){
        char line[108]; scanf("%s",line);
        int len=strlen(line), result=0;
        for(int i=0;i<=len;i++){
            int tmp=max_num(line,i);
            result=result>tmp?result:tmp;
        }
        printf("result:%s\ncase #%d:\n%d\n",line,cas,result);
    }
    return 0;
}

