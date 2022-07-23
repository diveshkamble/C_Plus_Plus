#include <iostream>
#include <vector>

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

int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int target = 18;
    vector<vector<int>> ans;
    ans = BruteTriplet(array, target);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int x : ans[i])
        {
            cout << x << ",";
        }
        cout << endl;
    }
}
