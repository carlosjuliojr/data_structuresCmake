#include<gtest/gtest.h>
#include"../../include/stack.h"


TEST(test1, test_push)
{

  Stack<int>* myStack = new Stack<int>;

  myStack->push(1);


  ASSERT_EQ(myStack->top_stack()->data,1);

  myStack->push(10);
  ASSERT_EQ(myStack->top_stack()->data,10);
  myStack->push(10);
  myStack->push(0);


  ASSERT_EQ(myStack->top_stack()->data,0);

  delete myStack;
}

TEST(test2, test_pop)
{

  Stack<int>* myStack = new Stack<int>;

  myStack->push(1);

  myStack->pop();

  ASSERT_TRUE(myStack->empty());

  myStack->push(1);
  myStack->push(2);
  myStack->push(3);

  myStack->pop();
  ASSERT_EQ(myStack->top_stack()->data,2);

  myStack->pop();
  myStack->pop();

  ASSERT_TRUE(myStack->empty());


  delete myStack;

}

TEST(test3, test_top)
{

  Stack<int>* myStack = new Stack<int>;

  myStack->push(1);

  ASSERT_EQ(myStack->top_stack()->data,1);

  myStack->push(1);
  myStack->push(2);
  myStack->push(3);

  myStack->top_stack();
  ASSERT_EQ(myStack->top_stack()->data,3);

  myStack->pop();
  myStack->pop();

  ASSERT_EQ(myStack->top_stack()->data,1);


  delete myStack;
}

TEST(test4, test_empty)
{

  Stack<int>* myStack = new Stack<int>;

  myStack->push(1);

  ASSERT_EQ(myStack->top_stack()->data,1);

  myStack->push(1);
  myStack->push(2);
  myStack->push(3);


  myStack->pop();
  myStack->pop();
  myStack->pop();

  ASSERT_FALSE(myStack->empty());

  myStack->pop();

  ASSERT_TRUE(myStack->empty());



  delete myStack;
}


TEST(test4, test_swap)
{

  Stack<int>* myStack = new Stack<int>;
  Stack<int>* myStack2 = new Stack<int>;

  myStack->push(1);
  myStack->push(1);
  myStack->push(2);
  myStack->push(3);

  myStack2->push(2);
  myStack2->push(3);


  Stack<int>::swap(myStack,myStack2);

  ASSERT_EQ(myStack->getSize(),2);
  ASSERT_EQ(myStack2->getSize(),4);



  delete myStack;
  delete myStack2;
}



