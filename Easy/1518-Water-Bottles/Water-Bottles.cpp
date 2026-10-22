class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        // All drink Bottle ka count.
        int count = numBottles;

        while(numBottles>=numExchange)
        {
            // Exchange Bottles
            int newBottles = numBottles/numExchange;
            // Jo Exchange Bottle hai. Usko drink kar liye hai. To usko count ker liye hai.
            count = count+newBottles;
            // ExtraEmpty Bottles + Exchange Bottles -> drink ker liye hai.
            numBottles = numBottles%numExchange+newBottles;
        }

        return count;
    }
};