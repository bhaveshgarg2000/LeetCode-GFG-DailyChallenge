class Solution
{
public:
    void solve(Node* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        solve(root->left,v);
        v.push_back(root->data);
        solve(root->right,v);
    }
    Node* create_tree(vector<int>v,int index){
        if(v[index]==-1){
            return NULL;
        }
        Node* newnode=new Node(v[index]);
        newnode->right=create_tree(v,index+1);
        return newnode;
    }
    Node *flattenBST(Node *root)
    {
        // code here
        vector<int>v;
        solve(root,v);
        v.push_back(-1);
        Node* newroot=create_tree(v,0);
        return newroot;
    }
};