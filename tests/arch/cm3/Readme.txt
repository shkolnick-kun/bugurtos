This is lpcxpresso workspace directory, it contains tests for CM3.

Tests where writen with lpcxpresso IDE for lpc176x microcontrollers.

There are some missing third party files (covered by third party licenses) 
in this directory, they are:

1. CMSISv2p00_LPC17xx project (unpacked!), it can be found in lpcxpresso IDE files.
2. cr_startup_lpc176x.c C startup file, it also can be found in IDE files.

I didn't include these files to repo and distribution because of licensing 
issues.

If you want to run the tests, then you should take these steps:

1.Take missing files from IDE, and place them to this directory. Don't forget to unpack CMSISv2p00_LPC17xx!!!
2.Launch the IDE and switch a workspace to this directory.
3.Import projects within this directory to workspace.
4.Build and run tests. 
5.??????
6.PROFIT!!!
