#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

// struct QueueUtils {
//     static int scheduleBands(const vector<string>& bands, int cooldown) {
//         if (bands.empty()) return 0;

//         int len = bands.size();
//         if (cooldown == 0) return len;

//         unordered_map<string, int> freq;
//         for (auto &band : bands) {
//             freq[band]++;
//         }

//         int maxFreq = 0;
//         int countMax = 0;

//         for (auto &f : freq) {
//             if (f.second > maxFreq) {
//                 maxFreq = f.second;
//                 countMax = 1;
//             } else if (f.second == maxFreq) {
//                 countMax++;
//             }
//         }

//         return max(len, (maxFreq - 1) * (cooldown + 1) + countMax);
//     }
// };

// global cooldown tanımlandığı için başka caseler varsa hatalı cevap verecektir. map kullanmadan yapılabilen çözüm bulamadık.
struct QueueUtils {
    static int scheduleBands(const vector<string>& bands, int cooldown) {
        if (bands.empty()) return 0;

        int len = bands.size();
        if (cooldown == 0) return len;

        int tempCooldown = cooldown;

        queue<string> q;
        stack<string> st;
        st.push("");
        for (auto band : bands) {
            if (tempCooldown == -1) {
                st.push(q.front());
                q.pop();
            }

            if (band == st.top()) {
                q.push(band);
                tempCooldown = cooldown;
            } else if (tempCooldown == -1 && q.empty()) {
                st.push("idle");
            } else {
                st.push(band);
            }

            if(!q.empty()) tempCooldown--;
        }

        while (!q.empty()) {
            if (tempCooldown != -1) {
                tempCooldown--;
                st.push("idle");
            } else {
                st.push(q.front());
                q.pop();
                tempCooldown = cooldown;
            }
        }

        int res = 0;
        while (!st.empty()) {
            res++;
            st.pop();
        }

        return res - 1;
    }
};

void solve() {
    vector<string> bands = {
        "Architects",
        "Architects",
        "BMTH",
        "IceNineKills",
        "Architects",
        "Imminence"
    };

    int cooldown = 2;

    int ans = QueueUtils::scheduleBands(bands, cooldown);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}