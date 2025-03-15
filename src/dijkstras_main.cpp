#include "dijkstras.h"


void test_dijkstras_small_dest_2(){
    Graph G;
    file_to_graph("../src/small.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> path = extract_shortest_path(distances, previous, 2);
    print_path(path, path.size());
}

void test_dijkstras_small_dest_3(){
    Graph G;
    file_to_graph("../src/small.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> path = extract_shortest_path(distances, previous, 3);
    print_path(path, path.size());
}

void test_dijkstras_small_dest_1(){
    Graph G;
    file_to_graph("../src/small.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> path = extract_shortest_path(distances, previous, 1);
    print_path(path, path.size());
}



int main(){
    test_dijkstras_small_dest_2();
    test_dijkstras_small_dest_3();
    test_dijkstras_small_dest_1();

    return 0;
}

