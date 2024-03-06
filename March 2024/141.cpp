/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // S.C : O(1)
    // T.C : O(N)
    bool hasCycle(ListNode *head) {
        // slow and fast pointer pointing to head
        ListNode* slow = head;
        ListNode* fast = head;
        // if LL is empty then no cycle
        if(head == NULL){
            return false;
        }
        // some condition check
        // slow not equals to null,same for fast and checking fast -> next gets null
        while(slow != NULL and fast != NULL and fast->next != NULL){
            // slow will one step while fast will move two att one time
            slow = slow->next;
            fast = fast->next->next;
            // if slow and fasts gets equal then cycle present
            if(slow == fast){
                return 1;
            }
        }
        // No cycle present
        return 0;

    }
    // S.C : O(N)
    // T.C : O(N)
    // bool hasCycle(ListNode *head) {
    //     if(head == NULL){
    //         return 0;
    //     }

    //     map<ListNode* ,bool> vis;
    //     ListNode* temp = head;
    //     while(temp != NULL){
    //         if(vis[temp] == true){
    //             return 1;
    //         }


    //         vis[temp] = true;
    //         temp = temp->next;




    //     }

    //     return 0;

    // }
};