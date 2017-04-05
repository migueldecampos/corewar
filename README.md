# corewar
This is my implementation of a version of corewar.

I worked on this project with Billy Betz and Artem Kalmykov for École 42.

At the root of this repository you will find a pdf file with, among other things, a description of the instructions, and the rules of the virtual machine.

We created two programs, the assembler, that compiles champions into bytecode, and the virtual machine, that runs those champions against each other.


The Assembler (asm):
	The assembler takes .s files as arguments and, if they possess valid instructions creates the corresponding .cor file which will then be used as an argument for the virtual machine.

The Virtual Machine (corewar):
	The virtual machine takes as arguments 1 to 6 champions, loads them to the memory, and attributes one process to each. When there are no longer any processes alive the vm checks which was the last champion to execute the live instruction, and declares that champion to have won.

Sample Champion (angrybird.s):
	We also included a very small champion. I will upload a repository with more champions soon...	
