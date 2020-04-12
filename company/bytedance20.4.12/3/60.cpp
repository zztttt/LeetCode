int func(int b, const vector<int>& a) {
	int len = a.size();
	if (a[0] > b) return b;
	if (a[len - 1] <= b) return b - a[len - 1];

	int low = 0, high = len - 1;
	int mid = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		int cur = a[mid];
		// a[mid]
		if (cur < b) {
			low = mid + 1;
		}
		else if (cur > b) {
			high = mid - 1;
		}
		else
			return 0;
	}

	if (b >= a[mid])
		return b - a[mid];
	else if (b < a[mid] && mid == 0)
		return b;
	else if (b < a[mid] && mid > 0)
		return b - a[mid - 1];

	/*for(int i = len - 1; i >= 0; --i){
		if(a[i] <= b){
			return b - a[i];
		}
	}*/
}
int main() {
	int n; cin >> n; int m; cin >> m;
	vector<int> a(n, 0), b(n, 0);
	int tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp; a[i] = tmp;
	}
	sort(a.begin(), a.end());
	int ret = 0;
	for (int i = 0; i < m; ++i) {
		cin >> tmp; b[i] = tmp;
		int res = func(b[i], a);
		//cout << "func:" << res << endl;
		ret += res;
	}
	cout << ret << endl;
	return 0;
}