#include "forward_list.h"
#include "list.h"
#include "stack.h"
#include <iostream>

int main() {
	SequenceContainers::Stack<int> s;
	std::cout << "push 0:4 ";
	for(int i = 0; i < 5; i++) {
		s.push(i);
		std::cout << s.top() << " ";
	}
	std::cout << "\n";

	std::cout << "s.size() " << s.size() << "\n";
	std::cout << "s.empty() " << s.empty() << "\n";
	
	std::cout << "pop 5times ";
	for(int i = 0; i < 5; i++)
		std::cout << s.pop() << " ";
	std::cout << "\n";
//list test
	SequenceContainers::List<int> l = {1, 2, 3};
	for (auto i : l)
		std::cout << i << " ";
	std::cout << "\n";

	std::cout << "push_back(4) ";
	l.push_back(4);
	for (auto i : l)
		std::cout << i << " ";
	std::cout << "\n";

	std::cout << "pop_back " << l.pop_back() << "\n";
	std::cout << " l after pop_back ";
	for (auto i : l)
		std::cout << i << " ";
	std::cout << "\n";

	std::cout << "l.back " << l.back() << "\n";
	std::cout << "l.size " << l.size() << "\n";
	
	std::cout << "l.rbegin() : l.rend() ";
	for (auto i = l.rbegin(); i != l.rend(); i++)
		std::cout << *i << " ";
	std::cout << "\n";

	l.reverse();
	std::cout << "l.reverse() ";
	for (auto i : l)
		std::cout << i << " ";
	std::cout << "\n";
//fl tes
	//SequenceContainers::ForwardList<int> fl0 {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	/*while(1) {
		fl0.insert(fl0.begin(), 10);
		fl0.erase(++fl0.begin());
		

		for (auto i : fl0)
			std::cout << i << " ";
		std::cout << "\n";	
	}*/

	auto il = {10, 20, 30, 40, 50, 60, 70, 80, 90, 0};
	//SequenceContainers::List<int> fl(il);//ForwardList
	SequenceContainers::List<int> fl{0, 90, 80, 70, 60, 50, 40, 30, 20, 10};
	fl.reverse();//test
	std::cout << "fl: ";
	for (auto i : fl)
		std::cout << i << " ";
	std::cout << "\n";

	std::cout << "il: ";
	for (auto i : il)
		std::cout << i << " ";
	std::cout << "\n";

	std::cout << "pop: " << fl.pop_front() << "\n";
	std::cout << "after pop: ";
	for (auto i : fl)
		std::cout << i << " ";
	std::cout << "\n";

	fl.push_front(10);
	std::cout << "after push(10): ";
	for (auto i : fl)
		std::cout << i << " ";
	std::cout << "\n";

	auto fl_begin_pp = ++fl.begin();
	std::cout << "++fl.begin(): " << *fl_begin_pp << "\n";

	fl.erase(fl_begin_pp);
	std::cout << "after fl.erase(fl_begin_pp): ";
	for (auto i : fl)
		std::cout << i << " ";
	std::cout << "\n";


	for (; *fl_begin_pp != 70; fl_begin_pp++) {}
	std::cout << "*fl_begin_pp after <<for (; *fl_begin_pp != 70; fl_begin++) {}>>: " << *fl_begin_pp << "\n";


	fl.erase(fl_begin_pp);
	std::cout << "after fl.erase(fl_begin_pp): ";
        for (auto i : fl)
        	std::cout << i << " ";
        std::cout << "\n";

	fl.insert(++fl.begin(), 35);
	std::cout << "after fl.insert(++fl.begin(), 35): ";
	for (auto i : fl)
		std::cout << i << " ";
	std::cout << "\n";

	fl.clear();
	std::cout << "fl.empty(): " << std::boolalpha << fl.empty() << "\n";
	
	fl = {1, 2, 3};

	std::cout << "fl = {1, 2, 3}: ";
	for (auto i : fl) 
		std::cout << i << " ";
	std::cout << "\n";


	SequenceContainers::List<int> fl2 = fl;
	std::cout << "fl2 = fl: ";
	for (auto i : fl2)
		std::cout << i << " ";
	std::cout << "\n";

	fl.clear();
	std::cout << "fl.clear(), fl2: ";
	for (auto i : fl2)
		std::cout << i << " ";
	std::cout << "\n";
	
	fl = {1, 2, 3};
	fl.reverse();
	std::cout << "fl.front() on reversed 1,2,3:" << fl.front() << "\n";

	fl.push_front(99);
	std::cout << "fl.front() after fl.push_front(99): " << fl.front() << "\n";

	//fl.erase(fl.end());
	//std::cout << "fl.erase(fl.end()): " << fl.front() << "\n";

	//fl.insert(fl.end(), 101);
	//std::cout << "fl.insert(fl.end(), 101): " << *++fl.begin() << "\n";
}
