class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st(supplies.begin(), supplies.end());
        vector<string> result;
        bool flag = true;

        while (flag) {
            flag = false;
            for (int i = 0; i < recipes.size(); i++) {
                if (st.count(recipes[i])) continue; // Already made
                
                bool canMake = true;
                for (const string& ing : ingredients[i]) {
                    if (!st.count(ing)) {
                        canMake = false;
                        break;
                    }
                }
                
                if (canMake) {
                    result.push_back(recipes[i]);
                    st.insert(recipes[i]);
                    flag = true;
                }
            }
        }

        return result;
    }
};