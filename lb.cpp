// 0/1 KNAPSACK USING DYNAMIC PROGRAMMING

/*
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/

#include <bits/stdc++.h>
using namespace std;

// A utility function that returns maximum of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// BOTTOM UP APPROACH
int knapsack(vector<int> &profit, vector<int> &weight, int capacity, int n){
    // step 1 : creating 2d dp vector
    vector<vector<int> > dp(n, vector<int> (capacity + 1, 0));

    // step 2 : analysing base case
    for(int w = weight[0]; w <= capacity; ++w){
        if(weight[0] <= capacity)
            dp[0][w] = profit[0];
        else
            dp[0][w] = 0;
    }

    // step 3: take care of remaining recursive calls
    for(int index = 1; index < n; ++index){
        for(int w = 0; w <= capacity; ++w){
            int include = 0;
            
            if(weight[index] <= w)
                include = profit[index] + dp[index - 1][w - weight[index]];
            
            int exclude = 0 + dp[index - 1][w];
            dp[index][w] = max(include, exclude);
        }
    }

    int ans = dp[n - 1][capacity];

    int x = n - 1;
    
    cout << "Selected Items: \n";
    while(x != 0){
        if(dp[x][capacity] != dp[x - 1][capacity]){
            cout << "Item " << x + 1 << " with Weight " << weight[x] << " and Profit " << profit[x] << endl;
            capacity -= weight[x];
        }
        x--;
    }

    return ans;
}

// Driver Code
int main()
{
	int n;
    
    cout << "Enter the number of items : ";
    cin >> n;

    vector<int> p, w;

    for(int i = 0; i < n; ++i){
        cout << "Enter Profit and Weight of item " << i + 1 << " : ";
        int x, y;
        cin >> x >> y;
        p.push_back(x);
        w.push_back(y);
    }

    int W;
    cout << "Enter capacity of Knapsack : ";
    cin >> W;

    cout << "Item :\t";
    for(int i = 0; i < n; ++i){
        cout << i+1 << "\t";
    }
    cout << endl;

    cout << "Profit : ";
    for(int i = 0; i < n; ++i){
        cout << p[i] << "\t";
    }
    cout << endl;

    cout << "Weight : ";
    for(int i = 0; i < n; ++i){
        cout << w[i] << "\t";
    }
    cout << endl;
	
	int ans = knapsack(p, w, W, n);

	cout << "Maximum profit attained is : "	<< ans << endl;

	return 0;
}


