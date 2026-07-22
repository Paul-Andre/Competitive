class Solution {
  // Hmmm, looks like I need to use union-find afterall because of the following case:
  // Dan, a@email.com
  // Dan, b@email.com
  // Dan, a@email.com, b@email.com
  //
  // Basically, an account coming later on can join two pre-existing accounts.
  // This can also happen through a long chain.
  //
  static class Account{
      String name;
      TreeSet<String> emails;

      int rank;
      Account parent;

      Account(String name){
        this.name = name;
        this.emails = new TreeSet<>();
        this.rank = 0;
        this.parent = null;
      }

      Account getTop() {
        if (parent == null) {
          return this;
        } else {
          Account top = parent.getTop();
          parent = top;

          // Do I need to change the rank at this point??
          // -> No I don't, because the invariants of rank only hold for the top node

          return top;
        }
      }

      Account mergeWith(Account other) {
        Account thisTop = this.getTop();
        Account otherTop = other.getTop();

        if (thisTop == otherTop) return thisTop;

        Account top;
        if (thisTop.rank < otherTop.rank) {
          thisTop.parent = otherTop;
          top = otherTop;
        }
        else if (thisTop.rank > otherTop.rank) {
          otherTop.parent = thisTop;
          top = thisTop;
        }
        else {
          thisTop.parent = otherTop;
          otherTop.rank ++;
          top = otherTop;
        }

        this.parent = top;
        return top;
      }
  }


  public List<List<String>> accountsMerge(List<List<String>> unparsedAccounts) {

    ArrayList<Account> initialAccounts = new ArrayList<>();

    for (int i=0; i<unparsedAccounts.size(); i++) {
      String name = unparsedAccounts.get(i).get(0);
      Account current = new Account(name);

      for (int j = 1; j<unparsedAccounts.get(i).size(); j++) {
        String email = unparsedAccounts.get(i).get(j);
        current.emails.add(email);
      }

      initialAccounts.add(current);
    }

    HashMap<String, Account> map = new HashMap<>();
    for (int i=0; i<initialAccounts.size(); i++) {
      Account account = initialAccounts.get(i);
      for (String email: account.emails) {
        if (map.containsKey(email)) {
          Account otherAccount = map.get(email);
          account.mergeWith(otherAccount);
        } else {
          map.put(email, account);
        }
      }
    }

    ArrayList<Account> finalAccounts = new ArrayList<>();

    for (int i=0; i<initialAccounts.size(); i++) {
      Account account = initialAccounts.get(i);
      Account top = account.getTop();
      if (top == account) {
        finalAccounts.add(top);
      } else {
        top.emails.addAll(account.emails);
      }
    }

    List<List<String>> ret = new ArrayList<>();
    for (Account account: finalAccounts) {
      ArrayList<String> serialized = new ArrayList<>();
      serialized.add(account.name);
      for (String email: account.emails) {
        serialized.add(email);
      }
      ret.add(serialized);
    }
    return ret;
  }
}

