#include<iostream>
#include<unordered_set>

class Recycler {
	Recycler* _next;
	std::unordered_set<std::string> _recyclable;
protected:
	Recycler(const std::initializer_list<std::string>& il) : _recyclable(il) {}
public:
	virtual std::string recycle(const std::string& trash) = 0;
	virtual Recycler* set_next(Recycler* next) final {
		_next = next;
		return next;
	}

	virtual bool can_recycle(const std::string& trash) final {
		return _recyclable.count(trash) > 0;
	}

	virtual std::string try_recycle(const std::string& trash) final {
		if(can_recycle(trash))
			return  recycle(trash);
		if(_next)
			return _next->try_recycle(trash);
		return trash + " is not recyclable\n";
	}
};

class PaperRecycler : public Recycler {
public:
	PaperRecycler() : Recycler{"paper", "cardboard"} {}
	std::string recycle(const std::string& trash) override {
		return trash + " is recyclable as paper\n";
	}
};

class MetalRecycler : public Recycler {
public:
	MetalRecycler() : Recycler{"aluminum", "steel"} {}
	std::string recycle(const std::string& trash) override {
		return trash + " is recyclable as metal\n";
	}
};

class GlassRecycler : public Recycler {
public:
	GlassRecycler() : Recycler{"glass bottle", "jar"} {}
	std::string recycle(const std::string& trash) override {
		return trash + " is recyclable as glass\n";
	}
};

class PlasticRecycler : public Recycler {
public:
	PlasticRecycler() : Recycler{"PET", "HDPE"} {}
	std::string recycle(const std::string& trash) override {
		return trash + " is recyclable as plastic\n";
	}
};

int main() {
	Recycler* recycler = new PaperRecycler;
	recycler->
		set_next(new MetalRecycler)->
		set_next(new GlassRecycler)->
		set_next(new PlasticRecycler);

	for(auto i : {"rubbish", "jar", "cloth", "paper"})
		std::cout << recycler->try_recycle(i);
}
