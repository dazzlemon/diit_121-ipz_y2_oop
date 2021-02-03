#include "sequence_containers.h"
#include <initializer_list>
#include <stdexcept>
#include <optional>

using SequenceContainers::ForwardList;

template<class T>
class ForwardList {
public:
	class Iterator;
protected:
	Iterator* _front = NULL;
private:	
	template<class InputIterator>
	void assign(InputIterator first, InputIterator last);
	std::optional<Iterator*> _find_prev(const Iterator& position);
	
public:
	ForwardList(std::initializer_list<T> il) {assign(il.begin(), il.end());}
	ForwardList(ForwardList& fl) {assign(fl.begin(), fl.end());}
	ForwardList() {}
	~ForwardList() {clear();}
	ForwardList& operator= (const ForwardList& fl);
	ForwardList& operator= (std::initializer_list<T> il);
	virtual Iterator begin() {return _front == NULL ? end() : *_front;}
	static Iterator end() {return Iterator();}
	bool empty() {return begin() == end();}
	T& front();	
	void push_front(const T& val) {_front = new Iterator(val, _front);}
	T pop_front();
	Iterator insert(const Iterator position, const T& val);
	Iterator erase(const Iterator position);
	void clear() {while(!empty()) pop_front();}
};

template<class T>
class ForwardList<T>::Iterator {
protected:
	std::optional<T> data;
	ForwardList<T>::Iterator* next = NULL;
	virtual void insert_after(const T& val) {next = new ForwardList<T>::Iterator(val, next);}
public:
	Iterator() {}
	Iterator(const T& data, Iterator* next);
	Iterator(const Iterator& other);
	virtual ~Iterator() {}	
	Iterator& operator= (const Iterator& other);
	bool operator== (const Iterator& other) {return next == other.next && data == other.data;}
	friend class ForwardList<T>;        
	friend SequenceContainers::Stack<T>;
	T& operator* ();
	Iterator operator++ (int);//postfix
	Iterator& operator++ () {return *this = next == NULL ? end() : *next;}
};                                                                         

template<class T>
T& ForwardList<T>::front() {
	if (empty()) throw(std::out_of_range("front call on empty ForwardList"));
	return **_front;
}

template<class T>
ForwardList<T>& ForwardList<T>::operator= (const ForwardList& fl) {
	assign(fl.begin(), fl.end());
	return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::operator= (std::initializer_list<T> il) {
	assign(il.begin(), il.end());
	return *this;
}

template<class T> template<class InputIterator>
void ForwardList<T>::assign (InputIterator first, InputIterator last) {
	if(!empty()) clear();
	_front = new ForwardList<T>::Iterator(*first++, NULL);	
	for(auto i = _front; first != last; first++, i = i->next)
		i->insert_after(*first);
}

template<class T>
T ForwardList<T>::pop_front() {
	ForwardList<T>::Iterator* tmp = _front;
	_front = _front->next;
	T val = **tmp;
	delete tmp;
	return val;
}

template<class T>
typename ForwardList<T>::Iterator ForwardList<T>::insert(ForwardList<T>::Iterator position, const T& val) {
	if (position == end()) throw(std::out_of_range("inserting after past the end iterator"));
	std::optional<ForwardList<T>::Iterator*> it;
	if (!empty() && position == *_front) it = _front;
	else if (auto prev = _find_prev(position)) it = (*prev)->next;
	if(it) (*it)->next = new ForwardList<T>::Iterator(val, position.next);
	else throw(std::bad_exception("bad iterator to insert after"));
	return *((*it)->next);
}

template<class T>
typename std::optional<typename ForwardList<T>::Iterator*> ForwardList<T>::_find_prev(const ForwardList<T>::Iterator& position) {
	std::optional<ForwardList<T>::Iterator*> prev;
	for(auto i = _front; i && !prev; i = i->next) {
		if (i->next && *(i->next) == position) prev = i;
	}
	return prev;
}

template<class T>
typename ForwardList<T>::Iterator ForwardList<T>::erase(const ForwardList<T>::Iterator position) {
	std::optional<ForwardList<T>::Iterator*> prev = _find_prev(position);
	if (prev) {
		delete (*prev)->next;
		(*prev)->next = position.next;
	}
	return prev ? **prev : begin();
}

template<class T>
ForwardList<T>::Iterator::Iterator(const ForwardList<T>::Iterator& other) {
	if (other.data) data = *(other.data);
	next = other.next;
}

template<class T>
ForwardList<T>::Iterator::Iterator(const T& data, ForwardList<T>::Iterator* next) {
	this->data = data;
	this->next = next;
}

template<class T>
typename ForwardList<T>::Iterator& ForwardList<T>::Iterator::operator= (const ForwardList<T>::Iterator& other) {
	data = other.data;
	next = other.next;
	return *this;
}

template<class T>
T& ForwardList<T>::Iterator::operator* () {
	if (!data) throw(std::out_of_range("dereferencing past the end iterator"));
	return *data;
}

template<class T>
typename ForwardList<T>::Iterator ForwardList<T>::Iterator::operator++ (int) {
	ForwardList<T>::Iterator tmp = *this;
	operator++();
	return tmp;
}
