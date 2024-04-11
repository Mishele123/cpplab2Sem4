
#include <vector>


template <typename Key, typename Val>
class HashTable
{
	struct Pair
	{
		Key _key;
		Val _value;
	};

	std::vector<Pair> _data;
public:
	HashTable(size_t size);
	HashTable(size_t count, size_t size);
	HashTable(const HashTable& other);
	HashTable& operator=(const HashTable& other);
	void print() const;
	void insert(Key key, Val value);
	bool contains(Val value) const;
	T* search(Key key);
	bool erase(Key key);
	int count(Key key) const;
};
