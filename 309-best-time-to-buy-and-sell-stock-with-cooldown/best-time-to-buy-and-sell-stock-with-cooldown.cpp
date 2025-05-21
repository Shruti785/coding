class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int startIndex = 0; // starting point
        bool coolDown = false; // no cooldown period at the start
        bool canBuy = true; // I can buy at the start

        int n = prices.size();

        vector<vector<int>> nextState(2,vector<int>(2,0)); // stores info about next index state
        vector<vector<int>> currState(2,vector<int>(2,0)); // stores info about current index state

        for(int startIndex = n-1 ; startIndex>=0 ; startIndex--){
            for(int canBuy = 0; canBuy<=1; canBuy++){
                for(int coolDown = 1; coolDown>=0 ; coolDown--){
                    
                    if(coolDown){   // if coolDown period is valid, move to the next index with no cooldown period left
                        currState[canBuy][coolDown] = nextState[canBuy][0];
                        continue;
                    }

                    int profit1 = 0;
                    int profit2 = 0;

                    if(canBuy){ // I have the permission to buy
                        profit1 = -prices[startIndex] + nextState[0][coolDown];  // buying the stock
                        profit2 = nextState[1][coolDown];  // moving forward
                    }

                    else{  // i already have a stock , so I must sell it first
                        profit1 = prices[startIndex] + nextState[1][1]; // selling the stock {Cooldown Period activated}
                        profit2 = nextState[0][coolDown]; // moving forward 
                    }

                    currState[canBuy][coolDown] = max(profit1,profit2);    // we want to maximise the profit from buying and selling of stocks

                }
            }

            nextState = currState;
        }

        return currState[canBuy][coolDown];

    }
};