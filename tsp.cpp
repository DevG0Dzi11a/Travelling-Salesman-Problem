#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int>mypr;
vector<mypr>graph[5];
vector<mypr>selected_graph[5];

void input_graph(int nodes, int edges)
{
    int starting_node, ending_node, weight;
    cout<< "Enter \nstarting node    ending node    weight"<<endl;
    //Assigning default value to all the edges
    for(int i=1; i<5; i++)
    {
        for(int j=1; j<5; j++)
        {
            graph[i].push_back(make_pair(j, 999));
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

/*int reduce_cost()
{
    int minimum, min_cost=0;
    // Row reduction
    for(int i=1; i<5; i++)
    {
        minimum=1000;
        //finding the minimum in a row
        for(int j=0; j<4; j++)
        {
            if(minimum>graph[i][j].second && graph[i][j].second!=999)
            {
                minimum = graph[i][j].second;
            }
        }
        cout<<"Minimum value in row "<<i<<" : "<<minimum<<endl;
        for(int j=0; j<4; j++)
        {
            if(graph[i][j].second!=999)
                graph[i][j].second-=minimum;
        }
        min_cost += minimum;
    }
    cout<<"Minimum cost from all the row: "<<min_cost<<endl;

    //Column reduction
    for(int i=0; i<4; i++)
    {
        minimum=1000;
        //finding the minimum in a row
        for(int j=1; j<5; j++)
        {
            if(minimum>graph[j][i].second && graph[j][i].second!=999)
            {
                minimum = graph[j][i].second;
            }
        }
        cout<<"Minimum value in column "<<i<<" : "<<minimum<<endl;
        for(int j=1; j<5; j++)
        {
            if(graph[j][i].second!=999)
                graph[j][i].second-=minimum;
        }
        min_cost += minimum;
    }
    cout<<"Minimum cost: "<<min_cost<<endl;
    return min_cost;
}*/

int reduce_cost(int from, int to)
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
        minimum=1000;
        //finding the minimum in a row
        for(int j=0; j<4; j++)
        {
            if(minimum>temp_graph[i][j].second && temp_graph[i][j].second!=999)
            {
                minimum = temp_graph[i][j].second;
            }
        }
        cout<<"Minimum value in row "<<i<<" : "<<minimum<<endl;
        for(int j=0; j<4; j++)
        {
            if(temp_graph[i][j].second!=999)
                temp_graph[i][j].second-=minimum;
        }
        min_cost += minimum;
    }
    cout<<"Minimum cost from all the row: "<<min_cost<<endl;

    //Column reduction
    for(int i=0; i<4; i++)
    {
        minimum=1000;
        //finding the minimum in a row
        for(int j=1; j<5; j++)
        {
            if(minimum>temp_graph[j][i].second && temp_graph[j][i].second!=999)
            {
                minimum = temp_graph[j][i].second;
            }
        }
        cout<<"Minimum value in column "<<i<<" : "<<minimum<<endl;
        for(int j=1; j<5; j++)
        {
            if(temp_graph[j][i].second!=999)
                temp_graph[j][i].second-=minimum;
        }
        min_cost += minimum;
    }
    for(int i=1; i<5; i++)
    {
        graph[i] = temp_graph[i];
    }
    cout<<"Minimum cost: "<<min_cost<<endl;
    return min_cost;
}

void output_graph()
{
    cout<<"    "<<"        0              1              2              3  "<<endl;
    cout<<"    "<<"        1              2              3              4  "<<endl;
    cout<<"----"<<"--------------------------------------------------------"<<endl;
    for(int i=1; i<5; i++)
    {

        cout<<i <<" |";
        /*if(graph[i].size()==0)
            cout<<"None";*/
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
    //cout<<"Enter nodes: ";
    //cin>>nodes;
    //cout<<"Enter edges: ";
    //cin>>edges;
    input_graph(nodes, edges);
    output_graph();
    int min_cost = reduce_cost(1,2);
    cout<<"After Reduction"<<endl;
    output_graph();


    return 0;
}
