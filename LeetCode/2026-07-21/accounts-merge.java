class Solution {
  static record Record(
      String name,
      ArrayList<String> emails)
  {}


  public List<List<String>> accountsMerge(List<List<String>> accounts) {
    // maps email to record
    HashMap<String, Record> map;
    for (int i=0; i<accounts.size(); i++) {
      String name = accounts[i][0];
      ArrayList<String> emails = new ArrayList<>();

      boolean alreadyExists = false;

      int j = 1;

      for (i<accounts[i].size(); j++) {
        String email = accounts[i][j];

        if (map.containsKey(email)) {
          alreadyExists = true;
          break;
        }

        emails.add(email);
      }

      if (!alreadyExists) {
        emails.put(
      }

      
    }
  }
}
