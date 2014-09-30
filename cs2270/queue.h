// class provided: queue
// libraries used
// list
// iostream
// namespace std

#ifndef QUEUE_H_
#define QUEUE_H_

template<class Item>
class queue
{
public:
	queue();
	~queue();
	queue(const queue&);

	void push(const Item& item);
	void pop();

	Item front() const;
	Item back() const;
	size_t size() const;
	bool empty() const;

	queue& operator=(const queue& source);

	template<class Thing2>
	friend ostream& operator <<(ostream& stream, 
				       const queue<Thing2>& target);
private:
	list<Item> data; //holy STL batman
};

#endif // QUEUE_H_

template<class Item>
queue<Item>::queue(){
	}

template<class Item>
queue<Item>::~queue()
{
	if( !data.empty())
	{
		data.clear();
	}
}

template<class Item>
queue<Item>::queue(const queue<Item>& item)
{
	data = item.data;
}

template<class Item>
void queue<Item>::push(const Item& item)
{
	data.push_front(item);
}

template<class Item>
void queue<Item>::pop()
{
	data.pop_back();
}

template<class Item>
Item queue<Item>::front() const
{
	return data.back();
}

template<class Item>
Item queue<Item>::back() const
{
	return data.front();
}

template<class Item>
size_t queue<Item>::size() const
{
	return data.size();
}

template<class Item>
bool queue<Item>::empty() const
{
	return data.empty();
}

template<class Item>	
queue<Item>& queue<Item>::operator=(const queue<Item>& source)
{
	if (this == &source) return *this;
	data = source.data;
	return *this;
}

template<class value_type>
ostream& operator <<(ostream &stream, const queue<value_type>& target) 
{
  typename list<value_type>::const_iterator i;
  stream << "[ ";
  for(i = target.data.begin(); 
      i != target.data.end(); ++i)
    {
      stream << *i << " ";
    }
  stream << "]";
  return stream;
}
