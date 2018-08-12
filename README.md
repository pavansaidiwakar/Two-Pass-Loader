# Two-Pass-Loader
An implementation of two pass linking loader which takes object program as input and loads the program into the memory at the user specified location

INTRODUCTION:
In computer systems a loader is the part of an operating system that is responsible for
loading programs and libraries. It is one of the essential stages in the process of starting a
program, as it places programs into memory and prepares them for execution. Loading a program
involves reading the contents of the executable file containing the program instructions into
memory, and then carrying out other required preparatory tasks to prepare the executable for
running. Once loading is complete, the operating system starts the program by passing control to
the loaded program code.
The functions of the loader are to allocate the space for program in the memory, to resolve the
symbolic references between the object modules by assigning all the user subroutine and library
subroutine addresses, to perform relocation for address dependent instructions and to place all
the machine instructions into the memory.


OBJECTIVE:
i)To initiate the execution process by using the two pass linking loader.
ii)To take the object code as input, prepare it for execution and load the executable code into the
memory.


METHODOLOGY:
ESTAB is used to store the name and address of each external symbol in the set of control
sections being loaded. Two variables PROGADDR and CSADDR. PROGADDR is the
beginning address in memory where the linked program is to be loaded. CSADDR contains the
starting address assigned to the control section currently being scanned by the loader.
First pass is concerned with assigning addresses to all external symbols present in the
instructions and Second Pass is actually responsible for the actual loading, along with the tasks
involved in relocating and linking the different object codes.
