void func(vector<int>& v) {
	int len = v.size();
	for (int i = 0; i < len; ++i) {
		int low = i - 1, high = i + 1;
		int ret = 0, cur = v[i];
		while (low >= 0) {
			if (v[low] <= cur)
				--low;
			else {
				break;
			}
		}
		ret += i - low - 1;
		while (high <= len - 1) {
			if (v[high] <= cur) {
				++high;
			}
			else {
				break;
			}
		}
		ret += high - i - 1;
		cout << ret << " ";
	}
	cout << endl;
}
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; ++i) {
		int n; cin >> n;
		vector<int> v(n, 0);
		int tmp;
		for (int j = 0; j < n; ++j) {
			cin >> tmp; v[j] = tmp;
		}
		func(v);
	}
	return 0;
}