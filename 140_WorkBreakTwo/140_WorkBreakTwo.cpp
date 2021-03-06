// 140_WorkBreakTwo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
		return wordBreak(s, dict);
	}
private:
	// >> append({"cats and", "cat sand"}, "dog");
	// {"cats and dog", "cat sand dog"}
	vector<string> append(const vector<string>& prefixes, const string& word) {
		vector<string> results;
		for (const auto& prefix : prefixes)
			results.push_back(prefix + " " + word);
		return results;
	}

	const vector<string>& wordBreak(string s, unordered_set<string>& dict) {
		// Already in memory, return directly
		if (mem_.count(s)) return mem_[s];

		// Answer for s
		vector<string> ans;

		// s in dict, add it to the answer array
		if (dict.count(s))
			ans.push_back(s);

		for (int j = 1; j < s.length(); ++j) {
			// Check whether right part is a word
			const string& right = s.substr(j);
			if (!dict.count(right)) continue;

			// Get the ans for left part
			const string& left = s.substr(0, j);
			const vector<string> left_ans =
				append(wordBreak(left, dict), right);

			// Notice, can not use mem_ here,
			// since we haven't got the ans for s yet.
			ans.insert(ans.end(), left_ans.begin(), left_ans.end());
		}

		// memorize and return
		mem_[s].swap(ans);
		return mem_[s];
	}
private:
	unordered_map<string, vector<string>> mem_;
};

int main()
{
	Solution* solution = new Solution();
	vector<string> vec{ "cat","cats","and","sand","dog" };
	vector<string> result = solution->wordBreak("catsanddog", vec);
	for (vector<string>::iterator it = result.begin(); it < result.end(); it++)
	{
		cout << *it << " " << endl;
	}
	/*for (const auto& s : result)
	{
		cout << s << " " << endl;
	}*/
}
