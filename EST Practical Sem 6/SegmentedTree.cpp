#include <bits/stdc++.h>
using namespace std;

void buildSegmentTree(vector<int> &arr, vector<int> &segTree, int index, int left, int right)
{
    if (left == right)
    {
        segTree[index] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    buildSegmentTree(arr, segTree, 2 * index + 1, left, mid);
    buildSegmentTree(arr, segTree, 2 * index + 2, mid + 1, right);
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
}

int querySegmentTree(vector<int> &segTree, int index, int left, int right, int qLeft, int qRight)
{
    if (qLeft > right || qRight < left)
    {
        return 0;
    }
    if (qLeft <= left && qRight >= right)
    {
        return segTree[index];
    }
    int mid = left + (right - left) / 2;
    return querySegmentTree(segTree, 2 * index + 1, left, mid, qLeft, qRight) +
           querySegmentTree(segTree, 2 * index + 2, mid + 1, right, qLeft, qRight);
}

void updateValue(vector<int> &segTree, int index, int left, int right, int pos, int newValue)
{
    if (left == right)
    {
        segTree[index] = newValue;
        return;
    }
    int mid = left + (right - left) / 2;
    if (pos <= mid)
    {
        updateValue(segTree, 2 * index + 1, left, mid, pos, newValue);
    }
    else
    {
        updateValue(segTree, 2 * index + 2, mid + 1, right, pos, newValue);
    }
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> segTree(4 * n);
    buildSegmentTree(arr, segTree, 0, 0, n - 1);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {

            int pos, newValue;
            cin >> pos >> newValue;
            updateValue(segTree, 0, 0, n - 1, pos, newValue);
        }
        else
        {

            int l, r;
            cin >> l >> r;
            cout << querySegmentTree(segTree, 0, 0, n - 1, l, r) << endl;
        }
    }

    return 0;
}