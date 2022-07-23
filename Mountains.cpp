#include <iostream>
#include <vector>

using namespace std;

int highest_mountain(vector<int> arr)
{
    int largest = 0;
    // loop through the array
    // looping from 1 because 0 can never be a peak
    // looping till n-2 because n can never be a peak
    // for a peak, n-1 and n+1 should be smaller than n
    int n = arr.size();
    for (int i = 1; i <= n - 2;)
    {
        // check if arr[i] is peak or not
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
        {
            // iterate left
            int count = 1;
            int j = i;
            while (j >= 1 and arr[j] > arr[j - 1])
            {
                j--;
                count++;
            }

            // iterate right
            while (i <= n - 2 and arr[i] > arr[i + 1])
            {
                i++;
                count++;
            }
            largest = max(largest, count);
        }
        else
        {
            i++;
        }
    }
    return largest;
}

int main()
{
    vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};

    int ans = highest_mountain(arr);
    cout << ans;
    return 0;
}