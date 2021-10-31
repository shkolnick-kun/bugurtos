# WUT? #
This is a BuguRTOS project.
The name BuguRTOS comes from Butthurt, Frugurt and RTOS.

BuguRTOS is small portable OS kernel for microcontrollers.
It is capable to work in hard/soft real time systems.

It is free and open source software, but you can use it for
proprietary software development.

# Main features #
* Small. BuguRTOS can run on small 8bit microcontrollers.
* Portable. The kernel is designed to be easily portable to new platforms.
* SMP-ready by design. The kernel was designed for SMP MCUs from the very begining. Although there were no SMP MCUs available at the end of 2010.
* No memory management in kernel.
* Smaller process stack size required as kernel runs in separate thread with its own stack.
* The kernel is almost fully preemptive. Only small chunks of code can't be preempted by interrupts.
* Interrupt virtualization. Virtual interrupts are run cooperatively in kernel threads. By default, they can be preempted by other virtual interrupts in preemption points.
* Customizable system call interface. One may comment out unneeded system calls, add custom system calls or rewrite system call table completely.

# Licensing #
* BuguRTOS is licensed under GPLv3 with linking exception, see [exception.txt](./exception.txt)
* STM8/SDCC tests are licensed under GPLv3 without exceptions as [libstm8](https://github.com/mnd/libstm8) is used!

# Get it! #
* Old releases are on [Gdrive!](https://drive.google.com/folderview?id=0B32mjehjqcIOYlFtNnRSc0JxdGc&usp=sharing).
* Since May 12th 2015 new releases are placed [here](https://github.com/shkolnick-kun/bugurtos/releases).

# Current status #
* Branches supported:
  * 0.6.x ([Immediate Ceiling Priority Protocol](http://en.wikipedia.org/wiki/Priority_ceiling_protocol) used) high level features and API are frozen;
  * 4.1.x (combines Immediate Ceiling Priority and [Basic Priority Inheritance](http://en.wikipedia.org/wiki/Priority_inheritance) protocols) is under active development.

* Current versions are:
  * 0.6.6;
  * 4.1.0;

* Platforms supported:
  * AVR (GNU-toolchain);
  * STM8:
    * IAR,
    * Raisonance,
    * SDCC (since 2.0.0);
  * Cortex<sup>TM</sup>-M7 (GNU-toolchain);
  * Cortex<sup>TM</sup>-M4 (GNU-toolchain);
  * Cortex<sup>TM</sup>-M3 (GNU-toolchain);
  * Cortex<sup>TM</sup>-M0 (GNU-toolchain);
  * rp2040 (since 4.1.0).

* Notes on STM8/SDCC port:
  * Thank [Philipp Klaus Krause](https://github.com/spth) for taking part in this port!
  * SDCC generates strange code for long linear functions which allocates __MUCH STACK SPACE__ for temporary vars, be careful!

* Notes on Cortex<sup>TM</sup>-M0 port:
  * This port should also work on Cortex<sup>TM</sup>-M1 with OS-extension.

* Notes on rp2040 port:
  * BuguRTOS runs in SMP mode. Only two RTOSes support SMP on rp2040 at the end of october 2021.
  * [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk) usage is optional.
  * The port use four interrupts, they are:
    * SysTick,
    * PendSv,
    * IRQ15 (core 0 SIO interrupt),
    * IRQ16 (core 1 SIO interrupt);
  * When [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk) standard runtime is used with BuguRTOS interrupt names are set to SDKs default ISR names. There is no need to define or configure them.
  * "Atomic" operations are core local. Cross-core memory accesses are concurrent.
  * rp2040 has 32 hardware locks but we can't use them in BuguRTOS because of two reasons:
    * We need unlimited number of spin locks for the Kernel.
    * Hardware locks are heavilly used by the [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk).
  * [Lamport's bakery algorithm](https://en.wikipedia.org/wiki/Lamport%27s_bakery_algorithm) is used for software implemented spin locks.
  * Software implemented spin locks are used to avoid cross-core concurency inside the kernel. **DO NOT use them directly!!!**

# Get started #
Getting started guide is [here](./doc/GettingStartedEN.md).

# Todo #
* Write libs for 4.x.y branch.
* Write more ports.
* Fix bugs.
* ??????
* PROFIT!!!

# News #
* **October 31st 2021 BuguRTOS updated** version 4.1.0 is out, see [Changelog](./doc/Changelog.md) for details!
* **January 7th 2019: BuguRTOS updated** version 4.0.0 is out, see [Changelog](./doc/Changelog.md) for details!
* **March 13th 2017: BuguRTOS updated** version 3.0.0 is out, see [Changelog](./doc/Changelog.md) for details!
* **August 31th 2016: BuguRTOS updated** version 2.0.0 is out, see [Changelog](./doc/Changelog.md) for details!
* **April 26th 2016: BuguRTOS updated** version 1.0.0 is out, see [Changelog](./doc/Changelog.md), semantic versioning is used now!
* **January 6th 2016: BuguRTOS updated** version 0.9.9 is out, see [Changelog](./doc/Changelog.md)!
* **July 3rd 2015: BuguRTOS updated** versions 0.6.6, 0.7.3, 0.8.4 are out,  are out, see [Changelog](./doc/Changelog.md)!
* **May 12th 2015: BuguRTOS-0.8.3** is out, see [Changelog](./doc/Changelog.md)! Added more argument checks, fixed several issues, ported tests to [libopencm3](https://github.com/libopencm3/libopencm3).
* **May 12th 2015:** Added [third party code](https://github.com/shkolnick-kun/bugurtos/tree/archives) to project repository.
* **April 25th 2015: BuguRTOS-0.8.2** is out, see [Changelog](./doc/Changelog.md)! Added basic timeout support and fifo scheduling policy support, fixed some bugs.
* **April 25th 2015: BuguRTOS moved to GitHub.**
* **March 13th 2015: BuguRTOS updated** versions 0.6.5, 0.7.2, 0.8.1 are out, see [Changelog](./doc/Changelog.md)! Three bugs fixed, significant changes made in 0.8.x branch.
* **January 24th 2015: BuguRTOS-0.8.0** is out, see [Changelog](./doc/Changelog.md)! Actually It's not just a new version, but a New branch. I will focus on it for a while. Working on this new branch I found and fixed some bugs in priority inheritance protocol of 0.7.x branch. Branches 0.6.x and 0.7.x will have only new ports and bug fixes.
* **BuguRTOS-0.7.1** is out, see [Changelog](./doc/Changelog.md), BuguRTOS-0.8.0 is on the way!
