/*
639. Word Abbreviation
Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.

Begin with the first character and then the number of characters abbreviated, which followed by the last character.
If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
If the abbreviation doesn't make the word shorter, then keep it as original.

Example
Given dict = ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
return ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]

Notice
Both n and the length of each word will not exceed 400.
The length of each word is greater than 1.
The words consist of lowercase English letters only.
The return answers should be in the same order as the original array.


Author: Yuan Li
Date: 9/23/2018 
Difficulty: Hard
*/

class Solution {
  public:
    /**
     * @param dict: an array of n distinct non-empty strings
     * @return: an array of minimal possible abbreviations for every word
     */
    vector<string> wordsAbbreviation(vector<string> &dict) {
        // write your code here
        vector<string> abbrs;
        for (int i = 0; i < dict.size(); ++i) {
            prefix_.push_back(1);
            string abbr = getAbbr(dict[i], prefix_[i]);
            abbrs.push_back(abbr);
            ++word_cnt_[abbr];
        }
        
        while (true) {
            bool unique = true;
            unordered_set<string> dups;
            for (int i = 0; i < abbrs.size(); ++i) {
                if (word_cnt_[abbrs[i]] > 1) {
                    unique = false;
                    dups.insert(abbrs[i]);
                    
                    string abbr = getAbbr(dict[i], ++prefix_[i]);
                    ++word_cnt_[abbr];
                    abbrs[i] = abbr;
                }
            }
            
            if (unique == true) {
                break;
            }
            
            for (auto &dup : dups) {
                word_cnt_.erase(dup);
            }
        }
        
        return abbrs;
    }
    
  private:
    unordered_map<string, int> word_cnt_;
    vector<int> prefix_;
    
  private:
    string getAbbr(string &word, int pref) {
        int abbr_num = word.length() - pref - 1;
        if (abbr_num <= 1) {
            return word;
        }
        return word.substr(0, pref) + to_string(abbr_num) + word.back(); 
    }
};
