#include <bits/stdc++.h>
using namespace std;

string word[]={
                        "-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",
                        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",//A-J
                        "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",//K-T
                        "..-","...-",".--","-..-","-.--","--.."//U-Z
                        };

int main(){
    int T; scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int cnt=0;
        char tmp[6]; int i=0;
        char c=getchar();

        printf("case #%d:\n",cas);

        while(c!='\n'){
            if(c!='/'){
                tmp[i++]=c;
                c=getchar();
            }
            else{
                cnt++;
                c=getchar();
                while(c=='/'){
                    cnt++;
                    c=getchar();
                }
                tmp[i]='\0';
                for(int j=0;j<36;j++){
                    if(strcmp(tmp,word[j].c_str())==0){
                        if(j<10) printf("%d",j);
                        else printf("%c",j-10+'A');
                    }
                }
                i=0;

                if(cnt==1);
                else if(cnt==3){
                    printf(" ");
                }
                else if(cnt==5){
                    printf(".");
                }
                cnt=0;
            }
        }
        tmp[i]='\0';
        for(int j=0;j<36;j++){
            if(strcmp(tmp,word[j].c_str())==0){
                if(j<10) printf("%d",j);
                else printf("%c",j-10+'A');
            }
        }
        printf("\n");
    }
    return 0;
}
