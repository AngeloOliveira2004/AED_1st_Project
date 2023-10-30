//
// Created by jose-costa on 10/11/23.
//
#pragma once

//common c++ libraries
#include <fstream>
#include "algorithm"
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
#include "map"
#include "set"
#include <list>
#include <queue>
#include <utility>
#include <deque>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "UC.h"
#include "Student.h"
#include "Class.h"
#include "Date.h"

struct PairHash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

using namespace std;
