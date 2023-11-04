/**
 * @file
 *
 */

#pragma once

// Standard C++ libraries
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <variant>
#include <any>

// Include custom header files
#include "UC.h"
#include "Student.h"
#include "Class.h"
#include "Date.h"

/**
 * @brief A hash function for std::pair objects.
 *
 * This struct defines a hash function for std::pair objects, allowing them to be
 * used as keys in unordered containers like std::unordered_map.
 */
struct PairHash {
    /**
     * @param T1 The first type of the pair.
     * @param T2 The second type of the pair.
     * @param p The pair to be hashed.
     * @return The hash value for the pair.
     */
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

using namespace std;
