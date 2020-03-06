#include <bits/stdc++.h>
using namespace std;

int main(){
    char line[100000]; int len;
    queue<int> tmp; long long int result=0;
    queue<int> results; bool no_result=true;
    bool flag=false, is_16=false;

    scanf("%s",line);
    len=strlen(line);

    for(int i=0;i<=len;i++){
        if(is_16==false){
            if(line[i]=='0'){
                flag=true;
            }
            else if(line[i]=='x'&&flag==true){
                flag=false;
                is_16=true;
            }
            else
                continue;
        }
        else{
            flag=false;
            if(line[i]>='0'&&line[i]<='9')
                tmp.push(line[i]-'0');
            else if(line[i]>='a'&&line[i]<='f')
                tmp.push(line[i]-'a'+10);
            else{
                is_16=false;
                bool is_empty=true;/**防止0xggg这类情况输出0**/
                while(!tmp.empty()){
                    is_empty=false;
                    result=result*16+tmp.front();
                    tmp.pop();
                }
                if(!is_empty){printf("%lld ",result); no_result=false;}/**lld，大括号**/
                result=0;
            }
        }
    }

    if(no_result) printf("-1");

    return 0;
}
