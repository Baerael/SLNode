#include <iostream>
#include <cstddef>

// SinglyLinked
class SLNode {
public:
	SLNode(int key, SLNode * next = NULL)
	  : key_(key), next_(next)
	{}
	int get_key()		const { return key_;  }
	SLNode * get_next() const { return next_; }
	void set_next(SLNode * next) { next_ = next; }

private:
	int key_;
	SLNode * next_;
};

std::ostream & operator<<(std::ostream & cout,
						  const SLNode & node) {
	cout << "<SLNode " << &node
		 << " key: " 		 << node.get_key()
		 << ", next: " 	 << node.get_next()
		 << '>';
	return cout;
}


int get_size(SLNode * p) {
	int size = 0;
	while(p != NULL) {
		p = p->get_next();
		size++;
	}
	return size;
}


void print(SLNode * p) {
	while (p != NULL) {
		std::cout << (*p) << std::endl;
		p = p->get_next();
	}
}


void insert_head(SLNode *& phead, int key) {
	std::cout << "instert *&" << std::endl;
	phead = new SLNode(key, phead);
}


void insert_head(SLNode ** phead, int i) {
	std::cout << "instert **" << std::endl;
	*phead = new SLNode(i, *phead);
}

int main() {
	SLNode * phead = NULL;
	insert_head(phead, 5);
	insert_head(phead, 2);
	insert_head(phead, 7);

	print(phead);
	std::cout << get_size(phead) << std::endl;

	return 0;
}