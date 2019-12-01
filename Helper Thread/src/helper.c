// Name: 
// Student ID #:
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include "mcfutil.h"
#include "helper.h"




void atomic_increment(volatile int *pw) 
{
             asm("mfence\n\t" /*mfence保证系统在后面的memory访问之前，先前的memory访问都已结束*/
                 "lock\n\t" /*封锁*/
                 "incl %0\n\t" /*输出操作数用%0引用;输入操作数用%1引用; %0++*/
                 "mfence":
                 "=m"(*pw): // output (%0)
                 "m"(*pw): // input (%1)
                 "cc" // clobbers
                 );
}

void atomic_decrement(volatile int *pw)
{
             asm("mfence\n\t" /*mfence保证系统在后面的memory访问之前，先前的memory访问都已结束*/
                 "lock\n\t" /*封锁*/
                 "decl %0\n\t" /*%0--*/
                 "mfence":
                 "=m"(*pw): // output (%0); 约束修饰符 "="，指定其为输出操作数 
                 "m"(*pw): // input (%1)
                 "cc" // clobbers
                 );
}

int atomic_compare_and_exchange(int requiredOldValue, volatile int* _ptr, int newValue, int sizeOfValue)
{
      int old;
      __asm volatile
      (
      "mov %3, %%eax;\n\t" /*%3 = 0b11; eax = accumulator*/
      "lock\n\t" 
      "cmpxchg %4, %0\n\t" /*cmpxchg(void *ptr, unsigned long old, unsigned long new)*/
      "mov %%eax, %1\n\t"
      :
      "=m" ( *_ptr ), "=r" ( old  ): // outputs (%0 %1); m(input),r(result)
      "m" ( *_ptr ), "r" ( requiredOldValue), "r" ( newValue ): // inputs (%2, %3, %4)
      "memory", "eax", "cc" // clobbers
      );
                                                                                          
      return old;
}

void helper_thread_sync()
{
	
}

void *helper_thread(void *x)
{
	
    
	return NULL;
}
