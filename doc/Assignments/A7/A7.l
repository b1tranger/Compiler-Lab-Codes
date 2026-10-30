%{
#include <stdio.h>
%}

/* Definitions / Shorthands */
DIGIT       [0-9]
FLOAT       [+-]?{DIGIT}+\.{DIGIT}+([eE][+-]?{DIGIT}+)?
POS_INT     \+?{DIGIT}+
NEG_INT     -{DIGIT}+
CUSTOM_ID   [A-Z][a-z_!@#$%^&*()\-+=~`[\]{}|;:'",.<>?/]+
WS          [ \t\r\n]+

%%

    /* 1. C Standard Keywords */
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"    { printf("[C KEYWORD]: %s\n", yytext); }
"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"     { printf("[C KEYWORD]: %s\n", yytext); }
"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"  { printf("[C KEYWORD]: %s\n", yytext); }
"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"            { printf("[C KEYWORD]: %s\n", yytext); }

    /* 2. Floating-Point Numbers */
{FLOAT}         { printf("[FLOATING POINT]: %s\n", yytext); }

    /* 3. Integers */
{NEG_INT}       { printf("[NEGATIVE INTEGER]: %s\n", yytext); }
{POS_INT}       { printf("[POSITIVE INTEGER]: %s\n", yytext); }

    /* 4. Custom Identifier */
{CUSTOM_ID}     { printf("[CUSTOM ID]: %s\n", yytext); }

    /* Skip Whitespace */
{WS}            { /* ignore whitespace */ }

    /* Catch-all for unrecognized characters */
.               { printf("[UNRECOGNIZED]: %s\n", yytext); }

%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) {
            perror("Error opening file");
            return 1;
        }
        yyin = fp;
    }
    yylex();
    return 0;
}