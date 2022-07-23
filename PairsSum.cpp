#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<int> pairSumBrute(vector<int> num, int target)
{
    vector<int> ans;
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = i + 1; j < num.size(); j++)
            if (num[i] + num[j] == target)
            {
                ans.push_back(num[i]);
                ans.push_back(num[j]);
                return ans;
            }
    }
    return ans;
}

vector<int> pairSumOptimised(vector<int> num, int target)
{
    vector<int> ans;
    unordered_set<int> s;
    for (int i = 0; i < num.size(); i++)
    {
        int x = target - num[i];
        if (s.find(x) != s.end())
        {
            ans.push_back(x);
            ans.push_back(num[i]);
            return ans;
        }
        s.insert(num[i]);
    }
    return {};
}
int main()
{
    vector<int> a = {10, 5, 2, 3, -6, 9, 11};
    int target = 4;
    auto bruteStart = high_resolution_clock::now();
    vector<int>
        ansBrute = pairSumBrute(a, target);
    auto bruteStop = high_resolution_clock::now();
    auto bruteDuration = duration_cast<microseconds>(bruteStop - bruteStart);
    for (int i : ansBrute)
    {
        cout << i << ", " << endl;
    }
    cout << "It takes " << bruteDuration.count() << " microseconds for brute algorithm" << endl;

    auto optimStart = high_resolution_clock::now();
    vector<int>
        ansOptim = pairSumOptimised(a, target);
    auto optimStop = high_resolution_clock::now();
    auto optimDuration = duration_cast<microseconds>(optimStop - optimStart);
    for (int i : ansOptim)
    {
        cout << i << ", " << endl;
    }
    cout << "It takes " << optimDuration.count() << " microseconds for optimised algorithm" << endl;

    return 0;
}