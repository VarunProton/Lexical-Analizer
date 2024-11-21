#ifndef LEXER_H
#define LEXER_H
 
#define MAX_KEYWORDS 20
#define MAX_TOKEN_SIZE 100
#define MAX_LINE_LENGTH 1024

static FILE *sourceFile = NULL;
static int round = 0;    // ()
static int square = 0;   // []
static int curly = 0;    // {}
static char value[12] ;
static char decimal[32] ;

// Keyword definitions
static const char* keywords[MAX_KEYWORDS] = {
    "int", "float", "return", "if", "else", "while", "for", "do", "break", "continue",
    "char", "double", "void", "switch", "case", "default", "const", "static", "sizeof", "struct"
};

static const char* Integer = "int";

// Operators and special characters
static const char* operators = "+-*/%=!<>|&";
static const char* specialCharacters = ",;{}()[]#\"\'";


typedef enum 
{
    KEYWORD = 1,
    OPERATOR = 2,
    SPECIAL_CHARACTER = 3,
    CONSTANT = 4,
    IDENTIFIER = 5,
    PROCESSOR_DIRECTIVE = 6,
    PRINT_OPERATION = 7,
    EOF_TOKEN = 8,
    ERROR = 8,
    UNKNOWN = 0
} TokenType;

typedef struct 
{
    char lexeme[MAX_TOKEN_SIZE];
    TokenType type;
} Token;

void initializeLexer(char* filename);
int isKeyword(const char* str);
int isOperator(const char* str);
int isSpecialCharacter(char ch);
int isConstant(const char* str);
int isIdentifier(const char* str);
int isHeader(const char* str);
void initBracketCounter(Token* bc);
void processFile();
void analyzeLine(char* line, int lineNumber);
void Errors(const char* line, int lineNumber);
void curly_brackets(char *line);
int isValidInt(const char* str);
int isInteger(const char* str);
int forInt(char* line, char* equals);
int isValidfloat(char* str);

#endif
