#include<bits/stdc++.h>
using namespace std;

int min_divisor(const int num){
    /*******************
    如果num是素数则返回1，否则返回“最大的最小因数”
    *******************/
    int sqrt_num=(int)sqrt((double)num);
    for(int i=2;i<=sqrt_num;i++){
        if(num%i==0){
            return i;
        }
    }
    return 1;
}

int legendre_symbol(const int a, const int p){
    /*******************
    计算a对p的勒让德符号
    *******************/
    int molec,denom,coeff;//分子 分母 系数
    int tmp;
    molec=a; denom=p; coeff=1;
    while((molec!=1)&&(molec!=denom-1)&&(molec!=2)){
        printf("coeff=%d molec=%d denom=%d\n",coeff,molec,denom);
        if(min_divisor(molec)!=1){
            printf("molec=%d 不是素数\n",molec);
            int _a=min_divisor(molec);
            int _p=denom;
            molec=molec/_a;
            coeff*=legendre_symbol(_a,_p);
        }
        else{
            coeff*=pow(-1,(double)(((molec-1)/2)*((denom-1)/2)));
            tmp=denom;
            denom=molec;
            molec=tmp%denom;
        }
    }
    if(molec==1){
        return coeff;
    }
    else if(molec==2){
        if((denom%8==1)||(denom%8==7)) return coeff;
        else return (-1*coeff);
    }
    else{
        return (coeff*pow(-1,(double)(denom-1)/2));
    }
}

int b_of_module_p(const int p, const int s){
    /*******************
    由p和s构造一个参数b
    *******************/
    int n=1,b=1;
    for(;n<p;n++){
        if(legendre_symbol(n,p)==-1)
            break;
    }
    for(int i=0;i<s;i++){
        b=(b*n)%p;
    }
    return b;
}

int main(){
    int p=0,s=0;
    int b;
    while(1){
        scanf("%d",&p);
        s=p-1;
        while(s%2!=1){
            s/=2;
        }
        printf("p=%d s=%d\n",p,s);
        b=b_of_module_p(p,s);
        printf("%d\n",b);
    }
    return 0;
}
