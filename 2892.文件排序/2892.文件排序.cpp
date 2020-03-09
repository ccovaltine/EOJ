#include <bits/stdc++.h>
using namespace std;

struct File{
    char day[12], time[6],name[64];
    int size;
};

bool cmp1(File a, File b){
    return strcmp(a.name,b.name)<0;
}

bool cmp2(File a, File b){
    if(a.size!=b.size) return a.size<b.size;
    else return strcmp(a.name,b.name)<0;
}

bool cmp3(File a, File b){
    if(strcmp(a.day,b.day)!=0) return strcmp(a.day,b.day)<0;
    else if(strcmp(a.time,b.time)!=0) return strcmp(a.time,b.time)<0;
    else return strcmp(a.name,b.name)<0;
}

int main(){
    int n; scanf("%d",&n);
    while(n!=0){
        File file[n];
        char cmd[5];
        for(int i=0;i<n;i++)
            scanf("%s %s %d %s\n",file[i].day,file[i].time,&file[i].size,file[i].name);
        scanf("LIST /%s",cmd);
        if(strcmp(cmd,"NAME")==0)
            sort(file,file+n,cmp1);
        else if(strcmp(cmd,"TIMEb b ")==0)
            sort(file,file+n,cmp3);
        else if(strcmp(cmd,"SIZE")==0)
            sort(file,file+n,cmp2);
        for(int i=0;i<n;i++)
            printf("%s %s %16d %s\n",file[i].day,file[i].time,file[i].size,file[i].name);
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}
