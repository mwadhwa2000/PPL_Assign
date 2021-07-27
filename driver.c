#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readGrammar.c"
#include "tokeniseSourceCode.c"
#include "parseTree.c"
#include "typeExpressionTable.c"

int main(int argc, char *argv[])
{
    //INTIALISATION PART
    // Read the grammar.
    grammar *g = malloc(NON_TERMINALS * sizeof(grammar));
    readGrammar("grammar.txt", g);
    // Tokenize the source code
    if (argc == 2)
        tokeniseSourcecode(argv[1], head);
    else
    {
        printf("Please provide the sourcefile.txt as command line\n");
        return 0;
    }
    // Create the parseTree
    //create the start node
    posToken = head;
    parseTree *p = malloc(sizeof(parseTree));
    p->isTerm = 0;
    p->Node.nonTerminal.expRule = NULL;
    p->Node.nonTerminal.nt = s;
    p->parent = p;
    p->sibling = NULL;
    p->firstChild = NULL;
    p->depth = 0;
    p->exp_type.tag = not_app;
   
    int n;
    // Printing the parse tree
    // printParseTree(p);

    // traverse_parse_tree(p);
    // printParseTree(p);
    // printTypeExpressionsTable(table, "typeExpressionTable.txt");
    do
    {
        printf("Option 0:To Exit\n");
        printf("Option 1:Create Parse Tree\n");
        printf("Option 2:Create and Traverse Parse Tree\n");
        printf("Option 3:Create, Traverse Parse Tree and Print Parse Tree\n");
        printf("Option 4:Create, Traverse Parse Tree, Print Parse Tree and Type Expression Table\n");
        printf("Please Choose your option : ");
        scanf("%d", &n);
        switch (n)
        {
        case 0:
            printf("EXITING!!\n");
            break;
        case 1:
            createParseTree(p, g);
            if (posToken != NULL)
            {
                printf("ERROR READING INPUT TESTCASE (IT OCCURS USUALLY IF AN UNKNOWN SYMBOLS APPEAR WHICH CANNOT DOEAS NOT MATCH ANY RULE)\n");
                return 0;
            }
            printf("Parse Tree Created Successfully\n");
            break;
        case 2:
            createParseTree(p, g);
            if (posToken != NULL)
            {
                printf("ERROR READING INPUT TESTCASE (IT OCCURS USUALLY IF AN UNKNOWN SYMBOLS APPEAR WHICH CANNOT DOEAS NOT MATCH ANY RULE)\n");
                return 0;
            }
            traverse_parse_tree(p);
            printf("Errors if any are Printed.\nParse Tree Traversal Successfull.\n");
            break;
        case 3:
            createParseTree(p, g);
            if (posToken != NULL)
            {
                printf("ERROR READING INPUT TESTCASE (IT OCCURS USUALLY IF AN UNKNOWN SYMBOLS APPEAR WHICH CANNOT DOEAS NOT MATCH ANY RULE)\n");
                return 0;
            }
            traverse_parse_tree(p);
            printParseTree(p);
            printf("Errors if any are Printed.\nParse Tree Printing in parseTree.txt and Traversal Successfull.\n");
            break;
        case 4:
            createParseTree(p, g);
            if (posToken != NULL)
            {
                printf("ERROR READING INPUT TESTCASE (IT OCCURS USUALLY IF AN UNKNOWN SYMBOLS APPEAR WHICH CANNOT DOEAS NOT MATCH ANY RULE)\n");
                return 0;
            }
            traverse_parse_tree(p);
            printParseTree(p);
            printTypeExpressionsTable(table, "typeExpressionTable.txt");
            printf("Errors if any are Printed.\nParse Tree Printing in parseTree.txt, Traversal performed and Type Expression Table Printing in typeExpressionTable.txt Successfull.\n");
            break;
        default:
            printf("Sorry! Enter a number between 0-4\n");
            break;
        }
    } while (n != 0);
    return 0;
}
