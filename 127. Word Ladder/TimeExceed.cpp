class Solution {
public:
	int ladderLength(string src, string dst, vector<string>& dict) {
		int dictLen = dict.size(), len = src.size();
		if (dictLen == 0) return 0;

		queue<stack<string>> q;
		stack<string> s;
		s.push(src);
		q.push(s);

		return bfs(q, src, dst, dict);
	}

	int bfs(queue<stack<string>> q, string src, string dst, vector<string> dict) {
		set<string> visited;
		visited.insert(src);

		while (!q.empty()) {
			stack<string> curPath = q.front();
			q.pop();

			string lastWord = curPath.top();
			int len = lastWord.size();

			for (int i = 0; i < len; ++i) {
				// replace s[i] with char from 'a' to 'z'
				for (char j = 'a'; j <= 'z'; ++j) {
					// assign s[i] = j
					string tmp = lastWord;
					tmp[i] = j;
					// skip the same word and visited word
					if (j == lastWord[i] || visited.find(tmp) != visited.end())
						continue;
					
					if (find(dict.begin(), dict.end(), tmp) != dict.end()) {
						// find dst word, return
						if (tmp == dst) {
							return curPath.size() + 1;
						}
						else {
							// else insert it into path
							stack<string> tmpPath = stack<string>(curPath);
							tmpPath.push(tmp);
							q.push(tmpPath);

							visited.insert(tmp);
						}
					}
				}
			}
		}
		// not found
		return 0;
	}
};