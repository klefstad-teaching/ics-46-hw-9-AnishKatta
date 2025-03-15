#include "dijkstras.h"


void test_dijkstras_small_dest_2(){
    Graph G;
    file_to_graph("../src/small.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> path = extract_shortest_path(distances, previous, 2);
    print_path(path, distances[2]);
}

void test_dijkstras_small_dest_3(){
    Graph G;
    file_to_graph("../src/small.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> path = extract_shortest_path(distances, previous, 3);
    print_path(path, distances[3]);
}

void test_dijkstras_small_dest_1(){
    Graph G;
    file_to_graph("../src/small.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> path = extract_shortest_path(distances, previous, 1);
    print_path(path, distances[1]);
}


void test_dijkstras_med_dest(){
    Graph G;
    file_to_graph("../src/medium.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> path = extract_shortest_path(distances, previous, 5);
    print_path(path, distances[5]);
}

void test_dijkstras_med_large(){
    Graph G;
    file_to_graph("../src/large.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> path = extract_shortest_path(distances, previous, 6);
    print_path(path, distances[6]);
}



int main(){
    test_dijkstras_small_dest_2();
    test_dijkstras_small_dest_3();
    test_dijkstras_small_dest_1();
    test_dijkstras_med_dest();
    test_dijkstras_med_large();
    return 0;
}

