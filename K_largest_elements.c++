/*rite an efficient program for printing k largest elements in an array. Elements in array can be in any order.
For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the largest 3 elements i.e., k = 3 then your program should print 50, 30 and 23.
*/
#include <bits/stdc++.h>
using namespace std;

void kLargestElements(int arr[], int n, int k)
{
    // Declaration of MinHeap
    priority_queue<int, vector<int>, greater<int>> minHeap; // jitne bhi chote element hote hai wo upar aa jate hai
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    cout << k << " largest elements are: ";
    while (minHeap.size() > 0)
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    kLargestElements(arr, n, k);

    return 0;
}