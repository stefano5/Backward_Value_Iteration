# Backward_Value_Iteration


Given a graph this code compute the optimal cost using the Backward Value Iteration.
The algorithm, given an arrival node, compute all the optimal paths from all the nodes

It is a discrete alghorithm that, according Bellman theory, want a fixed N number of step.
In order to avoid this parameter add an arc (with cost = 0) that have tail and head in the same node you want to reach.

Therefore if the arrival node is reached, the algorithm will end.

## File syntax
Suppose you have this graph:

![Screenshot_20211008_180101](https://user-images.githubusercontent.com/40228829/136588092-a8d62aab-38d9-4f70-bda1-c40776c8669d.png)

You need to create a file when, for each row, you write: tail,head,cost

For example, the file for the previous graph is:
```
A,B,7
A,C,5
A,F,2
B,G,2
C,B,1
C,G,4
C,D,1
D,E,1
D,G,1
E,C,2
E,D,4
E,F,1
F,A,1
F,C,1
F,E,1
G,B,1
G,D,1
```

But, in order to avoid to known the nunber of the required step we add the following arc:

```
D,D,0
```
where we suppose that we want to reach the D node and it means that when we reach the D node, we want to stop us there.

NB: the algorithm still want a N parameter, i suggest you to set it a value > number of arc

## How to use (example file)
Compile the example with:

```
$ g++ example_main.cpp -o example_main
```

Now use it by command line. The syntax is
 * file of the graph    
 * N steps number    

```
$ ./example_main example_graph/graph1.txt 10
File name: example_graph/graph1.txt
Number iteration given: 10
Enter arrival node: 

```

Enter the node's name you want to reach, for example:

```
[D] is the arrival node

Choose which optimal path to see. Enter a starting node: 

```


Now choose a node where the path begin, for example the node A.
The program ended, now try to deal with the output.

The output is: 

```
Table with optimal costs
        A       B       C       D       E       F       G
G_10    inf     inf     inf     0       inf     inf     inf
G_9     inf     inf     1       0       4       inf     1
G_8     6       3       1       0       3       2       1
G_7     4       3       1       0       3       2       1
G_6     4       3       1       0       3       2       1
G_5     4       3       1       0       3       2       1
G_4     4       3       1       0       3       2       1
G_3     4       3       1       0       3       2       1
G_2     4       3       1       0       3       2       1
G_1     4       3       1       0       3       2       1
G_0     4       3       1       0       3       2       1
Table with optimal parents
        A       B       C       D       E       F       G
k = 0   -       -       -       -       -       -       -
k = 1   -       -       D       D       D       -       D
k = 2   C       G       D       D       C       C       D
k = 3   F       G       D       D       C       C       D
k = 4   F       G       D       D       C       C       D
k = 5   F       G       D       D       C       C       D
k = 6   F       G       D       D       C       C       D
k = 7   F       G       D       D       C       C       D
k = 8   F       G       D       D       C       C       D
k = 9   F       G       D       D       C       C       D
k = 10  F       G       D       D       C       C       D
Optimal path starting from A is: 
We are already arrived
A --> F --> C --> D with total cost 4
We are already arrived
Optimal path:
        A
        F
        C
        D
```

The first table show the intermediate optimal costs, for each steps. 
EG: G_9 means that in just one step we can reach D from the nodes C,E,G only with optimal cost 1,4,1 respectively. Then don't exist any path in just one step that allow as to reach the node D from the others nodes A,B,F (where the cost is infinite). If you watch the graph it is trivial.

The second table show the optimal parents. Our solutions are just there.

Finally we have the optimal path twice printed.
Here is clear how the added arc act. We set N = 10, but the optimal cost required just 3 steps!

There are two function that give us the solution, the first one just return the string:

```
We are already arrived
A --> F --> C --> D with total cost 4
```
The second one return a vector<Node> that will be printed in the main function as following:

```
We are already arrived
Optimal path:
        A
        F
        C
        D
```

  
Note that if we don't add the arc with null cost and repeat the above procedure we get a more complex solution:
  
  
```
  Table with optimal cost
        A       B       C       D       E       F       G
G_10    inf     inf     inf     0       inf     inf     inf
G_9     inf     inf     1       inf     4       inf     1
G_8     6       3       5       2       3       2       inf
G_7     4       inf     3       4       3       4       3
G_6     6       5       5       4       5       4       5
G_5     6       7       5       6       5       6       5
G_4     8       7       7       6       7       6       7
G_3     8       9       7       8       7       8       7
G_2     10      9       9       8       9       8       9
G_1     10      11      9       10      9       10      9
G_0     12      11      11      10      11      10      11
Table with optimal parents
        A       B       C       D       E       F       G
k = 0   -       -       -       -       -       -       -
k = 1   -       -       D       -       D       -       D
k = 2   C       G       G       G       C       C       -
k = 3   F       -       D       E       F       E       D
k = 4   F       G       D       E       C       C       D
k = 5   F       G       D       E       F       C       D
k = 6   F       G       D       E       C       C       D
k = 7   F       G       D       E       F       C       D
k = 8   F       G       D       E       C       C       D
k = 9   F       G       D       E       F       C       D
k = 10  F       G       D       E       C       C       D
Optimal path starting from A is: 
A --> F --> C --> D --> E --> C --> D --> E --> F --> C --> D with total cost 10
Optimal path:
        A
        F
        C
        D
        E
        C
        D
        E
        F
        C
        D  
```
Note that the cost also increase, because the number of steps is fixed!


## How to use the class in another project
  You need to include the following file:

  ```
backward_value_iteration.cpp
backward_value_iteration.h
  ```
  
  But they required:
```
functions_stefano.h
functions_stefano.cpp
```
  
Then include them:
  
```
#include "[YOUR PATH]/functions_stefano.cpp"
#include "[YOUR PATH]/backward_value_iteration.cpp"
```

Now just instance the class like following:

```
std::string my_graph_file_path = "/YOUR/GRAPH/FILE/PATH";
Graph graph(my_graph_file_path);
```

  #### take care: the path my_graph_file_path must exist and its file syntax must be as mentioned above
  
  
  
```
int n_iteration = 10; // tip: set it to the number of arc of the graph 
std::string arrival_node = "D"; // it must deal with your node's name
graph.compute_optimal_cost(n_iteration, arrival_node);  
```

 After this all the optimal path to reach the node 'arrival_node' from all the other nodes has been computed.
 You can choose another node to see the path to reach the 'arrival_node'.
 To just print it: 
  
```
  std::string starting_node = "A";
  cout << graph._get_optimal_path(starting_node) << endl
```

  Insted, to get the optimal path:
```
std::string starting_node = "A";
std::vector<Node> op = graph.get_optimal_path(starting_node);
for (Node n:op) {
    std::cout << "\t" << n.get_head() << std::endl;
    //move_my_robot_to(n.get_head()); // For example
}
```

### Debug function  
To print the graph file:
```
std::string my_graph_file_path = "/YOUR/GRAPH/FILE/PATH";
std::cout << API_S::vector2string(API_S::read_file(my_graph_file_path)) << std::endl;
```
  
  
To print the stored graph:
```
std::string my_graph_file_path = "/YOUR/GRAPH/FILE/PATH";
Graph graph(my_graph_file_path);  
graph.print_graph()
```
