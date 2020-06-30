#include <bits/stdc++.h>
using namespace std;

string line; char *s;  int len;
int R, B, Y, G;

int calc_color(int i){
    bool is_R=true, is_B=true, is_Y=true, is_G=true;
    int cnt=0;
    for(int stt=i-3;stt<=i;stt++){
        is_R=true; is_B=true;
        is_Y=true; is_G=true;
        cnt=0;
        for(int i=stt;i<=stt+3;i++){
            switch(s[i]){
            case 'R':
                is_R=false;
                cnt++;
                break;
            case 'B':
                is_B=false;
                cnt++;
                break;
            case 'Y':
                is_Y=false;
                cnt++;
                break;
            case 'G':
                is_G=false;
                cnt++;
                break;
            }
            if(cnt<3) continue;
            if(is_R) return 1;
            if(is_B) return 2;
            if(is_Y) return 3;
            if(is_G) return 4;
        }
    }
    return -1;
}

int main(){
    int T; scanf("%d",&T);
    int color[4]; int tmp;
    int times;
    for(int cas=0;cas<T;cas++){
        cin>>line;
        s=(char*)line.c_str();
        len=line.length();
        times=1;
        for(int i=0;i<4;i++){color[i]=0;}
        while(times>0){
            for(int i=0;i<len;i++){
                if(s[i]=='!'){
                    tmp=calc_color(i);
                    if(tmp!=-1){
                        color[tmp-1]++;
                        switch(tmp){
                        case 1:
                            s[i]='R';
                            break;
                        case 2:
                            s[i]='B';
                            break;
                        case 3:
                            s[i]='Y';
                            break;
                        case 4:
                            s[i]='G';
                            break;
                        }
                    }
                    else{
                        times++;
                    }
                }
            }
            times--;
        }

        printf("case #%d:\n",cas);
        for(int i=0;i<4;i++){
            printf("%d ",color[i]);
        }
        printf("\n");
    }
    return 0;
}
