// https://codeforces.com/problemset/problem/977/F
// Consecutive Subsequence
// Codeforces 977F -> Consecutive Subsequence

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<long long, int> len;  // val -> best len ending at val
    unordered_map<long long, int> last; // val -> last index of that best
    vector<int> parent(n, -1);
    int bestLen = 0, bestEnd = -1;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < n; i++)
    {
        long long val = nums[i];
        int prevLen = len.count(val - 1) ? len[val - 1] : 0;
        int currLen = prevLen + 1;

        if (!len.count(val) || currLen > len[val])
        {
            len[val] = currLen;
            parent[i] = last.count(val - 1) ? last[val - 1] : -1;
            last[val] = i;
        }

        if (len[val] > bestLen)
        {
            bestLen = len[val];
            bestEnd = last[val];
        }
    }

    vector<int> pickedIndices;
    for (int i = bestEnd; i != -1; i = parent[i])
        pickedIndices.push_back(i);
    reverse(pickedIndices.begin(), pickedIndices.end());

    cout << bestLen << "\n";
    for (auto &i : pickedIndices)
    {
        cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}