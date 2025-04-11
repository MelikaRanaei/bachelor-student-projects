# Kruskal's Algorithm for Minimum Spanning Tree (MST) 🌲

This code contains a C++ implementation of **Kruskal's Algorithm** to find the **Minimum Spanning Tree (MST)** of a graph. Kruskal's algorithm is a classic **greedy algorithm** that works by selecting edges in increasing order of weight while ensuring no cycles are formed in the graph.

### Explanation of Kruskal's Algorithm 🔍:

**Kruskal's Algorithm** is used to find a **Minimum Spanning Tree (MST)** in a graph. An MST of a graph is a subset of edges that connects all the vertices together, without cycles, and with the minimum possible total edge weight. The main steps of Kruskal's Algorithm are:

1. **Sort all edges** of the graph in non-decreasing order of their weights. This helps in always picking the smallest edge to add to the MST.
   
2. **Initialize** a disjoint-set (also known as union-find) for the graph's nodes. Initially, each node is its own parent, meaning they belong to separate sets.

3. **Iterate through sorted edges**:
    - For each edge, check if the two nodes are in the same set using the `find` operation.
    - If they are in different sets (i.e., no cycle will be formed), add the edge to the MST and merge the sets using the `union` operation.
    - If they are in the same set (i.e., adding the edge would form a cycle), discard the edge.
   
4. **Repeat** the process until the MST contains exactly `n-1` edges (where `n` is the number of nodes in the graph).

5. **The final result** is the sum of the weights of the edges in the MST.

Kruskal’s Algorithm is efficient when the graph is sparse (i.e., it has relatively fewer edges). It ensures that the resulting tree connects all vertices while minimizing the total weight.<br>

### Features ⚙️:<br>
- Implements Kruskal's algorithm to find the MST.
- Uses a **union-find** (disjoint-set) data structure to manage connected components.
- Efficiently sorts edges and performs union and find operations to determine the MST.<br>

### C++ Implementation 🖥️:<br>
The main components of the code are:<br>
1. **Edge Structure**: Defines edges with their endpoints (`u`, `v`) and weight (`w`).
2. **Union-Find Operations**: The `findParent` and `set` functions manage connected components using path compression.
3. **Sorting**: Edges are sorted in ascending order by weight using `std::sort`.
4. **Kruskal's Algorithm**: Implements the logic to select edges and form the MST by checking if the edge would create a cycle.<br>

### Algorithm Steps 🛠️:<br>
1. **Sort** all the edges in non-decreasing order of their weight.
2. **Initialize** the disjoint-set structure for the nodes.
3. **Iterate** over sorted edges:<br>
   - For each edge, check if it connects two different components.
   - If it does, add the edge to the MST and perform a union of the two components.
4. **Stop** once the MST contains exactly `n-1` edges (where `n` is the number of nodes).<br>

### Example Usage 🖥️:<br>
**Input Format**:<br>

The first line contains two integers: n (number of nodes) and m (number of edges).<br>

The next m lines contain three integers each: u, v, w where u and v are the nodes connected by an edge, and w is the weight of that edge.<br>

**Sample Input:**<br>
4 5<br>
1 2 10<br>
1 3 20<br>
2 3 30<br>
3 4 40<br>
2 4 50<br>
**Sample Output:**<br>
100<br>
The output represents the total weight of the MST.




