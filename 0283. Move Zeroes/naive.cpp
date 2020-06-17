class Solution {
public:
	void moveZeroes(vector<int>& v) {
		if (v.size() == 0)
			return;
		int len = v.size(), last = -1;
		// find first zero pos
		for (int i = 0; i < len; ++i) {
			if (v[i] == 0) {
				last = i;
				break;
			}
		}
        // there are no zeros in array
        if(last == -1)
            return;
		// swap
		for (int i = 0; i < len; ++i) {
			if (v[i] != 0 && i > last) {
				// swap v[i] and v[last]
				int tmp = v[last];
				v[last] = v[i];
				v[i] = tmp;
				// update last
				last++;
			}
		}
	}
};