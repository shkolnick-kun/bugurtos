# Branch 0.8.x first release #
Differences with 0.6.x and 0.7.x branches are:
  * Deleted
    * Mutexes,
    * Semaphores,
    * Signals,
    * IPC.
  * Added basic synchronization primitive, with basic priority inheritance protocol supported.
This basic type can be used to implement mutexes, semaphores, events, conditional vars, message FIFOs, and other blocking synchronization primitives.
To implement some sync primitive one just need to write a wrapper type for sync\_t. Basic priority inheritance is supported "from the box", so no need to write it from scratch for new sync primitive.
  * Libraries with traditional sync primitives support have been planed.