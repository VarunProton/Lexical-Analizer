# Lexical Analizer
 A lexical analyzer (or lexer) is the first phase of a compiler, responsible for reading source code and breaking it into meaningful sequences called tokens (e.g., keywords, identifiers, literals). It removes whitespace and comments and checks for invalid tokens, serving as the bridge between the source code and the parser.

-Overview
This project implements a Lexical Analyzer, a crucial component in a compiler that reads source code and breaks it into tokens for further processing. It is designed to identify and categorize tokens such as keywords, identifiers, operators, literals, and delimiters.

-Features
Token Identification: Detects keywords, identifiers, operators, literals, and other language elements.
Error Handling: Recognizes invalid tokens and provides meaningful feedback.
Customizable Rules: Easily modify token recognition rules through lexer.h.
Performance: Efficient tokenization for input of varying complexity.

-Files
*lexer.h
Contains token definitions, regular expressions, and constants for the lexical analyzer.
Provides the necessary declarations for token structures and utility functions.

*main.c
Implements the main logic for scanning the source code.
Processes input, applies lexical rules, and outputs identified tokens.

*How to Use
-Prerequisites
-GCC or any C compiler.
-Basic knowledge of C programming and compilers.

-Compilation
Run the following command to compile the program:

-bash
gcc main.c -o lexical_analyzer  

-Execution
Provide the source code file as input to analyze:

-bash
./lexical_analyzer <input_file>  

-Output
The program will output the list of identified tokens along with their types and positions in the input.

Example:
-Input
c
int main() {  
    int a = 10;  
    printf("Hello, World!\n");  
    return 0;  
}  

-Output
Token: int, Type: Keyword  
Token: main, Type: Identifier  
Token: (, Type: Delimiter  
...  

-Customization
Update token patterns in lexer.h to accommodate new programming language constructs.
Modify main.c to enhance functionality or adapt to specific languages.

-Contributing
Contributions are welcome! Please fork the repository, create a new branch for your feature or fix, and submit a pull request.

-License
This project is licensed under the MIT License.
