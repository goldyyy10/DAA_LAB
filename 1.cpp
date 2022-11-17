// FRACTIONAL KNAPSACK USING GREEDY METHOD
// TIME COMPLEXITY -> O(N)
// SPACE COMPLEXITY -> O(N)

#include <bits/stdc++.h>

using namespace std;

double Fknapsack(vector<int> profit, vector<int> weight, int C){
    multimap<double, int, greater<double>> temp;
    int items = profit.size();

    for(int i = 0; i < items; ++i){
        double pw = (double)profit[i] / weight[i];
        temp.insert(make_pair(pw, i));
    }

    double max_profit = 0;

    for(auto it = temp.begin(); it != temp.end(); ++it){
        if((C >= 0) && (weight[it->second] <= C)){
            max_profit += profit[it->second];
            C -= weight[it->second];
        }
        else{
            max_profit += (profit[it->second] * (C / (double)weight[it->second]));
            break;
        }
    }

    return max_profit;
}

int main(){
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

    double ans = Fknapsack(p, w, W);

    cout << "\nMaximum profit attained is : " << ans << endl;

    return 0;
}