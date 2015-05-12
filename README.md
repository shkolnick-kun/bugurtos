# WUT? #
This is a BuguRTOS project.
The name BuguRTOS comes from Butthurt, Frugurt and RTOS.

BuguRTOS is small portable OS-kernel for microcontrollers.
It is capable to work in hard/soft real time systems.

It is free and open source software, but you can use it for
proprietary software development.

# Licensing #
* Development source code version (trunk) before release 33 is licensed under GNU GPL v3.
* Source code releases before version 0.3.3 are licensed under GNU GPL v3.

* Development source code version (trunk) of release 34 and newer is licensed under GNU GPL v3 with linking exception to enable BuguRTOS usage in closed source products.
* Source code releases starting from version 0.3.3 and newer are licensed under GNU GPL v3 with linking exception to enable BuguRTOS usage in closed source products.

# Get it! #
* Old releases are on [Gdrive!](https://drive.google.com/folderview?id=0B32mjehjqcIOYlFtNnRSc0JxdGc&usp=sharing).
* Since May 12th 2015 new releases are plased [here](https://github.com/shkolnick-kun/bugurtos/releases).

# Current status #
* Branches supported:
  * 0.6.x ([Immediate Ceiling Priority Protocol](http://en.wikipedia.org/wiki/Priority_ceiling_protocol) used) high level features and API are frozen;
  * 0.7.x ([Priority Inheritance Protocol](http://en.wikipedia.org/wiki/Priority_inheritance) used) high level features and API are frozen;
  * 0.8.x (combines both protocols) is under active development.

* Current versions are
  * 0.6.5;
  * 0.7.2;
  * 0.8.3.

* Platforms supported:
  * AVR (GNU-toolchain);
  * STM8:
    * IAR,
    * Raisonance;
  * Cortex<sup>TM</sup>-M4 (GNU-toolchain);
  * Cortex<sup>TM</sup>-M3 (GNU-toolchain);
  * Cortex<sup>TM</sup>-M0 (GNU-toolchain).

# Todo #
* Update documentation.
* ~~Fix virtual SMP to enable -Os flag in avr/gcc-vsmp arch.~~ Done!
* ~~Move Cortex<sup>TM</sup>-Mx tests to [libopencm3](https://github.com/libopencm3/libopencm3).~~ Done!
* Port BuguRTOS project wizard for Code::Blocks IDE to 0.8.x branch.
* Write libs for 0.8.x branch.
* Write more ports.
* Fix bugs.
* ??????
* PROFIT!!!

# News #
* **May 12th 2015: BuguRTOS-0.8.3** is out, see [Changelog](https://github.com/shkolnick-kun/bugurtos/blob/wiki/Changelog.md)! Added more argument checks, fixed several issues, ported tests to [libopencm3](https://github.com/libopencm3/libopencm3).
* **May 12th 2015:** Added [third party code](https://github.com/shkolnick-kun/bugurtos/tree/archives) to project repository.
* **April 25th 2015: BuguRTOS-0.8.2** is out, see [Changelog](https://github.com/shkolnick-kun/bugurtos/blob/wiki/Changelog.md)! Added basic timeout support and fifo scheduling policy support, fixed some bugs.
* **April 25th 2015: BuguRTOS moved to GitHub.**
* **March 13th 2015: BuguRTOS updated** versions 0.6.5, 0.7.2, 0.8.1 are out, see [Changelog](https://github.com/shkolnick-kun/bugurtos/blob/wiki/Changelog.md)! Three bugs fixed, significant changes made in 0.8.x branch.
* **January 24th 2015: BuguRTOS-0.8.0** is out, see [Changelog](https://github.com/shkolnick-kun/bugurtos/blob/wiki/Changelog.md)! Actually It's not just a new version, but a New branch. I will focus on it for a while. Working on this new branch I found and fixed some bugs in priority inheritance protocol of 0.7.x branch. Branches 0.6.x and 0.7.x will have only new ports and bug fixes.
* **BuguRTOS-0.7.1** is out, see [Changelog](https://github.com/shkolnick-kun/bugurtos/blob/wiki/Changelog.md), BuguRTOS-0.8.0 is on the way!
