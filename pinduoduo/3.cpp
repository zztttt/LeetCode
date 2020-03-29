int trap(vector<vector<int>>& v) {
	int M = v.size(), N = v[0].size();
	vector<vector<int>> water(1, vector<int>(N, 0));
	water.push_back(vector<int>(N, INT_MAX));
	water[1][0] = 0; water[1][N - 1] = 0;
	for (int i = 2; i < M - 1; ++i) {
		water.push_back(water[1]);
	}
	water.push_back(water[0]);
	bool flowing = true;
	while (flowing) {
		flowing = false;
		for (int i = 1; i < M - 1; ++i) {
			for (int j = 1; j < N - 1; ++j) {
				int height = min(max(water[i - 1][j], v[i - 1][j]), max(water[i][j - 1], v[i][j - 1]));
				if (water[i][j] > height) {
					if (!flowing)
						flowing = true;
					water[i][j] = height;
				}
			}
		}
		if (!flowing)
			break;
		flowing = false;
		for (int i = M - 2; i > 0; --i) {
			for (int j = N - 2; j > 0; --j) {
				int height = min(max(water[i + 1][j], v[i + 1][j]), max(water[i][j + 1], v[i][j + 1]));
				if (water[i][j] > height) {
					if (!flowing)
						flowing = true;
					water[i][j] = height;
				}
			}
		}
	}
	int ret = 0;
	for (int i = 1; i < M - 1; ++i) {
		for (int j = 1; j < N - 1; ++j) {
			if (water[i][j] > v[i][j])
				ret = ret + water[i][j] - v[i][j];
		}
	}
	return ret;
}