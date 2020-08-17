lex scanner.l
gcc -c -w lex.yy.c
gcc -w code.c lex.yy.o
./a.out 
rm lex.yy.o lex.yy.c a.out