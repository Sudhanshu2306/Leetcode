class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int a = arr.size() / 4;
        int c = 1;
        int x = arr[0];
        for (int i = 1 ; i < arr.size() ; i++) {

            if ( x == arr[i]){
                c++;
            } 
            else {
                c = 1;
            }
            if (c > a){
                return arr[i]; 
            } 
            
            x = arr[i];
        }

        return x;
    }
};