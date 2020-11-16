/*
648. Unique Word Abbreviation
An abbreviation of a word follows the form . Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example
Given dictionary = [ "deer", "door", "cake", "card" ]
isUnique("dear") // return false
isUnique("cart") // return true
isUnique("cane") // return false
isUnique("make") // return true


Author: Yuan Li
Date: 10/8/2018 
Difficulty: Medium
*/

class ValidWordAbbr {
  public:
    /*
    * @param dictionary: a list of words
    */
    ValidWordAbbr(vector<string> dictionary) {
        // do intialization if necessary
        for (const string &d : dictionary) {
            ++dict_[d];
            ++abbr_dict_[getAbbr(d)];
        }
    }

    /*
     * @param word: a string
     * @return: true if its abbreviation is unique or false
     */
    bool isUnique(const string &word) {
        // write your code here
        return dict_[word] == abbr_dict_[getAbbr(word)];
    }
    
  private:
    unordered_map<string, int> dict_;
    unordered_map<string, int> abbr_dict_;
    
  private:
    string getAbbr(const string &s) {
        int abbr_len = s.length() - 2;
        if (abbr_len < 1) {
            return s;
        }
        return s[0] + to_string(abbr_len) + s.back();
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */
 
