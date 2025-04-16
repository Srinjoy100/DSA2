// USE MAP FOR BETTER TIME COMPLEXITY//

class Solution
{
public:
    int findPosition(vector<int> in, int element, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    Node *solve(vector<int> in, vector<int> pre, int &index, int inOrderStart, int inOrderEnd, int n)
    {
        if (index >= n || inOrderStart > inOrderEnd)
        {
            return NULL;
        }
        int element = pre[index++];
        Node *temp = new Node(element);
        int pos = findPosition(in, element, n);
        temp->left = solve(in, pre, index, inOrderStart, pos - 1, n);
        temp->right = solve(in, pre, index, pos + 1, inOrderEnd, n);
        return temp;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &in, vector<int> &pre)
    {
        // code here
        int preOrderIndex = n - 1;
        int n = in.size();
        Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
        return ans;
    }
};
