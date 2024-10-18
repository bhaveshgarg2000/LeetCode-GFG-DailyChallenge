class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long int n1 = 0;
        long long int n2 = 0;
        long long int mod = 1000000007;
        struct Node *p1,*p2;
        p1 = first;
        p2 = second;
        while(p1 != NULL){
            n1 = (n1 * 10 + (p1->data))%mod;
            p1 = p1 -> next;
        }
        
        
        while(p2 != NULL){
            n2 = (n2 * 10 + (p2->data))%mod;
            p2 = p2 -> next;
        }
        
        
        return (n1 * n2 )%mod;

    }
};