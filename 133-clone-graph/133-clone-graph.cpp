/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        map<Node*,Node*> visited;
        return cloneG(node,visited);
    }
    
    Node* cloneG(Node* node, map<Node*,Node*> & visited){
        Node* newNode = new Node(node->val);
        visited.insert({node,newNode});
        vector<Node*> neighborsCopy;
        for(int i = 0; i < node->neighbors.size();++i){
            if(visited.find(node->neighbors[i]) == visited.end()){
                Node* childNode = cloneG(node->neighbors[i],visited);
                visited.insert({node->neighbors[i],childNode});
                neighborsCopy.push_back(childNode);
            }
            else{
                neighborsCopy.push_back(visited.find(node->neighbors[i])->second);
            }
        }
        newNode->neighbors = neighborsCopy;
        return newNode;
    }
};