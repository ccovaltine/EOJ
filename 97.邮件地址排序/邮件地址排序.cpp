#include <bits/stdc++.h>
using namespace std;
typedef struct{
    string user;
    string net;
} Addr;

bool cmp(Addr a, Addr b){
    if(a.net==b.net)
        return a.user>b.user;
    else
        return a.net<b.net;
}

int main()
{
    int len;
    scanf("%d", &len);
    Addr data[len];
    while (getchar() != '\n')
        continue;
    for (int i = 0; i < len; i++){
        char ch;
        while((ch=getchar())!='@'){
            data[i].user += ch;
        }
        while ((ch = getchar()) != '\n' && ch != EOF){
            data[i].net += ch;
        }
    }
    sort(data, data + len, cmp);
    for (int k = 0; k < len; k++)
        cout << data[k].user << "@" << data[k].net << endl;
    return 0;
}
