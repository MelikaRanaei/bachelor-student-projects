# 🕷️ Butterfly vs Spider – A Graph-Based Strategy Game<br>

<br>This C project simulates a game between butterflies and spiders on a user-defined graph. It uses Dijkstra's algorithm to <br>calculate the shortest path between nodes and models strategic moves in a battle for survival.<br><br>

![Game Diagram](images/graph_diagram.png)<br><br>



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


