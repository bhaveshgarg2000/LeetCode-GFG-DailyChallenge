class Solution {
    public:
    long long unsigned int decimalValue(Node *head) {
        long long unsigned int decimal_value=0, M=1e9+7;
        while(head) {
            decimal_value = (decimal_value*2+head->data) % M;
            head=head->next;
        }
        return decimal_value;
    }
};