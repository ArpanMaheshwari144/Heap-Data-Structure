/*Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.
Example:
Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}*/
#include <bits/stdc++.h>
using namespace std;

void sortKSortedArray(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            v.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    while (minHeap.size() > 0)
    {
        v.push_back(minHeap.top());
        minHeap.pop();
    }

    cout << "Sorted array is: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    sortKSortedArray(arr, n, k);

    return 0;
}