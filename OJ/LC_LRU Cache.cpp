#include<list>
#include<unordered_map>
using namespace std;
class LRUCache{
public:
	struct CacheNode{
		int key;
		int val;
		CacheNode(int k, int v) :key(k), val(v) {}
	};
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (cache_map.find(key) == cache_map.end()){
			return -1;
		}
		cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
		cache_map[key] = cache_list.begin();
		return cache_map[key]->val;
	}

	void set(int key, int value) {
		if (cache_map.find(key) == cache_map.end()){
			if (cache_map.size() == capacity){
				cache_map.erase(cache_list.back().key);
				cache_list.pop_back();
			}
			cache_list.push_front(CacheNode(key, value));
			cache_map[key] = cache_list.begin();
		}
		else{
			cache_map[key]->val = value;
			cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
			cache_map[key] = cache_list.begin();
		}
	}
private:
	int capacity;
	list<CacheNode> cache_list;
	unordered_map<int, list<CacheNode>::iterator> cache_map;
};