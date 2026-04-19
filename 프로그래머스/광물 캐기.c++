#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int dia, iron, stone;
}m;
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<m>v;
    int d=0,i=0,s=0;
    int total=min((int)minerals.size(),(picks[0]+picks[1]+picks[2])*5);
    for(int k=0;k<total;k++)
    {

        if (minerals[k].substr(0,1)=="d")
            d++;
        else if (minerals[k].substr(0,1)=="s")
            s++;
        else
            i++;
        if ((k+1)%5==0||k==total-1)
        {
            v.push_back({d,i,s});
            d=0,i=0,s=0;
        }
    }
    sort(v.begin(),v.end(),[](const m &a,const m &b){
        if (a.dia != b.dia) return a.dia > b.dia;
        if (a.iron != b.iron) return a.iron > b.iron;
        return a.stone > b.stone;
    });
    
    int pick_id=0;
    for(auto&group:v)
    {
        while(pick_id<3&&!picks[pick_id])pick_id++;
        if (pick_id==3)break;
        
        if (pick_id==0)
        {
            answer+=group.dia+group.iron+group.stone;
        }
        else if (pick_id==1)
        {
            answer+=group.dia*5+group.iron+group.stone;
        }
        else
        {
            answer+=group.dia*25+group.iron*5+group.stone;
        }
        picks[pick_id]--;
    }
    
    return answer;
}
