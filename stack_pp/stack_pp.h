#ifndef STACK_PP_STACK_PP_H
#define STACK_PP_STACK_PP_H


#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define assert_stack(nameStack) {\
    if ( !(StackOK(nameStack)) ) {\
        printf("| !!!Assertion failed!!!\n");\
        printf("|       what: StackOK(%s),\n", #nameStack);\
        printf("|       in: %s,\n", __FILE__);\
        printf("|       function: %s,\n",  __PRETTY_FUNCTION__);\
        printf("|       on: %d line.\n", __LINE__);\
        printf("|   !!!Look at DUMP!!!\n");\
        Dump(nameStack);\
        abort();\
    }\
}

#define assert_var(variable) {\
    if ( !(std::isfinite(variable)) ) {\
        printf("| !!!Assertion failed!!!\n");\
        printf("|       what: StackOK(%s),\n", #variable);\
        printf("|       in: %s,\n", __FILE__);\
        printf("|       function: %s,\n",  __PRETTY_FUNCTION__);\
        printf("|       on: %d line.\n", __LINE__);\
        printf("|   !!!Look at DUMP!!!\n");\
        Dump(nameStack);\
        abort();\
    }\
}

//----------------------------------------------------------------------------------------------------------------------
//! This define created for Hash sum
//----------------------------------------------------------------------------------------------------------------------

#define SAFETY_STACK
#ifdef SAFETY_STACK
#define HASH_SUM(what, op, ref) {\
    if ((#op)[0] == '+') {\
        (what) = ( (what) op (ref) );\
        (what) = ( ( (int) (what) ) << 1 );\
    }\
    else {\
        (what) = ( ( (int) (what) ) >> 1 );\
        (what) = ( (what) op (ref) );\
    }\
}

#else
#define HASH_SUM(what, op, ref)
#endif


typedef int data_t;

const size_t InSize = 2;

const size_t petuhValue1 = 110900;

const data_t petuhValue2 = 160716;

const size_t yad_size= 255;

class Stack {
private:
    data_t* Data_;
    size_t Size_;

public:
    Stack(size_t capacity);
    ~Stack();

    void Push(data_t val);
    data_t Pop();
};

enum STACK_ERRORS {
    STACK_ERROR_CTOR = 100010,
    STACK_ERROR_INIT = 0b100001,
    STACK_ERROR_PUSH = 100011,
    STACK_ERROR_PUSH_REALLOC = 100100,
    STACK_ERROR_POP = 100101,
    STACK_ERROR_POP_REALLOC = 100110,
};

//----------------------------------------------------------------------------------------------------------------------
//! StackCtor\n\n
//! StackCtor function initialise stack.
//!
//! \param nameStack - pointer to stack.
//! \param capacity - stack capacity.
//! \return - returns 1 if all is well and returns STACK_ERROR_CTOR if can't allocate memory.
//----------------------------------------------------------------------------------------------------------------------

size_t StackCtor(Stack* nameStack, size_t capacity = 0);

//----------------------------------------------------------------------------------------------------------------------
//! StackPush\n\n
//! StackPush function pushes element in stack.
//!
//! \param nameStack - pointer to stack.
//! \param variable - the variable we want to push in stack.
//! \return - returns 1 if all is well and returns STACK_ERROR_PUSH if something uncommon.
//----------------------------------------------------------------------------------------------------------------------

size_t StackPush(Stack* nameStack, data_t variable);

//----------------------------------------------------------------------------------------------------------------------
//! StackPop\n\n
//! StackPop function pops element from stack.
//!
//! \param nameStack - pointer to stack.
//! \return - returns element which was popped. If there isn't any element to pop returns NAN
//! and returns STACK_ERROR_POP if can't allocate memory.
//----------------------------------------------------------------------------------------------------------------------

data_t StackPop(Stack* nameStack);

//----------------------------------------------------------------------------------------------------------------------
//! StackPeek\n\n
//! StackPeek function shows the top element.

//! \param nameStack - pointer to stack.
//! \return - returns the top element. If there isn't any element returns NAN,
//! and returns STACK_ERROR_PEEK if something uncommon.
//----------------------------------------------------------------------------------------------------------------------

data_t StackPeek(Stack* nameStack);

//----------------------------------------------------------------------------------------------------------------------
//! StackClear\n\n
//! StackClear function clears all stack (memory is filled with nan's).
//!
//! \param nameStack - pointer to stack.
//----------------------------------------------------------------------------------------------------------------------

void StackClear(Stack* nameStack);

//----------------------------------------------------------------------------------------------------------------------
//! StackDtor\n\n
//! Destroy the stack.
//!
//! \param nameStack - pointer to stack.
//----------------------------------------------------------------------------------------------------------------------

void StackDtor(Stack* nameStack);

//----------------------------------------------------------------------------------------------------------------------
//! StackMem\n\n
//! StackMem function allocates memory for stack.
//!
//! \param nameStack - pointer to stack.
//! \param initialSize - size of initialise for stack.
//! \return - return STACK_ERROR_INIT if can't allocate memory and 1 if all is well.
//----------------------------------------------------------------------------------------------------------------------

size_t StackMem(Stack* nameStack, size_t initialSize = 0);

//----------------------------------------------------------------------------------------------------------------------
//! StackPushMemInc\n\n
//! StackPushMemInc function allocate new memory if it's needed.
//!
//! \param nameStack - pointer to stack.
//! \return - returns STACK_ERROR_REALLOC if can't allocate memory and 1 if all is well.
//----------------------------------------------------------------------------------------------------------------------

size_t StackPushMemInc (Stack* nameStack);

//----------------------------------------------------------------------------------------------------------------------
//! StackPopMemDec\n\n
//! StackPopMemDec function decrease memory if it's not needed.
//!
//! \param nameStack - pointer to stack.
//! \return - returns STACK_ERROR_REALLOC if can't allocate memory and 1 if all is well.
//----------------------------------------------------------------------------------------------------------------------

size_t StackPopMemDec(Stack* nameStack);

//----------------------------------------------------------------------------------------------------------------------
//! StackOK\n\n
//! StackOK function checks stack.
//!
//! \param nameStack - pointer to stack.
//! \return - returns 0 if there is something wrong, and 1 if all is well.
//----------------------------------------------------------------------------------------------------------------------

bool StackOK(Stack* nameStack);

//----------------------------------------------------------------------------------------------------------------------
//! Dump\n\n
//! Dump function creates DUMP.txt file and writes there information about Stack
//!
//! \param nameStack - pointer to stack.
//----------------------------------------------------------------------------------------------------------------------

void Dump(Stack* nameStack);

//----------------------------------------------------------------------------------------------------------------------
//! unittest/n/n
//! unittest function tests stack looking for promblems or mistakes
//!
//! \param nameStack - pointer to stack.
//----------------------------------------------------------------------------------------------------------------------

void unittest(Stack* nameStack);


#endif //STACK_PP_STACK_PP_H
