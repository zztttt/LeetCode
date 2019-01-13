#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;

//naive implemention
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> output;
		for (int i = 0; i < nums.size() - 1; i++) {
			int a = nums[i];
			for (int j = i + 1; j < nums.size(); j++) {
				int b = nums[j];
				if (a + b == target) {
					output.push_back(i);
					output.push_back(j);
					break;
				}
			}
		}
		return output;
	}
};

/*
 Approach 1: Brute Force
 The brute force approach is simple. Loop through each element xx and find if there is another value that equals to target - x.
 Time complexity : O(n^2)
 Space complexity : O(1)
 */
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int vsize = nums.size();
		vector<int> res;
		for (int i = 0; i < vsize; i++) {
			int vsrc = nums[i];
			vector<int> out = vector<int>(1, i);
			for (int j = i + 1; j < vsize; j++) {
				if (nums[j] == target - vsrc) {
					out.push_back(j);
					res = out;
					break;
				}
			}
		}
		return res;
	}
};

/*
Approach 2: Two-pass Hash Table
NOTICE: DO NOT USE ITERATOR! leetcode uses serious empty pointer detection, and iterator can't be compared to nullptr...
To improve our run time complexity, we need a more efficient way to check if the complement exists in the array. 
If the complement exists, we need to look up its index.
What is the best way to maintain a mapping of each element in the array to its index? A hash table.
Time complexity : O(n)
Space complexity : O(n)
*/
class Solution2 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int vsize = nums.size();
		vector<int> res;
		//add each element's value and its index to the table.
		unordered_map<int, int> m;
		for (int i = 0; i < vsize; i++) {
			//map[value] = pos
			m[nums[i]] = i;
		}
		//check if each element's complement (target - nums[i]) exists in the table
		//map[key] = value, map.find(key)...

		/*unordered_map<int, int>::iterator it;
		  init the first iterator
		  unordered_map<int, int>::iterator this_it = m.find(nums[0]);//do not use m.begin() because leetcode is too SHABI
		  unordered_map<int, int>::iterator this_it = m.find(nums[0]);
		*/
		for (int i = 0; i < vsize; i++) {
			int component = target - nums[i];
			/*if ((it = m.find(component)) != m.end() && it != this_it) {
				res.push_back(i);
				res.push_back(it->second);
				break;
			}*/
			if (m.find(component) != m.end()) {
				int find_pos = m[component];
				if (find_pos != i) {
					res.push_back(i);
					res.push_back(find_pos);
					break;
				}
			}
			//this_it++;
		}
		return res;
	}
};
int main() {
	vector<int> nums = { 3, 2, 4 };
	int target = 6;//dst num

	vector<int> out = Solution2().twoSum(nums, target);

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << ",";
	}
	return 0;
}