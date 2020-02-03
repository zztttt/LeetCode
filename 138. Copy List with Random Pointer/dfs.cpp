/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    // old Node - new Node
    map<Node*, Node*> visited;
    
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        if(visited.find(head) != visited.end())
            return visited[head];
        else{
            Node* root = new Node(head->val, nullptr, nullptr);
            visited[head] = root;
            
            root->next = copyRandomList(head->next);
            root->random = copyRandomList(head->random);
            return root;
        }
    }
};