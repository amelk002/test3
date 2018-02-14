#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Sort;
class Container;
class SelectionSort;
class BubbleSort;
class VectorContainer;
class ListContainer;
class Base
{
	public:
		/* Constructors */
		Base() {};
		/* Pure virtual Functions */
		virtual double evaluate() = 0;
};
class Operand : public Base
{
	protected:
		double number;
	public:
		Operand(): number(0) {}
		Operand(double a): number(a) {}
		double evaluate()
		{
			return number;
		}
};
class Add : public Base
{
	protected:
		Base* leftChild;
		Base* rightChild;
	public:
		Add(): leftChild(NULL), rightChild(NULL) {}
		Add(Base* left, Base* right): leftChild(left), rightChild(right) {}
		double evaluate()
		{
			return leftChild->evaluate() + rightChild->evaluate();
		}	
};
class Subtract : public Base
{
	protected:
		Base* leftChild;
		Base* rightChild;
	public:
		Subtract(): leftChild(NULL), rightChild(NULL) {}
		Subtract(Base* left, Base* right): leftChild(left), rightChild(right) {}
		double evaluate()
		{
			return leftChild->evaluate() - rightChild->evaluate();
		}
};
class Multiply : public Base
{
	protected:
		Base* leftChild;
		Base* rightChild;
	public:
		Multiply(): leftChild(NULL), rightChild(NULL) {}
		Multiply(Base* left, Base* right): leftChild(left), rightChild(right) {}
		double evaluate()
		{
			return leftChild->evaluate() * rightChild->evaluate();
		}
};
class Divide : public Base
{
	protected:
		Base* leftChild;
		Base* rightChild;
	public:
		Divide(): leftChild(NULL), rightChild(NULL) {}
		Divide(Base* left, Base* right): leftChild(left), rightChild(right) {}
		double evaluate()
		{
			return leftChild->evaluate() / rightChild->evaluate();
		}
};
class Squared : public Base
{
	protected:
		Base* onlyChild;
	public:
		Squared(): onlyChild(NULL) {}
		Squared(Base* onlyValue): onlyChild(onlyValue) {}
		double evaluate()
		{
			return onlyChild->evaluate() * onlyChild->evaluate();
		}
};
class Container
{
	protected:
		Sort* sort_function;
	public:
		/* Constructors */
		Container() : sort_function(NULL){};
		Container(Sort* function) : sort_function(function) {};
		/* Non Virtual Functions */
		void set_sort_function(Sort* sort_function)
		{
			this->sort_function = sort_function;
			// set the type of sorting algorithm
		}
		/* Pure Virtual Functions */
		// push the top pointer of the tree into container
		virtual void add_element(Base* element) = 0;
		// iterate through trees and output values
		virtual void print() = 0;
		// calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
		virtual void sort() = 0;
		/*Essentially the only functions needed to sort */
		// switch tree locations
		virtual void swap(int i, int j) = 0;
		// get top pointer of tree at index i
		virtual Base* at(int i	) = 0;
		// return container size
		virtual int size() = 0;
};
class Sort
{
	public:
		/* Constructors */
		Sort() {}
		/* Pure Virtual Functions */
		virtual void sort(Container* container) = 0;
};
class VectorContainer : public Container
{
	protected:
		vector<Base*> vector1;
		Base* child;
	public:
		VectorContainer(): child(NULL) {}
		VectorContainer(Sort* vectors): child(NULL)
		{
			sort_function = vectors;
		}
		void sort()
		{
			sort_function->sort(this);
		}
		void add_element(Base* newElement)
		{
			vector1.push_back(newElement);
		}
		void print()
		{
			for(unsigned int i = 0; i < vector1.size(); ++i)
			{
				cout << vector1.at(i)->evaluate() << endl;
			}
		}
		void swap(int first, int second)
		{
			Base* tempVal  = vector1.at(first);
			vector1.at(first) = vector1.at(second);
			vector1.at(second) = tempVal;
		}
		Base* at(int i)
		{
			return vector1.at(i);
		}
		int size()
		{
			return vector1.size();
		}
};
class ListContainer : public Container
{
	protected:
		list<Base*> baseList;
		Base* child;
	public:
		ListContainer(): child(NULL) {}
		ListContainer(Sort* newList): child(NULL)
		{
			sort_function = newList;	
		}
		void sort()
		{
			sort_function->sort(this);
		}
		void add_element(Base* newElement)
		{
			baseList.push_back(newElement);
		}
		void print()
		{
			list<Base*>::iterator it;
			for(it = baseList.begin(); it != baseList.end(); ++it)
			{
				Base* temp = *it;
				cout << temp->evaluate() << endl;
			}
		}
		void swap(int first, int second)
		{
			list<Base*>::iterator it;
			int counter = 0;
			int counter2 = 0;
			Base* firstElement;
			Base* secondElement;
			for(it = baseList.begin(); it != baseList.end(); ++counter, ++counter2, ++it)
			{
				if(counter == first)
				{
					firstElement = *it;
				}
				if(counter2 == second)
				{
					secondElement = *it;
				}
			}
			for(counter = 0, counter2 = 0, it = baseList.begin(); it != baseList.end(); ++counter, ++counter2, ++it)
			{
				if(counter == first)
				{
					*it = secondElement;
				}
				if(counter2 == second)
				{
					*it = firstElement;
				}
			}
		}
		Base* at(int i)
		{
			list<Base*>::iterator it;
			int counter = 0;
			for(it = baseList.begin(); it != baseList.end(); ++it, ++counter)
			{
				if(counter == i)
				{
					return *it;
				}
			}
			return *it;
		}
		int size()
		{
			return baseList.size();
		}
};
class SelectionSort : public Sort
{
	protected:
		Container* child;
	public:
		SelectionSort(): child(NULL) {}
		SelectionSort(Container* temp): child(temp) {}
		void sort(Container* temp)
		{
			child = temp;
			int first, in, out;
			for(out = 0; out < temp->size(); ++out)
			{
				first = 0;
				for(in = 1; in <= out; ++in)
				{
					if(temp->at(in)->evaluate() > temp->at(first)->evaluate())
					{
						first = in;
					}
				}
				temp->swap(first, out);
			}
		}
};	
class BubbleSort : public Sort
{
	protected:
		Container* child;
		vector<Base*> baseVector;
	public:
		BubbleSort(): child(NULL) {}
		BubbleSort(Container* temp): child(temp) {}
		void sort(Container* temp)
		{
			child = temp;
			for( int i = 0; i < temp->size(); ++i)
			{
				for(int j = 0; j < temp->size(); ++j)
				{
					if(j != temp->size() - 1)
					{
						if(temp->at(j)->evaluate() > temp->at(j + 1)->evaluate())
						{
							temp->swap(j, j+1);
						}
					}
				}
			}
		}
};
int main() 
{
	Operand* op7 = new Operand(7);
	Operand* op4 = new Operand(4);
	Operand* op3 = new Operand(3);
	Operand* op2 = new Operand(2);
	Multiply* A = new Multiply(op7, op4);
	Add* B = new Add(op3, A);
	Subtract* C = new Subtract(B, op2);
	Squared* D = new Squared(C);

	VectorContainer* container = new VectorContainer();
	container->add_element(A);
	container->add_element(B);
	container->add_element(C);
	container->add_element(D);

	cout << "Container Before Sort: " << endl;
	container->print();

	cout << "Container After Sort: " << endl;
	container->set_sort_function(new SelectionSort());
	container->sort();
	container->print();
	return 0;
}
