class Solution
{

public:
    int ans = 0;

    int merge(vector<int> &vec, int low, int mid, int high)
    {

        vector<int> temp(high - low + 1);

        int i = low;

        int j = mid + 1;

        int k = 0;

        while (i <= mid && j <= high)
        {

            if (vec[i] <= vec[j])
            {

                temp[k++] = vec[i++];
            }
            else
            {

                ans += mid - i + 1;

                temp[k++] = vec[j++];
            }
        }

        while (i <= mid)
        {

            temp[k++] = vec[i++];
        }

        while (j <= high)
        {

            temp[k++] = vec[j++];
        }

        i = 0;

        for (i = 0; i < temp.size(); i++)
        {

            vec[i + low] = temp[i];
        }

        return ans;
    }

    int mergeSort(vector<int> &vec, int low, int high)
    {

        if (low < high)
        {

            int mid = (low + high) / 2;

            mergeSort(vec, low, mid);

            mergeSort(vec, mid + 1, high);

            merge(vec, low, mid, high);
        }
    }

    void inorder(Node *root, vector<int> &vec)
    {

        if (!root)
            return;

        inorder(root->left, vec);

        vec.push_back(root->data);

        inorder(root->right, vec);
    }

    /*You are required to complete below function */

    int pairsViolatingBST(int n, Node *root)
    {

        vector<int> vec;

        inorder(root, vec);

        int ans = 0;

        ans = mergeSort(vec, 0, vec.size() - 1);

        return ans;
    }
};