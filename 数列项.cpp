#include<bits/stdc++.h>
using namespace std;

class BigInt{
    string value;
public:
    BigInt();
    BigInt(const string num);
    BigInt operator+(const BigInt b);
    BigInt operator-(const BigInt b);
    void print();
};

BigInt::BigInt(){//默认初始值为0
    value="";
}

BigInt::BigInt(const string num){
    value=num;
}

BigInt BigInt::operator+(const BigInt bb){//大数加法
    BigInt result;
    const char *a=(this->value).c_str(), *b=bb.value.c_str();
    int l1=(this->value).length(),l2=bb.value.length();
    stack<char> sa,sb;
    stack<char> res;
    for(int i=0;i<l1;i++){
        sa.push(a[i]);
    }
    for(int i=0;i<l2;i++){
        sb.push(b[i]);
    }
    int m=0,n=0,up=0;
    while((!sa.empty())&&(!sb.empty())){
        m=sa.top()-'0';
        n=sb.top()-'0';
        res.push((m+n+up)%10+'0');
        up=(m+n+up)/10;
        sa.pop();
        sb.pop();
    }
    while(!sa.empty()){
        m=sa.top()-'0';
        res.push(((m+up)%10+'0'));
        up=(m+up)/10;
        sa.pop();
    }
    while(!sb.empty()){
        m=sb.top()-'0';
        res.push((m+up)%10+'0');
        up=(m+up)/10;
        sb.pop();
    }
    if(up>0){
        res.push(up+'0');
    }
    char c;
    while(!res.empty()){
        c=res.top();
        result.value=result.value+c;
        res.pop();
    }
    return result;
}

void BigInt::print(){
    cout<<value;
}

int main(){
    int k,n; scanf("%d%d",&k,&n);
    BigInt val[n];
    BigInt big0("0"),big1("1");
    val[0]=big0; val[1]=big1;
    for(int i=2;i<n;i++){
        val[i]=big0;
        for(int j=(i-k>=0?i-k:0);j<i;j++){
            val[i]=val[i] + val[j];
        }
    }
    val[n-1].print();
    return 0;
}
