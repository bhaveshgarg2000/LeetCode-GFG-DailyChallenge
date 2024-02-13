class Solution
{
public:
    // Recursive function to clone the graph
    Node *solve(Node *node, vector<Node *> &vis)
    {
        // Create a new node with the same value as the original node
        Node *graph = new Node(node->val);

        // Mark the original node as visited in the vis array
        vis[node->val] = graph;

        // Iterate through the neighbors of the original node
        for (auto it : node->neighbors)
        {
            // If the neighbor hasn't been visited yet
            if (!vis[it->val])
            {
                // Recursively clone the neighbor and mark it visited
                solve(it, vis);
            }
            // Add the cloned neighbor (which might have been already visited) to the current node's neighbors list
            graph->neighbors.push_back(vis[it->val]);
        }

        // Return the cloned graph
        return graph;
    }

    // Main function to clone the graph
    Node *cloneGraph(Node *node)
    {
        // Create a vector to keep track of visited nodes (assuming there are at most 10000 nodes)
        vector<Node *> vis(10001, NULL);

        // Call the recursive function to clone the graph starting from the given node
        return solve(node, vis);
    }
};
