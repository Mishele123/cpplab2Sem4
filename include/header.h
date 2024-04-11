#include <iostream>
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
	HashTable(const HashTable& other);
	HashTable& operator=(const HashTable& other);
	void print() const;
	void insert(Key key, Val value);
	bool contains(Val value) const;
	Val* search(Key key);
	bool erase(Key key);
	int count(Key key) const;
};


size_t HashFunction(int key)
{
	const int w = 32;
	const int l = 8;
	const float A = 0.6;
	float hashedValue = key * A;
	hashedValue = fmod(hashedValue, pow(2, w));

	// hashedValue >>= (w - l);
	hashedValue *= pow(2, -(w - l));

	return size_t(hashedValue);
}
