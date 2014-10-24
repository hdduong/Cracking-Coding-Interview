#include <iostream> 
#include <map> 

using namespace std;

template <typename DataType>
class LinkedList {
public:

	LinkedList() {
		data = new DataType();
		next = nullptr;
	}

	explicit LinkedList (DataType dt) {
		data = new DataType(dt);
		next = nullptr;
	}

	explicit LinkedList(DataType dt, LinkedList* nextPtr) {
		data = new DataType(dt);
		next = nextPtr;
	}
	
	~LinkedList() {
		delete next;
		delete data;
	}

	void setNext(LinkedList * lls) {
		this->next = lls;
	}

	LinkedList * getNext() {
		if (this->next == nullptr)
			return nullptr;
		return next;
	}

	DataType * getData() {
		return data;
	}

	LinkedList & insert(LinkedList *insertLL) {
		insertLL->setNext(this->getNext());
		this->setNext(insertLL);
		return *this;
	}

	void printNode (ostream & out = cout) {
		auto tmp = this;
		while(tmp != nullptr) {
			out << *tmp->getData() << " " ;
			tmp = tmp->getNext();
		}
		cout << "\n";
	}

	void removeDuplicate() {

		map<DataType,DataType> dupMap;

		// need to pointers to remove duplicate
		auto tmp = this;
		auto prevTmp = tmp;

		while(tmp != nullptr) {
			pair<map<DataType,DataType>::iterator, bool> ret;
			ret = dupMap.insert( pair<DataType, DataType>(*tmp->getData(), *tmp->getData()) );
			if (!ret.second) { //already exist
				prevTmp->setNext(tmp->getNext());				
			} else {
				prevTmp = tmp;
			}
			tmp=tmp->getNext();
		}
	}

private:
	LinkedList *next;
	DataType *data;
};

ostream & operator<< (ostream & out, LinkedList<int> & root) {
	root.printNode(out);
	return out;
}

void main() {
	//LinkedList<int> *root = new LinkedList<int>(2);
	//LinkedList<int> *node1 = new LinkedList<int>(3);
	//LinkedList<int> *node2 = new LinkedList<int>(4);
	//LinkedList<int> *node3 = new LinkedList<int>(3);
	//LinkedList<int> *node4 = new LinkedList<int>(4);
	//root->insert(node1);
	//root->insert(node2);
	//root->insert(node3);
	//root->insert(node4);

	LinkedList<int> *root = new LinkedList<int>(2);
	LinkedList<int> *node1 = new LinkedList<int>(3);
	LinkedList<int> *node2 = new LinkedList<int>(4);
	LinkedList<int> *node3 = new LinkedList<int>(3);
	LinkedList<int> *node4 = new LinkedList<int>(4);
	node3->insert(node4);
	node2->insert(node3);
	node1->insert(node2);
	root->insert(node1);
	
	cout << *root << endl;
	
	root->removeDuplicate();
	cout << *root << endl;

}