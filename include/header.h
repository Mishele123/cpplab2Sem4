#include <iostream>
#include <vector>


template <typename Key, typename Val>
class HashTable
{
	struct Pair
	{
		Key _key;
		Val _value;
		enum class Status
		{
			EMPTY, OCCUPIED, DELETED
		} _status;

		Pair() : _status(EMPTY) {}
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


template <typename Key, typename Val>
HashTable<Key, Val>::HashTable(size_t size) : _data(size) {}

template <typename Key, typename Val>
HashTable<Key, Val>::HashTable(const HashTable& other) : _data(other._data) {}


template <typename Key, typename Val>
HashTable<Key, Val>& HashTable<Key, Val>::operator=(const HashTable& other)
{
	if (this != &other)
	{
		_data = other._data;
	}
	return *this;
}

template <typename Key, typename Val>
void HashTable<Key, Val>::print() const
{
	for (const auto& pair : _data)
	{
		if (pair._status == Pair::OCCUPIED)
			std::cout << pair._key << " : " << pair._value << std::endl;
	}
}

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
