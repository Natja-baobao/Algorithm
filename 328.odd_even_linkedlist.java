/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode oddEvenList(ListNode head) {
        if( head != null) {
            ListNode odd = head;
            ListNode even = odd.next, even_head = odd.next;
            while( even != null && even.next != null) {
                //&&的顺序不可变
                odd.next = odd.next.next;
                even.next = even.next.next;
                odd = odd.next;
                even = even.next;
            }
            odd.next = even_head;
        }
        return head;
    } 
}
