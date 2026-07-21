class Solution {
    public String minWindow(String s, String t) {
        HashMap<Character, Integer> desired = new HashMap<>();
        HashMap<Character, Integer> current = new HashMap<>();
        for (char c='a'; c<='z'; c++) {
          desired.put(c, 0);
          current.put(c, 0);
        }
        for (char c='A'; c<='Z'; c++) {
          desired.put(c, 0);
          current.put(c, 0);
        }
        for (int i=0; i<t.length(); i++) {
          char c = t.charAt(i);
          desired.put(c, desired.get(c)+1);
        }

        int best_l = -1;
        int best_r = s.length();
        
        // l and r are inclusive, however we allow the special case of r being one unit smaller than l to indicate a string of size zero
        int l = 0;
        int r = -1;
        int missingLetterTypes = 0;

        for (Map.Entry<Character, Integer> entry: desired.entrySet()) {
          if (entry.getValue() > 0) {
            missingLetterTypes +=1;
          }
        }

        while(true) {
          if (missingLetterTypes > 0) {
            r += 1;
            if (r == s.length()) break;

            char c = s.charAt(r);
            int freqBefore = current.get(c);
            int freqAfter = freqBefore + 1;
            current.put(c, freqAfter);
            int desiredFreq = desired.get(c);
            if (freqBefore < desiredFreq && freqAfter >= desiredFreq) {
              missingLetterTypes -= 1;
            }
          } else {
            assert (r >= l);


            int currentLength = r-l+1;
            int bestLengthSoFar = best_r - best_l + 1;
            if (currentLength < bestLengthSoFar) {
              best_l = l;
              best_r = r;
            }

            char c = s.charAt(l);
            int freqBefore = current.get(c);
            int freqAfter = freqBefore - 1;
            current.put(c, freqAfter);
            int desiredFreq = desired.get(c);
            if (freqBefore >= desiredFreq && freqAfter < desiredFreq) {
              missingLetterTypes += 1;
            }

            l += 1;
          }

        }

        if (best_l == -1) return "";
        return s.substring(best_l, best_r+1);
    }
}
