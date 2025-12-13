/* https://github.com/DuckyShine004/leetcode-template
 * Line number is incorrect */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

#define all(a) (a).begin(), (a).end()
#define in(a, b) ((a).find(b) != (a).end())

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vi = vector<int>;
using vll = vector<long long>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long, long>>;

inline constexpr pair<int, int> D4[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
inline constexpr pair<int, int> D8[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, -1}};

template <class S, class T = null_type, class chash = hash<S>> using hash_set = gp_hash_table<S, T, chash>;
template <class S, class T = null_type, class cmp = less<S>> using ordered_set = tree<S, T, cmp, rb_tree_tag, tree_order_statistics_node_update>;

inline int recur_depth = 0;

inline void __print(int x) {
    cout << x;
}

inline void __print(long x) {
    cout << x;
}

inline void __print(long long x) {
    cout << x;
}

inline void __print(unsigned x) {
    cout << x;
}

inline void __print(unsigned long x) {
    cout << x;
}

inline void __print(unsigned long long x) {
    cout << x;
}

inline void __print(float x) {
    cout << x;
}

inline void __print(double x) {
    cout << x;
}

inline void __print(long double x) {
    cout << x;
}

inline void __print(char x) {
    cout << '\'' << x << '\'';
}

inline void __print(const char *x) {
    cout << '\"' << x << '\"';
}

inline void __print(const string &x) {
    cout << '\"' << x << '\"';
}

inline void __print(bool x) {
    cout << (x ? "true" : "false");
}

template <typename T, typename V> void __print(const pair<T, V> &x) {
    cout << '{';
    __print(x.first);
    cout << ", ";
    __print(x.second);
    cout << '}';
}

template <typename T> void __print(const T &x) {
    int f = 0;
    cout << '{';
    for (const auto &i : x) {
        if (f++)
            cout << ", ";
        __print(i);
    }
    cout << '}';
}

inline void _print() {
    cout << "]" << endl;
}

template <typename T, typename... V> void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v))
        cout << ", ";
    _print(v...);
}

template <typename K, typename V> void __print(const map<K, V> &x) {
    int f = 0;
    cout << '{';
    for (const auto &it : x) {
        if (f++)
            cout << ", ";
        __print(it.first);
        cout << ": ";
        __print(it.second);
    }
    cout << '}';
}

template <typename K, typename V> void __print(const unordered_map<K, V> &x) {
    int f = 0;
    cout << '{';
    for (const auto &it : x) {
        if (f++)
            cout << ", ";
        __print(it.first);
        cout << ": ";
        __print(it.second);
    }
    cout << '}';
}

template <typename T, typename Container> void __print(const queue<T, Container> &q) {
    int f = 0;
    queue<T, Container> tmp = q;
    cout << '{';
    while (!tmp.empty()) {
        if (f++)
            cout << ", ";
        __print(tmp.front());
        tmp.pop();
    }
    cout << '}';
}

template <typename T, typename Container> void __print(const stack<T, Container> &s) {
    int f = 0;
    stack<T, Container> tmp = s;
    cout << '{';
    while (!tmp.empty()) {
        if (f++)
            cout << ", ";
        __print(tmp.top());
        tmp.pop();
    }
    cout << '}';
}

template <typename T, typename Container, typename Compare> void __print(const priority_queue<T, Container, Compare> &pq) {
    int f = 0;
    priority_queue<T, Container, Compare> tmp = pq;
    cout << '{';
    while (!tmp.empty()) {
        if (f++)
            cout << ", ";
        __print(tmp.top());
        tmp.pop();
    }
    cout << '}';
}

inline vector<string> split_names(const string &names_str) {
    vector<string> names;
    size_t start = 0;
    size_t comma = names_str.find(',');
    while (comma != string::npos) {
        string name = names_str.substr(start, comma - start);
        size_t last = name.find_last_not_of(" \t");
        size_t first = name.find_first_not_of(" \t");
        if (first != string::npos && last != string::npos)
            name = name.substr(first, last - first + 1);
        else
            name = "";
        names.push_back(name);
        start = comma + 1;
        comma = names_str.find(',', start);
    }
    string name = names_str.substr(start);
    size_t last = name.find_last_not_of(" \t");
    size_t first = name.find_first_not_of(" \t");
    if (first != string::npos && last != string::npos)
        name = name.substr(first, last - first + 1);
    else
        name = "";
    names.push_back(name);
    return names;
}

template <typename T> inline string to_string_debug(const T &x) {
    ostringstream oss;
    streambuf *old_buf = cout.rdbuf(oss.rdbuf());
    __print(x);
    cout.rdbuf(old_buf);
    return oss.str();
}

/* Change to whatever the offset is to get correct line number in debug */
inline constexpr int LINE_OFFSET = 0;

namespace Debug {
template <typename... Args> void debug(const char *func, const int line, const Args &...args) {
    vector<string> values{to_string_debug(args)...};
    if (values.empty())
        return;
    int lineNumber = line + LINE_OFFSET;
    cout << string(recur_depth, '\t') << func << ":" << lineNumber << " | ";
    for (size_t i = 0; i < values.size(); i++) {
        if (i > 0)
            cout << " ";
        cout << values[i];
    }
    cout << endl;
}
} // namespace Debug

#define debug(...) (Debug::debug(__func__, __LINE__, __VA_ARGS__))
