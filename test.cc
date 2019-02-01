#include <unistd.h> // getopt 
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include <math.h>

#include <fstream> //file output
#include <sstream> //string operation

#include <stdio.h>

using namespace std;

// ########################################## //
// ##  C program for Dijkstra's single source shortest path algorithm. 
// ##  The program is for adjacency matrix representation of the graph. ## //
// ##  Modified based on https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/  ## //
// ########################################## //

// A utility function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[], int V) 
{    
    // Initialize min value 
    int min = 10000, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) {
                min = dist[v]; 
                min_index = v; 
        }
        
    return min_index; 
} 

// Function to print shortest path from source to j using parent array 
void printPath(int parent[], int j, int src, int dst, vector< vector<int> > &pair_path, int V) 
{ 
    // Base Case : If j is source 
    if (parent[j] == -1) 
        return; 
  
    printPath(parent, parent[j], src, dst, pair_path, V); 
  
    //printf("%d ", j); 
    pair_path[src*V+dst].push_back(j);
} 

// A utility function to print the constructed distance array 
int printSolution(int dist[], int V, int parent[], int src, vector< vector<int> > &pair_path) 
{ 
    //int src = 0; 
    //printf("Vertex\t Distance\tPath"); 
    for (int i = 0; i < V; i++) 
    { 
        if (i != src) {
                //printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src); 
                int dst = i;
                printPath(parent, i, src, dst, pair_path, V); 
        }
    } 
}

// Funtion that implements Dijkstra's single source shortest path algorithm for a graph represented using adjacency matrix representation 
void dijkstra(int V, vector<int> graph, int src, vector< vector<int> > &pair_path) 
{ 
      
    // The output array. dist[i] will hold the shortest distance from src to i 
    int dist[V];  
  
    // sptSet[i] will true if vertex i is included / in shortest path tree or shortest distance from src to i is finalized 
    bool sptSet[V]; 
  
    // Parent array to store shortest path tree 
    int parent[V]; 
  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = -1; 
        dist[i] = 10000; 
        sptSet[i] = false; 
    } 
  
    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) 
    { 
        // Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in first iteration. 
        int u = minDistance(dist, sptSet, V); 
  
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < V; v++) 
  
            // Update dist[v] only if is not in sptSet, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u*V+v] && dist[u] + graph[u*V+v] < dist[v]) 
            { 
                parent[v] = u; 
                dist[v] = dist[u] + graph[u*V+v]; 
            }  
    } 
  
    // print the constructed distance array 
    printSolution(dist, V, parent, src, pair_path); 
}

int main(int argc, char *argv[])
{
        // int c;
        // static char* topology_file; // topology file

        // while((c = getopt(argc, argv, "t:")) != -1) {
        // switch (c) { 
        //         case 't': //topology file (Topology = 5)
        //                 topology_file = optarg;
        //                 break;               
        //         default:
        //                 //usage(argv[0]);
        //                 cout << " This option is not supported. " << endl;
        //                 return EXIT_FAILURE;
        //         }
        // }

        // vector<int> topo_file;
        // vector<int> topo_sws_dup; // duplicate
        // vector<int> topo_sws_uni; // unique
        // ifstream infile_feat(topology_file);
        // string line_data;
        // int data;
        // while (!infile_feat.eof()){
        //         getline(infile_feat, line_data);
        //         stringstream stringin(line_data);
        //         int column = 0;
        //         while (stringin >> data){
        //                 if (column == 0){ // src_sw
        //                         topo_file.push_back(data);
        //                         topo_sws_dup.push_back(data);
        //                         topo_sws_uni.push_back(data);
        //                         column++;
        //                 }
        //                 else if (column == 1){ // src_port
        //                         topo_file.push_back(data);    
        //                         column++;                           
        //                 }
        //                 else if (column == 2){ // dst_sw
        //                         topo_file.push_back(data); 
        //                         topo_sws_dup.push_back(data);
        //                         topo_sws_uni.push_back(data);  
        //                         column++;                                                           
        //                 }
        //                 else if (column == 3){ // dst_port
        //                         topo_file.push_back(data);   
        //                         column++;                            
        //                 }                                                
        //         }
        // }
        // infile_feat.close();

        // sort(topo_sws_uni.begin(), topo_sws_uni.end());
        // topo_sws_uni.erase(unique(topo_sws_uni.begin(), topo_sws_uni.end()), topo_sws_uni.end());
        // int switch_num = topo_sws_uni.size();
        // int degree = 0;
        // int cnt;
        // for (int i=0; i<switch_num; i++){
        //         cnt = count(topo_sws_dup.begin(), topo_sws_dup.end(), topo_sws_uni[i]);
        //         if (cnt > degree) degree = cnt;
        // }

        // for (int i=0; i<topo_file.size(); i++) cout << topo_file[i] << " ";
        // cout << endl;
        // for (int i=0; i<topo_sws_uni.size(); i++) cout << topo_sws_uni[i] << " ";
        // cout << endl;   
        // for (int i=0; i<topo_sws_dup.size(); i++) cout << topo_sws_dup[i] << " ";    
        // cout << endl; 
        // cout << degree << endl;      
        // cout << switch_num << endl;    

        // static int Host_Num = 1;
        // int ports = ((switch_num-1)+1+2*Host_Num)*switch_num;  
        // vector<int> Switch_Topo(ports);

        // for (int i=0; i<Switch_Topo.size(); i++){
        //         Switch_Topo[i] = -1;
        // }
        // for (int i=0; i<switch_num; i++){
        //         for (int j=0; j<topo_file.size(); j=j+2){
        //                 if (topo_sws_uni[i] == topo_file[j]){
        //                         int connect_sw = -1;
        //                         int connect_port = -1;
        //                         if (j%4 == 0){
        //                                 connect_sw = topo_file[j+2];
        //                                 connect_port = topo_file[j+1];
        //                         }
        //                         else if (j%4 == 2){
        //                                 connect_sw = topo_file[j-2];
        //                                 connect_port = topo_file[j+1];
        //                         }
        //                         for (int k=0; k<switch_num; k++){
        //                                 if (topo_sws_uni[k] == connect_sw){
        //                                         Switch_Topo[i*((switch_num-1)+1+2*Host_Num)+k] = connect_port;
        //                                 }
        //                         }
        //                 }
        //         }
        // }

        // for (int i=0; i<Switch_Topo.size(); i++) {
        //         cout << Switch_Topo[i] << " ";    
        //         if (i%((switch_num-1)+1+2*Host_Num) == ((switch_num-1)+1+2*Host_Num)-1)
        //                 cout << endl;  
        // }

        // int V = switch_num;
        // vector<int> graph(V*V);
        // for (int i=0; i<graph.size(); i++){
        //         if (Switch_Topo[(i/V)*((switch_num-1)+1+2*Host_Num)+i%V] == -1){
        //                 graph[i] = 0;
        //         }
        //         else {
        //                 graph[i] = 1;
        //         }
        // }
        // for (int i = 0; i < graph.size(); i++){
        //         cout << graph[i] << " ";
        //         if (i%V == V-1) cout << endl;
        // }

        // vector< vector<int> > pair_path(V*V);
        // for (int i=0; i<V; i++){
        //          dijkstra(V, graph, i, pair_path); 
        // }  
        // //dijkstra(V, graph, 1, pair_path); 

        // for (int i=0; i<V*V; i++){
        //         cout << i << ": ";
        //         for (int j=0; j<pair_path[i].size(); j++){
        //                 cout << pair_path[i][j] << " ";
        //         }
        //         cout << endl;
        // } 

        int a = -1, b = -1, c = -1;
        while ( cin >> a){	
                cin >> b; 
                // getchar();
                // char x;
                // while((x=cin.get()) != '\n') 
                //     if(x != ' ' && x != '\t'){
                //         //c = x-48;
                //         cin >> c;
                //         break;
                //     }   
                char array[20];
                cin.getline(array, 20);
                stringstream stringin(array);
                int flowid;
                while (stringin >> flowid){c = flowid;}
                cout << a << " " << b << " " << c << endl;
        }     

}
