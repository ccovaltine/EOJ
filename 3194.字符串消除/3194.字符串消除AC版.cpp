#include <bits/stdc++.h>
using namespace std;
//模拟：每个位置都试一遍

int T, cnt;
string str;

int rmov(string s)
{
    string temp=s;
    string ans="";
    int len=s.length();
    int i ,j ,flag=1;
    while(s!=ans){
        i=0, j=0, len=s.length();
        while(i<len){
            if(len==1) {ans=s;break;}
            if(s[i]!=s[i+1]) {
                ans+=s[i];
                i++;//虚指针后移
            }
            else {
                for(j=i+1;j<len&&s[j]==s[i];++j);
                i=j;
            }
        }
        if(s!=ans) {
            s=ans;
            ans="";
        }
    }
    return temp.length()-ans.length();
}

string add(string s, int pos, char ch)//在pos位置后插入字符
{
    string ans="";
    int len=s.length();
    for(int i=0;i<len;++i){
        ans+=s[i];
        if(i==pos) ans+=ch;
    }
    return ans;
}
int main()
{
    cin>>T;
    while(T--){
        cin>>str;
        int _max=0;
        int len=str.length();
        string temp=str;
        str='A'+str;_max=max(_max,rmov(str));
        str=temp;
        str='B'+str;_max=max(_max,rmov(str));
        str=temp;
        str='C'+str;_max=max(_max,rmov(str));
        str=temp;
        for(int i=0;i<len;++i){
            str=add(str,i,'A');_max=max(_max,rmov(str));
            str=temp;
            str=add(str,i,'B');_max=max(_max,rmov(str));
            str=temp;
            str=add(str,i,'C');_max=max(_max,rmov(str));
            str=temp;
        }
        printf("case #%d:\n",cnt++);
        cout<<_max<<endl;
    }
    return 0;
}
