// https://codeforces.com/problemset/problem/702/C
// Cellular Network

#include <bits/stdc++.h>
using namespace std;

int findMinTowers(vector<int> &cities, vector<int> &towers)
{
    int n = cities.size(), m = towers.size();
    int j = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        int diff = abs(cities[i] - towers[j]);
        while (j + 1 < m && abs(cities[i] - towers[j + 1]) < diff)
        {
            diff = abs(cities[i] - towers[j + 1]);
            j++;
        }

        ans = max(ans, diff);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> cities;
    vector<int> towers;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!i)
        {
            cities.push_back(x);
        }
        else if (cities[cities.size() - 1] != x)
        {
            cities.push_back(x);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (!i)
        {
            towers.push_back(x);
        }
        else if (towers[towers.size() - 1] != x)
        {
            towers.push_back(x);
        }
    }

    cout << findMinTowers(cities, towers) << "\n";

    return 0;
}