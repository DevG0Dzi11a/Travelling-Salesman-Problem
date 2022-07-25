#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int>mypr;
#define inf INT_MAX
vector<mypr>selected_graph[5];
priority_queue<mypr>prQ;


void input_graph(vector<mypr>graph[], int nodes, int edges)
{
    int starting_node, ending_node, weight;
    cout<< "Enter \nstarting node    ending node    weight"<<endl;
    //Assigning default value to all the edges
    for(int i=1; i<5; i++)
    {
        for(int j=1; j<5; j++)
        {
            graph[i].push_back(make_pair(j, inf));
        }
    }
    //taking input for the edges
    for(int i=1; i<=edges; i++)
    {
        cin>>starting_node>>ending_node>>weight;
        if(starting_node!=ending_node)
            graph[starting_node][ending_node-1].second = weight;
    }
}


int reduce_cost(vector<mypr>graph[])
{
    int minimum, min_cost=0;
    vector<mypr>temp_graph[5];
    for(int i=1; i<5; i++)
    {
        temp_graph[i] = graph[i];
    }
    // Row reduction
    for(int i=1; i<5; i++)
    {
        minimum=inf;
        //finding the minimum in a row
        for(int j=0; j<4; j++)
        {
            if(minimum>temp_graph[i][j].second && temp_graph[i][j].second!=inf)
            {
                minimum = temp_graph[i][j].second;
            }
        }
        cout<<"Minimum value in row "<<i<<" : "<<minimum<<endl;
        for(int j=0; j<4; j++)
        {
            if(temp_graph[i][j].second!=inf)
                temp_graph[i][j].second-=minimum;
        }
        min_cost += minimum;
    }
    cout<<"Minimum cost from all the row: "<<min_cost<<endl;


    //Column reduction
    for(int i=0; i<4; i++)
    {
        minimum=inf;
        //finding the minimum in a row
        for(int j=1; j<5; j++)
        {
            if(minimum>temp_graph[j][i].second && temp_graph[j][i].second!=inf)
            {
                minimum = temp_graph[j][i].second;
            }
        }
        cout<<"Minimum value in column "<<i<<" : "<<minimum<<endl;
        for(int j=1; j<5; j++)
        {
            if(temp_graph[j][i].second!=inf)
                temp_graph[j][i].second-=minimum;
        }
        min_cost += minimum;
    }

    for(int i=1; i<5; i++)
    {
        selected_graph[i] = temp_graph[i];
    }
    return min_cost;
}

void output_graph(vector<mypr>graph[])
{
    cout<<"    "<<"        0              1              2              3  "<<endl;
    cout<<"    "<<"        1              2              3              4  "<<endl;
    cout<<"----"<<"--------------------------------------------------------"<<endl;
    for(int i=1; i<5; i++)
    {

        cout<<i <<" |";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<setw(10)<<graph[i][j].second<<"     ";
        }
        cout<<endl;
    }

}

int main()
{
    int nodes=4, edges=12;
    vector<mypr>graph[5];
    int status[5] = {0,0};
    //cout<<"Enter nodes: ";
    //cin>>nodes;
    //cout<<"Enter edges: ";
    //cin>>edges;
    input_graph(graph, nodes, edges);
    output_graph(graph);
    int min_cost = reduce_cost(graph);
    cout<<"After Reduction min cost : "<<min_cost<<endl;
    for(int i = 1; i<5; i++)
    {
        graph[i] = selected_graph[i];
    }
    output_graph(graph);


    status[1] = 1;
    int min_cost_node=0;

    for(int i=1; i<5; i++)
    {
        for(int j=1; j<5; j++)
        {
            if(status[j] != 1)
            {

            }
        }
    }
    return 0;
}
