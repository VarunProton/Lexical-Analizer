#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

int forInt(char* line, char* equals)
{
    if (equals != NULL) 
    {
        equals++; // Move past '='
        while (isspace(*equals)) equals++; // Skip spaces

        // Extract content until ';' is found
        char* semicolon = strchr(equals, ';');
        if (semicolon != NULL) 
        {
            strncpy(value, equals, semicolon - equals);
            value[semicolon - equals] = '\0'; // Null-terminate the extracted value

            // Validate the extracted value
            if (isValidInt(value)) 
            {
                return 1;
            } 
            else 
            {
                return 0;
            }
        }
    }
}

// Predict errors in the line
void Errors(const char* line, int lineNumber)
{
    int inQuotes = 0;
    int inDoubleQuotes = 0;

    for (int i = 0; line[i] != '\0'; i++) 
    {
        char ch = line[i];

        if (ch == '\'' && !inDoubleQuotes) inQuotes = !inQuotes;
        if (ch == '\"' && !inQuotes) inDoubleQuotes = !inDoubleQuotes;
    }

    if (round != 0 || square != 0) 
    {
        fprintf(stderr, "Error at Line %d: Unbalanced brackets.\n", lineNumber);
    }
    if (inQuotes) 
    {
        fprintf(stderr, "Error at Line %d: Unmatched single quote.\n", lineNumber);
    }
    if (inDoubleQuotes) 
    {
        fprintf(stderr, "Error at Line %d: Unmatched double quote.\n", lineNumber);
    }
    if (!strstr(line, ";") && !strstr(line, "if") && !strstr(line, "while") && !strstr(line, "for") && !strstr(line, "#") && !strstr(line, "()") && !strstr(line, "{") && !strstr(line, "}")) 
    {
        fprintf(stderr, "Error at Line %d: Missing semicolon at the end.\n", lineNumber);
    }
}

// Check if the string is a keyword
int isKeyword(const char* str) 
{
    for (int i = 0; i < MAX_KEYWORDS; i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return 1;
        }
    }
    return 0;
}

int isInteger(const char* str)
{
    if(strstr(str, "int")!=NULL)
        return 1;
    else    return 0;
}

// Check if the character is an operator
int isOperator(const char* str) 
{
    return strchr(operators, *str) != NULL;
}

// Check if the character is a special character
int isSpecialCharacter(char ch) 
{
    return strchr(specialCharacters, ch) != NULL;
}


// Function to check if a string represents a valid integer in decimal, octal, or hexadecimal
int isValidInt(const char* str) {
    int i = 0;

    // Handle optional '+' or '-' sign
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }

    // Check if string is empty after handling sign
    if (str[i] == '\0') {
        return 0; // Not valid
    }

    // Hexadecimal (starts with 0x or 0X)
    if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')) {
        i += 2; // Skip '0x'
        if (str[i] == '\0') {
            return 0; // Not valid, no digits after '0x'
        }
        // Check for valid hexadecimal digits
        while (str[i] != '\0') {
            if (!isxdigit(str[i])) {
                return 0; // Invalid character
            }
            i++;
        }
        return 1; // Valid hexadecimal
    }

    // Octal (starts with 0, but not 0x/0X)
    if (str[i] == '0') {
        i++; // Skip leading '0'
        if (str[i] == '\0') {
            return 1; // Valid octal (just '0')
        }
        // Check for valid octal digits
        while (str[i] != '\0') {
            if (str[i] < '0' || str[i] > '7') {
                return 0; // Invalid character
            }
            i++;
        }
        return 1; // Valid octal
    }

    // Decimal (no prefix, only digits)
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0; // Invalid character
        }
        i++;
    }
    return 1; // Valid decimal
}

int isValidfloat(char* str)
{
    int len = strlen(str);
    int i = 0;
    // Empty string is not a float
    if (len == 0) 
    {
        return 0;
    }
    // Optional sign
    if (str[i] == '+' || str[i] == '-') 
    {
        i++;
    }
    // Scan the digits
    for (; i < len; i++) 
    {
        if (isdigit(str[i]))  continue;
        else if (str[i] == '.' )  continue;
        else  return 0;
    }
    return 1;
}