/*Given an array of n numbers. Your task is to read numbers from the array and keep at-most K numbers at the top (According to their decreasing frequency) every time a new number is read. We basically need to print top k numbers sorted by frequency when input stream has included k distinct elements, else need to print all distinct elements sorted by frequency.
Example:
Input :  arr[] = {5, 2, 1, 3, 2}
k = 4
Output : 5 2 5 1 2 5 1 2 3 5 2 1 3 5*/
#include <bits/stdc++.h>
using namespace std;

void topKFrequentNumbers(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        // Working of unordered_map
        /*                   Elements(first)   Frequency(second)
            i = 0 -> arr[0] ->    1               3
            i = 3 -> arr[3] ->    3               1
            i = 4 -> arr[4] ->    2               2
            i = 6 -> arr[6] ->    4               1
        */

        // we stored in unordered_map as element(first) and then frequency(second)
        mp[arr[i]]++; // unordered_map mei arr[i] -> elements ke liye or mp[arr[i]]++ unki frequency count karne ke liye
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // auto means this is a iterator
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        // according to unordered_map element(as first) and frequency(as second)
        // pushing in a MinHeap -> frequency and then element
        minHeap.push({i->second, i->first}); // agar iterator hai to ->(arrow) operator use hota hai
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    cout << "Top " << k << " frequent numbers which are present in this array is: ";
    while (minHeap.size() > 0)
    {
        // in MinHeap frequency(as first) and element(as second)
        cout << minHeap.top().second << " "; // agar pair hai to .(dot) operator use hota hai
        minHeap.pop();
    }
}

int main()
{
    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    topKFrequentNumbers(arr, n, k);

    return 0;
}