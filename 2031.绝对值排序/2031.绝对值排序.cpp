#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>

using namespace std;

int cmp(const void *a, const void *b){
    int n1=*(int*)a, n2=*(int*)b;
    n1=n1<0?(-1*n1):n1;
    n2=n2<0?(-1*n2):n2;
    return n1<n2?-1:1;
}

int main()
{
    int n;
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n];                    //a是原数组，b是原数组绝对值化，用以排序

        for(i=0;i<n;i++)
             scanf("%d",&a[i]);      //初始化数组a和b

        qsort(a,n,sizeof(int),cmp);

        for(i=0;i<n-1;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[i]);

    }
    return 0;
}

