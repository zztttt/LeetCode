class LRUCache {
public:
	class Node {
	public:
		long time;
		int val;
		int key;
		Node(int k, int v, long t) : key(k), val(v), time(t) {}
	};
	class less {
	public:
		bool operator()(Node* a, Node* b) {
			return a->time > b->time;
		}
	};
	int _capacity;
	int _size = 0;
	// key-{time,value,key}
	map<int, Node*> data;
	priority_queue<Node*, vector<Node*>, less> q;

	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		if (data.find(key) != data.end()) {
			Node* cur = data[key];
			cur->time = clock();
			// triger auto sort
			Node* t = q.top();
			q.pop();
			q.push(t);
			return cur->val;
		}
		else {
			return -1;
		}
	}

	void put(int key, int value) {
		if (data.find(key) != data.end()) {
			// update old value
			Node* node = data[key];
			node->val = value;
			node->time = clock();
			// triger auto sort
			Node* t = q.top();
			q.pop();
			q.push(t);
		}
		else {
			// insert new key
			Node* cur = new Node(key, value, clock());
			// cache is full, pop the first Node* from queue and delete map
			if (_size == _capacity) {
				Node* old = q.top();
				//cout << "in key:" << key << ", evict key" << old->key << ", time:" << old->time << endl;
				q.pop();
				data.erase(old->key);
				delete old;
			}
			else if (_size < _capacity) {
				// insert directly
				_size++;
			}
			else
				assert(0);
			data[key] = cur;
			q.push(cur);
		}
	}
};