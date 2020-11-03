flex scanner.l
yacc -d parser.y
gcc y.tab.c lex.yy.c -w 