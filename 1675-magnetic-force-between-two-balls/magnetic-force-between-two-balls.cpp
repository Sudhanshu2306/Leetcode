class Solution {
public:
    bool canWePlace(vector<int> &position, int dist, int balls) {
        int n = position.size(); //size of array
        int cntBalls = 1; //no. of cows placed
        int last = position[0]; //position of last placed cow.
        for (int i = 1; i < n; i++) {
            if (position[i] - last >= dist) {
                cntBalls++; //place next cow.
                last = position[i]; //update the last location.
            }
            if (cntBalls >= balls) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size(); //size of array
        //sort the position[]:
        sort(position.begin(), position.end());

        int low = 1, high = position[n - 1] - position[0];
        //apply binary search:
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canWePlace(position, mid, m) == true) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return high;
    }
};