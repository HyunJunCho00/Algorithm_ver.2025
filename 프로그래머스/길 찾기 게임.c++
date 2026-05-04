#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int id,x,y;
};
void insert(int parent,int child,const vector<Node>&node,vector<int>&leftnode,vector<int>&rightnode)
{
    if(node[parent].x>node[child].x)
    {
        if(leftnode[parent]==0)leftnode[parent]=child;
        else insert(leftnode[parent],child,node,leftnode,rightnode);
    }
    else
    {
        if(rightnode[parent]==0)rightnode[parent]=child;
        else insert(rightnode[parent],child,node,leftnode,rightnode);
    }
}
void preorder(int parent,vector<int>&leftnode,vector<int>&rightnode,vector<vector<int>>&answer)
{
    answer[0].push_back(parent);
    if(leftnode[parent]!=0)
        preorder(leftnode[parent],leftnode,rightnode,answer);
    if(rightnode[parent]!=0)
        preorder(rightnode[parent],leftnode,rightnode,answer);
}
void postorder(int parent,vector<int>&leftnode,vector<int>&rightnode,vector<vector<int>>&answer)
{
    if(leftnode[parent]!=0)
        postorder(leftnode[parent],leftnode,rightnode,answer);
    if(rightnode[parent]!=0)
        postorder(rightnode[parent],leftnode,rightnode,answer);
    answer[1].push_back(parent);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<int>leftnode(nodeinfo.size()+1,0);
    vector<int>rightnode(nodeinfo.size()+1,0);
    vector<Node> node(nodeinfo.size()+1);
    vector<Node> nodes;
    for(int i = 0; i < nodeinfo.size(); i++) 
    {
        node[i + 1] = {i + 1, nodeinfo[i][0], nodeinfo[i][1]};
        nodes.push_back(node[i + 1]);
    }
        
    sort(nodes.begin(), nodes.end(), [](Node a, Node b) {
        if (a.y == b.y) return a.x < b.x;
        return a.y > b.y;
    });
    for(int i=1;i<nodes.size();i++)
    {
        insert(nodes[0].id,nodes[i].id,node,leftnode,rightnode);
    }
    preorder(nodes[0].id,leftnode,rightnode,answer);
    postorder(nodes[0].id,leftnode,rightnode,answer);
    
    return answer;
}
