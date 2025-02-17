# SAMSUNG-RISC-V-INTERNSHIP
Samsung semiconductor research india's mini internship 2024 program where we learnt about RISC-V processor and VLSI Design using various open source tools.

---

##  Basic Details

**Name:** P Chethas  
**College:** SJB Institute of technology
<br>
**Email ID:** chethaspedu@gmail.com

---
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

---

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

---

<details>
<summary><b>Task 3:</b> Task is to identify the type of instruction of all codes given with its exact 32 bits of instruction code in the desired instruction type format </summary>

## Types of instructions in RISC-V

### 1. R-type Instruction
In RV32, each instruction is of size 32 bits. In R-type instruction, R stands for register which means that operations are carried on the Registers and not on memory location. This instruction type is used to execute various arithmetic and logical operations. The entire 32 bits instruction is divided into 6 fields as shown below.

* The first field in the instruction format is known as **opcode**, also referred as operation code. The opcode is of length 7 bits and is used to determine the type of instruction format.
* The next subfield is known as **rd** field which is referred as Destination Register. The rd field is of length 5 bits and is used to store the final result of operation.
* The next subfield is **func3** also referred as function 3. Here the ‘3’ represents the size of this field. This field tells the detail about the operation, i.e., the type of arithmetic and logical that is performed.
* The next two subfields are the source registers, **rs1 and rs2** each of length 5 bits. These are mainly used to store and manipulate the data during the execution of instructions.
* The last subfield is **func7** also referred as function 7. Here ‘7’ represents the size of the field. The function of func7 field is same as that of func3 field.
---
### 2. I-type Instruction
In RV32, each instruction is of size 32 bits. In I-type instruction, I stand for immediate which means that operations use Registers and Immediate value for their execution and are not related with memory location. This instruction type is used in immediate and load operations. The entire 32 bits instruction is divided into 5 fields as shown below.

* The first field in the instruction format is known as **opcode**, also referred as operation code. The opcode is of length 7 bits and is used to determine the type of instruction format.
* The next subfield is known as **rd** field which is referred as Destination Register. The rd field is of length 5 bits and is used to store the final result of operation.
* The next subfield is **func3** also referred as function 3. Here the ‘3’ represents the size of this field. This field tells the detail about the operation, i.e., the type of arithmetic and logical that is performed.
* The next subfield is the source registers, **rs1** of length 5 bits. It is mainly used to store and manipulate the data during the execution of instructions.
* The only difference between R-type and I-type is **rs2 and func7** field of R-type has been replaced by 12-bits signed immediate, **imm[11:0]**.
---
### 3. S-type Instruction
In RV32, each instruction is of size 32 bits. In S-type instruction, S stand for store which means it is store type instruction that helps to store the value of register into the memory. Mainly, this instruction type is used for store operations. The entire 32 bits instruction is divided into 6 fields as shown below.

* The first field in the instruction format is known as **opcode**, also referred as operation code. The opcode is of length 7 bits and is used to determine the type of instruction format.
* S-type instructions encode a 12-bit signed immediate, with the top seven bits **imm[11:5] in bits [31:25]** of the instruction and the lower five bits **imm[4:0] in bits [11:7]** of the instruction.
* S-type instruction doesn’t have rd fields which states that these instructions are not used to write value to a register, but to write/store a value to a memory.
* The value to be stored is defined in **rs1** field and address to which we have to store this value is calculated using **rs1 and immediate** field. The width of the operation and types of instruction is defined by **func3**, it can be a word, half-word or byte.
---
### 4. B-type Instruction
In RV32, each instruction is of size 32 bits. In B-type instruction, B stand for branching which means it is mainly used for branching based on certain conditions. The entire 32 bits instruction is divided into 8 fields as shown below.
* The first field in the instruction format is known as opcode, also referred as operation code. The opcode is of length 7 bits and is used to determine the type of instruction format.
* B-type instructions encode a 12-bit signed immediate, with the most significant bit **imm[12] in bit [31]** of the instruction, six bits **imm[10:5] in bits [25:30]** of the instruction, four bits **imm[4:1] in bits [11:8]** and one bit **imm[11] on bit[7]**.
* There are two source registers **rs1 and rs2** on which various operations are performed based on certain conditions, and those conditions are defined by **func3** field.
* After performing operations on the source register based on the conditions, it is evaluated that if the condition is true, Program Counter value gets updated by ```PC = Present PC Value + Immediate Value```, and if the condition is false then PC will be given as ```PC = Present PC value + 4 bytes```, which states that PC will move to next instruction set.
* RV32 instructions are word-aligned, which means that address is always defined in the multiple of 4 bytes.
---
### 5. U-type Instruction
In RV32, each instruction is of size 32 bits. In U-type instruction, U stand for Upper Immediate instructions which means it is simply used to transfer the immediate data into the destination register. The entire 32 bits instruction is divided into 3 fields as shown below.

* The first field in the instruction format is known as opcode, also referred as operation code. The opcode is of length 7 bits and is used to determine the type of instruction format.
* The U-type instruction only consists of two instructions, i.e., ```LUI``` and ```AUIPC```.
* For Example, lets take the instruction **lui rd, imm** and understand this instruction.
```lui x15, 0x13579``` : This instruction will be executed and the immediate value 0x13579 will be written in the MSB of the rd x15, and it will look like x15 = 0x13579000.
---
### 6. J-type Instruction
In RV32, each instruction is of size 32 bits. In U-type instruction, J stand for jump, which means that this instruction format is used to implement jump type instruction. The entire 32 bits instruction is divided into 6 fields as shown below.

* The first field in the instruction format is known as **opcode**, also referred as operation code. The opcode is of length 7 bits and is used to determine the type of instruction format.
* The J-type instruction only consists of single instruction, ```JAL```.
* J-type instruction encode 20 bits signed immediate which is divided into four fields.
* The J-type instructions are often used to perform jump to the desired memory location. The address of the desired memory location is defined in the instruction. These instructions are also used to implement loops.
---
<b>*Refer to the following image for better understanding*</b>

![types of instructions](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%203/types%20of%20instructions.png)

## Now let's analyse each instruction one by one:
**Use the object dump command to get the instructions**
![Obj dump](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%203/object%20dump.png)
**Select the 15 unique instructions and write the 32 bit instruction code as shown below**


### 1.  ``` lui a2, 0x1```
* Explanation:
>* The lui (Load Upper Immediate) instruction is used to load a 20-bit immediate value into the upper 20 bits of the destination register.
>* It belongs to the <b>``` U-type ```</b> instruction set.
>* a2 (x12) is the destination register.
>* The immediate value is 0x1 (20 bits: 0000 0000 0000 0000 0001).
* Instruction fields:
>* Opcode for lui = 0110111
>* rd (destination) = a2 = x12 = 01100
>* imm[31:12] = 0x1 (in binary: 0000 0000 0000 0000 0001)
#### 32-bit instruction:```00000000000000000001_01100_0110111```
---
### 2. ``` addi sp, sp, -16 ```
* Explanation:
>* The addi (Add Immediate) instruction adds an immediate value to the source register and stores the result in the destination register.
>* It belongs to the <b>``` I-type ```</b> instruction set.
>* sp (x2) is both the source and destination register.
>* The immediate value is -16 (12-bit signed: 1111 1111 1111 0000).
* Instruction fields:
>* Opcode for addi = 0010011
>* rd (destination) = sp = x2 = 00010
>* rs1 (source) = sp = x2 = 00010
>* func3 = 000
>* imm[11:0] = -16 (in binary: 1111 1111 1111 0000)
#### 32-bit instruction: ```111111111111_00010_000_00010_0010011```
---
### 3. `li a1,100`
* Explanation:
>* The `li` instruction is a **pseudo-instruction** in RISC-V. It is translated into an actual instruction (or a combination of instructions) by the assembler.
>* It belongs to the **I-type instruction set**.
>* a1 (x11) is the destination register.
>* zero (x0) is the source register, which always holds the value 0.
>* The immediate value is 100 (12 bits: 0000 0000 0110 0100)
* Instruction fields:
>* Opcode for addi = 0010011
>* rd (destination) = a1 = x11 = 01011
>* rs1 (source) = zero = x0 = 00000
>* func3 = `000`
>* imm[11:0] = `100` (in binary: `0000 0000 0110 0100`).

#### 32-bit instruction:`000000001100_01011_000_00000_0010011`
---

### 4. ``` sd ra, 8(sp) ```
* Explanation:
>* The sd (Store Doubleword) instruction stores a doubleword (64 bits) from a source register to memory.
>* It belongs to the **```S-type```** instruction set.
>* ra (x1) is the source register.
>* sp (x2) is the base register for the address.
>* The immediate value is 8 (split into imm[11:5] and imm[4:0]).
* Instruction fields:
>* Opcode for sd = 0100011
>* rs1 (base register) = sp = x2 = 00010
>* rs2 (source) = ra = x1 = 00001
>* func3 = 011
>* imm[11:5] = 0000000
>* imm[4:0] = 01000
#### 32-bit instruction: ``` 0000000_00001_00010_011_01000_0100011 ```
---

### 5. ``` jal ra, 1040c ```
* EXplanation:
>* The jal (Jump and Link) instruction jumps to a target address and saves the return address in the destination register.
>* It belongs to the **```J-type```** instruction set.
>* ra (x1) is the destination register.
>* Target address offset = 1040c (adjusted relative offset: 0x40c in 21-bit signed format).
* Intruction fields:
>* Opcode for jal = 1101111
>* rd (destination) = ra = x1 = 00001
>* imm[20|10:1|11|19:12] = 0000 0000 1000 0011 0000
#### 32-bit instruction:``` 00000001000000110000_00001_1101111 ```
---
### 6. ```  ld ra, 8(sp) ```
* Explanation:
>* The ld (Load Doubleword) instruction loads a doubleword (64 bits) from memory into the destination register.
>* It belongs to the **```I-type```** instruction set.
>* ra (x1) is the destination register.
>* sp (x2) is the base register for the address.
>* Immediate value = 8.
* Instruction fields:
>* Opcode for ld = 0000011
>* rd (destination) = ra = x1 = 00001
>* rs1 (base register) = sp = x2 = 00010
>* func3 = 011
>* imm[11:0] = 8 (in binary: 0000 0000 1000)
#### 32-bit instruction:``` 000000001000_00010_011_00001_0000011 ```
---

### 7. ``` auipc a5, 0xffff0 ```
* Explanation:
>* The auipc (Add Upper Immediate to PC) instruction adds a 20-bit immediate value to the current program counter (PC) and stores the result in the destination register.
>* It belongs to the U-type instruction set.
>* a5 (x15) is the destination register.
>* Immediate value = 0xffff0.
* Instruction fields:
>* Opcode for auipc = 0010111
>* rd (destination) = a5 = x15 = 01111
>* imm[31:12] = 0xffff0 (in binary: 1111 1111 1111 1111 0000)
#### 32-bit instruction:```11111111111111110000_01111_0010111```
---
### 8. ``` beqz a5, 100f8  ```
* Explanation:
>* The beqz (Branch if Equal to Zero) instruction is a pseudo-instruction for beq a5, zero, offset.
>* It checks if the value in a5 (x15) equals 0 and branches to the given offset if true.
>* It belongs to the **```B-type**``` instruction set.
>* a5 (x15) is the source register.
>* zero (x0) is the second operand.
>* Offset = 100f8 (adjusted relative offset: 0x0f8).
* Instruction fields:
>* Opcode for beq = 1100011
>* rs1 = a5 = x15 = 01111
>* rs2 = zero = x0 = 00000
>* func3 = 000
>* imm[12|10:5|4:1|11] = 1001111000 (split: imm[12]=1, imm[10:5]=00111, imm[4:1]=1000, imm[11]=0).
#### 32-bit instruction: ```1_001111_1000_01111_000_00000_1100011 ```
---

### 9. ```j 101b4 ```
* Explanation:
>*  The j (Jump) instruction is a pseudo-instruction for jal zero, offset.
>*  It unconditionally jumps to the target address while setting zero (x0) as the destination register (effectively discarding the link value).
>*  It belongs to the **```J-type```** instruction set.
>*  Target address offset = 101b4 (adjusted relative offset: 0x1b4).
*  Instruction fields:
>*  Opcode for jal = 1101111
>*  rd (destination) = zero = x0 = 00000
>*  imm[20|10:1|11|19:12] = 1011010010 (split: imm[20]=1, imm[10:1]=011010010, imm[11]=0, imm[19:12]=00000000).
#### 32-bit instruction:``` 1_0000000_011010010_00000_1101111```

---
### 10. ```sub a2, a2, a0```
* Explanation:
>* The sub (Subtract) instruction subtracts the value in the second source register (a0) from the value in the first source register (a2) and stores the result in the destination register (a2).
>* It belongs to the **`R-type`** instruction set.
>* a2 (x12) is both the destination and first source register.
>* a0 (x10) is the second source register.
* Instruction fields:
>* Opcode for sub = 0110011
>* rd (destination) = a2 = x12 = 01100
>* rs1 (source 1) = a2 = x12 = 01100
>* rs2 (source 2) = a0 = x10 = 01010
>* func3 = 000
>* func7 = 0100000
#### 32-bit instruction: ```0100000_01010_01100_000_01100_0110011```
---

### 11. ```lw a0, 0(sp)```
* Explanation:
>* The lw (Load Word) instruction loads a word (32 bits) from memory into the destination register.
>* It belongs to the **```I-type```** instruction set.
>* a0 (x10) is the destination register.
>* sp (x2) is the base register.
>* Immediate value = 0.
* Instruction fields:
>* Opcode for lw = 0000011
>* rd (destination) = a0 = x10 = 01010
>* rs1 (base register) = sp = x2 = 00010
>* func3 = 010
>* imm[11:0] = 0 (in binary: 0000 0000 0000)
#### 32-bit instruction:```000000000000_00010_010_01010_0000011```
---

### 12. ```lbu a5, 1944(gp)```
* Explanation:
>* The lbu (Load Byte Unsigned) instruction loads an 8-bit unsigned value from memory into the destination register.
>* It belongs to the **`I-type`** instruction set.
>* a5 (x15) is the destination register.
>* gp (x3) is the base register.
>* Immediate value = 1944 (in binary: 0111 1001 1000).
* Instruction fields:
>* Opcode for lbu = 0000011
>* rd (destination) = a5 = x15 = 01111
>* rs1 (base register) = gp = x3 = 00011
>* func3 = 100
>* imm[11:0] = 1944.
#### 32-bit instruction:`01111001000_00011_100_01111_0000011`

---
### 13. `jalr zero`
* Explanation:
>* The jalr (Jump and Link Register) instruction jumps to an address calculated as rs1 + imm and stores the return address in the destination register.
Here, the destination is zero (x0), effectively discarding the return address.
>* imm = 0 and rs1 = zero (x0).
* Instruction fields:
>* Opcode for jalr = 1100111
>* rd (destination) = zero = x0 = 00000
>* rs1 (source) = zero = x0 = 00000
>* func3 = 000
>* imm[11:0] = 0 (in binary: 0000 0000 0000).
#### 32-bit instruction:`000000000000_00000_000_00000_1100111`
---
### 14. `ret`
* Explanation:
>* The ret (Return) instruction is a pseudo-instruction in RISC-V. It is equivalent to `jalr zero, ra, 0`
>* It belongs to the **`I-type`** instruction set.
>* The return address (ra, register x1) contains the address to return to after a function call.
>* Since the destination is zero (x0), no link value is stored.
* Instruction fields:
>* Opcode for jalr = 1100111
>* func3: 000
>* rd (destination) = zero = x0 = 00000
>* rs1 (base register): ra = x1 = 00001
>* func3 = 000
>* imm[11:0] = 0 (in binary: 0000 0000 0000).
#### 32-bit instruction:`000000000000_00001_000_00000_1100111`
---

### 15. `sb a5, 1944(gp)`
* Explanation:
>* The sb (Store Byte) instruction stores the least significant byte (8 bits) from the source register (a5) into memory at an address calculated as the base address in the register (gp) plus an immediate offset (1944).
>* It belongs to the **`S-type`** instruction set.
* Instruction fields:
>* Opcode: 0100011 (for store instructions)
>* func3: 000 (for sb)
>* rs1 (base register): gp = x3 = 00011
>* rs2 (source register): a5 = x15 = 01111
>* imm[11:5]: Upper 7 bits of the immediate value 1944 = 1111001
>* imm[4:0]: Lower 5 bits of the immediate value 1944 = 01000
* Immediate value breakdown:
>* 1944 in binary (12 bits): 0111 1001 1000
>* Upper 7 bits (imm[11:5]): 0111100
>* Lower 5 bits (imm[4:0]): 11000 
#### 32-bit instruction:`0111100_01111_00011_000_11000_0100011`
---


</details>

---

<details>
<summary><b>Task 4:</b> To perform an experiment of Functional Simulation and observe the waveforms of the instructions with the help of RISCV CORE, Netlist and Testbench. </summary>
	
### About iverilog and gtkwave
- Icarus Verilog is an implementation of the Verilog hardware description language.
- GTKWave is a fully featured GTK+ v1. 2 based wave viewer for Unix and Win32 which reads Ver Structural Verilog Compiler generated AET files as well as standard Verilog VCD/EVCD files and allows their viewing.
---

### Installing iverilog and gtkwave

- **For Ubuntu**
 1. Open your terminal and type the following to install iverilog and GTKWave
 ```
 $   sudo apt update
 $   sudo apt install iverilog gtkwave
 ```
2. Create a new directory with your name ```mkdir <your_name>```
3. Create two files by using ```touch``` command as ```chethas_rv32i.v``` and ```chethas_rv32i_tb.v```  
4. Copy the code from the [FILE](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/tree/main/Task%204/Code) and paste it in your verilog netlist and testbench files 
  
  
5. To run and simulate the verilog code, enter the following command:  
	```
	$ iverilog -o chethas_rv32i.out chethas_rv32i_tb.v chethas_rv32i_tb.v
	$ vvp chethas_rv32i.out
	```
6. To see the output simulation waveform in GTKWave, enter the name of dump file in the command:
	```
	$ gtkwave iiitb_rv32i.vcd
	```
 
 ---

 
#### All the instructions in the given verilog file is hard-coded. Hard-coded means that instead of following the RISCV specifications bit pattern, the designer has hard-coded each instructions based on their own pattern. Hence the 32-bits instruction that we generated in Task-3 will not match with the given instruction.  
  
<img width="500" alt="Instructions" src="https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%204/Waveforms/Instructions%20list.png">

  
#### Following are the differences between standard RISCV ISA and the Instruction Set given in the reference repository:  

|  **Operation**  |  **Standard RISCV ISA**  |  **Hardcoded ISA**  |  
|  :----:  |  :----:  |  :----:  |  
|  ADD R6, R2, R1  |  32'h00110333  |  32'h02208300  |  
|  SUB R7, R1, R2  |  32'h402083b3  |  32'h02209380  |  
|  AND R8, R1, R3  |  32'h0030f433  |  32'h0230a400  |  
|  OR R9, R2, R5  |  32'h005164b3  |  32'h02513480  |  
|  XOR R10, R1, R4  |  32'h0040c533  |  32'h0240c500  |  
|  SLT R1, R2, R4  |  32'h0045a0b3  |  32'h02415580  |  
|  ADDI R12, R4, 5  |  32'h004120b3  |  32'h00520600  |  
|  BEQ R0, R0, 15  |  32'h00000f63  |  32'h00f00002  |  
|  SW R3, R1, 2  |  32'h0030a123  |  32'h00209181  |  
|  LW R13, R1, 2  |  32'h0020a683  |  32'h00208681  |  
|  SRL R16, R14, R2  |  32'h0030a123  |  32'h00271803  |
|  SLL R15, R1, R2  |  32'h002097b3  |  32'h00208783  |  

  ---
  
## *Analysing the Output Waveform of various instructions that we have covered in TASK-3*  
**```Instruction 1: ADD R6, R2, R1```**  

![ADD](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%204/Waveforms/waveform%20add.png)

**```Instruction 2: SUB R7, R1, R2```**  
  
![SUB](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%204/Waveforms/waveform%20SUB.png)

**```Instruction 3: AND R8, R1, R3```**  

![AND](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%204/Waveforms/waveform%20AND.png)

**```Instruction 4: OR R9, R2, R5```**  

![OR](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%204/Waveforms/waveform%20OR.png)

**```Instruction 5: XOR R10, R1, R4```**  

![XOR](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%204/Waveforms/waveform%20XOR.png)

**```Instruction 6: SLT R1, R2, R4```**  

![SLT](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%204/Waveforms/waveform%20SLT.png)

**```Instruction 7: ADDI R12, R4, 5```**  

![ADDI](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%204/Waveforms/waveform%20ADDI.png)

**```Instruction 8: BEQ R0, R0, 15```**  
  
![BEQ](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%204/Waveforms/waveform%20BEQ.png)
 
**```Instruction 9: SW R3, R1, 2```**

![sw](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%204/Waveforms/waveform%20SW.png)
  
**```Instruction 10: LW R13, R1, 2```**  

![lw](https://github.com/Chethas01/SAMSUNG-RISC-V-INTERNSHIP/blob/main/Task%204/Waveforms/waveform%20LW.png)

</details>

---

<details>
<summary><b>Task 5:</b> To impliment any digital circuit using VSDsqadron Mini. </summary>
	
# PWM-Based LED Dimming using CH32V003X  

## Overview  
This project demonstrates **PWM-based LED brightness control** using the **CH32V003X RISC-V microcontroller**. Instead of simply turning an LED **ON or OFF**, we use **Pulse Width Modulation (PWM)** to smoothly adjust its brightness.  

### Features  
- **Potentiometer-controlled brightness**:  
  - **Potentiometer (PA1)** → Adjusts the LED brightness smoothly.
- **Smooth LED dimming** using a PWM signal on **PC6**.  
- **Debounce handling** for stable potentiometer readings.  
- Uses **TIM2 timer module** to generate PWM.  

## Components Required  
- **VSDSQUADRON (CH32V003X Board)**  
- **LED** (Any color)  
- **330Ω Resistor** (Current limiting for LED)  
- **Potentiometer (10kΩ)** (For brightness control)  
- **Jumper Wires & Breadboard**  

## Circuit Diagram  
| Component               | VSD Pin         |  
|-------------------------|-----------------------|  
| LED Anode (+)           | PC6 (PWM Output)      |  
| LED Cathode (-)         | GND (via 330Ω Resistor) |  
| Potentiometer (Middle Pin) | PA1 (Analog Input) |  
| Potentiometer Left Pin  | GND                   |  
| Potentiometer Right Pin | 3.3V                  |  

## How It Works  
1. **PWM Generation:** PC6 generates a PWM signal using **TIM2 Timer**.  
2. **Potentiometer Input Handling:**  
   - The potentiometer's analog value on **PA1** is read and used to adjust the **PWM duty cycle** (brightness).  
3. **Brightness Control Logic:**  
   - The duty cycle is scaled from the potentiometer’s analog input (0-3.3V) to the PWM duty cycle (0% to 100%).  
4. **Software Debouncing:** Ensures smooth potentiometer readings and prevents noise from affecting the signal.  

## Code Explanation  
The code:  
- Initializes **GPIO pins** (PC6, PA1).  
- Configures **TIM2 Timer for PWM output** on PC6.  
- **Reads the potentiometer value** from **PA1** and updates the **PWM duty cycle** accordingly.  

## Installation & Usage  
1. **Flash the code** onto the CH32V003X using **MounRiver Studio**.  
2. **Test the circuit**:  
   - Turn the potentiometer to adjust the **LED brightness** smoothly.  

## Future Enhancements  
- **Implement auto-dimming** for a breathing light effect.  
- **Upgrade to RGB LED** with multi-channel PWM.  
- **Add a display** to show the current brightness percentage.
---

**Author:** [P Chethas]  



</details>
