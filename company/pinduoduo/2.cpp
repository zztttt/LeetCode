int main() {
	int N; cin >> N;
	vector<long> v(N, 0);
	for (int i = 0; i < N; ++i) {
		long tmp; cin >> tmp;
		v[i] = tmp;
	}
	sort(v.begin(), v.end());

	queue<long> q;
	q.push(v[0]);
	int pos = 1;
	while (pos <= N - 1) {
		long front = q.front();
		long cur = v[pos];
		if (front < cur) {
			q.pop();
		}
		q.push(cur);
		pos++;
	}
	cout << q.size() << endl;
	return 0;
}