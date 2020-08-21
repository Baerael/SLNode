#include <iostream>
#include <cstddef>

// SinglyLinked
class SLNode {
public:
	SLNode(int key, SLNode * next = NULL)
	  : key_(key), next_(next)
	{}
	int get_key() 		  const { return key_;  }
	SLNode * get_next() const { return next_; }
	void set_next(SLNode * next) { next_ = next; }

private:
	int key_;
	SLNode * next_;
};

std::ostream & operator<<(std::ostream & cout,
						  const SLNode & node)
{
	cout << "<SLNode " << &node
		 << " key: " 		 << node.get_key()
		 << ", next: " 	 << node.get_next()
		 << '>';
		 return cout;
}

void print(SLNode * p) {
	while (p != NULL) {
		std::cout << (*p) << std::endl;
		p = p->get_next();
	}
	/* recursive
	if (p != NULL) {
		std::cout << (*p) << std::endl;
		print(p->get_next());
	}
	*/
}

/*
void insert_head(SLNode * phead, int key) {
	phead = new SLNode(key, phead);
}
*/


void insert_head(SLNode *& phead, int key) {
	std::cout << 'instert *&' << std::endl;
	phead = new SLNode(key, phead);
}


void insert_head(SLNode ** pphead, int i) {
	std::cout << 'instert **' << std::endl;
	*pphead = new SLNode(i, *pphead);
}



int main()
{
	SLNode * n5 = new SLNode(5, NULL);
	SLNode * n4 = new SLNode(4, NULL);
	SLNode * n6 = new SLNode(6, NULL);
	SLNode * n2 = new SLNode(2, NULL);

	n2->set_next(n6);
	n6->set_next(n4);
	n4->set_next(n5);

	SLNode * phead = n2;
	SLNode * q = new SLNode(3, phead);
	phead = q;


	print(phead);

	return 0;
}
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

void insert_tail(SLNode *& r, int i) {
	SLNode * q = new SLNode(i, NULL);
	while (1) {
		if (r->get_next() == NULL) {
			std::cout << "found " << (*r) << std::endl;
			r->set_next(q);
			break;
		}
		r = r->get_next();
	}
}

int main() {
	SLNode * phead = NULL;
	insert_head(phead, 5);
	insert_head(phead, 2);
	insert_head(phead, 7);

	insert_tail(phead, 1234);

	SLNode * q = new SLNode(1337, NULL);
	SLNode * r = phead;
	while (1) {
		if (r->get_next() == NULL) {
			std::cout << "found " << (*phead) << std::endl;
			r->set_next(q);
			break;
		}
		r = r->get_next();
	}
	std::cout << "after break " << (*r) << std::endl;
	print(phead);

	return 0;
}