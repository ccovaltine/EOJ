#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

typedef struct {
    int x, y, z;
} Point;

//********** Specification of NearPoints **********
int NearPoints(Point *p, int n) {
    int ans=0;
    for(int i=0;i<n;i++){
        int tmp=pow(p[i].x,2)+pow(p[i].y,2)+pow(p[i].z,2);
        if(tmp>=0&&tmp<10000) ans++;
    }
    return ans;
}

/***************************************************************/
int main() {
    int n, i;
    Point p[MAX];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
    printf("%d\n", NearPoints(p, n));
    return 0;
}
