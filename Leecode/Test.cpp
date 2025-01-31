/*
# Let's create a text file with the schedule for saving

schedule_text = """
🔹 **2-Week DFS/BFS Plan (1-2 Problems Daily)**
Each day has **one required problem** and an **optional harder problem** if you
have time.

### 📅 **Week 1: Basic DFS/BFS Traversals**
**(Goal: Get Comfortable with DFS/BFS on Trees & Grids)**
✅ = Required, 🔥 = Optional

- **Day 1**: ✅ [Flood Fill](https://leetcode.com/problems/flood-fill/) 🔥 [Max
Area of Island](https://leetcode.com/problems/max-area-of-island/)
- **Day 2**: ✅ [Number of
Islands](https://leetcode.com/problems/number-of-islands/) 🔥 [Rotting
Oranges](https://leetcode.com/problems/rotting-oranges/)
- **Day 3**: ✅ [Same Tree](https://leetcode.com/problems/same-tree/) 🔥 [Path
Sum](https://leetcode.com/problems/path-sum/)
- **Day 4**: ✅ [Course
Schedule](https://leetcode.com/problems/course-schedule/) 🔥 [Walls and
Gates](https://leetcode.com/problems/walls-and-gates/)
- **Day 5**: ✅ [Pacific Atlantic Water
Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/) 🔥 [Word
Ladder](https://leetcode.com/problems/word-ladder/)
- **Day 6**: ✅ [Connected Components](https://www.lintcode.com/problem/431/) 🔥
[Critical Connections in a
Network](https://leetcode.com/problems/critical-connections-in-a-network/)
- **Day 7**: ✅ **Solve any DFS/BFS problem you struggled with again** 🔥 Try to
do it faster

---

### 📅 **Week 2: Graphs & Advanced DFS/BFS**
**(Goal: Understand BFS for shortest paths & DFS for cycles/SCCs)**

- **Day 8**: ✅ [Minimum Knight
Moves](https://leetcode.com/problems/minimum-knight-moves/) 🔥 [Cut Off Trees
for Golf Event](https://leetcode.com/problems/cut-off-trees-for-golf-event/)
- **Day 9**: ✅ [Longest Increasing Path in a
Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) 🔥
[Topological Sort (Kahn’s
Algorithm)](https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/)
- **Day 10**: ✅ [Alien
Dictionary](https://leetcode.com/problems/alien-dictionary/) 🔥 [Strongly
Connected Components (Kosaraju’s
Algorithm)](https://www.geeksforgeeks.org/strongly-connected-components/)
- **Day 11**: ✅ [Find Bridges in a
Graph](https://www.geeksforgeeks.org/bridge-in-a-graph/) 🔥 [Articulation
Points](https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/)
- **Day 12**: ✅ [Practice a Harder Graph
Problem](https://leetcode.com/tag/graph/) (Your Choice) 🔥 [Timed DFS/BFS
problem](https://leetcode.com/problems/)
- **Day 13**: ✅ **Revisit any topic you struggled with** 🔥 Implement BFS + DFS
from scratch
- **Day 14**: ✅ **Mock NAC practice** 🔥 Solve **two DFS/BFS problems in one
sitting**

---

### 📌 **After 2 Weeks: Add Backtracking**
Once DFS/BFS feels easy, start **backtracking** alongside it:
- **Backtracking problems** → Sudoku Solver, N-Queens, Word Search
- **DFS/BFS stays in practice** → Solve 1 per week

This schedule should **speed up your problem-solving for NAC** while avoiding
burnout.
"""

# Save the schedule to a file
file_path = '/mnt/data/DFS_BFS_Plan.txt'
with open(file_path, 'w') as file:
    file.write(schedule_text)

file_path
*/
