/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode *buildTree(ListNode *&head, int st, int end)
    {
        if(st>end) return NULL;

        int mid = st  +(end-st)/2;
        TreeNode *left = buildTree(head,st,mid-1);

        TreeNode *root = new TreeNode(head->val);
        head = head->next;

        TreeNode *right = buildTree(head,mid+1,end);

        root->left = left;
        root->right = right;

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *temp = head;
        int cnt = 0;

        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }

        return buildTree(head,0,cnt-1);
    }
};