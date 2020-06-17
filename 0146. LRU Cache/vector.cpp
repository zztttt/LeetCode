class LRUCache {
public:
	class Node {
	public:
		int key;
		int val;
		Node(int k, int v) : key(k), val(v) {}
	};
	int _capacity;
	int _size = 0;
	// key-{time,value,key}
	map<int, Node*> data;
	vector<Node*> v;

	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		if (data.find(key) != data.end()) {
			Node* cur = data[key];
			vector<Node*>::iterator it = find(v.begin(), v.end(), cur);
			// erase and push_back
			v.erase(it);
			v.push_back(cur);

			return cur->val;
		}
		else {
			return -1;
		}
	}

	void put(int key, int value) {
		if (data.find(key) != data.end()) {
			// update old value
			Node* cur = data[key];
			vector<Node*>::iterator it = find(v.begin(), v.end(), cur);
			// erase and update value, then push_back
			v.erase(it);
			cur->val = value;
			v.push_back(cur);
		}
		else {
			// insert new key
			Node* cur = new Node(key, value);
			// cache is full, pop the first Node* from queue and delete map
			if (_size == _capacity) {
				Node* old = v.front();
				//cout << "in key:" << key << ", evict key" << old->key << ", time:" << old->time << endl;
				data.erase(old->key);
				v.erase(v.begin());
				delete old;
			}
			else if (_size < _capacity) {
				// insert directly
				_size++;
			}
			else
				assert(0);
			data[key] = cur;
			v.push_back(cur);
		}
	}
};