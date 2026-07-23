class Solution {
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    HashMap<String, HashSet<String>> dotted = new HashMap<>();

    for (String word: wordList) {
      StringBuilder replaceable = new StringBuilder(word);
      for (int i=0; i<replaceable.length(); i++) {
        char c = replaceable.charAt(i);
        replaceable.setCharAt(i, '.');
        dotted.computeIfAbsent(replaceable.toString(), (k) -> new HashSet<>()).add(word);
        replaceable.setCharAt(i, c);
      }

    }

    // System.out.println(dotted);

    Queue<String> q = new ArrayDeque<>();
    HashSet<String> vis = new HashSet<>();

    q.add(beginWord);
    vis.add(beginWord);
    int steps = 0;
    boolean success = false;
outer_loop:
    while(q.size() > 0) {
      steps += 1;

      int currentSize = q.size();
      for (int i=0; i<currentSize; i++) {
        String word = q.remove();
        if (word.equals(endWord)) {
          success = true;
          break outer_loop;
        }
        StringBuilder replaceable = new StringBuilder(word);
        for (int j=0; j<replaceable.length(); j++) {
          char c = replaceable.charAt(j);
          replaceable.setCharAt(j, '.');
          String k = replaceable.toString();
          HashSet<String> newWords = dotted.get(k);
          if (newWords != null) for (String newWord: newWords) {
            if (!vis.contains(newWord)) {
              vis.add(newWord);
              q.add(newWord);
            }
          }
          replaceable.setCharAt(j, c);
        }

      }
    }

    if (success) {
      return steps;
    } else {
      return 0;
    }
  }
}
