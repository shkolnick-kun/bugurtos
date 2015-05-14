# THIS FILE IS WORK IN PROGRESS, IT IS NOT FINISHED YET!!!
# Getting startted with BuguRTOS-0.8.x

##Hello, %username%!!!
If you are reading this flow of words, then you may be interested in BuguRTOS.
In this document you will get **basic concepts** and **first step instructions** of writing BuguRTOS apps.

###What is BuguRTOS?
BuguRTOS is an embedded OS kernel, written by 
anonymous for [LULZZZZ](https://www.google.com/search?q=LULZ&ie=utf-8&oe=utf-8).

You must bee familiar with an OS on your own computer, and you may think that every OS must have a bunch of software, 
[GUI](http://en.wikipedia.org/wiki/Graphical_user_interface) or at least console interface.
If you are, well, I have bad news for you.

People mean different things when they talk about OS: 
some people think that OS is some kernel with minimal set of system libs and software, 
others think that OS is the wallpaper on their desktop,
and some people think that OS is a software library, that enables execution of "many" processes on "small number" of CPUs.

BuguRTOS now is such a library. In fact BuguRTOS is a set of source and header files, written in C and assembler,
that you can use in your project of [Giant Anthropomorphic Robot](http://www.themoscowtimes.com/business/article/russia-wants-in-on-a-killer-robot-future/500203.html) firmware.

###Why should I need this?
If you like to blink a LED on you Arduino<sup>TM</sup>, then you definitely **DON'T NEED AN OS!**
But if you want to write big and complex firmware which must do many tasks simultaneously, 
then you probably need one.

###But why?
Because OS enables you to **control the complexity** of your project and to use **any styles of programming**
and **any suitable software libs**.

###Why BuguRTOS?
You can use any OS you like. [Here](http://en.wikipedia.org/wiki/List_of_real-time_operating_systems) 
you can see the list of different RTOS.

###What do I need?
 1. You need to get OS source code, check releases on the project page.
 2. You need a cross toolchain for your processor.
 3. You may need som IDE, I prefer to use Code::Blocks.
 4. You need to configure your buid environment:
   * Create a workspace dir.
   * Create a project dir.
   * Copy BuguRTOS to some dir in your workspace.
   * Write config.h file or take one from examples/tests.
   * Add files to your project and configure it:
     *  preinclude config.h;
     *  add following dirs to compiler search path:
        * [%bugurtos_dir%]/kernel, 
        * [%bugurtos_dir%]/libs/generic, 
        * [%bugurtos_dir%]/arch/[%processor%]/[%toolchain%].
   * Write your program, in **main.c** you may write something like:
   ```C
   // #include<bugurt.h> // For Cortex-M
   #include<bugurt_kernel.h> // For AVR, STM8
   /*Project includes, defines, declarations etc.*/

   void idle_main(void * arg ){
	    /*You may write your idle_main or use bultin.*/
	    while(1);
  }
  int main(void){
	    init_bugurt();
	    /*Initialize everything*/
	    start_bugurt();
	    /*
	    Don't write anything here, as control never reaches this place.
	    */
   }
   ```
   * Try to build your project.
   * ??????
   * PROFIT!!!

##Inside BuguRTOS.

