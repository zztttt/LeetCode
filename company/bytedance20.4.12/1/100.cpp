string func(vector<long>& a, vector<long>& b) {
	int len = a.size();//long k = 0;
	for (int i = 0; i < len; ++i) {
		a[i] -= b[i];
	}
	long k = 1;
	int start = 0;
	for (; start < len; ++start) {
		if (a[start] != 0) {
			k = a[start];
			break;
		}
	}
	if (k > 0) return "NO";
	int end = start;
	for (int i = start + 1; i < len; ++i) {
		if (a[i] != k) {
			end = i;
			break;
		}
	}
	for (int i = end; i < len; ++i) {
		if (a[i] != 0)
			return "NO";
	}
	return "YES";
}
int main() {
	int t; cin >> t;
	//vector<string> ret;
	for (int i = 0; i < t; ++i) {
		int n; cin >> n;
		vector<long> a(n, 0), b(n, 0);
		for (int j = 0; j < n; ++j) {
			long tmp; cin >> tmp;
			a[j] = tmp;
		}
		for (int j = 0; j < n; ++j) {
			long tmp; cin >> tmp;
			b[j] = tmp;
		}
		string res = func(a, b);
		cout << res << endl;
	}
	return 0;
}