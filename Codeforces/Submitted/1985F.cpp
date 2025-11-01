// https://codeforces.com/problemset/problem/1985/F
// Final Boss

#include <bits/stdc++.h>
using namespace std;

void fn(int health, vector<int64_t> &damage, vector<int64_t> &cooldown, vector<int64_t> &results)
{
    int64_t turn = 1;

    // {next turn, {damage, cooldown}}
    priority_queue<pair<int64_t, pair<int64_t, int64_t>>, vector<pair<int64_t, pair<int64_t, int64_t>>>, greater<pair<int64_t, pair<int64_t, int64_t>>>> pq;

    for (int i = 0; i < damage.size(); i++)
    {
        health -= damage[i];
        if (health <= 0)
        {
            results.push_back(1);
            return;
        }
        pq.push({(turn + cooldown[i]), {damage[i], cooldown[i]}});
    }

    while (health > 0)
    {
        int64_t cool = pq.top().first;
        int64_t dmg = pq.top().second.first;
        int64_t nextTurn = pq.top().second.second;
        pq.pop();
        turn = cool;
        health -= dmg;
        pq.push({cool + nextTurn, {dmg, nextTurn}});
    }

    results.push_back(turn);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int64_t> results;

    int t;
    cin >> t;
    while (t--)
    {
        int health, n;
        cin >> health >> n;
        vector<int64_t> damage(n);
        vector<int64_t> cooldown(n);
        for (int i = 0; i < n; i++)
            cin >> damage[i];
        for (int i = 0; i < n; i++)
            cin >> cooldown[i];

        fn(health, damage, cooldown, results);
    }

    for (auto it : results)
        cout << it << "\n";

    return 0;
}