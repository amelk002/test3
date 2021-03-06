#include <iostream>
#include "composite.h"
#include "strategy.h"
#include "container.h"
#include "component.h"
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;



class Sort;
class Container;
class SelectionSort;
class BubbleSort;
class VectorContainer;
class ListContainer;
class Base

int main() {
    Op* op1 = new Op(5);
    Op* op2 = new Op(2);
    Op* op3 = new Op(4);
    Op* op4 = new Op(6);
    Mult* A = new Mult(op1, op2);
    Sub* B = new Sub(op3, op4);
    Add* C = new Add(A, B);
    Sqr* D = new Sqr(C);

    cout << A->evaluate() << endl;
    cout << B->evaluate() << endl;
    cout << C->evaluate() << endl;
    cout << D->evaluate() << endl;
   VectorContainer* container = new VectorContainer();
   ListContainer* container = new ListContainer();
   container->add_element(A);
   container->add_element(B);
   container->add_element(D);
   cout << "Container Before Sort: " << endl;
   container->print();
   container->set_sort_function(new SelectionSort());
  container->sort();
   cout << "Container After Sort: " << endl;
   container->print();
};
