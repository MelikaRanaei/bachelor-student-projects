# 🕷️ Butterfly vs Spider – A Graph-Based Strategy Game<br>

<br>This C project simulates a game between butterflies and spiders on a user-defined graph. It uses Dijkstra's algorithm to calculate the shortest path between nodes and models strategic moves in a battle for survival.<br><br>


<img src="images/graph_diagram.png" alt="Game Diagram" width="100" height="100"/>





**📌 Features**<br><br>

+ Graph input as an adjacency matrix.


+ Validates user inputs.

+ Calculates shortest paths using Dijkstra's algorithm.

+ Simulates spider movement toward butterflies.

+ Allows butterflies to remove edges to avoid spiders.

+ Ends when:

+ A spider catches a butterfly,

+ Butterflies isolate themselves from all spiders,

+ Or after 10 spider turns.<br><br>


**🧠 How It Works**<br><br>


+ The graph is input by the user (symmetric adjacency matrix).

+ Spiders try to reach the nearest butterfly using the shortest path.

+ Butterflies remove edges to prevent spiders from reaching them.

+ The simulation continues until one of the end conditions is met.<br><br>

**🏁 Getting Started**<br><br>

Follow the prompts to:<br>

+ Enter the number of nodes in the graph (max 11)

+ Provide the adjacency matrix

+ Define the number and positions of spiders

+ Define the number and positions of butterflies<br><br>

**📋 Example Input**<br><br>

Number of nodes: 4<br><br>

Enter map:<br><br>
0 1 1 0<br>
1 0 0 1<br>
1 0 0 1<br>
0 1 1 0<br><br>

Number of spiders: 1<br>
Spider positions: 1<br><br>

Number of butterflies: 1<br>
Butterfly positions: 3<br><br>

**🎯 Goal of the Game**<br><br>
Spiders: Reach a butterfly node.<br>

Butterflies: Avoid spiders by removing critical edges.<br><br>

**⚙️ Main Algorithms**<br><br>

Dijkstra’s Algorithm: For computing shortest paths.<br>

Graph Traversal & Simulation: To determine movement and disconnection logic.<br><br>




