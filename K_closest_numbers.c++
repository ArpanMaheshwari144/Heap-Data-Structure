/*Given an unsorted array and two numbers x and k, find k closest values to x.
Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3*/
#include <bits/stdc++.h>
using namespace std;

void kClosestNumbers(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < n; i++)
    {
        // push pair into the MaxHeap
        // If there is a pair in MinHeap so it is always sort according to their first(key). Key is the denoted as first in MinHeap
        maxHeap.push({abs(arr[i] - x), arr[i]});
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    cout << "The numbers which are closest or equal to " << x << " are: ";
    while (maxHeap.size() > 0)
    {
        cout << maxHeap.top().second << " ";
        maxHeap.pop();
    }
}

int main()
{
    int arr[] = {5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int x = 7;

    kClosestNumbers(arr, n, k, x);

    return 0;
}