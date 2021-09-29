/*Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.*/
#include <bits/stdc++.h>
using namespace std;

int kthSmallestElement(int arr[], int n, int k)
{
    // Declaration of MaxHeap
    priority_queue<int> maxHeap; // jitne bhi bade element hote hai wo upar aa jate hai
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "The " << k << "rd smallest element is " << kthSmallestElement(arr, n, k);

    return 0;
}