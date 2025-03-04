class Solution {
public:
    bool checkPowersOfThree(int n) {
        // any way we do it, after dividing we get it in the form (3^x+1) order, if ever we get 3^x+2, we cannot move further!
        if(n%3==2) return false;
        if(n==1) return true;

        return checkPowersOfThree(n/3);
    }
};