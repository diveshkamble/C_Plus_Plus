#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> BruteTriplet(vector<int> arr, int target)
{
    vector<vector<int>> result;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    result.push_back({arr[i], arr[j], arr[k]});
                }
            }
        }
    }
    return result;
}

// Better Approach: O(N Log N) + O(N)
vector<vector<int>> PairSumTriplets(vector<int> arr, int target)
{
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int j, k;
    for (int i = 0; i < n - 3; i++)
    {
        j = i + 1;
        k = n - 1;

        while (j < k)
        {
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];

            if (current_sum == target)
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (current_sum > target)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int target = 18;
    vector<vector<int>> ans;
    ans = PairSumTriplets(array, target);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int x : ans[i])
        {
            cout << x << ",";
        }
        cout << endl;
    }
}
