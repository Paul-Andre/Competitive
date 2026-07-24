class Solution {

  //matrix[i][j] = true if i comes before j
  boolean[][] matrix;

  public String alienOrder(String[] words) {
    matrix = new boolean[26][26];
    boolean succ = partition(words, 0, words.length-1, 0);
    if (!succ) return "";

    boolean[] exist = new boolean[26];
    for (int i=0; i<words.length; i++) {
      for (int j=0; j<words[i].length(); j++) {
        char c = words[i].charAt(j);
        exist[c-'a'] = true;
      }
    }

    StringBuilder ret = new StringBuilder();

    boolean[] taken = new boolean[26];

    boolean continuing = true;
    while(continuing) {
      continuing = false;

      for (int i=0; i<26; i++) {
        if (!exist[i]) continue;
        if (taken[i]) continue;

        int incoming = 0;
        for (int j=0; j<26; j++) {
          if(matrix[j][i] && !taken[j]) incoming+=1;
        }
        if (incoming == 0) {
          char c = (char)('a'+i);
          ret.append(c);
          taken[i] = true;
          continuing = true;
        }
      }
    }
    boolean all_taken = true;
    for (int i=0; i<26; i++) {
      if (exist[i] && !taken[i]) all_taken = false;
    }
    if (!all_taken) return "";
    else return ret.toString();
  }

  public boolean partition(String[] words, int wl, int wr, int ci) {
    char prev = '-';
    int sectionStart = -1;
    int wi;
    for (wi = wl; wi<=wr; wi++) {
      String word = words[wi];
      char c;
      if (ci < word.length()) {
        c = word.charAt(ci);
      } else {
        c = '-';
      }

      if (c!= prev) {

        if (c == '-' && prev != '-') {
          return false;
        }

        if (prev != '-') {
          if (matrix[c-'a'][prev-'a']) {
            return false;
          }
          matrix[prev-'a'][c-'a'] = true;

          int sectionL = sectionStart;
          int sectionR = wi-1;
          assert(sectionR >= wl);

          if (!partition(words, sectionL, sectionR, ci+1)) {
            return false;
          }
        }

        sectionStart = wi;
      }

      prev = c;
    }

    if (prev != '-') {

      int sectionL = sectionStart;
      int sectionR = wi-1;
      assert(sectionR >= wl);

      if (!partition(words, sectionL, sectionR, ci+1)) {
        return false;
      }
    }

    return true;
  }
}
