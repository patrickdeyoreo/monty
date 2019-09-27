# Monty
## C - Stacks (LIFO) & Queues (FIFO)

### The Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty Byte Code Files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument. Monty byte code files can contain blank lines (empty or made entirely of whitespace). Any additional text following an opcode and its required argument(s) is not taken into account.

### Instructions
|Opcode|Usage|Description|
|------|-----|-----------|
|`push`|`push N`|Push a value onto the stack|
|`pop`|`pop`|Pop a value off the stack|
|`pall`|`pall`|Print the contents of the stack|
|`pint`|`pint`|Print the topmost value|
|`swap`|`swap`|Swap the two topmost values|
|`add`|`add`|Add the topmost value to its predecessor|
|`sub`|`sub`|Subtract the topmost value from its predecessor|
|`mul`|`mul`|Multiply the topmost value with its predecessor|
|`div`|`div`|Divide the topmost value into its predecessor|
|`mod`|`mod`|Mod the topmost value into its predecessor|
|`nop`|`nop`|Do nothing|
|`pchar`|`pchar`|Print the character corresponding to the topmost value|
|`pstr`|`pstr`|Print a string starting from the top of the stack|
|`rotl`|`rotl`|Rotate values toward the top of the stack|
|`rotr`|`rotr`|Rotate values toward the bottom of the stack|
|`stack`|`stack`|Operate as a "Last-In, First-Out" data structure (default)|
|`queue`|`queue`|Operate as a "First-In, First-Out" data structure|
