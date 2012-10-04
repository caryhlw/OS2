/* ctsw.c : context switcher
 */

#include <xeroskernel.h>

/* Your code goes here - You will need to write some assembly code. You must
   use the gnu conventions for specifying the instructions. (i.e this is the
   format used in class and on the slides.) You are not allowed to change the
   compiler/assembler options or issue directives to permit usage of Intel's
   assembly language conventions.
*/

void contextswitch(void * currentProccess)
{
  __asm__ (
      "pushf;" //push kernel state onto the stack
      "pusha;"
      "mov1 %esp, kern_stack;" //save kernel stack pointer
      "mov1 proc_stack, $esp;" //switch to process stack
      //save return value of system call
      "popa;" //pop process state from the process stack
      "iret;");
//entry point:
   __asm__ (
       "pusha;" //* push process state onto process stack
       "mov1 %esp, proc_stack;" //* save process stack pointer
       "mov1 kern_stack, %esp;" //* switch to kernel stack
       //* save system call arguments
       "popa; popf;"); //* pop kernel state from kernel stack

   return; //* return from context switcher

}

/*
 * void contexSwitch(É) {
  save kernel state & stack ptr
  recover process stack ptr &
          registers

  iret
COMMON_ISR:
  save process registers and
       stack pointer
  recover kernel stack ptr & state
}
 */
