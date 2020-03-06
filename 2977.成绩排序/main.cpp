#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

struct Student{
    char id[12];
    int num_of_questions;
    int succeed_questions[11];
    int score;
};

/*bool cmp(Student a, Student b){
    //Student a=*pa, b=*pb;
    if(a.score!=b.score) return a.score>b.score;
    else return strcmp(a.id,b.id)<0?true:false;
}*/

int cmp(const void *a, const void *b){
    Student *stu1,*stu2;
    stu1=(Student*)a,stu2=(Student*)b;
    if(stu1->score!=stu2->score)
        return stu1->score-stu2->score<0?1:-1;
    else
        return strcmp(stu1->id,stu2->id)<0?-1:1;
}

int main()
{
    int T; cin>>T;
    for(int cas=0;cas<T;cas++){
        int n,m,g; cin>>n>>m>>g;
        int num_of_pass=0;
        int point[m+1];
        for(int i=1;i<=m;i++)
            cin>>point[i];

        Student stu[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<11;j++)
                cin>>stu[i].id[j];

            cin>>stu[i].num_of_questions;

            stu[i].score=0;
            for(int j=0;j<stu[i].num_of_questions;j++){
                cin>>stu[i].succeed_questions[j];
                stu[i].score+=point[stu[i].succeed_questions[j]];
            }
        }
        //sort(stu,stu+n,cmp);
        qsort(stu,n,sizeof(Student),cmp);

        cout<<"case #"<<cas<<":"<<endl;

        for(int i=0;stu[i].score>=g;i++)
            num_of_pass++;
        cout<<num_of_pass<<endl;
        for(int i=0;i<num_of_pass;i++){
            for(int j=0;j<11;j++)
                cout<<stu[i].id[j];
            cout<<" "<<stu[i].score<<endl;
        }

    }
    return 0;
}
