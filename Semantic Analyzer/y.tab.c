/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sem.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>

	struct symbol_table_structure
	{
		int sno;
		char token[100];
		int type[100];
		int tn;
		int addr;
		float fvalue;
		int scope;
		int arrFlag;
		int funcFlag;
		int fType[100]; 
		int numParams; 
	}Symbol_Table[100];

	int var_addr = 0;
	int scope_incrementer=1;
	int j=8;
	int scope_stack[100];
	int index1=0;
	int end[100];
	int return_types[10];
	int gl1,gl2,curr_type=0,c=0,b;
	int type=258;
	int fname[100];
	int nP;
	int fTypes[100];
	int fTypes2[100];
	int temptype;
	int it;
	int temp;

	int n=0, return_types[10];

	void storereturn( int curr_type, int returntype )
	{
		return_types[curr_type] = returntype;
		return;
	}

	void insertscope(char *a,int s)
	{
		int i;
		for (i=0;i<n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token))
			{
				Symbol_Table[i].scope=s;
				break;
			}
		}
	}

	int returntype_func(int ct)
	{
		return return_types[ct-1];
	}

	int isArray(char* a)
	{
		int i;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token))
			{
				if (Symbol_Table[i].arrFlag==1)
					return Symbol_Table[i].fvalue;
						else
							return 0;
			}
		}
		return 0;
	}

	int retNumParams(char* a)
	{
		int i;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token))
			{
				return Symbol_Table[i].numParams;
			}
		}
		return 0;
	}

	void getParams(char* a)
	{
		int i;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token))
			{
				for (int j=0; j<Symbol_Table[i].numParams; j++)
					fTypes[j] = Symbol_Table[i].fType[j]; 
			}
		}
		return 0;
	}
	int returnScope(char *a,int cs)
	{
		//printf("\nString is: %s", a);
		int i;
		int max = 0;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token))
			{
				if (Symbol_Table[i].scope>=max)
					max = Symbol_Table[i].scope;
			}
		}
		return max;
	}

	int lookup(char *a)
	{
		int i;
		for (i=0;i<n;i++)
		{
			if ( !strcmp( a, Symbol_Table[i].token) )
				return 0;
		}
		return 1;
	}

	int returntype(char *a,int scope_curr)
	{
		int i;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token) && Symbol_Table[i].scope==scope_curr)
				return Symbol_Table[i].type[0];
		}
	}

	void update_value(char *a,char *b,int sc)
	{
		int i,j,k;
		int max=0;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token)   && sc>=Symbol_Table[i].scope)
			{
				if (Symbol_Table[i].scope>=max)
					max=Symbol_Table[i].scope;
			}
		}
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token)   && max==Symbol_Table[i].scope)
			{
				float temp=atof(b);
				for (k=0;k<Symbol_Table[i].tn;k++)
				{
					if (Symbol_Table[i].type[k]==258||Symbol_Table[i].type[0]==269)
						Symbol_Table[i].fvalue=(int)temp;
					else
						Symbol_Table[i].fvalue=temp;
				}
			}
		}
	}

	void insert(char *name, int type, int addr, int arrFlag, int funcStatus)
	{
		int i;
		if (lookup(name))
		{
			strcpy(Symbol_Table[n].token,name);
			if (funcStatus == 1)
				Symbol_Table[n].funcFlag=1;
			Symbol_Table[n].tn=1;
			Symbol_Table[n].type[Symbol_Table[n].tn-1]=type;
			Symbol_Table[n].addr=addr;
			Symbol_Table[n].sno=n+1;
			Symbol_Table[n].arrFlag = arrFlag;
			n++;
		}
		else
		{
			if (funcStatus == 1)
				Symbol_Table[n].funcFlag=1;
			for (i=0;i<n;i++)
			{
				if (!strcmp(name,Symbol_Table[i].token))
				{
					Symbol_Table[i].tn++;
					Symbol_Table[i].type[Symbol_Table[i].tn-1]=type;
					break;
				}
			}
		}

		return;
	}
	void insertFunc(char *name, int type, int addr, int arrFlag, int params[100], int numParams)
	{
		int i;
		if (lookup(name))
		{
			strcpy(Symbol_Table[n].token,name);
			Symbol_Table[n].tn=1;
			Symbol_Table[n].type[Symbol_Table[n].tn-1]=type;
			Symbol_Table[n].addr=addr;
			Symbol_Table[n].sno=n+1;
			Symbol_Table[n].arrFlag = arrFlag;
			Symbol_Table[n].funcFlag = 1;
			for (int j=0; j<numParams; j++)
				Symbol_Table[n].fType[j] = params[j];
			Symbol_Table[n].numParams = numParams;
			n++;
		}
		else
		{
			for (i=0;i<n;i++)
			{
				if (!strcmp(name,Symbol_Table[i].token))
				{
					Symbol_Table[i].tn++;
					Symbol_Table[i].type[Symbol_Table[i].tn-1]=type;
					break;
				}
			}
		}

		return;
	}
	void insert_dup(char *name, int type, int addr,int s_c, int arrFlag)
	{
		strcpy(Symbol_Table[n].token,name);
		Symbol_Table[n].tn=1;
		Symbol_Table[n].type[Symbol_Table[n].tn-1]=type;
		Symbol_Table[n].addr=addr;
		Symbol_Table[n].sno=n+1;
		Symbol_Table[n].scope=s_c;
		Symbol_Table[n].arrFlag=arrFlag;
		n++;
		return;
	}

	void print()
	{
		int i,j;
		printf("\n------------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t\tSYMBOL TABLE\n");
		printf("------------------------------------------------------------------------------------------");
		printf("\nToken\tValue\tScope\tisArray\tArrayDim\tType\tReturn Type\tArguments\n");
		for (i=0;i<n;i++)
		{
			if (Symbol_Table[i].type[0]==258 || Symbol_Table[i].type[0]==261|| Symbol_Table[i].type[0]==262|| Symbol_Table[i].type[0]==263)
				printf("%s\t%d\t%d\tFalse\t-\t",Symbol_Table[i].token,(int)Symbol_Table[i].fvalue,Symbol_Table[i].scope);
			else
			{
				if (Symbol_Table[i].arrFlag)
					printf("%s\t-\t%d\tTrue\t%d\t",Symbol_Table[i].token,Symbol_Table[i].scope, (int)Symbol_Table[i].fvalue);
				else if (Symbol_Table[i].type[0]==274)
					printf("%s\t-\t%d\tFalse\t-\t",Symbol_Table[i].token,Symbol_Table[i].scope);
				else
					printf("%s\t%.1f\t%d\tFalse\t-\t",Symbol_Table[i].token,Symbol_Table[i].fvalue,Symbol_Table[i].scope);
			}
			

			for (j=0;j<Symbol_Table[i].tn;j++)
			{
				if (Symbol_Table[i].type[j]==258)
					printf("\tINT");
				else if (Symbol_Table[i].type[j]==259)
					printf("\tFLOAT");
				else if (Symbol_Table[i].type[j]==274)
					printf("\tFUNCTION");
				else if (Symbol_Table[i].type[j]==269)
					printf("\tARRAY");
				else if (Symbol_Table[i].type[j]==260)
					printf("\tVOID");
				else if (Symbol_Table[i].type[j]==261)
			  		printf("\tUNSIGNED INT");
				else if (Symbol_Table[i].type[j]==263)
			    		printf("\tLONG INT");
				else if (Symbol_Table[i].type[j]==262)
			      		printf("\tSHORT INT");
			}
			printf("\t");
			for (int j=0;j<Symbol_Table[i].numParams;j++)
			{
				if (Symbol_Table[i].fType[j]==258)
					printf("INT,");
				else if (Symbol_Table[i].fType[j]==259)
					printf("FLOAT,");
				else if (Symbol_Table[i].fType[j]==274)
					printf("FUNCTION,");
				else if (Symbol_Table[i].fType[j]==269)
					printf("ARRAY,");
				else if (Symbol_Table[i].fType[j]==260)
					printf("VOID,");
				else if (Symbol_Table[i].fType[j]==261)
			  		printf("UNSIGNED INT,");
				else if (Symbol_Table[i].fType[j]==263)
			    		printf("LONG INT,");
				else if (Symbol_Table[i].fType[j]==262)
			      		printf("SHORT INT,");
			}
			printf("\n");
		}
		return;
	}

#line 379 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    UNSIGNED_INT = 261,
    S_INT = 262,
    L_INT = 263,
    ID = 264,
    INT_CONST = 265,
    FLOAT_CONST = 266,
    WHILE = 267,
    FOR = 268,
    IF = 269,
    RETURN = 270,
    PREPROC = 271,
    STRING = 272,
    PRINT = 273,
    FUNCTION = 274,
    ARRAY = 275,
    ELSE = 276,
    INCR = 277,
    DECR = 278,
    EQUAL = 279,
    LE = 280,
    LT = 281,
    GE = 282,
    GT = 283,
    MOD = 284
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define UNSIGNED_INT 261
#define S_INT 262
#define L_INT 263
#define ID 264
#define INT_CONST 265
#define FLOAT_CONST 266
#define WHILE 267
#define FOR 268
#define IF 269
#define RETURN 270
#define PREPROC 271
#define STRING 272
#define PRINT 273
#define FUNCTION 274
#define ARRAY 275
#define ELSE 276
#define INCR 277
#define DECR 278
#define EQUAL 279
#define LE 280
#define LT 281
#define GE 282
#define GT 283
#define MOD 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 331 "sem.y" /* yacc.c:355  */

		int ival;
		char *str;
	

#line 480 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 497 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   302

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    34,    32,    31,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   338,   338,   339,   340,   341,   345,   361,   379,   380,
     383,   384,   385,   386,   387,   388,   392,   396,   397,   398,
     402,   403,   404,   405,   406,   407,   413,   414,   415,   416,
     417,   420,   437,   447,   448,   449,   450,   454,   455,   459,
     463,   466,   467,   468,   469,   470,   471,   472,   475,   494,
     502,   503,   504,   512,   513,   516,   531,   557,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   606,   607,   611,   638,   659,   671,   683
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "UNSIGNED_INT",
  "S_INT", "L_INT", "ID", "INT_CONST", "FLOAT_CONST", "WHILE", "FOR", "IF",
  "RETURN", "PREPROC", "STRING", "PRINT", "FUNCTION", "ARRAY", "ELSE",
  "INCR", "DECR", "EQUAL", "LE", "LT", "GE", "GT", "MOD", "'='", "','",
  "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'", "'['",
  "']'", "$accept", "start", "Function", "param_list", "Type",
  "compound_stmt", "statement_list", "stmt", "function_call", "call_list",
  "if_stmt", "while_stmt", "for_stmt", "expr1", "secondary_assignment",
  "assignment_exp", "exp", "consttype", "Declaration", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      61,    44,    43,    45,    42,    47,    40,    41,   123,   125,
      59,    91,    93
};
# endif

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -68

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     139,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   157,   -83,
     -83,   139,   142,   142,   142,    66,   139,    59,    45,   -83,
     -18,   221,   139,   147,   147,    82,   -83,    53,    67,   -83,
      67,   171,   -83,   -83,   177,   -83,   -83,   -83,    87,   142,
     142,   142,   142,   147,   -83,   -83,   -83,    71,   112,   142,
     142,   142,   142,   -83,    47,    18,   -83,   117,   -83,   259,
     259,   173,   173,   -83,    99,    88,   137,   203,    94,   205,
     101,   116,   -28,   154,   126,   142,   -83,   -83,   -83,   -83,
     -83,   -83,   116,   -83,   294,   116,   -83,   141,   -18,   -83,
      97,   167,   -83,   -83,   255,   146,   148,   149,     9,   161,
     -83,   -83,   168,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,    51,   147,   147,   147,   -83,   159,   184,    84,   -83,
     172,    56,   -83,   233,   -83,    50,   238,   -83,   136,   -83,
     220,   174,   147,   147,   147,   147,   147,   116,   147,   116,
     142,   175,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,    55,   190,   187,   -83,   147,   116,   183,   252,   -83,
     -83,   116,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    79,    10,    11,    12,    13,    14,    15,    52,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      53,    54,     0,     0,     0,     0,     3,    56,    69,    67,
      70,     0,     1,     2,     0,    77,    71,    72,     0,     0,
       0,     0,     0,     0,     4,    48,    49,     0,     0,     0,
       0,     0,     0,    68,     0,     0,    76,     0,    62,    58,
      59,    60,    61,    51,    57,     0,    58,    59,    60,    61,
       0,     0,     0,     0,     0,     0,    57,    63,    64,    65,
      66,    75,    19,     6,     0,     0,     8,     0,    55,    18,
       0,     0,     7,    78,    56,     0,     0,     0,     0,     0,
      16,    27,     0,    30,    17,    24,    21,    22,    23,    20,
       9,     0,    47,    47,    47,    26,     0,     0,     0,    33,
       0,     0,    34,     0,    46,     0,     0,    25,     0,    32,
       0,     0,    47,    47,    47,    47,    47,     0,    47,     0,
       0,     0,    35,    36,    31,    45,    41,    42,    43,    44,
      39,     0,    37,     0,    29,    47,     0,     0,     0,    38,
      28,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   110,   -83,   -83,   -43,   -72,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -82,    48,   -83,    -6,   -12,   143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    16,    72,    17,    83,    90,   104,   105,   121,
     106,   107,   108,   123,   124,    19,    20,    21,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    29,    29,    84,    36,    37,    28,    30,    31,    85,
      89,    38,    73,    92,    39,    40,    41,    42,   103,     9,
      10,     2,     3,     4,     5,     6,     7,    29,    29,    29,
      29,   125,   126,    59,    60,    61,    62,    29,    29,    29,
      29,    91,    70,    66,    67,    68,    69,   102,    18,   115,
     145,   146,   147,   148,   149,    71,   151,     9,    10,    18,
     119,     9,    10,    29,    18,   150,    32,   152,    34,    88,
      18,    45,    46,   158,   132,   133,   134,   135,   136,   132,
     133,   134,   135,   136,   159,    35,   116,   130,   120,   162,
     138,    63,    47,   131,    48,   155,    38,    58,     1,   122,
       2,     3,     4,     5,     6,     7,    94,     9,    10,    95,
      96,    97,    98,    64,    54,    99,    36,    37,   143,    12,
      13,    26,    65,    38,    56,    57,    33,    74,    29,    75,
      76,    79,    44,    14,   153,    82,   100,   101,    18,    -5,
       1,    81,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    27,     9,    10,    82,    11,     8,     9,    10,    36,
      37,    12,    13,    86,    12,    13,    38,   140,    87,    12,
      13,    41,    42,   141,    77,    14,   110,   118,    14,   -56,
     -56,    93,   112,    14,   113,   114,   -56,    23,    24,   -56,
     -56,   -56,   -56,    36,    37,    36,    37,   117,    25,   127,
      38,   128,    38,    49,    50,    51,    52,    54,    53,    36,
      37,   156,   129,    55,   144,   154,    38,    56,    57,    39,
      40,    41,    42,   160,   157,    36,    37,    36,    37,   142,
       9,    10,    38,   109,    38,     0,     0,    41,    42,     0,
      78,     0,    80,   -67,   -67,     0,     0,     0,     0,     0,
     -67,     0,    43,   -67,   -67,   -67,   -67,   132,   133,   134,
     135,   136,   132,   133,   134,   135,   136,     0,     0,     0,
     137,     0,     0,     0,     0,   139,   132,   133,   134,   135,
     136,    36,    37,     0,     0,    23,    24,     0,    38,   161,
       0,   111,     0,    41,    42,   -52,    25,     2,     3,     4,
       5,     6,     7
};

static const yytype_int16 yycheck[] =
{
      12,    13,    14,    31,    22,    23,    12,    13,    14,    37,
      82,    29,    55,    85,    32,    33,    34,    35,    90,    10,
      11,     3,     4,     5,     6,     7,     8,    39,    40,    41,
      42,   113,   114,    39,    40,    41,    42,    49,    50,    51,
      52,    84,    54,    49,    50,    51,    52,    90,     0,    40,
     132,   133,   134,   135,   136,    37,   138,    10,    11,    11,
       9,    10,    11,    75,    16,   137,     0,   139,     9,    75,
      22,    23,    24,   155,    24,    25,    26,    27,    28,    24,
      25,    26,    27,    28,   156,    40,    98,    31,    37,   161,
      40,    43,    10,    37,    41,    40,    29,    10,     1,   111,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    42,    30,    18,    22,    23,   130,    22,
      23,    11,    10,    29,    40,    41,    16,    10,   140,    30,
      42,    37,    22,    36,   140,    38,    39,    40,    90,     0,
       1,    40,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     9,    10,    11,    38,    16,     9,    10,    11,    22,
      23,    22,    23,     9,    22,    23,    29,    31,    42,    22,
      23,    34,    35,    37,    37,    36,     9,     9,    36,    22,
      23,    40,    36,    36,    36,    36,    29,    30,    31,    32,
      33,    34,    35,    22,    23,    22,    23,    36,    41,    40,
      29,    17,    29,    32,    33,    34,    35,    30,    37,    22,
      23,    21,    40,    36,    40,    40,    29,    40,    41,    32,
      33,    34,    35,    40,    37,    22,    23,    22,    23,     9,
      10,    11,    29,    90,    29,    -1,    -1,    34,    35,    -1,
      37,    -1,    37,    22,    23,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    31,    32,    33,    34,    35,    24,    25,    26,
      27,    28,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    37,    24,    25,    26,    27,
      28,    22,    23,    -1,    -1,    30,    31,    -1,    29,    37,
      -1,    36,    -1,    34,    35,    40,    41,     3,     4,     5,
       6,     7,     8
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    16,    22,    23,    36,    44,    45,    47,    57,    58,
      59,    60,    61,    30,    31,    41,    44,     9,    59,    60,
      59,    59,     0,    44,     9,    40,    22,    23,    29,    32,
      33,    34,    35,    31,    44,    57,    57,    10,    41,    32,
      33,    34,    35,    37,    30,    36,    40,    41,    10,    59,
      59,    59,    59,    57,    42,    10,    59,    59,    59,    59,
      60,    37,    46,    47,    10,    30,    42,    37,    37,    37,
      37,    40,    38,    48,    31,    37,     9,    42,    59,    48,
      49,    47,    48,    40,     9,    12,    13,    14,    15,    18,
      39,    40,    47,    48,    50,    51,    53,    54,    55,    61,
       9,    36,    36,    36,    36,    40,    60,    36,     9,     9,
      37,    52,    60,    56,    57,    56,    56,    40,    17,    40,
      31,    37,    24,    25,    26,    27,    28,    37,    40,    37,
      31,    37,     9,    60,    40,    56,    56,    56,    56,    56,
      48,    56,    48,    59,    40,    40,    21,    37,    56,    48,
      40,    37,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    44,    44,    45,    45,    46,    46,
      47,    47,    47,    47,    47,    47,    48,    49,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    51,    51,    52,    52,    52,    52,    53,    53,    54,
      55,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     5,     6,     2,     4,
       1,     1,     1,     1,     1,     1,     3,     2,     1,     0,
       1,     1,     1,     1,     1,     3,     2,     1,     7,     5,
       1,     5,     4,     1,     1,     3,     3,     5,     7,     5,
       9,     3,     3,     3,     3,     3,     1,     0,     3,     3,
       1,     3,     1,     1,     1,     6,     1,     4,     3,     3,
       3,     3,     3,     5,     5,     5,     5,     1,     3,     2,
       2,     2,     2,     1,     1,     5,     3,     2,     6,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 345 "sem.y" /* yacc.c:1646  */
    {
	 
	if ((yyvsp[-4].ival)!=returntype_func(curr_type))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}

	if (!(strcmp((yyvsp[-3].str),"printf") && strcmp((yyvsp[-3].str),"scanf") && strcmp((yyvsp[-3].str),"getc") && strcmp((yyvsp[-3].str),"gets") && strcmp((yyvsp[-3].str),"getchar") && strcmp	((yyvsp[-3].str),"puts") && strcmp((yyvsp[-3].str),"putchar") && strcmp((yyvsp[-3].str),"clearerr") && strcmp((yyvsp[-3].str),"getw") && strcmp((yyvsp[-3].str),"putw") && strcmp((yyvsp[-3].str),"putc") && strcmp((yyvsp[-3].str),"rewind") && strcmp((yyvsp[-3].str),"sprint") && strcmp((yyvsp[-3].str),"sscanf") && strcmp((yyvsp[-3].str),"remove") && strcmp((yyvsp[-3].str),"fflush")))
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-3].str),printline());
	else
	{
		insert((yyvsp[-3].str),FUNCTION,var_addr, 0, 1);
		insert((yyvsp[-3].str),(yyvsp[-4].ival),var_addr, 0, 0);
		var_addr+=4;
	}
	}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 361 "sem.y" /* yacc.c:1646  */
    {
	

	if ((yyvsp[-5].ival)!=returntype_func(curr_type))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}

	if (!(strcmp((yyvsp[-4].str),"printf") && strcmp((yyvsp[-4].str),"scanf") && strcmp((yyvsp[-4].str),"getc") && strcmp((yyvsp[-4].str),"gets") && strcmp((yyvsp[-4].str),"getchar") && strcmp	((yyvsp[-4].str),"puts") && strcmp((yyvsp[-4].str),"putchar") && strcmp((yyvsp[-4].str),"clearerr") && strcmp((yyvsp[-4].str),"getw") && strcmp((yyvsp[-4].str),"putw") && strcmp((yyvsp[-4].str),"putc") && strcmp((yyvsp[-4].str),"rewind") && strcmp((yyvsp[-4].str),"sprint") && strcmp((yyvsp[-4].str),"sscanf") && strcmp((yyvsp[-4].str),"remove") && strcmp((yyvsp[-4].str),"fflush")))
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-4].str),printline());
	else
	{
		insertFunc((yyvsp[-4].str),FUNCTION,var_addr, 0, fname, nP);
		insert((yyvsp[-4].str),(yyvsp[-5].ival),var_addr, 0, 0);
		var_addr+=4;
	}
	}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 379 "sem.y" /* yacc.c:1646  */
    { nP = 1; fname[nP-1] = (yyvsp[-1].ival); }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 380 "sem.y" /* yacc.c:1646  */
    { nP++; fname[nP-1] = (yyvsp[-1].ival); }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 407 "sem.y" /* yacc.c:1646  */
    {
					if (!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str))))
						storereturn(curr_type,FLOAT);
					else
						storereturn(curr_type,INT); curr_type++;
				}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 413 "sem.y" /* yacc.c:1646  */
    {storereturn(curr_type,VOID); curr_type++;}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 420 "sem.y" /* yacc.c:1646  */
    {
	if (lookup((yyvsp[-4].str)))
		printf("\nError: Undeclared function %s : Line %d\n", (yyvsp[-4].str), printline());
	else
	{
		if (retNumParams((yyvsp[-4].str)) == 0)
			printf("\nError : Parameter list does not match signature : Line %d\n", printline()); 
		getParams((yyvsp[-4].str));				
	}

	for (int j=0; j<retNumParams((yyvsp[-4].str)); j++)
	{
		if (fTypes[j] != fTypes2[j])
			printf("\nError : Parameter list does not match signature : Line %d\n", printline());
	}
	
}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 437 "sem.y" /* yacc.c:1646  */
    {
	if (lookup((yyvsp[-3].str)))
		printf("\nError: Undeclared function %s : Line %d\n", (yyvsp[-3].str), printline());
	else
	{
		if (retNumParams((yyvsp[-3].str)) != 0)
			printf("\nError : Parameter list does not match signature : Line %d\n", printline()); 
	}
}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 447 "sem.y" /* yacc.c:1646  */
    { temptype = returntype((yyvsp[0].str), scope_stack[index1-1]); it = 0; fTypes2[it] = temptype; }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 448 "sem.y" /* yacc.c:1646  */
    { temptype = temp; it = 0; fTypes2[it] = temptype; }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 449 "sem.y" /* yacc.c:1646  */
    { it++; temptype = returntype((yyvsp[0].str), scope_stack[index1-1]); fTypes2[it] = temptype;}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 450 "sem.y" /* yacc.c:1646  */
    { temptype = temp; it++; fTypes2[it] = temptype;}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 476 "sem.y" /* yacc.c:1646  */
    {
	  c=0;
		int scope_curr=returnScope((yyvsp[-2].str),scope_stack[index1-1]);
		int type=returntype((yyvsp[-2].str),scope_curr);
		if ((!(strspn((yyvsp[0].str),"0123456789")==strlen((yyvsp[0].str)))) && type==258)
			printf("\nError : Type Mismatch : Line %d\n",printline());
		if (!lookup((yyvsp[-2].str)))
		{
			int curr_scope=scope_stack[index1-1];
			int scope=returnScope((yyvsp[-2].str),curr_scope);
			if ((scope<=curr_scope && end[scope]==0) && !(scope==0))
				update_value((yyvsp[-2].str),(yyvsp[0].str),curr_scope);
		}
		if (isArray((yyvsp[-2].str)))
				printf("\nError: array Identfier has no subscript: Line %d\n", printline());

		}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 494 "sem.y" /* yacc.c:1646  */
    {
					if (lookup((yyvsp[-2].str)))
						printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),printline());

						if (isArray((yyvsp[-2].str)))
								printf("\nError: array identfier has no subscript: Line %d\n", printline());

				}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 504 "sem.y" /* yacc.c:1646  */
    {
		if (lookup((yyvsp[0].str)))
			printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());

			if (isArray((yyvsp[0].str)))
				printf("\nError: Non-array variable used as an array: Line %d\n", printline());

		}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 516 "sem.y" /* yacc.c:1646  */
    {
			if (lookup((yyvsp[-5].str)))
				printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-5].str),printline());

			if (isArray((yyvsp[-5].str))==0)
				printf("\nError: Non-array variable used as an array: Line %d\n", printline());

				float bound = isArray((yyvsp[-5].str));

				if (isArray((yyvsp[-5].str)) && (atoi((yyvsp[-3].str)) >= bound || atoi((yyvsp[-3].str)) < 0))
					printf("\nError: array subscript out of bounds : Line %d\n", printline());

		}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 531 "sem.y" /* yacc.c:1646  */
    {
	if (isArray((yyvsp[0].str)))
	 printf("\nError: array identifier has no subscript: Line %d\n", printline());

	if (c==0)
	{
		c=1;
		int scope_curr=returnScope((yyvsp[0].str),scope_stack[index1-1]);
		b=returntype((yyvsp[0].str),scope_curr);
	}
	else
	{
		int scope_curr1=returnScope((yyvsp[0].str),scope_stack[index1-1]);
		if (b!=returntype((yyvsp[0].str),scope_curr1))
			printf("\nError : Type Mismatch : Line %d\n",printline());
	}
	if (!lookup((yyvsp[0].str)))
	{
		int curr_scope=scope_stack[index1-1];
		int scope=returnScope((yyvsp[0].str),curr_scope);
		if (!(scope<=curr_scope && end[scope]==0))
			printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[0].str),printline());
	}
  else
    printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());
	}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 557 "sem.y" /* yacc.c:1646  */
    {
		if (c==0)
		{
			c=1;
			int scope_curr=returnScope((yyvsp[-3].str),scope_stack[index1-1]);
			b=returntype((yyvsp[-3].str),scope_curr);
		}
		else
		{
			int scope_curr1=returnScope((yyvsp[-3].str),scope_stack[index1-1]);
			if (b!=returntype((yyvsp[-3].str),scope_curr1))
				printf("\nError : Type Mismatch : Line %d\n",printline());
		}
		if (!lookup((yyvsp[-3].str)))
		{
			int curr_scope=scope_stack[index1-1];
			int scope=returnScope((yyvsp[-3].str),curr_scope);
			if (!(scope<=curr_scope && end[scope]==0))
				printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-3].str),printline());
		}
	  else
	    printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-3].str),printline());

		if (isArray((yyvsp[-3].str))==0)
			printf("\nError: Non-array variable used as an array: Line %d\n", printline());

		float bound = isArray((yyvsp[-3].str));

		if (isArray((yyvsp[-3].str)) && (atoi((yyvsp[-1].str)) >= bound || atoi((yyvsp[-1].str)) < 0) )
			printf("\nError: array subscript out of bounds : Line %d\n", printline());

	}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 606 "sem.y" /* yacc.c:1646  */
    { temp = 258;}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 607 "sem.y" /* yacc.c:1646  */
    { temp = 259;}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 612 "sem.y" /* yacc.c:1646  */
    {
			if ( (!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) && (yyvsp[-4].ival)==258)
				printf("\nError : Type Mismatch : Line %d\n",printline());

			if (!lookup((yyvsp[-3].str)))
			{
				int curr_scope=scope_stack[index1-1];
				int previous_scope=returnScope((yyvsp[-3].str),curr_scope);
				if (curr_scope==previous_scope)
					printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-3].str),printline());
				else
				{
					insert_dup((yyvsp[-3].str),(yyvsp[-4].ival),var_addr,curr_scope, 0);
					update_value((yyvsp[-3].str),(yyvsp[-1].str),scope_stack[index1-1]);
					var_addr+=4;
				}
			}
			else
			{
				int scope=scope_stack[index1-1];
				insert((yyvsp[-3].str),(yyvsp[-4].ival),var_addr, 0, 0);
				insertscope((yyvsp[-3].str),scope);
				update_value((yyvsp[-3].str),(yyvsp[-1].str),scope_stack[index1-1]);
				var_addr+=4;
			}
		}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 638 "sem.y" /* yacc.c:1646  */
    {
		if (!lookup((yyvsp[-1].str)))
		{
			int curr_scope=scope_stack[index1-1];
			int previous_scope=returnScope((yyvsp[-1].str),curr_scope);
			if (curr_scope==previous_scope)
				printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-1].str),printline());
			else
			{
				insert_dup((yyvsp[-1].str),(yyvsp[-2].ival),var_addr,curr_scope, 0);
				var_addr+=4;
			}
		}
		else
		{
			int scope=scope_stack[index1-1];
			insert((yyvsp[-1].str),(yyvsp[-2].ival),var_addr, 0, 0);
			insertscope((yyvsp[-1].str),scope);
			var_addr+=4;
		}
	}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 659 "sem.y" /* yacc.c:1646  */
    {
				if (!lookup((yyvsp[-1].str)))
				{
					int curr_scope=scope_stack[index1-1];
					int scope=returnScope((yyvsp[-1].str),curr_scope);
					if (!(scope<=curr_scope && end[scope]==0))
						printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-1].str),printline());
				}
				else
					printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-1].str),printline());
				}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 671 "sem.y" /* yacc.c:1646  */
    {
						insert((yyvsp[-4].str),ARRAY,var_addr,1,0);
						insert((yyvsp[-4].str),(yyvsp[-5].ival),var_addr,1,0);
						update_value((yyvsp[-4].str),(yyvsp[-2].str),scope_stack[index1-1]);
						int scope=scope_stack[index1-1];
						insertscope((yyvsp[-4].str), scope);
						var_addr+=4;
						if (atoi((yyvsp[-2].str))<=0)
						{
							printf("\nError: Illegal array subscript %d : Line %d\n", atoi((yyvsp[-2].str)), printline());
						}
					}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2073 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 686 "sem.y" /* yacc.c:1906  */


#include "lex.yy.c"
#include<ctype.h>
int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	if (!yyparse())
	{
		printf("PARSING DONE\n");
		print();
	}
	else
	{
		printf("Error\n");
	}
	fclose(yyin);
	return 0;
}

yyerror(char *s)
{
	printf("\nLine %d : %s %s\n",yylineno,s,yytext);
}

int printline()
{
	return yylineno;
}

void block_start()
{
	scope_stack[index1]=scope_incrementer;
	scope_incrementer++;
	index1++;
	return;
}

void block_end()
{
	index1--;
	end[scope_stack[index1]]=1;
	scope_stack[index1]=0;
	return;
}
