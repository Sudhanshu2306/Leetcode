class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=0; int drunk=0;
        while(empty>=numExchange || numBottles!=0){
            if(empty<numExchange){
                empty+=numBottles;
                drunk+=numBottles;
                numBottles-=numBottles;
            }
            else{
                while(empty>=numExchange){
                    empty-=numExchange;
                    numExchange++;
                    numBottles++;
                }
            }
        }
        return drunk;
    }
};