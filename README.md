# Instruction-Set-Architecture


### Info:

 	* Developed an I.S.A using two pass assembler which performs 
	  Basic Arithmetic and Logical Operations
	
	* I.S.A which understand user inputs(assembly language codes (32 bits) 
	  and gives desired outputs


### Two pass assembler Implementation with hypothetical Instruction Set Architecture using C.

```
Pass 1 : 	* Read Assembly Language Instructions From Console and create the Symbol Table, 
		  mnemonic op-code table and operand fields and 
		  convert the whole Instructions into Machine Level Code.
		
		* Determine the storage required for each Assembly Language statement 
		  and Update the location counter.
		
		
Pass 2 :	Extract the Instructions from Machine Code File, using translation of op-code 
		and symbolic operands specified by I.S.A
		and generate value defined by different Instructions.

```


**Instructions:**

	• Run "part1.c" by giving Assembly Language Instructions From Console
	
	• then Run "part2.c", and get the desired results.
	

> Sample Program
```
    MOVI $15 R01     // Move value 15 to register R01
    MOVI $25 R02    // Move value 25 to register R01
    ADD R02 R01     // Add value R02 = R02 + R01 and store in register R02
    PRINT R02       // Print R02
    HLT             // End of Program
```
