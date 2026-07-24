import java.util.*;

class IdentityDeque<T> {

  static class Node<T> {
      Node<T> prev;
      Node<T> next;
      final T payload;
      public Node(T payload) {
        this.payload = payload;
      }
  }

  IdentityHashMap<T, Node<T>> map = new IdentityHashMap<>();
  Node<T> beginDummy;
  Node<T> endDummy;

  IdentityDeque() {
    beginDummy = new Node<>(null);
    endDummy = new Node<>(null);
    beginDummy.next = endDummy;
    endDummy.prev = beginDummy;
  }


  void addFirst(T payload) {
    Node<T> node = new Node<>(payload);

    Node<T> pastFirst = beginDummy.next;

    beginDummy.next = node;
    node.prev = beginDummy;

    node.next = pastFirst;
    pastFirst.prev = node;

    map.put(payload, node);
  }

  public T removeLast() {
    if (beginDummy.next == endDummy) {
      assert(endDummy.prev == beginDummy.next);
      throw new NoSuchElementException("no item remaining in IdentityDeque");
    }

    Node<T> last = endDummy.prev;
    Node<T> beforeLast = last.prev;

    last.next = null;
    last.prev = null;

    beforeLast.next = endDummy;
    endDummy.prev = beforeLast;

    map.remove(last.payload);

    return last.payload;
  }
  
  public boolean remove(T payload) {
    Node<T> node = map.get(payload);
    if (node == null) return false;

    Node<T> prev = node.prev;
    Node<T> next = node.next;

    node.prev = null;
    node.next = null;

    prev.next = next;
    next.prev = prev;
    
    map.remove(payload);
    return true;
  }

 public int size() {
   return map.size();
 }
  
}

class LFUCache {



  static class Record {
    int useCount = 0;
    final int key;
    int value;
    Record(int k, int v) {
      this.key = k;
      this.value = v;
    }
  }

  static class Bucket {
    final int useCount;
    IdentityDeque<Record> records = new IdentityDeque<>();
    Bucket(int useCount) {
      this.useCount = useCount;
    }
  }

  int capacity;

  // useCount -> bucket
  final private TreeMap<Integer, Bucket> buckets = new TreeMap<>();

  // key -> record
  final private HashMap<Integer, Record> records = new HashMap<>();

  public LFUCache(int capacity) {
    this.capacity = capacity;
  }

  private void bump(Record record) {
    int oldCount = record.useCount;
    record.useCount += 1;
    int newCount = record.useCount;

    Bucket oldBucket = buckets.get(oldCount);
    assert(oldBucket != null);
    Bucket newBucket = buckets.computeIfAbsent(newCount, (c) -> new Bucket(c));

    oldBucket.records.remove(record);
    if (oldBucket.records.size() == 0) {
      buckets.remove(oldCount);
    }

    newBucket.records.addFirst(record);
  }

  public int get(int key) {
    Record record = records.get(key);
    if (record == null) return -1;
    bump(record);
    return record.value;
  }

  public void evict() {
    int lowestCount = buckets.firstKey();
    Bucket lowestBucket = buckets.get(lowestCount);
    assert(lowestBucket.records.size() > 0);
    Record removed = lowestBucket.records.removeLast();
    records.remove(removed.key);
    if (lowestBucket.records.size() == 0) {
      buckets.remove(lowestCount);
    }
  }

  public void put(int key, int value) {
    if (capacity < 1) return;
    Record record = records.get(key);
    if (record != null) {
      bump(record);
      record.value = value;
      return;
    } else {
      while (records.size() >= capacity) {
        evict();
      }
      record = new Record(key, value);
      Bucket zeroBucket = buckets.computeIfAbsent(0, (c) -> new Bucket(c));
      zeroBucket.records.addFirst(record);
      records.put(key, record);
    }
  }
}
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
