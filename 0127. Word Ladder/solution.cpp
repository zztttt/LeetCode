class Solution {
public:
	int ladderLength(string src, string dst, vector<string>& dict) {
		int dictLen = dict.size(), len = src.size();
		if (dictLen == 0) return 0;
		return bfs(src, dst, dict);
	}

	int bfs(string src, string dst, vector<string> dict) {
		int level = 1;
		vector<string> curLevel(1, src);
		while (!curLevel.empty()) {
			vector<string> nextLevel;
			while (!curLevel.empty()) {
				// pop first word
				string latestWord = curLevel.front();
				curLevel.erase(curLevel.begin());
				int len = latestWord.size();

				// compare lastedWord with dict's each word， delete every hasOneDiff() word
				vector<string>::iterator it = dict.begin();
				while(it != dict.end()) {
					if (hasOneCharDiff(*it, latestWord)) {
						// find dst word
						if (*it == dst)
							return level + 1;
						// if not visited, insert it into nextLevel
						else {
							nextLevel.push_back(*it);
							// auto plus with 1
							it = dict.erase(it);
						}
					}
					else {
						it++;
					}
				}
			}
			curLevel.swap(nextLevel);
			//curLevel = nextLevel;
			level++;
		}
		// not found
		return 0;
	}

	bool hasOneCharDiff(string a, string b) {
		int diff = 0, len = a.size();
		for (int i = 0; i < len; ++i) {
			if (a[i] != b[i]) {
				if (diff >= 1)
					return false;
				else
					diff++;
			}
		}
		return diff == 1;
	}
};