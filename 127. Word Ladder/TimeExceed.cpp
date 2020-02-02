class Solution {
public:
	int ladderLength(string src, string dst, vector<string>& dict) {
		int dictLen = dict.size(), len = src.size();
		if (dictLen == 0) return 0;
		return bfs(src, dst, dict);
	}

	int bfs(string src, string dst, vector<string> dict) {
		set<string> visited;
		visited.insert(src);
		int level = 1;
		vector<string> curLevel(1, src);
		while (!curLevel.empty()) {
			vector<string> nextLevel;
			while (!curLevel.empty()) {
				// pop first word
				string latestWord = curLevel.front();
				curLevel.erase(curLevel.begin());
				int len = latestWord.size();

				for (int i = 0; i < len; ++i) {
					// replace s[i] with char from 'a' to 'z'
					for (char j = 'a'; j < 'z'; ++j) {
						// assign s[i] = j
						string tmp = latestWord;
						tmp[i] = j;
						// skip the same word and visited word
						if (j == latestWord[i] || visited.find(tmp) != visited.end())
							continue;
						if (find(dict.begin(), dict.end(), tmp) != dict.end()) {
							// find dst word, return
							if (tmp == dst) {
								return level + 1;
							}
							else {
								// else insert it into nextLevel
								nextLevel.push_back(tmp);
								visited.insert(tmp);
							}
						}
					}
				}
			}
			// curLevel.swap(nextLevel);
			curLevel = nextLevel;
			level++;
		}
		// not found
		return 0;
	}
};