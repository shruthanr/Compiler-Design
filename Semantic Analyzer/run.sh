rm ./a.out
yacc sem.y -Wnone
lex sem.l
gcc y.tab.c -ll -ly -w 