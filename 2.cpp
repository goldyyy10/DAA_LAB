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

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int profit[], int weight[], int C, int n){
    int k[n + 1][C + 1];

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= C; ++j){
            if(i == 0 || j == 0){
                k[i][j] = 0;
            }
            else if(weight[i - 1] <= j){
                k[i][j] = max(k[i - 1][j], (k[i - 1][j - weight[i - 1]] + profit[i - 1]));
            }
            else{
                k[i][j] = k[i - 1][j];
            }
        }
    }

    int res = k[n][C];

    cout << "Selected Items: \n";
	
	while (n != 0) {
		if (k[n][C] != k[n - 1][C]) {
			cout << "\tItem " << n << " with Weight = " << weight[n - 1] << " and Profit = " << profit[n - 1] << endl;
			C = C - weight[n - 1];
		}
		
		n--;
	}

    return res;
}

// Driver Code
int main()
{
	int n;
    
    cout << "Enter the number of items : ";
    cin >> n;

    int p[n], w[n];

    for(int i = 0; i < n; ++i){
        cout << "Enter Profit and Weight of item " << i + 1 << " : ";
		cin >> p[i] >> w[i];
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


