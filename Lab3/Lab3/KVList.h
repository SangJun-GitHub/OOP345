/**********************************
| Subject        : Workshop 3     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.06.06     |
**********************************/
#include<utility>
using namespace std;

template <typename K, typename V, int N>
class KVList
{
	pair <K, V> key_value[N];
	size_t m_size;

public:
	KVList() : m_size(0)
	{
		for (int i = 0; i < N; i++)
		{
			key_value[i].first = { 0 };
			key_value[i].second = { 0 };
		}
	}

	size_t size() const
	{
		return m_size;
	}

	const K& key(int i) const
	{
		i = (i < N) ? i : 0;
		return key_value[i].first;
	}

	const V& value(int i) const
	{
		i = (i < N) ? i : 0;
		return key_value[i].second;
	}

	KVList& add(const K& k, const V& v)
	{
		if (size() < N)
		{
			key_value[size()] = make_pair(k, v);
			m_size++;
		}
		return *this;
	}

	int find(const K& k) const
	{
		int i = 0;
		for (int j = 0; j < N; j++)
		{
			if (key_value[j].first == k)
			{
				i = j;
			}
		}
		return i;
	}

	KVList& replace(int i, const K& k, const V& v)
	{
		if (i < N)
		{
			key_value[i].first = k;
			key_value[i].second = v;
		}
		return *this;
	}
};