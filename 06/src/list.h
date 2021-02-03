#include "sequence_containers.h"


using SequenceContainers::List;

template<class T>
class SequenceContainers::List : public SequenceContainers::ForwardList<T> {
public:
	class Iterator;
private:
	T pop(bool side);
	Iterator begin_or_end(bool side) const;
	T& front_or_back(bool side);
	void push(const T& val, bool side);
	bool _reversed = false;
	Iterator* _front = NULL;
	Iterator* _back = NULL;
	template<class InputIterator>
	void assign(InputIterator first, InputIterator last);
public:
	List() : ForwardList<T>::ForwardList() {}
	List(std::initializer_list<T> il) : ForwardList<T>::ForwardList() {assign(il.begin(), il.end());}
	List(const List& other) : ForwardList<T>::ForwardList() {assign(other.begin(), other.end());}
	bool empty() const {return _front == NULL;}
	List& operator=(const List& other) {assign(other.begin(), other.end()); return *this;}
	Iterator rbegin() const {return begin_or_end(!_reversed);}
	static Iterator end() {return Iterator();}
	static Iterator rend() {return end();}
	Iterator begin() const {return begin_or_end(_reversed);}
	void reverse() {_reversed ^= 1;}
	size_t size();
        T& back() {return front_or_back(_reversed);}
	T& front() {return front_or_back(!_reversed);}
	void push_front(const T& val) {push(val, !_reversed);}
	T pop_front() {return pop(!_reversed);}
	void push_back(const T& val) {push(val, _reversed);}
	T pop_back() {return pop(_reversed);}
	Iterator erase(const Iterator position);
	Iterator insert(const Iterator position, const T& val);
};

template<class T>
class List<T>::Iterator : public ForwardList<T>::Iterator {
	List<T>::Iterator& next_or_prev(bool side);
	bool reversed = false;
	List<T>::Iterator* prev = NULL;
	List<T>::Iterator* next = NULL;
	void insert_after(const T& val) override {next = new Iterator(val, next, this, false);}//reversed = false!!!!!!!!!!!!!!
public:
	Iterator() {}
	Iterator(const Iterator& other) : ForwardList<T>::Iterator::Iterator(other), reversed(other.reversed) {operator=(other);}
	Iterator(const T& data, Iterator* next, Iterator* prev, bool reversed) : ForwardList<T>::Iterator::Iterator(data, next), reversed(reversed), prev(prev), next(next) {}
	Iterator operator--(int) {Iterator tmp = *this; operator--(); return tmp;}
       	Iterator& operator--() {return next_or_prev(reversed);}
	Iterator& operator=(const Iterator& other) {ForwardList<T>::Iterator::operator=(other); prev = other.prev; next = other.next; reversed = other.reversed; return *this;}
	Iterator& operator++ () {return next_or_prev(!reversed);}
	Iterator operator++ (int) {Iterator tmp = *this; operator++(); return tmp;}
		
	bool operator== (const Iterator& other) {return ForwardList<T>::Iterator::operator==(other) && prev == other.prev;}
	friend class List<T>;
};

template<class T> template<class InputIterator>
void List<T>::assign(InputIterator first, InputIterator last) {
	if(!empty()) ForwardList<T>::clear();
	_reversed = false;
	_front = new List<T>::Iterator(*first++, NULL, NULL, false);
	_back = _front;
	for(; first != last; first++, _back = _back->next)
		_back->insert_after(*first);	
}

template<class T>
List<T>::Iterator& List<T>::Iterator::next_or_prev(bool side) {
	auto t = side ? next : prev;
	bool tmp = reversed;
	*this = t ? *t : end();
	reversed = tmp;
	return *this;
}

template<class T>
size_t List<T>::size() {
	size_t ret = 0;
	if (!empty()) {
		auto i = _front;
		auto j = _back;
		for(; i != j && j->next != i; i = i->next, j = j->prev)
			ret += 2;
		ret += i == j;
	}
	return ret;
}

template<class T>
List<T>::Iterator List<T>::begin_or_end(bool side) const {
	if(empty()) return end();
	List<T>::Iterator t;
	t = *(side ? _back : _front);
	t.reversed = side;
	return t;
}

template<class T>
T& List<T>::front_or_back(bool side) {
	if(empty()) throw(std::out_of_range("element access on empty List"));
	return **(side ? _front : _back);
}

template<class T>
void List<T>::push(const T& val, bool side) {
	if(side) {
		_front = new List<T>::Iterator(val, _front, NULL, false);
		_front->next->prev = _front;
	} else {
		_back = new List<T>::Iterator(val, NULL, _back, false);
		_back->prev->next = _back;
	}
}

template<class T>
T List<T>::pop(bool side) {
	List<T>::Iterator* tmp;
	if(side) {
		tmp = _front;
		_front = _front->next;
		_front->prev = NULL;
	} else {
		tmp = _back;
		_back = _back->prev;
		_back->next = NULL;
	}
	T val = **tmp;
	delete tmp;
	return val;
}

template<class T>
typename List<T>::Iterator List<T>::erase(const List<T>::Iterator position) {
	if(empty())
		throw(std::out_of_range("erase on empty List"));
	List<T>::Iterator* it = NULL;
	for (auto i = _front; i != NULL; i = i->next)
		if (*i == position) it = i;
	if(!it) throw(std::out_of_range("bad iterator to erase"));	
	if (position.prev) position.prev->next = position.next;
	if (position.next) position.next->prev = position.prev;
	delete it;
	return position;
}

template<class T>
typename List<T>::Iterator List<T>::insert(const List<T>::Iterator position, const T& val) {
	if (position == end()) throw(std::out_of_range("inserting after past the end iterator"));
	List<T>::Iterator* it = NULL;
	for (auto i = _front; i != NULL; i = i->next)
		if (*i == position) it = i;
	if(!it) throw(std::out_of_range("bad iterator to insert"));
	if(_reversed)
		return *(it->prev = new List<T>::Iterator(val, it, it->prev, false));
	else
		return *(it->next = new List<T>::Iterator(val, it->next, it, false));
}
