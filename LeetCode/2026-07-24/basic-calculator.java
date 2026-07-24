class Solution {
  int pos = 0;
  String s;
  

  public int calculate(String s) {
    this.pos = 0;
    this.s = s;
    return computeExpression();
  }

  private void skipWhitespce() {
    while(pos < s.length() && s.charAt(pos)==' ') {
      pos += 1;
    }
  }

  private char peek() {
    if (pos >= s.length()) {
      return '\0';
    }
    char ret = s.charAt(pos);
    return ret;
  }

  private void advance() {
    if (pos >= s.length()) {
      return;
    }
    pos+=1;
  }

  private int parseInt() {
    int acc = 0;
    char c = peek();
    while(c>='0' && c<='9') {
      int dig = c-'0';
      acc = acc*10+dig;
      advance();
      c = peek();
    }
    return acc;
  }

  private int computeTerm() {
    skipWhitespce();
    char c = peek();

    if (c == '-') {
      advance();
      int term = computeTerm();
      return -term;
    } else if (c == '(') {
      advance();
      int ret = computeExpression();
      skipWhitespce();
      char cc = peek();
      assert(cc==')');
      advance();
      return ret;
    } else if (c>='0' && c<='9') {
      int ret = parseInt();
      return ret;
    }

    throw new IllegalStateException("Could not understand first charcter of term.");
  }

  private int computeExpression() {
    int acc = computeTerm();
    while(true) {
      skipWhitespce();
      char c = peek();
      if (c == '+') {
        advance();
        int term = computeTerm();
        acc += term;

      } else if (c == '-') {
        advance();
        int term = computeTerm();
        acc -= term;

      } else if (c == '\0' || c == ')') {
        // Return without advancing
        return acc;

      } else {
        throw new IllegalStateException("Could not understand charcter inside of expression.");
      }
    }
  }
}
