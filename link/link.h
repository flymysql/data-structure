#ifndef NEW_H
#define NEW_H
template<class T>
class link {
public:
    T data;
    link<T> *next;

    link(const T info, link<T> *nextnode = NULL) {
        data = info;
        next = nextnode;
    }

    link(link<T> *nextnode = NULL) {
        next = nextnode;
    }
};


#endif //NEW_H
