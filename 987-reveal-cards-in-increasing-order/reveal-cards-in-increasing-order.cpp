class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        // vector<int> ans;
        sort(deck.rbegin(),deck.rend());
        deque<int> dq;

        for(int i=0;i<n;i++){
            if(!dq.empty()){
              dq.push_front(dq.back());
              dq.pop_back();  
            }
            dq.push_front(deck[i]);  
        }
        vector<int> ans(dq.begin(),dq.end());
        return ans;
    }
};