#include<bits/stdc++.h>
using namespace std;
#define inf 999
/*
999 20 30 10 11
15 999 16 4 2
3 5 999 2 4
19 6 18 999 3
16 4 7 16 999
*/

//cost, matrix, path, dest
typedef vector<int> vec_d;
typedef vector<vec_d> vec_2d;
typedef pair<vec_d, int> pair1;
typedef pair<vec_2d, pair1> pair2;
typedef pair<int , pair2> main_pair;

priority_queue < main_pair > my_queue, temp_queue;
int nodes;
vec_2d cost_matrix;
vec_2d temp_mat;
int reduced_cost1;
int hold_cost;
vec_d temp_path;
int temp_cost=0;



void inputMatrix()
{
    int i, j, x;
    for(i=0; i<nodes; i++)
    {
        vec_d temp;
        for(j=0; j<nodes; j++)
        {
            cin>>x;
            temp.push_back(x);
        }
        cost_matrix.push_back(temp);
    }
}

void printMatrix(vec_2d temp)
{
    int i, j;
    for(i=0; i<nodes; i++)
    {
        for(j=0; j<nodes; j++)
        {
            if(temp[i][j] == inf)
                cout<<setw(5)<<"inf"<<" ";
            else
                cout<<setw(5)<<temp[i][j]<<" " ;
        }
        cout<<endl;
    }
}

vec_2d reduce(vec_2d temp)
{
    int i, j, minimum, min_cost=0;

    for(i=0; i<nodes; i++)//row reduction loop
    {
        minimum = inf;//setting a maximum value for minimum
        for(j=0; j<nodes; j++)//minimum finding loop
        {
            if(minimum>temp[i][j] && temp[i][j] != inf)
            {
                minimum = temp[i][j];
            }
        }
        for(j=0; j<nodes; j++)
        {
            if(temp[i][j] != inf)
            {
                temp[i][j]-=minimum;
            }
        }
        if(minimum != inf)
            min_cost += minimum;
    }
//    cout<<"Row min :"<< min_cost;
    for(i=0; i<nodes; i++)//column reduction loop
    {
        minimum = inf;
        for(j=0; j<nodes; j++)
        {
            if(minimum>temp[j][i] && temp[j][i] != inf)
            {
                minimum = temp[j][i];
            }
        }
        for(j=0; j<nodes; j++)
        {
            if(temp[j][i] != inf)
            {
                temp[j][i]-=minimum;
            }
        }
        if(minimum != inf)
            min_cost += minimum;
    }
//    cout<<"   Column min :"<< min_cost<<endl;
    if(reduced_cost1 == 0)
        reduced_cost1 = min_cost;
    else if(min_cost != inf)
        hold_cost = min_cost;
//    cout<<"Min cost : "<<min_cost<<" hold cost : "<<hold_cost<<endl;
    return temp;
}

void source_to_nodes(int source)
{
    int i, j, k, source_to_node_cost, total_cost;

    for(i=1; i<=nodes; i++)
    {
        vec_d path = temp_path;
        vec_2d temp = cost_matrix;
        if(i != source && temp[i-1][0] != inf)
        {
            path.push_back(i);
            source_to_node_cost = cost_matrix[source-1][i-1];
            temp[i-1][source-1] = inf;
            temp[i-1][0] = inf;
            for(j=1; j<=nodes; j++)
            {
                temp[source-1][j-1] = inf;
                temp[j-1][i-1] = inf;
            }
            cout<<endl<<i<<endl<<endl;
            cout<<"Path in SNC : ";
            for(int j=0; j<path.size(); j++)
            {
                cout<<path[j]<<" ";
            }
            cout<<endl;
            printMatrix(temp);
            temp = reduce(temp);
            total_cost = reduced_cost1 + source_to_node_cost + hold_cost;
            cout<<reduced_cost1<<"    "<<source_to_node_cost<<"    "<<hold_cost<<"      "<<total_cost<<endl;
            my_queue.push(make_pair((total_cost*(-1)), make_pair(temp, make_pair(path, i))));
            path.clear();
            if(path.size() == nodes)
                break;
        }
    }
}

int main()
{
    nodes = 5;
    //cout<<"Number of nodes :";
    //cin>>nodes;
    //cout<<"Enter the cost matrix :"<<endl;
    //inputMatrix();
    cost_matrix = {
        {999, 20, 30, 10, 11},
        {15, 999, 16, 4, 2},
        {3, 5, 999, 2, 4},
        {19, 6, 18, 999, 3},
        {16, 4, 7, 16, 999}
    };
    cout<<"Initial matrix : "<<endl;
    printMatrix(cost_matrix);
    vec_2d reduced_cost_matrix = reduce(cost_matrix);
    cost_matrix = reduced_cost_matrix;


    temp_path.push_back(1);
    source_to_nodes(1);
    main_pair  top = my_queue.top();
    cout<<"Path : ";
    cout<<my_queue.top().second.second.first[0];
    cout<<endl;
    temp_cost = temp_cost + my_queue.top().first*(-1);


    cost_matrix = my_queue.top().second.first;
    temp_path = my_queue.top().second.second.first;
    source_to_nodes(my_queue.top().second.second.first[my_queue.top().second.second.first.size()-1]);
    cout<<"Path : ";
    for(int i=0; i<my_queue.top().second.second.first.size(); i++)
        cout<<my_queue.top().second.second.first[i]<<" ";
    cout<<endl;
    temp_cost = temp_cost + my_queue.top().first*(-1);
    my_queue.pop();



    cost_matrix = my_queue.top().second.first;
    temp_path = my_queue.top().second.second.first;
    source_to_nodes(my_queue.top().second.second.first[my_queue.top().second.second.first.size()-1]);
    cout<<"Path : ";
    for(int i=0; i<my_queue.top().second.second.first.size(); i++)
        cout<<my_queue.top().second.second.first[i]<<" ";
    cout<<endl;


    cost_matrix = my_queue.top().second.first;
    temp_path = my_queue.top().second.second.first;
    source_to_nodes(my_queue.top().second.second.first[my_queue.top().second.second.first.size()-1]);
    cout<<"Path : ";
    for(int i=0; i<my_queue.top().second.second.first.size(); i++)
        cout<<my_queue.top().second.second.first[i]<<" ";
    cout<<endl;

    return 0;
}
