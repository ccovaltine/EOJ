#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct Special{
    int place;
    char inner;
};

int cmp(const void *a, const void *b){
    char w1=*(char*)a, w2=*(char*)b;
    bool w1_is_special=!(w1>='A'&&w1<='Z'),
            w2_is_special=!(w2>='A'&&w2<='Z');
    if(w1_is_special||w2_is_special)
        return w1_is_special==true?1:-1;
    else return w1<w2?-1:1;
}

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        char line[220]; char temp; int len=0;
        while(1){
            scanf("%c",&temp);
            if(temp=='\n') {
                    line[len]='\0';
                    break;
            }
            else line[len++]=temp;
        }
        int blank[208]; int k=0;//record the places of blanks; k is a "pointer"
        Special spc[208]; int num=0;
        for(int i=0;line[i]!='\0';i++){
            if(line[i]!=' '){
                if(line[i]<'A'||line[i]>'Z'){
                    spc[num].inner=line[i];
                    spc[num++].place=i;
                }
            }
            else{
                blank[k++]=i;
            }
        }

        qsort(line,len,sizeof(char),cmp);

        printf("case #%d:\n",cas);

        //cout<<num<<endl;

        //for(int i=0;i<num;i++)
            //cout<<spc[i].inner<<" "<<spc[i].place<<endl;
        //for(int i=0;i<k;i++)
            //cout<<blank[i]<<" is blank."<<endl;

        for(int i=0,b=0,s=0,cnt=0;cnt<len;){
            if(b<k&&cnt==blank[b]){
                //if(){
                    printf(" ");
                    b++;
                    cnt++;
                //}
            }
            else if(s<num&&cnt==spc[s].place){
                //if(){
                    printf("%c",spc[s].inner);
                    cnt++;
                    s++;
                //}
            }
            else{
                printf("%c",line[i]);
                i++; cnt++;
            }
        }
        cout<<endl;
    }
    return 0;
}

