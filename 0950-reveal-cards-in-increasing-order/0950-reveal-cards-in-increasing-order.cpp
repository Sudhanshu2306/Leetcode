class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end(),greater());
        deque<int> d;
        for(int i=0;i<deck.size();i++){
            if(!d.empty()){
              d.push_front(d.back());
              d.pop_back();  
            }
            d.push_front(deck[i]);   
        }
        vector<int> temp(d.begin(),d.end());
    return temp;
    }
};