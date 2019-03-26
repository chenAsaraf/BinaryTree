/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  ariel::Tree smalltree;
  ariel::Tree bigtree;  

  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  smalltree.insert(16);
  smalltree.insert(2);

  bigtree.insert(520);
  bigtree.insert(52);
  bigtree.insert(64);
  bigtree.insert(25);
  bigtree.insert(4500);
  bigtree.insert(7800);
  bigtree.insert(6000);

  
  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())

  .CHECK_EQUAL (smalltree.size(),2)
  .CHECK_THROWS(smalltree.remove(2341))
  .CHECK_OK    (smalltree.remove(16))
  .CHECK_EQUAL (smalltree.size(),1)
  .CHECK_EQUAL (smalltree.root(),2)
  .CHECK_THROWS(smalltree.parent(2))
  .CHECK_OK    (smalltree.insert(1))
  .CHECK_OK    (smalltree.insert(3))
  .CHECK_EQUAL (smalltree.left(2),1)
  .CHECK_EQUAL (smalltree.right(2),3)
  .CHECK_OK    (smalltree.print())

  .CHECK_OK    (bigtree.remove(7800))
  .CHECK_EQUAL (bigtree.right(4500),6000)
  .CHECK_OK    (bigtree.remove(52))
  .CHECK_EQUAL (bigtree.left(520),25)
  .CHECK_EQUAL (bigtree.right(25),64)
  .CHECK_OK    (bigtree.remove(520))
  .CHECK_EQUAL (bigtree.parent(4500),64)
  .CHECK_THROWS(bigtree.parent(64))
  .CHECK_OK    (bigtree.remove(64))
  .CHECK_OK    (bigtree.insert(64))
  .CHECK_EQUAL (bigtree.parent(64),4500)
  .CHECK_EQUAL (bigtree.parent(4500),25)
  .CHECK_EQUAL (bigtree.size(),4)
  .CHECK_EQUAL (bigtree.right(4500),6000)
  .CHECK_OK    (bigtree.print())

  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
