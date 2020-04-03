#include <bits/stdc++.h>
using namespace std;

typedef struct{
    string user,net;
}Email;

bool cmp(Email a, Email b){
    if(a.net==b.net) return a.user>b.user;
    else return a.net<b.net;
}

int main(){
    int n; scanf("%d",&n);
    Email email[n];
    char c=getchar();
    for(int i=0;i<n;i++){
        while(c=='\n') c=getchar();
        while(c!='@'){
            email[i].user+=c;
            c=getchar();
        }
        while(c!='\n'&&c!=EOF){
            email[i].net+=c;
            c=getchar();
        }
    }
    sort(email,email+n,cmp);
    for(int i=0;i<n;i++)
        printf("%s%s\n",email[i].user.c_str(),email[i].net.c_str());
    return 0;
}
