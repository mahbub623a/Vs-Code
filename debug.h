#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL   // Enable debug only if compiled with -DLOCAL
#define print(...) print_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define print(...) 42
#endif

// Forward declaration
template <typename T>
string to_string_debug(const T& value);

// ---------- Pair ----------
template <typename A, typename B>
string to_string_debug(const pair<A, B>& p) {
    return "(" + to_string_debug(p.first) + ", " + to_string_debug(p.second) + ")";
}

// ---------- Map ----------
template <typename K, typename V>
string to_string_debug(const map<K, V>& m) {
    stringstream ss;
    ss << "{";
    bool first = true;
    for (auto &kv : m) {
        if (!first) ss << ", ";
        first = false;
        ss << to_string_debug(kv.first) << " => " << to_string_debug(kv.second);
    }
    ss << "}";
    return ss.str();
}

// ---------- Generic containers ----------
template <typename T>
string range_to_string(const T& container) {
    stringstream ss;
    ss << "{";
    bool first = true;
    for (auto &x : container) {
        if (!first) ss << ", ";
        first = false;
        ss << to_string_debug(x);
    }
    ss << "}";
    return ss.str();
}

// ---------- Generic types ----------
template <typename T>
string to_string_debug(const T& value) {
    if constexpr (is_same<T, string>::value) {
        return "\"" + value + "\"";
    } else if constexpr (is_arithmetic<T>::value) {
        return std::to_string(value);
    } else if constexpr (is_same<T, char>::value) {
        return string(1, value);
    } else {
        return range_to_string(value); // assume iterable
    }
}

// ---------- Base case ----------
inline void print_out(const char* names) {
    cerr << "\n";
}

// ---------- Recursive case ----------
template <typename T, typename... Args>
void print_out(const char* names, T value, Args... args) {
    const char* comma = strchr(names, ',');
    if (comma) {
        cerr.write(names, comma - names) << " = " << to_string_debug(value) << " ";
        print_out(comma + 1, args...);
    } else {
        cerr << names << " = " << to_string_debug(value) << "\n";
    }
}

#endif // DEBUG_H
