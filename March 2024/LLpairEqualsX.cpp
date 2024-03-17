class Solution
{
public:
    // your task is to complete this function
    int countPairs(struct Node *head1, struct Node *head2, int x)
    {
        // NAIVE APPROACH
        //   int cnt = 0;
        //   struct Node* curr1 = head1;
        //   struct Node* curr2 = head2;
        //   while(curr1 != NULL){
        //       curr2 = head2;
        //       while(curr2 != NULL){
        //           if(curr1 -> data + curr2 -> data == x){
        //               cnt++;
        //               break;
        //           }
        //           curr2 = curr2 -> next;
        //       }
        //       curr1 = curr1 -> next;
        //   }
        //   return cnt;
        // OPTIMISED CODE
        unordered_set<int> st;
        struct Node *curr1 = head1;
        struct Node *curr2 = head2;
        while (curr1 != NULL)
        {
            st.insert(curr1->data);
            curr1 = curr1->next;
        }

        int cnt = 0;
        while (curr2 != NULL)
        {
            if (st.find(x - curr2->data) != st.end())
            {
                cnt++;
            }
            curr2 = curr2->next;
        }
        return cnt;
    }
};