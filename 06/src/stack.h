#include "sequence_containers.h"

template<class T>
class SequenceContainers::Stack : private SequenceContainers::ForwardList<T> {
public:
	size_t size() {size_t size = 0; for(auto i = this->_front; i != NULL; i = i->next) size++; return size;}
	using ForwardList<T>::ForwardList;
	T& top() {return ForwardList<T>::front();}
	void push(const T& val) {ForwardList<T>::push_front(val);}
	T pop() {return ForwardList<T>::pop_front();}
	using ForwardList<T>::empty;
};
