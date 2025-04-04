// Given an unsorted array of alphabets cantaining duplicate elements, design an algorithm to find out element with maximum number of occureneces and print it. Time Complexity should be O(n).
#include <bits/stdc++.h>
using namespace std;

void maxOccurrence(string s) {
    if (s.empty()) {
        cout << "No characters found." << endl;
        return;
    }
    unordered_map<char, int> mp;
    for (char i : s) {
        mp[i]++;
    }
    int maxOccurrence = 0;
    char maxOccurrenceElement = s[0]; 
    for (auto i : mp) {
        if (i.second > maxOccurrence) {
            maxOccurrence = i.second;
            maxOccurrenceElement = i.first;
        }
    }
    cout << "Element with maximum occurrence: " << maxOccurrenceElement << endl;
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    maxOccurrence(s);

    return 0;
}