#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

struct Str{
    char line[24];
    int kind;
};

bool cmp(Str str1, Str str2){
    if(str1.kind!=str2.kind)
        return str1.kind>str2.kind;
    else
        return strcmp(str1.line,str2.line)<0;
}

int num_of_dif(char *s){
    int cnt=0;
    char difChars[20];
    difChars[0]=s[0];cnt++;
    for(int i=0;s[i]!='\0';i++){
        for(int j=0;j<cnt&&s[i]!=difChars[j];j++){
            if(j==cnt-1) difChars[cnt++]=s[i];
        }
    }
    return cnt;
}

int main(){
    int T; cin>>T;
    for(int cas=0;cas<T;cas++){
        int n; cin>>n;
        int zimu[26];
        Str str[n];

        for(int i=0;i<n;i++){
            cin>>str[i].line;

            str[i].kind=num_of_dif(str[i].line);
        }
        sort(str,str+n,cmp);
        cout<<"case #"<<cas<<":"<<endl;
        for(int i=0;i<n;i++)
            cout<<str[i].line<<endl;
    }
    return 0;
}
