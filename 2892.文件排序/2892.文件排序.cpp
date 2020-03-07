#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {char date[11]; char time[6]; int size; char name[70];}File;
int cmptime(const void*a, const void*b)
{
    File *p1=(File*)a, *p2=(File*)b;
    if(!strcmp(p1->date, p2->date))
    {
        if(!strcmp(p1->time, p2->time))
            return strcmp(p1->name, p2->name);
        return strcmp(p1->time, p2->time);
    }
    return strcmp(p1->date, p2->date);
}
int cmpname(const void*a, const void*b)
{
    File *p1=(File*)a, *p2=(File*)b;
    return strcmp(p1->name, p2->name);
}
int cmpsize(const void*a, const void*b)
{
    File *p1=(File*)a, *p2=(File*)b;
    if(p1->size==p2->size) return strcmp(p1->name, p2->name);
    return p1->size-p2->size;
}
int main()
{
    int n;
    char command[6], list[5];
    scanf("%d",&n);
    while(n)
    {
        File file[100];
        int i;
        for(i=0; i<n; i++)
            scanf("%s %s %d %s",file[i].date, file[i].time, &file[i].size, file[i].name);
        scanf("%s %s",list,command);
        if(!strcmp(command, "/NAME"))
            qsort(file, n, sizeof(file[0]), cmpname);
        else if(!strcmp(command, "/SIZE"))
            qsort(file, n, sizeof(file[0]), cmpsize);
        else
            qsort(file, n, sizeof(file[0]), cmptime);
        for(i=0; i<n; i++)
            printf("%s %s %16d %s\n",file[i].date, file[i].time, file[i].size, file[i].name);
        printf("\n");
        if(!scanf("%d",&n)) break;
    }
    return 0;
}
