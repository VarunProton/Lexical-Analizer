#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

// Initialize the lexer by opening the source file
void initializeLexer(char* filename) {
    sourceFile = fopen(filename, "r");
    if (sourceFile == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        perror("fopen");
    } else {
        printf("INFO: The file '%s' is opened successfully.\n", filename);
    }
}

void processFile() {
    if (sourceFile == NULL) {
        fprintf(stderr, "Error: Source file not opened.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 1;

    while (fgets(line, sizeof(line), sourceFile)) 
    {
        printf("\nProcessing Line %d: %s", lineNumber, line);
        analyzeLine(line, lineNumber);
        Errors(line, lineNumber);
        lineNumber++;
    }
    curly_brackets(line);

    fclose(sourceFile);
}

void curly_brackets(char *line)
{
    if(strstr(line, "}") != NULL)
    {
        curly--;
    }
    if(curly != 0)
    {
        fprintf(stderr, "\nUnbalenced Flower Braces.\n");
    }
}

void analyzeLine(char* line, int lineNumber)
{
    Token token = { .type = UNKNOWN, .lexeme = "" };
    int i = 0;
    char ch;

    while ((ch = line[i++]) != '\0') 
    {
        if (strlen(line) == 0 || line[0] == '\n') continue;

        if (isspace(ch)) continue;
        
        // Track brackets
        switch (ch) 
        {
            case '(': round++; break;
            case ')': round--; break;
            case '[': square++; break;
            case ']': square--; break;
            case '{': curly++; break;
            case '}': curly--; break;
        }

        if (ch == '#') 
        { 
            int j = 0;
            printf("Processor Directive detected\n");
            printf("Header Line = %s\n",line);
            return;
        }

        if (isalpha(ch)) 
        {
            int j = 0;
            while (isalnum(ch) || ch == '_') {
                token.lexeme[j++] = ch;
                ch = line[i++];
            }
            token.lexeme[j] = '\0';
            i--;
            
            if(isInteger(token.lexeme) && curly!=0)
            {
                char* equals = strchr(line + i, '=');

                // Validate the extracted value
                if (forInt(line, equals) == 1) 
                {
                    printf("Valid Integer (Line %d): %s\n", lineNumber, value);
                } 
                else 
                {
                    fprintf(stderr, "Error: Invalid integer '%s' at Line %d.\n", value, lineNumber);
                }
            }
            else if (strstr(token.lexeme,"return") !=NULL)
            {
                char* equals = strchr(line + i, ' ');

                // Validate the extracted value
                if (forInt(line, equals) == 1) 
                {
                    printf("Valid Integer after Return (Line %d): %s\n", lineNumber, value);
                    printf("Return value is valid.\n");
                } 
                else 
                {
                    fprintf(stderr, "Error: Invalid integer '%s' at Line %d.\n", value, lineNumber);
                }
            }
            else if(strstr(token.lexeme, "float") != NULL)
            {
                char* equals = strchr(line + i, '=');
                if (equals != NULL) 
                {
                    equals++; // Move past '='
                    while (isspace(*equals)) equals++; // Skip spaces
                    // Extract content until ';' is found
                    char* semicolon = strchr(equals, ';');
                    if (semicolon != NULL) 
                    {
                        strncpy(decimal, equals, semicolon - equals);
                        decimal[semicolon - equals] = '\0'; // Null-terminate the extracted value

                        if(isValidfloat(decimal) == 1)
                        {
                            printf("Valid Float (Line %d): %s\n", lineNumber, decimal);
                        }
                        else
                        {
                            fprintf(stderr, "Error: Invalid float '%s' at Line %d.\n", value, lineNumber);
                        }
                    }
                }
            }
            else if(strstr(token.lexeme, "printf") != NULL)
            {
                printf("Printing the statement.\n");
                return;
            }
            else if (isKeyword(token.lexeme)) 
            {
                token.type = KEYWORD;
                printf("Keyword: %s\n", token.lexeme);
                continue;
            }
            else 
            {
                token.type = IDENTIFIER;
                printf("Identifier: %s\n", token.lexeme);
            }
        
        }
         
        else if (isdigit(ch)) 
        {
            int j = 0;
            while (isdigit(ch)) 
            {
                token.lexeme[j++] = ch;
                ch = line[i++];
            }
            token.lexeme[j] = '\0';
            i--;
            token.type = CONSTANT;
            printf("Constant: %s\n", token.lexeme);
        } 
        else if (isOperator(&ch)) 
        {
            printf("Operator: %c\n", ch);
        } 
        else if (isSpecialCharacter(ch)) 
        {
            printf("Special Character: %c\n", ch);
        } 
        else 
        {
            fprintf(stderr, "Syntax Error at Line %d: Unexpected character '%c'.\n", lineNumber, ch);
        }
    }
}
