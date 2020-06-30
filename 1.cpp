#include<bits/stdc++.h>
using namespace std;

int main(){
    char line[100];
    scanf("%s",line);
    for(int i=0;i<26;i++){
        for(int j=0;line[j]!='\0';j++){
            printf("%c",(line[j]-'a'+i)%26+'a');
        }
        printf("\n");
    }
    return 0;
}
