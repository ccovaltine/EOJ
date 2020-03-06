#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;


bool is_prime(int num){
    if(num<=1) return false;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0)return false;
    }
    return true;
}

struct Item{
    int x;
    int y;
    int val;
};

bool cmp(Item a, Item b){
    if(a.val!=b.val) return a.val<b.val;
    else if(a.x!=b.x) return a.x<b.x;
    else if(a.y!=b.y) return a.y<b.y;
    else return false;
}

int main()
{
    int T; cin>>T;

    vector<int> vec1;
    for(int i=2;i<10010;i++){
        vector<int>::iterator it;
        if(is_prime(i))
            vec1.push_back(i);
    }

    for(int t=0;t<T;t++){ //the number of problems
        int n; cin>>n;
        Item item[n];
        for(int i=0;i<n;i++){
            cin>>item[i].x>>item[i].y;
            vector<int>::iterator it1,it2;
            it1=lower_bound(vec1.begin(),vec1.end(),item[i].x);
            it2=upper_bound(vec1.begin(),vec1.end(),item[i].y);
            item[i].val=it2-it1;
        }
        sort(item,item+n,cmp);
        cout<<"case #"<<t<<":"<<endl;
        for(int i=0;i<n;i++){
            cout<<item[i].x<<" "<<item[i].y<<endl;
        }
    }

    return 0;
}
