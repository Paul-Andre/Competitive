/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    
    public ListNode mergeKLists(ListNode[] lists) {


      PriorityQueue<ListNode> queue = new PriorityQueue<>(Comparator.comparingInt( a -> a.val));
      for (int i=0; i<lists.length; i++) {
        if (lists[i] != null) queue.add(lists[i]);
      }

      ListNode startDummy = new ListNode();
      ListNode prev = startDummy;

      while(!queue.isEmpty()) {
        ListNode top = queue.poll();
        prev.next = top; 
        ListNode toReinsert = top.next;
        top.next = null;

        prev = top;

        if (toReinsert != null) {
          queue.add(toReinsert);
        }
      }

      return startDummy.next;
    }
}
