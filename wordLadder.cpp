#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> s;
        bool ispresent = false;
        for (string word : wordList)
        {
            if (endWord == word)
                ispresent = true;
            s.insert(word);
        }
        if (ispresent == false)
            return 0;

        queue<string> q;
        q.push(beginWord);
        int depth = 0;

        while (!q.empty())
        {
            depth += 1;
            int levelSize = q.size();
            while (levelSize--)
            {
                string curr = q.front();
                q.pop();
                for (int i = 0; i < curr.length(); i++)
                {
                    string temp = curr;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;
                        if (curr == temp)
                            continue;
                        if (temp == endWord)
                            return depth + 1;
                        if (s.find(temp) != s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};