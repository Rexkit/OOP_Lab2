#include <iostream>
#include "StatisticMultiset.h"

int main() {
    StatisticMultiset<int> test;
    string fileName = "test.ini";
    StatisticMultiset<int> test1;
    test1.AddNum(7);
    test1.AddNum(8);
    test1.AddNum(9);
    test.AddNums(test1);
    /*test.AddNumsFromFile(fileName.c_str());
    test.AddNum(7);
    test.AddNum(8);
    test.AddNum(9);*/
    cout << test.GetCountUnder(9) << "\n";
    cout << test.GetCountUnder(9) << "\n";
    cout << test.GetCountUnder(8) << "\n";
    cout << test.GetCountAbove(7) << "\n";
    return 0;
}