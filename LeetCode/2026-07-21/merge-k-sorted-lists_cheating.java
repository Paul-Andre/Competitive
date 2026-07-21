
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
        ArrayList<Integer> a = new ArrayList<>();
        for (int i=0; i<lists.length; i++) {
            ListNode node = lists[i];
            while(node != null) {
                a.add(node.val);
                node = node.next;
            }
        }

        Collections.sort(a);

        ListNode beginDummy = new ListNode();
        ListNode prev = beginDummy;

        for (int aa : a) {
            prev.next = new ListNode(aa);
            prev = prev.next;
        }
        return beginDummy.next;
    }
}
