//
// Created by User on 27.09.2017.
//

#ifndef OOP_LAB2_STATISTICMULTISET_H
#define OOP_LAB2_STATISTICMULTISET_H

#include <iostream>
#include <set>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

template<class T>
class StatisticMultiset {
public:
    StatisticMultiset();

    ~StatisticMultiset();

    void AddNum(T num);

    void AddNum(const std::multiset<T> &numbers);

    void AddNum(const vector<T> &numbers);

    void AddNum(const list<T> &numbers);

    void AddNumsFromFile(const char *filename);

    void AddNums(const StatisticMultiset &a_stat_set);

    T GetMax() const;

    T GetMin() const;

    float GetAvg() const;

    int GetCountUnder(float threshold) const;

    int GetCountAbove(float threshold) const;

private:
    multiset<T> mset;
    mutable T min, max, gcu, gca;
    mutable float avg, lgca = 0, lgcu = 0;
    mutable T fmin = 0, fmax = 0, favg = 0, fgcu = 0, fgca = 0;
};


template <class T>
void StatisticMultiset<T>::AddNum(T num) {
    mset.insert(num);
}

template <class T>
T StatisticMultiset<T>::GetMax() const {
    if (mset.size() > fmax) {
        T tmax = *mset.begin();
        for (auto it : mset)
            if (it > tmax)
                tmax = it;
        max = tmax;
    }
    fmax = mset.size();
    return max;
}

template <class T>
T StatisticMultiset<T>::GetMin() const {
    if (mset.size() > fmin) {
        T tmin = *mset.begin();
        for (auto it : mset)
            if (it < tmin)
                tmin = it;
        min = tmin;
    }
    fmin = mset.size();
    return min;
}

template <class T>
float StatisticMultiset<T>::GetAvg() const {
    float tavg = 0;
    if (mset.size() > favg) {
        for (auto it : mset)
            tavg += it;
        avg = tavg;
    }
    favg = mset.size();
    return avg / mset.size();
}

template <class T>
int StatisticMultiset<T>::GetCountUnder(float threshold) const {
    int count = 0;
    if (lgcu != threshold) {
        for (auto it : mset)
            if (it < threshold)
                count += 1;
        lgcu = threshold;
        gcu = count;
    }
    return gcu;
}

template <class T>
int StatisticMultiset<T>::GetCountAbove(float threshold) const {
    int count = 0;
    if (lgca != threshold) {
        for (auto it : mset)
            if (it > threshold)
                count += 1;
        lgca = threshold;
        gca = count;
    }
    return gca;
}

template <class T>
StatisticMultiset<T>::StatisticMultiset() {

}

template <class T>
StatisticMultiset<T>::~StatisticMultiset() {

}

template <class T>
void StatisticMultiset<T>::AddNumsFromFile(const char *filename) {
    ifstream fin(filename);
    string tempStr;
    while (getline(fin, tempStr))
        AddNum(stoi(tempStr));
}

template <class T>
void StatisticMultiset<T>::AddNum(const std::multiset<T> &numbers) {
    for (auto it : numbers)
        AddNum(it);
}

template <class T>
void StatisticMultiset<T>::AddNum(const vector<T> &numbers) {
    for (auto it : numbers)
        AddNum(it);
}

template <class T>
void StatisticMultiset<T>::AddNum(const list <T> &numbers) {
    for (auto it : numbers)
        AddNum(it);
}

template <class T>
void StatisticMultiset<T>::AddNums(const StatisticMultiset &a_stat_set) {
    for (auto it : a_stat_set.mset)
        AddNum(it);
}



#endif //OOP_LAB2_STATISTICMULTISET_H
