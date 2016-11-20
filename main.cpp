#include <iostream>

using namespace std;

const int ASCII_VALUES = 256;

int findLongestSub(string s) {

    int max = 0;
    int curCount = 0;
    int count[ASCII_VALUES] = {0};
    int last = 0;
    int cur = 0;
    for (int i=0; i<s.length(); i++) {
        if (i+1 < s.length() && s[i] != s[i+1]) {
            if (count[s[i]] == 0) {
                curCount++;
            } else {
                i = count[s[i]]+s.length();
                fill(count,count+ASCII_VALUES,0);
                if (curCount > max) {
                    max = curCount;
                }
                curCount = 0;
                continue;
            }
        } else {
            if (count[s[i]] == 0) {
                curCount++;
            }
        }
        count[s[i]]=i-s.length();
    }
    if (curCount > max) {
        max = curCount;
    }
    return max;

}

int main() {
    string s = "123145";
    int result = findLongestSub(s);
    cout << result;
    return 0;
}