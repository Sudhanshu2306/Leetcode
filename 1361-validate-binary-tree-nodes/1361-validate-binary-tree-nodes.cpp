class Solution {
public:
    bool isValidBinaryTree(int current, vector<int>& leftChild, vector<int>& rightChild, vector<bool> &visited){
        if (leftChild[current] != -1) {
            if (visited[leftChild[current]]) 
                return false;
    
            visited[leftChild[current]] = true; 
            if(!isValidBinaryTree(leftChild[current], leftChild, rightChild, visited))
                return false;
        }
        
        if (rightChild[current] != -1) {
            if (visited[rightChild[current]]) 
                return false;
    
            visited[rightChild[current]] = true; 
            if(!isValidBinaryTree(rightChild[current], leftChild, rightChild, visited))
                return false ;
        }
        return true;
    }
        
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> childCount(n, false);
        
        for (auto child : leftChild) {
            // Check if node has child
            if (child != -1)
                childCount[child] = true;
        }
        
        for (auto child : rightChild) {
            // Check if node has child
            if (child != -1) {
                if (childCount[child]) 
                    return false;

                childCount[child] = true;
            }
        }
        
        int root = -1; // Root node
        for (int i = 0; i < n; ++i) {
            if (!childCount[i]) {
                if (root == -1)
                    root = i;
                else
                    return false; 
            }
        }

        if (root == -1)
            return false;
        
        if (root == -1)
            return false; 

        
        vector<bool> visited(n) ; 
        visited[root] = true ;
        if(!isValidBinaryTree(root, leftChild, rightChild, visited))
            return false ;

        // Check if there is multiple components
        for(int i = 0 ; i < visited.size() ; i ++)
            if(!visited[i])
                return false ;

        return true; 
    }
};