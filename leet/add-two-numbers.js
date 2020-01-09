/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
function ListNode(val) {
  this.val = val;
  this.next = null;
}
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
  function add(l1, l2, carry) {
    if (!l1 && !l2) {
      return new ListNode(carry);
    } else if (!l1) {
      return addTwoNumbers(l2, new ListNode(carry));
    } else if (!l2) {
      return addTwoNumbers(l1, new ListNode(carry));
    } else {
      ans = l1.val + l2.val + carry;
      ret = new ListNode(ans % 10);
      ret.next = addTwoNumbers(l1.next, l2.next, Math.floor(ans / 10));
      return ret;
    }
  }
  return add(l1, l2, 0);
};
