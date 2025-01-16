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

![C Code compiled on gcc Compiler](https://github.com/Chethas01/localrepo/blob/main/Task%201/images/output%20sum1to15.png)
<br>
### RISCV based LAB
We have to do the same compilation of our code but this time using RISCV gcc compiler. Follow the given commands:  
1. Open the terminal and run the given command:  
```	
	cat sum1ton.c
```

![cat_Command](https://github.com/Chethas01/localrepo/blob/main/Task%201/images/cat%20sum1ton.PNG)
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

<details>
<summary><b>Task 2:</b> Performing SPIKE Simulation and Debugging the C code with Interactive Debugging Mode using Spike</summary> 


  
### What is SPIKE in RISCV?
> SPIKE is the RISC-V Reference Simulator: It is the official software simulator for RISC-V, providing a platform to simulate and test RISC-V instructions and architectures.
> * Spike is a free, open-source C++ simulator for the RISC-V ISA that models a RISC-V core and cache system. It can be used to run programs and a Linux kernel, and can be a starting point for running software on a RISC-V target.
> * SPIKE executes RISC-V instructions and emulates their behavior to verify correctness, making it a tool for hardware and software co-design. 
> * Key Features: It supports various RISC-V features, including multiple privilege levels, instruction set extensions, and configurable core architectures, facilitating debugging and validation of RISC-V implementations.

#### *To run the spike operations, let's install the tools and libraries required.*  

*Use the following command to install **SPIKE** in your machine*  
```
 git clone https://github.com/riscv/riscv-isa-sim.git  
 cd riscv-isa-sim  
 mkdir build  
 cd build  
 sudo apt-get install device-tree-compiler // to install the missing dependencies   
 sudo apt-get install libboost-all-dev // to install the libboost library
 ../configure --prefix=/opt/riscv  
 make  
 sudo make install  
 sudo apt update  
 sudo apt install g++-8
 make CXX=g++-8  
 echo 'export PATH=$PATH:/opt/riscv/bin' >> ~/.bashrc
 source ~/.bashrc  
```
#### What this code does? 
>*This script sets up the RISC-V SPIKE simulator by cloning its source code from GitHub and preparing a build directory. It installs necessary dependencies like the device tree compiler and Boost libraries, then configures the build system to install the simulator in the /opt/riscv directory. After compiling and installing the simulator, it ensures GCC version 8 is used for compatibility. Finally, it updates the system's PATH environment variable to include the SPIKE binary directory, allowing the simulator to be accessed from any location in the terminal. This process enables users to simulate and debug RISC-V instructions effectively.*
  
### What is PK (Proxy Kernel)?  
* Proxy Kernel is a lightweight operating system environment for RISC-V that provides basic services like handling system calls, enabling user-level programs to run without a full operating system.  
* A Proxy Kernel in the RISC-V ecosystem simplifies the interaction between complex hardware and the software running on it, making it easier to manage, test, and develop software and hardware projects.
* It is primarily used with RISC-V simulators (like SPIKE) and hardware to test and debug applications in a simplified kernel environment, bridging the gap between bare-metal and full OS setups.

*Use the following command to install **pk** in your machine*  
```
Make sure you are on home directory  
 git clone https://github.com/riscv/riscv-pk.git  
 cd riscv-pk  
 mkdir build  
 cd build  
 ../configure --prefix=/opt/riscv --host=riscv64-unknown-elf --with-arch=rv64gc  
 make  
 sudo make install  
```
#### What this code does? 
>This script sets up the RISC-V Proxy Kernel (PK) by cloning its source code from GitHub and preparing a build directory. It configures the build system for the 64-bit RISC-V architecture (`rv64gc`) with a target installation path of `/opt/riscv`. After compiling the source code, it installs the Proxy Kernel binaries in the specified directory. This enables the use of PK as a lightweight operating environment for running RISC-V applications on simulators or hardware.

### Using the SPIKE Simulator  
The target is to run the ```sum1ton.c``` code using both ```gcc compiler``` and ```riscv compiler```, and both of the compiler must display the same output on the terminal. So to compile the code using **gcc compiler**, use the following command:  
```
gcc sum1ton.c  
./a.out
```
And to compile the code using **riscv compiler**, use the following command:  
```
spike pk sum1ton.o
```

![SPIKE RESULTS](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%202/Images/spike%20test.png)
<br>

### RISCV Objdump with -O1 option
*Use the following code for 01 object dump:*
```
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
riscv64-unknown-elf-objdump -d sum1ton.o

```
*To diplay less information use the below code*
```
riscv64-unknown-elf-objdump -d sum1ton.o | less
```
![O1 object dump](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%202/Images/obj%20dump%20O1.png)
<br>

### RISCV Objdump with -Ofast option
*Use the following code for 01 object dump:*
```
riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
riscv64-unknown-elf-objdump -d sum1ton.o
```
*To diplay less information use the below code*
```
riscv64-unknown-elf-objdump -d sum1ton.o | less
```
![O1 object dump](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%202/Images/obj%20dump%20Ofast.png)

### Debugging the Assembly Language Program of  ```sum1ton.c```  
* Open the **Objdump** of code by using the following command  
```
riscv64-unknown-elf-objdump -d sum1ton.o | less  
```
* Open the debugger in another terminal by using the following command  
```
spike -d pk sum1ton.o
```
* The debugger will be opened in the terminal. Now, debugging operations can be performed as shown in the following snapshot.

![Debugging](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%202/Images/debug.PNG) 

</details>

<details>
<summary><b>Task 3:</b> Task is to identify the type of instruction of all codes given with its exact 32 bits of instruction code in the desired instruction type format </summary>

 
</details>
