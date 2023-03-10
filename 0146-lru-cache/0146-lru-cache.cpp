class LRUCache
{
public:
  int size;
  list<int> lru;
  unordered_map<int, list<int>::iterator> mp;
  unordered_map<int, int> kv;

  LRUCache(int capacity) : size(capacity) {}
  int get(int key)
  {
    if (kv.count(key) == 0)
      return -1;
    updateLRU(key);
    return kv[key];
  }
  void put(int key, int value)
  {
    if (kv.size() == size && kv.count(key) == 0)
      evict();
    updateLRU(key);
    kv[key] = value;
  }
  void updateLRU(int key)
  {
    if (kv.count(key))
      lru.erase(mp[key]);
    lru.push_front(key);
    mp[key] = lru.begin();
  }
  void evict()
  {
    mp.erase(lru.back());
    kv.erase(lru.back());
    lru.pop_back();
  }
};