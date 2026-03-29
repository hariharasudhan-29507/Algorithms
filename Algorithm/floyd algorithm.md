# Floyd-Warshall Algorithm

## Description
Floyd-Warshall is a dynamic programming algorithm that finds the shortest paths between all pairs of vertices in a weighted directed graph. It works by iteratively considering each vertex as an intermediate node and checking whether routing through it produces a shorter path between any two vertices.

---

## Algorithm: FloydWarshall

FloydWarshall(dist[0..n-1][0..n-1])  
//Input: dist[][] — n × n adjacency matrix where dist[i][j] is the edge weight  
//&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;from vertex i to j, INF if no direct edge, and dist[i][i] = 0  
//Output: dist[][] updated with shortest path distances between all pairs

FOR k ← 0 TO n − 1 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FOR i ← 0 TO n − 1 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FOR j ← 0 TO n − 1 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF dist[i][k] + dist[k][j] < dist[i][j] THEN  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dist[i][j] ← dist[i][k] + dist[k][j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END IF  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END FOR  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END FOR  
END FOR

Return dist[][]

---

## Time Complexity

| Case        | Complexity | Explanation |
|-------------|------------|-------------|
| **Best**    | Θ(n³)      | The three nested loops each run exactly n times with no branching or early exit — the `IF` condition only controls an assignment, not a loop skip. |
| **Average** | Θ(n³)      | All n³ combinations of (i, j, k) are evaluated unconditionally for any graph structure. |
| **Worst**   | Θ(n³)      | Same as best and average — the triple nested loop structure makes it unconditionally cubic in the number of vertices. |

## Space Complexity

| Type          | Complexity | Explanation |
|---------------|------------|-------------|
| **Input**     | O(n²)      | The n × n distance matrix stores edge weights for all pairs of vertices. |
| **Auxiliary** | O(1)       | The algorithm updates dist[][] in-place using only loop index variables i, j, k — no additional data structures are needed. |
