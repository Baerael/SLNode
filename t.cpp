#include <iostream>
#include <cstddef>

// SinglyLinked
class SLNode {
public:
    SLNode(int key, SLNode * next = NULL)
      : key_(key), next_(next)
    {}
    int get_key()       const { return key_;  }
    SLNode * get_next() const { return next_; }
    void set_next(SLNode * next) { next_ = next; }

private:
    int key_;
    SLNode * next_;
};

std::ostream & operator<<(std::ostream & cout,
                          const SLNode & node) {
	cout << "<SLNode " << &node
		 << " key: "   << node.get_key()
		 << ", next: " << node.get_next()
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
    //std::cout << "instert *&" << std::endl;
    phead = new SLNode(key, phead);
}


void insert_head(SLNode ** phead, int key) {
    //std::cout << "instert **" << std::endl;
    *phead = new SLNode(key, *phead);
}

void insert_tail(SLNode * phead, int key) {
    SLNode * tail = new SLNode(key, NULL);
    SLNode * r = phead;
    while (1) {
        if (r->get_next() == NULL) {
            r->set_next(tail);
            break;
        }
        r = r->get_next();
    }

}

void delete_head(SLNode ** phead) {
    if ((*phead) != NULL) {
        SLNode * temp = *phead;
        *phead = (*phead)->get_next();
        delete temp;
    }
}

void delete_tail(SLNode ** phead) {
    SLNode * prev;
    SLNode * r = (*phead);

    while (1) {
        if (r->get_next() == NULL) {
            prev->set_next(NULL);
            delete r;
            break;
        }
        prev = r;
        r = r->get_next();
    }
    std::cout << "r: " << (*r) << std::endl;
    std::cout << "prev: " << (*prev) << std::endl;
}

void find(SLNode ** phead, int key) {
    SLNode * r = (*phead);
    while(1) {
        if (r->get_key() == key)
            std::cout << "check: " << r->get_key() << std::endl;
        if (r->get_next() == NULL) {
            std::cout << "not found" << std::endl;
            break;
        }
        r = r->get_next();
    }
}


int main() {
    SLNode * phead = NULL;
    insert_head(phead, 5);
    insert_head(phead, 2);
    insert_head(phead, 3);

    delete_head(&phead);
    delete_head(&phead);


    print(phead);

    return 0;
}