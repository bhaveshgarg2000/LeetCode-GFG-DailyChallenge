class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       Node *curr = head;
       Node *temp = new Node(data);
    //   when LL is empty
       if(curr == NULL){
           temp->next = temp;
           return temp;
       }
    //   if head is greater than data 
       else if(curr -> data >= data){
           while(curr->next != head){
               curr = curr->next;
           }
           curr->next = temp;
           temp->next = head;
           return temp;
       }
       else{
           while(curr->next != head and curr->next->data < data){
               curr = curr->next;
           }
           temp->next = curr->next;
           curr->next = temp;
           return head;
       }
    }
};