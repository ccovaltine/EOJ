#include<iostream>
#include<algorithm>
using namespace std;

struct Team{
    int name;
    int score;
    int win;
    int lose;
};

bool cmp(Team team1, Team team2){
    if(team1.score>team2.score)
        return true;
    else if(team1.score==team2.score&&team1.win>team2.win)
        return true;
    else if(team1.score==team2.score&&team1.win==team2.win
            &&team1.lose<team2.lose)
        return true;
    else if(team1.score==team2.score&&team1.win==team2.win
            &&team1.lose==team2.lose&&team1.name<team2.name)
        return true;
    else
        return false;

}

int main(){
    int n=-1,m=-1;
    cin>>n>>m;
    while(n!=0||m!=0){
        Team team[n];
        for(int i=0;i<=n;i++){
            team[i].lose=0; team[i].score=0; team[i].win=0;
            team[i].name=i+1;
        }
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(c==1){
                team[a-1].win++; team[a-1].score+=3;
                team[b-1].lose++; team[b-1].score--;
            }
            if(c==-1){
                team[b-1].win++; team[b-1].score+=3;
                team[a-1].lose++; team[a-1].score--;
            }
            if(c==0){
                team[a-1].score++; team[b-1].score++;
                //team[a-1].lose++; team[b-1].lose++;
            }
        }
        sort(team,team+n,cmp);
        for(int i=0;i<n-1;i++){
                cout<<team[i].name<<" ";
        }
        cout<<team[n-1].name<<endl;
        cin>>n>>m;
    }
    return 0;
}

