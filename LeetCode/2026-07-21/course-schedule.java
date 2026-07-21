class Solution {

  // This is just cycle detection.

  ArrayList<ArrayList<Integer>> g;
  ArrayList<Integer> vis;

  final int WHITE = 0;
  final int GREY = 1;
  final int BLACK = 2;

  private boolean visit(int i) {
    if (vis.get(i) == BLACK) {
      return true;
    }
    if (vis.get(i) == GREY) {
      return false;
    }
    assert(vis.get(i) == WHITE);
    vis.set(i, GREY);
    for (int j=0; j<g.get(i).size(); j++) {
      int u = g.get(i).get(j);
      if (!visit(u)) {
        return false;
      }
    }
    vis.set(i, BLACK);
    return true;
  }

  public boolean canFinish(int numCourses, int[][] prerequisites) {
    g = new ArrayList<>();
    vis = new ArrayList<>();

    for (int i=0; i<numCourses; i++) {
      g.add(new ArrayList<>());
      vis.add(0);
    }
    for (int i=0; i<prerequisites.length; i++) {
      int course = prerequisites[i][0];
      int prereq = prerequisites[i][1];
      g.get(course).add(prereq);
    }

    for (int i=0; i<numCourses; i++) {
      if (!visit(i)) {
        return false;
      }
    }
    return true;
  }
}
