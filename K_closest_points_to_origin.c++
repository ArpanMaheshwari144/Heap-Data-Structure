/*Given a list of points on the 2-D plane and an integer K. The task is to find K closest points to the origin and print them.
Note: The distance between two points on a plane is the Euclidean distance.
Example:
Input : point = [[3, 3], [5, -1], [-2, 4]], K = 2
*/
#include <bits/stdc++.h>
using namespace std;

#define R 4

void kClosestPointsToOrigin(int arr[R][2], int k)
{
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    for (int i = 0; i < R; i++)
    {
        maxHeap.push({arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1], {arr[i][0], arr[i][1]}});
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    while (maxHeap.size() > 0)
    {
        pair<int, int> p = maxHeap.top().second;
        cout << p.first << " " << p.second << endl;
        maxHeap.pop();
    }
}

int main()
{
    int arr[R][2] = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1},
    };
    int k = 2;

    kClosestPointsToOrigin(arr, k);

    return 0;
}