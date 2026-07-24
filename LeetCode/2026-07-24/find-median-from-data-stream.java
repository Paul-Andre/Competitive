class TreeSortedList<T extends Comparable<T>> {
  // Note - this version is an attempt to use SBT, but is buggy and may become unbalanced because it doesn't implement the full balancing
  static int size(Node n) {
    if (n == null) return 0;
    return n.subtreeSize;
  }

  static class Node<T extends Comparable<T>> {
    T value;
    int subtreeSize;
    Node<T> left;
    Node<T> right;
    Node(T value) {
      this.value = value;
      this.subtreeSize = 1;
    }


    void recalculateSubtreeSize() {
      subtreeSize = 1 + size(left) + size(right);
    }

    Node<T> rotateLeft() {
      //    X
      //  A   Y
      //     B C
      //  --->
      //      Y
      //   X    C
      //  A B
      //
      Node X = this;
      Node Y = this.right;

      Node A = X.left;

      Node B = Y.left;
      Node C = Y.right;

      X.left = A;
      X.right = B;

      Y.left = X;
      Y.right = C;

      X.recalculateSubtreeSize();
      Y.recalculateSubtreeSize();
      return Y;
    }

    Node<T> rotateRight() {
      //      Y
      //   X    C
      //  A B
      //  --->
      //    X
      //  A   Y
      //     B C
      //
      Node Y = this;
      Node X = Y.left;

      Node A = X.left;
      Node B = X.right;

      Node C = Y.right;

      X.left = A;
      X.right = Y;

      Y.left = B;
      Y.right = C;

      Y.recalculateSubtreeSize();
      X.recalculateSubtreeSize();

      return X;
    }

    Node<T> balance() {
      //       this
      //  left      right
      // A    B    C     D

      if (left == null && right == null) {
        return this;
      }
      if (right != null) {
        if (size(left) < size(right.left) || size(left) < size(right.right)) {
          return rotateLeft();
          
        }
      }
      if (left != null) {
        if (size(right) < size(left.left) || size(right) < size(left.right)) {
          return rotateRight();
        }
      }
      recalculateSubtreeSize();
      return this;
    }

    Node<T> add(T t) {
      if (t.compareTo(value) <= 0) {
        if (left == null) {
          left = new Node(t);
        } else {
          left = left.add(t);
        }
      } else {
        if (right == null) {
          right = new Node(t);
        } else {
          right = right.add(t);
        }
      }
      Node<T> ret = balance();
      return ret;
    }

    T get(int pos) {
      int leftSubtreeSize = 0;
      if (left != null) leftSubtreeSize = left.subtreeSize;
      if (pos < leftSubtreeSize) {
        assert(pos >= 0);
        return left.get(pos);
      } else if (pos == leftSubtreeSize) {
        return value;
      } else {
        return right.get(pos-leftSubtreeSize-1);
      }
    }
  }

  Node<T> root;

  TreeSortedList() {}

  int size() {
    return size(root);
  }

  void add(T t) {
    if (root == null) {
      root = new Node<>(t);
    }
    else {
      root = root.add(t);
    }
  }
  
  T get(int pos) {
    if (root == null) {
      throw new IndexOutOfBoundsException("Index "+pos+" is out of bound in TreeList");
    }
    if (pos < 0 || pos >= root.subtreeSize) {
      throw new IndexOutOfBoundsException("Index "+pos+" is out of bound in TreeList");
    }
    return root.get(pos);
  }

}


class MedianFinder {

  TreeSortedList<Integer> list = new TreeSortedList<>();

  public MedianFinder() {

  }

  public void addNum(int num) {
    list.add(num);

  }

  public double findMedian() {
    int size = list.size();
    if (size % 2 == 1) {
      int i = size/2;
      return list.get(i);
    } else {
      int i1 = size/2-1;
      int i2 = size/2;

      return ((double)(list.get(i1) + list.get(i2)))/2;
    }
  }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
