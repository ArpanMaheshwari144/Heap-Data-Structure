/*Given an array of integers and two numbers k1 and k2. Find the sum of all elements between given two k1’th and k2’th smallest elements of the array. It may  be assumed that all elements of array are distinct.
Example :
Input : arr[] = {20, 8, 22, 4, 12, 10, 14},  k1 = 3,  k2 = 6  
Output : 26          
3rd smallest element is 10. 6th smallest element is 20. Sum of all element between k1 & k2 is 12 + 14 = 26*/
#include <bits/stdc++.h>
using namespace std;

int kthSmallestElement(int arr[], int n, int k)
{
    priority_queue<int> maxHeap;
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
    int arr[] = {1, 3, 12, 5, 15, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k1 = 3;
    int k2 = 6;

    int first = kthSmallestElement(arr, n, k1);
    int second = kthSmallestElement(arr, n, k2);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > first && arr[i] < second)
        {
            sum = sum + arr[i];
        }
    }
    cout << "The sum of elements between " << k1 << "rd smallest and " << k2 << "th smallest is " << sum;

    return 0;
}