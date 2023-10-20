/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize the stack with the nested list and the index of the current element
        stack.push({&nestedList, 0});
    }
    
    int next() {
        // Ensure hasNext() is called before next(), so we are guaranteed to have the next integer
        return nextVal;
    }
    
    bool hasNext() {
        while (!stack.empty()) {
            auto& top = stack.top();
            auto& nestedList = top.first;
            int& index = top.second;

            if (index == nestedList->size()) {
                // We have reached the end of the current list, pop it from the stack
                stack.pop();
            } else {
                if ((*nestedList)[index].isInteger()) {
                    // If the current element is an integer, set nextVal and increment the index
                    nextVal = (*nestedList)[index].getInteger();
                    index++;
                    return true;
                } else {
                    // If the current element is a nested list, push it onto the stack and increment the index
                    stack.push({&((*nestedList)[index].getList()), 0});
                    index++;
                }
            }
        }
        return false; // No more integers in the nested list
    }
    
private:
    stack<pair<const vector<NestedInteger>*, int>> stack; // Stack to hold nested lists and their indices
    int nextVal; // Variable to store the next integer
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */