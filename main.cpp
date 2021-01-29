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


class SLList {
public:
    SLList()
    : phead_(NULL), size_(0)
    {}

    void insert_head(int key) {
        phead_ = new SLNode(key, phead_);
    }

    void insert_tail(int key) {
        SLNode * tail = new SLNode(key, NULL);
        SLNode * r = phead_;
        while (1) {
            if (r->get_next() == NULL) {
                r->set_next(tail);
                break;
            }
            r = r->get_next();
        }
    }

    void delete_head() {
        if ((phead_) != NULL) {
            SLNode * temp = phead_;
            phead_ = phead_->get_next();
            delete temp;
        }
    }

    void delete_tail() {
        SLNode * prev;
        SLNode * r = phead_;

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

    void print() {
        SLNode * p = phead_;
        while (p != NULL) {
            std::cout << (*p) << std::endl;
            p = p->get_next();
        }
    }

    SLNode * get_next() const { 
        return phead_->get_next(); 
    }

    int get_size() {
        SLNode * p = phead_;
        int size = 0;
        while(p != NULL) {
        p = p->get_next();
            size++;
        }
        return size;
    }

    // not working
    void find(int key) {
        SLNode * r = phead_;
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

    class iterator {
    private:
        SLNode * p; 
    };


private:
    SLNode * phead_;
    int size_;
};

// list cout stream
std::ostream & operator<<(std::ostream & cout,
                          const SLList & list) {
	cout << "<List " << &list
		 << "> ";
    return cout;
}



int main() {
    SLList list;
    list.insert_head(5);
    list.insert_head(100);
    list.insert_head(100);
    list.insert_head(100);
    list.print();

    std::cout << '\n';

    return 0;
}