/*Print the elements of an array in the increasing frequency if 2 numbers have same frequency then print the one which came first.
Example:
Input : arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output : arr[] = {8, 8, 8, 2, 2, 5, 5, 6}
*/
#include <bits/stdc++.h>
using namespace std;

void frequenySort(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    priority_queue<pair<int, int>> maxHeap;

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        maxHeap.push({i->second, i->first});
    }

    while (maxHeap.size() > 0)
    {
        int frequency = maxHeap.top().first;
        int element = maxHeap.top().second;
        for (int i = 1; i <= frequency; i++)
        {
            cout << element << " ";
        }
        maxHeap.pop();
    }
}

int main()
{
    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    frequenySort(arr, n);

    return 0;
}