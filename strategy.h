#ifndef __STRATEGY_H__
#define __STRATEGY_H__
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Sort {
    public:
        /* Constructors */
        Sort();

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
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


#endif // __STRATEGY_H__
