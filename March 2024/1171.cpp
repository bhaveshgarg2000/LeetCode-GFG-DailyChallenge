/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        // Check if the list is empty
        if (head == NULL)
        {
            return 0;
        }
        // Create a map to store prefix sums and their corresponding nodes
        unordered_map<int, ListNode *> mpp;
        // Create a dummy node to handle cases where the whole list is removed
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        mpp[0] = dummy;    // Initialize map with prefix sum 0 pointing to dummy node
        int prefixSum = 0; // Initialize prefix sum
        // Iterate through the list
        while (head != NULL)
        {
            prefixSum += head->val; // Update prefix sum
            // If prefix sum is found in the map, it means a subarray with sum 0 is found
            if (mpp.find(prefixSum) != mpp.end())
            {
                ListNode *start = mpp[prefixSum]; // Get the node corresponding to prefix sum
                int sum = prefixSum;              // Initialize sum to prefix sum
                // Iterate from start node to current head
                while (start != NULL && start != head)
                {
                    start = start->next; // Move start pointer
                    sum += start->val;   // Update sum
                    // If the current node is not head, remove nodes in between from map
                    if (start != head)
                    {
                        mpp.erase(sum);
                    }
                    // Update the next pointer of the node corresponding to prefix sum
                    mpp[prefixSum]->next = head->next;
                }
            }
            else
            {
                mpp[prefixSum] = head; // Store prefix sum and its corresponding node in map
            }
            head = head->next; // Move to the next node
        }
        return dummy->next; // Return the modified list
    }
};
