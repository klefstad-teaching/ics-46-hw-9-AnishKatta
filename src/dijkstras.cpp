#include "dijkstras.h"
#include <climits>
#include <queue>
#include <utility>


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    //previous values should be nothing initially
    int num = G.size();
    vector<int> distances(num, INT_MAX);
    vector<int> visited(num, false);
    previous.resize(num, -1);
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    
    pq.push({0, source});
    //weight, vertex
    distances[source] = 0;
    while(!pq.empty()){
        std::pair<int, int> edge = pq.top();
        pq.pop();
        int currVertex = edge.second;
        if(visited[currVertex]){
            continue;
        }
        visited[currVertex] = true;
        for(Edge e : G[currVertex]){
            int neighbor = e.dst;
            int weight = e.weight;
            if(!visited[neighbor] && distances[currVertex] + weight < distances[neighbor]){
                distances[neighbor] = distances[currVertex] + weight;
                previous[neighbor] = currVertex;
                // pq.push({neighbor, distances[neighbor]});
                pq.push({distances[neighbor], neighbor});
            }
        }

    }
    return distances;


    //previous vector stores predecessors for each vertex
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    std::vector<int> path;
    if(distances[destination] == INT_MAX){
        return path;
    }
    while(destination != -1){
        path.push_back(destination);
        destination = previous[destination];
    }
    std::reverse(path.begin(), path.end());
    return path;


}

void print_path(const vector<int>& v, int total){
    for(int vec: v){
        std::cout << vec << " ";
    }
    std::cout << "\n";
    std::cout << "Total cost is " << total << std::endl;
}