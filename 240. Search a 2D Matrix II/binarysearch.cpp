class Solution {
public:
	bool ret = false;
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return false;
		int row = matrix.size(), col = matrix[0].size();
		int rlow = 0, rhigh = row - 1, clow = 0, chigh = col - 1;

		//ret = ret || binarySearch(matrix, 0, row - 1, 0, col - 1, int target);
		binarySearch(matrix, 0, row - 1, 0, col - 1, target);
		return ret;
	}
	void binarySearch(vector<vector<int>>& matrix, int rlow, int rhigh, int clow, int chigh, int target) {
		if (rlow < 0 || rhigh > matrix.size() - 1 || clow < 0 || chigh > matrix[0].size() - 1)
			return;
		if (rlow > rhigh || clow > chigh)
			return;

		int rmid = rlow + (rhigh - rlow) / 2, cmid = clow + (chigh - clow) / 2;
		int mid = matrix[rmid][cmid];
		if (mid == target)
			ret = ret || true;
		else if (mid > target) {
			for (int i = rlow; i <= rmid; ++i) {
				if (matrix[i][cmid] == target) {
					ret = ret || true;
					return;
				}
					
			}
			for (int i = clow; i <= cmid; ++i) {
				if (matrix[rmid][i] == target) {
					ret = ret || true;
					return;
				}
			}
			//	1 1
			//	1 0
            if(!ret){
                binarySearch(matrix, rlow, rmid - 1, clow, cmid - 1, target);
                binarySearch(matrix, rlow, rmid - 1, cmid + 1, chigh, target);
                binarySearch(matrix, rmid + 1, rhigh, clow, cmid - 1, target);
            }
		}
		else if (mid < target) {
			// loop edge col
			for (int i = rmid; i <= rhigh; ++i) {
				if (matrix[i][cmid] == target) {
					ret = ret || true;
					return;
				}
			}
			for (int i = cmid; i <= chigh; ++i) {
				if (matrix[rmid][i] == target) {
					ret = ret || true;
					return;
				}
			}
			// 0 1
			// 1 1
            if(!ret){
                binarySearch(matrix, rmid + 1, rhigh, cmid + 1, chigh, target);
                binarySearch(matrix, rmid + 1, rhigh, clow, cmid - 1, target);
                binarySearch(matrix, rlow, rmid - 1, cmid + 1, chigh, target);
            }
		}
	}
};