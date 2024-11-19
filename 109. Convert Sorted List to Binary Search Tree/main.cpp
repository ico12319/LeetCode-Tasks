#include <iostream>

//109. Convert Sorted List to Binary Search Tree
//Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val) : val(val),next(nullptr){}
    ListNode(int val,ListNode* next) : val(val),next(next){}
};

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode* left,TreeNode* right) : val(val),left(left),right(right){}
};


ListNode* get_mid(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev)
        prev->next = nullptr;
    return slow;
}


TreeNode* sortedListToBST(ListNode* head) {
    if(!head) return nullptr;
    
    ListNode* mid = get_mid(head);
    TreeNode* node = new TreeNode(mid->val);
    
    if(head == mid)
        return node;
    
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(mid->next);
    
    return node;
}

void in_order(TreeNode* root){
    if(!root) return;
    in_order(root->left);
    std::cout<<root->val<<" ";
    in_order(root->right);
}

int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    
    TreeNode* tree = sortedListToBST(head);
    in_order(tree);
}
