#include<cstring>

template<class T>
class Node{
private:
    T data;
    Node* next;
protected:
public:
    Node(T a, Node* n = nullptr){
       data = a;
       next = n;
    }
    ~Node(){}
    Node*& next(){return _next;}
	T& data(){return _data;}
};

template<>
Node<char*>::~Node(){
    if(_data){
        delete [] _data;
    }
}

template<>
Node<char*>::Node(char* a, Node<char*>* t){
    if(a){
        _data = new char[strlen(a)+1];
        strcpy(_data, a);
    } else {
        _data = nullptr;
        _next = t;
    }
}

template<class T>
class LinkedList{
	private:
		Node<T>* front;
		unsigned int size;
	protected:
		bool Node<T>*& fiendBack(){
			if(front){
				if(front->next){
					auto a = front;
					while(a->next()->next()) a = a->next();
					ref = a;
                    return true;
				} else {
                    ref = front;
					return false;
				}
				return false;
			}
		}
	public:
		LinkedList() : front(nullptr), size(0) {}
		void push_front(T a){
			front = new Node<T>(a, front);
			size++;
		}
		void push_back(T a){
            Note<T>* r = nullptr;
			bool isBeforeBack = findBack(r);
			auto n = new Node<T>(a);
			size++;
			if(r){
				if(!isBeforeBack){
					front->next() = n;
				} else {
					r->next()->next() = n;
				}
			} else {
				front = n;
			}
		}
		void pop_front(){ // no wrapping cuz is slower and retarded
			auto a = front;
			front = a->next();
			delete a;
			size--;
		}
		void pop_back(){
            Note<T>* ref;
			auto isBeforeBack = fiendBack();
			if(ref){
				size--;
				if(!isBeforeBack){
					delete front;
					front = null;
				} else {
					delete a->next();
					a->next() = nullptr;
				}
			}
		}
		~LinkedList(){}
};