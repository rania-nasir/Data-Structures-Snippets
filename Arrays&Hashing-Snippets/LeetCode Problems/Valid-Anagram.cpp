//#include <iostream>
//#include <string>
//#include<algorithm>
//#include<unordered_map>
//
//using namespace std;
//
//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        
//        if (s.length() != t.length()) {
//            return false;
//        }
//        
//        //// Method 1
//        ////Sorting method will take time complexity O(nlog(n))
//        //sort(s.begin(), s.end());
//        //sort(t.begin(), t.end());
//
//        //return s == t;
//
//        // Method 2
//        // Unordered map method will take Time Complexity O(n)
//        unordered_map<char, int> charCount;
//
//        for (char ch : s) {
//            charCount[ch]++;
//        }
//
//        for (char ch : t) {
//            if (charCount.find(ch) == charCount.end() || charCount[ch] == 0) {
//                return false; // If the character is not in s or count becomes negative
//            }
//            charCount[ch]--;
//        }
//
//        return true;    
//    }
//};
//
//int main() {
//    Solution solution;
//
//    string s = "anagram";
//    string t = "nagaram";
//
//    if (solution.isAnagram(s, t)) {
//        cout << "The strings are anagrams." << endl;
//    }
//    else {
//        cout << "The strings are not anagrams." << endl;
//    }
//
//    return 0;
//}
