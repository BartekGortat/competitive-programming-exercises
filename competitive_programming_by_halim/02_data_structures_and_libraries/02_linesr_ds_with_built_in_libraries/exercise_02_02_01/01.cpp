// Determine if an unsorted array of n integers contains one of more pairs of duplicate integers.

#include <chrono>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

// Solution 1. Use an axiliary storage containing all the visited values.
// The storage can be based on a hash set, which offers O(1) put/get time complexity.
// The input array needs to be traversed once, and each value needs to be checked for presence
// in the storage. After each failed get, the values goes to the storage.
// Time complexity: O(n)
// Space compexity: O(n)
bool contains_duplicate_1(const vector<int> &values)
{
    unordered_set<int> past_values;
    for (auto &value : values)
    {
        if (past_values.find(value) == past_values.end())
            past_values.insert(value);
        else
            return true;
    }
    return false;
}

// Solution 2. Sort the array and while traversing compare with the previous value.
// Time compexity: O(n * log(n))
// Space complexity: O(1)
bool contains_duplicate_2(const vector<int> &values)
{
    sort(values.begin(), values.end());
    int previous_value;
    auto iter = values.begin();
    const auto end = values.end();
    if (iter != end)
    {
        previous_value = *iter;
        ++iter;
        while (iter != end)
        {
            const auto current_value = *iter;
            if (current_value == previous_value)
                return true;
            previous_value = current_value;
            ++iter;
        }
    }
    return false;
}

int main()
{
    vector<int> values_1 = { 5, -3, 9, 2, 1, 8, 7, 4, 15, -13, 19, 12, 11, 18, 17, 14, 25, -23, 29, 22, 21, 28, 27, 24, 35, -33, 39, 32, 31, 38, 37, 34 };
    vector<int> values_2 = { 5, -3, 9, 2, 1, 8, 7, 4, 15, -13, 19, 12, 11, 18, 17, 14, 25, -23, 29, 22, 21, 28, 27, 24, 35, -3, 39, 32, 31, 38, 37, 34 };

    steady_clock::time_point before, after;
    bool result;
    
    before = steady_clock::now();
    result = contains_duplicate_1(values_1);
    after = steady_clock::now();
    cout << "Solution 1, values 1. Result: " << result << endl;
    cout << "execution time in microseconds: " << duration_cast<microseconds>(after - before).count() << endl;

    before = steady_clock::now();
    result = contains_duplicate_1(values_2);
    after = steady_clock::now();
    cout << "Solution 1, values 2. Result: " << result << endl;
    cout << "execution time in microseconds: " << duration_cast<microseconds>(after - before).count() << endl;

    before = steady_clock::now();
    result = contains_duplicate_2(values_1);
    after = steady_clock::now();
    cout << "Solution 2, values 1. Result: " << result << endl;
    cout << "execution time in microseconds: " << duration_cast<microseconds>(after - before).count() << endl;

    before = steady_clock::now();
    result = contains_duplicate_2(values_2);
    after = steady_clock::now();
    cout << "Solution 2, values 2. Result: " << result << endl;
    cout << "execution time in microseconds: " << duration_cast<microseconds>(after - before).count() << endl;

    return 0;
}