#include <bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> freq(maxCost+1, 0);

        for(int c:costs){
            freq[c]++;
        }

        int bars = 0;

        for(int price = 1; price <= maxCost; price++){
            if(freq[price]==0) continue;

            int iceCream = min(freq[price], coins/price);
            bars+=iceCream;
            coins -= iceCream*price;
        
            if(coins<price) break;
        }
        return bars;
}

int main(){
    int n; 
    cout<<"Enter the number of total iceCreams: ";
    cin>>n;
    vector<int> costs;
    cout<<"Enter the costs: ";
    for(int i=0; i<n; i++){
        int inputVal;
        cin>>inputVal;
        costs.push_back(inputVal);
    }

    int coins;
    cout<<"Enter the amount of coins: ";
    cin>>coins;

    int bars = maxIceCream(costs, coins);
    cout<<"The maximum ice cream bars that can be bought are: "<<bars<<endl;
    return 0;
}