
// USE MAP FOR BETTER TIME COMPLEXITY//

class Solution
{
public:
    int findPosition(vector<int> &in, int element, int n)
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

    Node *solve(vector<int> &in, vector<int> &post, int &index, int inOrderStart, int inOrderEnd, int n)
    {
        if (index < 0 || inOrderStart > inOrderEnd)
        {
            return NULL;
        }

        int element = post[index--];
        Node *temp = new Node(element);
        int pos = findPosition(in, element, n);

        // Build right first (since we're going backwards in postorder)
        temp->right = solve(in, post, index, pos + 1, inOrderEnd, n);
        temp->left = solve(in, post, index, inOrderStart, pos - 1, n);

        return temp;
    }

    // Function to build the tree from given inorder and postorder traversals
    Node *buildTree(vector<int> &in, vector<int> &post)
    {
        int n = in.size();
        int postOrderIndex = n - 1;
        Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n);
        return ans;
    }
};
