#!/bin/bash
rm ./a.out
yacc sem.y -Wnone
lex sem.l
gcc y.tab.c -ll -ly -w 
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 1: 		     "
echo "         Symbol table insertion for different scopes"
echo "_______________________________________________________"
cat -n test1.c
echo "-------------------------------------------------------"
echo "          	      Output: 			     "
echo "_______________________________________________________"
./a.out test1.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 2: "
echo "                  Multiple functions"
echo "_______________________________________________________"
cat -n test2.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test2.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 3: "
echo "                 Undeclared variable"
echo "_______________________________________________________"
cat -n test3.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test3.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 4: "
echo "              Redeclaration in same scope"
echo "_______________________________________________________"
cat -n test4.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test4.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 5: "
echo "                     Out of scope	"
echo "_______________________________________________________"
cat -n test5.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test5.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 6: "
echo "                    Type mismatch "
echo "_______________________________________________________"
cat -n test6.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test6.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 7: "
echo "         Redeclaration of pre defined function"
echo "_______________________________________________________"
cat -n test7.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test7.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 8: "
echo "            Return type of function mismatch"
echo "_______________________________________________________"
cat -n test8.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test8.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 9: "
echo "           Same variable different scopes"
echo "_______________________________________________________"
cat -n test9.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test9.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 10: "
echo "                 Different data types"
echo "_______________________________________________________"
cat -n test10.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test10.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 11: "
echo "         Usage of non-array variable with subscript"
echo "_______________________________________________________"
cat -n test11.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test11.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 12: "
echo "                Out of bounds subscript"
echo "_______________________________________________________"
cat -n test12.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test12.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 13: "
echo "         Usage of array identifier without subscript"
echo "_______________________________________________________"
cat -n test13.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test13.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 14: "
echo "       Function call with matching parameter list"
echo "_______________________________________________________"
cat -n test14.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test14.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 15: "
echo "    Function call with differing number of parameters"
echo "_______________________________________________________"
cat -n test15.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test15.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 16: "
echo "         Correct function call for no parameters"
echo "_______________________________________________________"
cat -n test16.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test16.c
echo " "
echo " "
echo "-------------------------------------------------------"
echo "                     Test Case 17: "
echo "     Function call with non matching parameter type"
echo "_______________________________________________________"
cat -n test17.c
echo "-------------------------------------------------------"
echo "                         Output:	"
echo "_______________________________________________________"
./a.out test17.c