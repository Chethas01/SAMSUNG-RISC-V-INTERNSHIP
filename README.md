# SAMSUNG-RISC-V-INTERNSHIP
Samsung semiconductor research india's mini internship 2024 program where we learnt about RISC-V processor and VLSI Design using various open source tools.

##  Basic Details

**Name:** P Chethas  
**College:** SJB Institute of technology
<br>
**Email ID:** chethaspedu@gmail.com

<details>
<summary><b>Task 1:</b> Task is to refer to C based and RISCV based lab videos and execute the task of compiling the C code using gcc and riscv compiler</summary>

### C Language based LAB
We have to follow the given steps to compile any *.c* file in our machine:  
1. Open the terminal and access the leafpad in which we code the c program. To open leapad run the following command:

```
leafpad 1ton.c

```
	  
2. This will open the editor and allows you to write into the file that you have created as sum1ton. Write the following C code of printing the sum of n numbers.
   
```
#include <stdio.h>
    int main() {
    int sum = 0 , n = 15;
    for ( i = 1 ; i <= n ; ++i )  {
    sum += i ;
    }
    printf("Sum of numbers from 1 to %d is: %d\n", n, sum);
    return 0;
}
```
Once you are done with your code, save your file, and then close the editor.   


  
3. To the C code on your terminal, run the following commands:

```	
	gcc 1ton.c
	./a.out
```
The output should look like this:
<br>
![C Code compiled on gcc Compiler](https://github.com/Chethas01/localrepo/blob/main/Task%201/images/output%20sum1to15.png)

### RISCV based LAB
We have to do the same compilation of our code but this time using RISCV gcc compiler. Follow the given commands:  
1. Open the terminal and run the given command:  
```	
	cat sum1ton.c
```
<br>	
![cat Command](https://github.com/Chethas01/localrepo/blob/main/Task%201/images/cat%20sum1ton.PNG)
<br>
Using the *cat* command, the entire C code will be displayed on the terminal.

2. Now run the following command to compile the code in riscv64 gcc compiler:

```
	riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
```
	
3. Open a new terminal and run the given command:    

```	
	riscv64-unknown-elf-objdump -d sum1ton.o
```

![Objdump using -O1 format](https://github.com/Chethas01/localrepo/blob/main/Task%201/images/Capture4.PNG)

4. The Assembly Language code of our C code will be displayed on the terminal. Type /main to locate the main section of our code.  

### Descriptions of the keyword used in above command  
* *-mabi=lp64:* This option specifies the ABI (Application Binary Interface) to use lp64, which is for 64-bit integer, long and pointer size. This ABI is used for 64-bit RISCV architecture.  
* *-march=rv64i:* This option specifies the architecture that we use, which is rv64i, indicates the 64-bit RISCV base integer instruction set. This also confirms the targeting of 64-bit architecture.  
* *riscv-objdump:* A tool for disassembling RISC-V binaries, providing insights into the code structure and helping in debugging.  
* *-Ofast:* The option -Ofast in the command riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c is a compiler optimization flag used with the GNU Compiler Collection (GCC). This flag is used to instruct the compiler to optimize the generated code for maximum speed. The use of -Ofast is typically chosen for applications where execution speed is critical and where deviations from standard behavior are acceptable. However, it's important to test thoroughly, as this level of optimization can introduce subtle bugs, especially in complex calculations or when strict compliance with external standards is required.  
* *-O1:* This options is an optimization level that tells the compiler to optimize the generated code but without greatly increasing compilation time. -O1 aims to reduce code size and execution time while keeping the compilation process relatively quick.  

#### Other common options are as follows:  
> 1. *-O0:* No optimization, the default level if no -O option is specified.  
> 2. *-O2:* More aggressive optimizations that might increase compilation time but typically provide faster and sometimes smaller code.  
> 3. *-O3:* Maximizes optimization more aggressively than -O2.  
> 4. *-Os:* Optimizes code for size. It enables all -O2 optimizations that do not typically increase code size.

Here, the term *more aggressive optimization* in the context of compilers like GCC refers to a deeper and more complex set of transformations applied to the code in order to improve its performance and possibly reduce its size. The compiler uses more complex techniques that aims to generate faster executing code or code that occupies less memory. However, these optimizations typically increase the compilation time and can sometimes introduce bugs, making it harder to debug.
</details>
