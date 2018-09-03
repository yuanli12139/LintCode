/*
1110. Replace Words
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:

Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Notice
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000


Author: Yuan Li
Date: 9/2/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param dict: List[str]
     * @param sentence: a string
     * @return: return a string
     */
    string replaceWords(vector<string> &dict, string &sentence) {
        // write your code here
        for (string &word : dict) {
            roots_.insert(word);
        }
        
        string res = "";
        for (int start = 0, end = 0; end <= sentence.length(); ++end) {
            if (sentence[end] == ' ' || end == sentence.length()) {
                res += replace(sentence, start, end) + ' ';
                start = end + 1;
            }
        }
        
        res.pop_back();
        return res;
    }
    
  private:
    unordered_set<string> roots_;
    
  private:
    string replace(string &sentence, int start, int end) {
        string root;
        for (int i = start; i <= end; ++i) {
            root = sentence.substr(start, i - start);
            if (roots_.count(root)) {
                return root;
            }
        }
        
        return root;
    }
};
