#pragma once
template<typename Key, typename Val>
class Pair
{
private:
	Key key;
	Val val;
public:
	Pair()
	{
	}
	Pair(Key key, Val val)
	{
		this->key = key;
		this->val = val;
	}
	const Key & getKey() const
	{
		return key;
	}
	const Val & getValue() const
	{
		return val;
	}
};