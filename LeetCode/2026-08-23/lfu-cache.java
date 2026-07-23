import java.util.*;


// Broken. Actual solution in lfu-cache_try-2.java


class LRUCache<K,V> extends LinkedHashMap<K, V> {

    final int cap;

    public LRUCache(int capacity) {
        super(16, 0.75f, true);
        this.cap = capacity;
    }

    public int get(int key) {
        // System.out.println(this);
        //         System.out.println(size());

        Integer ret = super.get(key);
        if (ret == null) return -1;
        return ret;
    }


    public void put(int key, int value) {
        super.put(key, value);
    }
    
    @Override
    protected boolean removeEldestEntry(Map.Entry<Integer,Integer> eldest) {
        return size() > cap;
    }
}


class UseOrderIdentitySet<K,V> {
   // Satisfactory solution using explicit manually created linked list

    static class ListNode {
        ListNode prev;
        ListNode next;

        final K key;
        V value;

        ListNode(K key, V value) {
          this.key = key;
          this.value = value;
        }
    }

    IdentityHashMap<K, ListNode> map;
    ListNode beginDummy;
    ListNode endDummy;

    public UseOrderIdentitySet {
        map = new HashMap<>();
        beginDummy = new ListNode();
        endDummy = new ListNode();
        beginDummy.next = endDummy;
        endDummy.prev = beginDummy;
    }
    
    public void bump(K key) {
        if (map.containsKey(key)) {
            ListNode node  = map.get(key);

            node.prev.next = node.next;
            node.next.prev = node.prev;
            node.prev = null;
            node.next = null;

            // Move to front
            beginDummy.next.prev = node;
            node.next = beginDummy.next;
            node.prev = beginDummy;
            beginDummy.next = node;

            return;
        }
        else return;
    }

    public void evictLast() {
      ListNode last = endDummy.prev;
      assert(last != beginDummy);

      last.prev.next = last.next;
      last.next.prev = last.prev;
      last.prev = null;
      last.next = null;

      map.remove(last.key);
      size -= 1;
    }

    public void add(K key) {
        ListNode node;
        if (map.containsKey(key)) {
            node  = map.get(key);

            node.prev.next = node.next;
            node.next.prev = node.prev;
            node.prev = null;
            node.next = null;

        } else {
            node = new ListNode();
            node.key = key;
            size += 1;
            map.put(key, node);
        }

        // Move to front
        beginDummy.next.prev = node;
        node.next = beginDummy.next;
        node.prev = beginDummy;
        beginDummy.next = node;

        // Set value
        //node.value = value;

        // {
        //     node = beginDummy.next;
        //     while(node != endDummy) {
        //         System.out.print(node.key);
        //         System.out.print(" ");
        //         node= node.next;
        //     }
        //                     System.out.print("\n");
        //     System.out.println(map);

        // }
    }
}

class LFUCache {

  static class Record {
    int useCount = 0;
    final int key;
    int value;
    Record(int key, int value) {
      this.key = key;
      this.value = value;
    }
  }

  // One bucket per a given
  static class Bucket {
    final int useCount;
    final UseOrderIdentitySet<Record> records = UseOrderIdentitySet<>();
    Bucket(int useCount) {
      this.useCount = useCount;
    }
  }


  final int capacity;
  final TreeMap<Integer, Bucket> buckets = new TreeMap<>();
  final HashMap<Integer, Record> records = new HashMap<>();

  LFUCache(int capacity) {
    if (capacity < 1) {
      throw new IllegalArgumentException("capacity for LFUCache has to be at least 1");
    }
    this.capacity = capacity;
  }

  private void bumpUseCount(Record record) {
    int prevUseCount = record.useCount;
    int newUseCount = prevUseCount + 1;
    record.useCount = newUseCount;

    Bucket prevBucket = buckets.get(prevUseCount);
    Bucket newBucket = buckets.computeIfAbsent(newUseCount, k -> new Bucket(k));

    prevBucket.records.remove(record);
    if (prevBucket.records.size() == 0) {
      buckets.remove(prevUseCount);
    }
    newBucket.records.add(record);
  }

  int get(int key) {
    Record record = records.get(key);
    if (record == null) return -1;

    bumpUseCount(record);

    return record.value;
  }

  void evict() {
    int smallestUseCount = buckets.firstKey();
    int firstBucket = buckets.get(smallestUseCount);
    // Oh, I need to LRU on ties
  }

  void put(int key, int value) {
    Record record = records.get(key);
    if (record != null) {
      bumpUseCount(record);
      record.value = value;
    } else {
      assert(capacity >= 1);
      while (records.size() >= capacity) {

      }
      record = new Record(key, value);
      Bucket zeroBucket = buckets.computeIfAbsent(0, _k -> new Bucket(0));
      zeroBucket.records.add(record);
    }
  }
};





/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
