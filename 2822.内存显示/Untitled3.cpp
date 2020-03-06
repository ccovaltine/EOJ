#include <bits/stdc++.h>
using namespace std;

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len){
    int i;
    for (i = 0; i < len; i++)
        printf("%.2x ", start[i]);
}
void show_int(int x){
    show_bytes((byte_pointer)&x, sizeof(int));
}
void show_float(float x){
    show_bytes((byte_pointer)&x, sizeof(float));
}
void show_double(float x){
    show_bytes((byte_pointer)&x, sizeof(double));
}

int main(){
    char tmp[20];

    while(scanf("%s",tmp)!=EOF){
        bool is_int=true, is_neg=false;
        int ire=0;double dre=0.0;
        int i;

        if(tmp[0]=='-') is_neg=true;
        for(i=0;tmp[i]!='\0';i++){//tmp is int or double?
            if(tmp[i]=='.'){
                is_int=false;
                break;
            }
        }

        if(is_int){
            for(i=(is_neg==false?0:1);tmp[i]!='\0';i++){
                ire=ire*10+tmp[i]-'0';
            }
            ire*=(is_neg==false?1:-1);
        }
        else{
            bool before_point=true;
            double add=0;
            for(i=(is_neg==false?0:1);tmp[i]!='.';i++){
                dre=dre*10+tmp[i]-'0';
            }
            for(i=strlen(tmp)-1;tmp[i]!='.';i--){
                add=add/10.0+(tmp[i]-'0')/10.0;
            }
            dre+=add;
            dre*=(is_neg==false?1:-1);
            printf("%s is double: %lf\n",tmp,dre);
        }
        if(is_int)show_int(ire);
        else show_double(dre);
        printf("\n");

    }
    return 0;
}

