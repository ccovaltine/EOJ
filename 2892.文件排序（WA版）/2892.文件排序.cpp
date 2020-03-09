xs#include <bits/stdc++.h>
using namespace std;

struct File{
    char line[120];
    char day[12],time[6],size[10],name[64];
};

bool cmp1(File a, File b){
    return strcmp(a.name,b.name)<0;
}

bool cmp2(File a, File b){
    if(strcmp(a.size,b.size)!=0) return strcmp(a.size,b.size)<0;
    else return strcmp(a.name,b.name)<0;
}

bool cmp3(File a, File b){
    if(strcmp(a.day,b.day)!=0) return strcmp(a.day,b.day)<0;
    else if(strcmp(a.time,b.time)!=0) return strcmp(a.time,b.time)<0;
    else return strcmp(a.name,b.name)<0;
}

int main(){
    int n; scanf("%d\n",&n);
    while(n!=0){
        File file[n];
        for(int i=0;i<n;i++){
            memset(file[i].line,'\0',sizeof(file[i].line));
            gets(file[i].line);
            int flag=0;//0--day; 1--time; 2--size; 3--name;
            int k=0;
            bool begin=false;
            for(int j=0;file[i].line[j]!='\0';j++){
                if(file[i].line[j]!=' '&&!begin) begin=true;
                if(begin){
                    if(flag==0){
                        if(file[i].line[j]==' '){ file[i].day[k]='\0';flag++;k=0;begin=false; }
                        else file[i].day[k++]=file[i].line[j];
                    }
                    else if(flag==1){
                        if(file[i].line[j]==' '){ file[i].time[k++]='\0';flag++;k=0;begin=false; }
                        else file[i].time[k++]=file[i].line[j];
                    }
                    else if(flag==2){
                        if(file[i].line[j]==' '){ file[i].size[k++]='\0';flag++;k=0;begin=false; }
                        else file[i].size[k++]=file[i].line[j];
                    }
                    else if(flag==3){
                        if(file[i].line[j]==' '){ file[i].name[k++]='\0';flag++;k=0;begin=false; }
                        else file[i].name[k++]=file[i].line[j];
                    }
                }
            }
            file[i].name[k++]='\0';
            //printf("line:\"%s\"\nday:\"%s\" time:\"%s\" size:\"%s\" name:\"%s\"\n",file[i].line,file[i].day,file[i].time,file[i].size,file[i].name);
        }
        char choice[5]; scanf("LIST /%s",choice);
        if(strcmp(choice,"NAME")==0)
            sort(file,file+n,cmp1);
        else if(strcmp(choice,"SIZE")==0)
            sort(file,file+n,cmp2);
        else if(strcmp(choice,"TIME")==0)
            sort(file,file+n,cmp3);
        for(int i=0;i<n;i++)
            printf("%s\n",file[i].line);

        printf("\n");
        scanf("%d\n",&n);
    }
    return 0;
}

