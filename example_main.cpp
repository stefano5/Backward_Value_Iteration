#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

#include "dependencies/functions_stefano.cpp"
#include "backward_value_iteration.cpp"



using namespace std;

int main(int argc, char **argv) {
    string name_file;
    uint16_t n_iteration;
    string name_xf;

    /////////////////////////////////////// input check

    if (argc == 3) {
        name_file = string(argv[1]);
        n_iteration = atoi(argv[2]);
    } else if (argc == 2) {
        if (atoi(argv[1]) == 0) {
            name_file = string(argv[1]);
            cout << "Enter N (number interations): " << endl;
            cin >> n_iteration;
        } else {
            n_iteration = atoi(argv[1]);
            cout << "Enter file name: " << endl;
            cin >> name_file;
        }
    } else if (argc == 1) {
        cout << "Enter file name: " << endl;
        cin >> name_file;
        cout << "Enter N (number interations): " << endl;
        cin >> n_iteration;
    } else {
        cerr << "Numero di parametri errati :(" << endl;
        cerr << "Parameter numbers is wrong :(" << endl;
        cerr << argv[0] << " <name file> <number iterations>" << endl;
        exit(-1);
    }

    cout << "File name: " << name_file << endl;
    cout << "Number iteration given: " << n_iteration << endl;

    /////////////////////////////////////// check the existence of the file 

    if (!API_S::exist_file(name_file)) {
        cerr << "File [" << name_file << "] doesn't exist" << endl;
        exit(-1);
    }

    /////////////////////////////////////// read file and store it in a vector<string>
    
    std::vector<std::string> graph_on_file = API_S::read_file(name_file);

    /////////////////////////////////////// choose starting node and arrival node

    cout << "Print graph: " << endl;  // if you need
    cout << API_S::vector2string(graph_on_file) << endl;
    cout << "Enter arrival node: " << endl;
    string arrival_node;
    cin >> arrival_node;
    cout << "[" << arrival_node << "] is the arrival node" << endl;
    cout << endl;

    string starting_node;
    //cout << "Da quale nodo vuoi vedere il path ottimo?" << endl;
    cout << "Chose which optimal path to see. Enter a starting node: " << endl;
    cin >> starting_node;

    /////////////////////////////////////// Instance class, compute optimal cost and show it

    Graph graph(graph_on_file);
    //graph.print_graph();  // if you need
    graph.compute_optimal_cost(n_iteration, arrival_node);

    cout << "Optimal path starting from " << starting_node << " is: " << endl;
    cout << graph._get_optimal_path(starting_node) << endl;
    vector<Node> op =  graph.get_optimal_path(starting_node);

    cout << "Optimal path:" << endl;
    for (Node n:op) {
        cout << "\t" <<n.get_head() << endl;
    }

    graph.~Graph();


    /////////////////////////////////////// All done

    exit(EXIT_SUCCESS);
}

