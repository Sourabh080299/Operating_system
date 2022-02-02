#include<bits/stdc++.h>
using namespace std;
void get_ct(vector<vector<int> > process,vector<int> &ct,vector<int> &wt){
    if(process.size()==0)return;
       priority_queue<vector<int> > q;
       vector<int> v={process[0][1],process[0][0],process[0][2]};
       q.push(v);
       int counter=0;
       for(int i=1;i<process.size();i++){
            if(process[i][0]>counter)i--;
            
       }

}
void get_tat(vector<vector<int> > process,vector<int> &tat,vector<int> ct){
       for(int i=0;i<process.size();i++){
           tat.push_back(ct[i]-process[i][0]);
       }
}
void get_wt(vector<int> tat,vector<int> ct,vector<int> &wt){
       for(int i=0;i<ct.size();i++){
           wt.push_back(tat[i]-ct[i]);
       }
}
void finddata(vector<vector<int> > process){
    vector<int> ct,wt,tat,rt;
    get_ct(process,ct,wt);
    get_tat(process,tat,ct);
    // get_wt(tat,ct,wt);
    cout<<"process"<<" "<<"arrival"<<" "<<"brust"<<" "<<"ct"<<"    "<<"wt"<<"   "<<"tat"<<" "<<endl;
    for(int i=1;i<=ct.size();i++){
        cout<<"P"<<process[i-1][2]<<"       "<<process[i-1][0]<<"      "<<process[i-1][1]<<"      "<<ct[i-1]<<"     "<<wt[i-1]<<"     "<<tat[i-1]<<"  "<<endl;
    }
}
int main(){
    vector<vector<int> > process;
    int n;
    cout<<"Enter Numbers of Process:";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
       cout<<"process:"<<i<<endl;
       cout<<"Enter arrival time of process:";
       cin>>a;
       cout<<"Enter brust time of process:";
       cin>>b;
       vector<int> v={a,b,i};
       process.push_back(v);
    }
    sort(process.begin(),process.end());
    finddata(process);
    return 0;
}
