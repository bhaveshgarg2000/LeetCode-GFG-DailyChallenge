class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
         // Code here
         if((*head)==NULL || (*head)->next==NULL) return ;
         Node *temp=*head;
         vector<int>v;
         while(temp){
             auto val=temp->data;
             v.push_back(val);
             temp=temp->next;
         }
         
        std:: sort(v.begin(),v.end());
         
         temp=*head;
         
        for(int i=0;i<v.size();i++){
            temp->data=v[i];
            temp=temp->next;
        }
    }
};