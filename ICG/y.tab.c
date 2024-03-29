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
#line 1 "parser.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	
	
	void yyerror(char* s);
	int yylex();
	void ins();
	void insV();
	int flag=0;
	
	extern char curid[20];
	extern char curtype[20];
	extern char curval[20];
	extern int currnest;
	void deletedata (int );
	char currfunctype[100];
	char currfunc[100];
	char currfunccall[100];

	int params_count=0;
	extern int call_params_count=0;


#line 92 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,
    INT = 259,
    CHAR = 260,
    FLOAT = 261,
    DOUBLE = 262,
    LONG = 263,
    SHORT = 264,
    SIGNED = 265,
    UNSIGNED = 266,
    STRUCT = 267,
    RETURN = 268,
    MAIN = 269,
    VOID = 270,
    WHILE = 271,
    FOR = 272,
    DO = 273,
    BREAK = 274,
    ENDIF = 275,
    identifier = 276,
    array_identifier = 277,
    func_identifier = 278,
    integer_constant = 279,
    string_constant = 280,
    float_constant = 281,
    character_constant = 282,
    ELSE = 283,
    leftshift_assignment_operator = 284,
    rightshift_assignment_operator = 285,
    XOR_assignment_operator = 286,
    OR_assignment_operator = 287,
    AND_assignment_operator = 288,
    modulo_assignment_operator = 289,
    multiplication_assignment_operator = 290,
    division_assignment_operator = 291,
    addition_assignment_operator = 292,
    subtraction_assignment_operator = 293,
    assignment_operator = 294,
    OR_operator = 295,
    AND_operator = 296,
    pipe_operator = 297,
    caret_operator = 298,
    amp_operator = 299,
    equality_operator = 300,
    inequality_operator = 301,
    lessthan_assignment_operator = 302,
    lessthan_operator = 303,
    greaterthan_assignment_operator = 304,
    greaterthan_operator = 305,
    leftshift_operator = 306,
    rightshift_operator = 307,
    add_operator = 308,
    subtract_operator = 309,
    multiplication_operator = 310,
    division_operator = 311,
    modulo_operator = 312,
    SIZEOF = 313,
    tilde_operator = 314,
    exclamation_operator = 315,
    increment_operator = 316,
    decrement_operator = 317
  };
#endif
/* Tokens.  */
#define IF 258
#define INT 259
#define CHAR 260
#define FLOAT 261
#define DOUBLE 262
#define LONG 263
#define SHORT 264
#define SIGNED 265
#define UNSIGNED 266
#define STRUCT 267
#define RETURN 268
#define MAIN 269
#define VOID 270
#define WHILE 271
#define FOR 272
#define DO 273
#define BREAK 274
#define ENDIF 275
#define identifier 276
#define array_identifier 277
#define func_identifier 278
#define integer_constant 279
#define string_constant 280
#define float_constant 281
#define character_constant 282
#define ELSE 283
#define leftshift_assignment_operator 284
#define rightshift_assignment_operator 285
#define XOR_assignment_operator 286
#define OR_assignment_operator 287
#define AND_assignment_operator 288
#define modulo_assignment_operator 289
#define multiplication_assignment_operator 290
#define division_assignment_operator 291
#define addition_assignment_operator 292
#define subtraction_assignment_operator 293
#define assignment_operator 294
#define OR_operator 295
#define AND_operator 296
#define pipe_operator 297
#define caret_operator 298
#define amp_operator 299
#define equality_operator 300
#define inequality_operator 301
#define lessthan_assignment_operator 302
#define lessthan_operator 303
#define greaterthan_assignment_operator 304
#define greaterthan_operator 305
#define leftshift_operator 306
#define rightshift_operator 307
#define add_operator 308
#define subtract_operator 309
#define multiplication_operator 310
#define division_operator 311
#define modulo_operator 312
#define SIZEOF 313
#define tilde_operator 314
#define exclamation_operator 315
#define increment_operator 316
#define decrement_operator 317

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 267 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  234

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

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
      67,    68,     2,     2,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    63,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,     2,    70,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    71,    74,    75,    78,    79,    82,    85,
      85,    88,    88,    89,    89,    93,    93,    96,    97,   100,
     101,   104,   105,   106,   109,   109,   109,   109,   110,   111,
     112,   113,   114,   117,   117,   117,   117,   120,   120,   120,
     120,   123,   123,   126,   126,   129,   132,   135,   135,   135,
     138,   138,   141,   141,   144,   147,   148,   151,   151,   154,
     155,   158,   158,   159,   159,   160,   160,   161,   164,   164,
     167,   168,   171,   172,   175,   175,   175,   178,   179,   182,
     182,   182,   183,   183,   183,   184,   184,   184,   186,   187,
     200,   203,   206,   209,   212,   213,   216,   216,   225,   225,
     232,   232,   239,   239,   246,   246,   252,   252,   259,   260,
     261,   265,   265,   266,   269,   269,   270,   274,   274,   275,
     278,   279,   282,   282,   282,   282,   282,   282,   285,   286,
     289,   290,   293,   294,   297,   297,   297,   300,   301,   304,
     317,   317,   325,   326,   327,   330,   330,   357,   357,   360,
     361,   363,   363,   363,   363,   363,   366,   367,   368,   369
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "INT", "CHAR", "FLOAT", "DOUBLE",
  "LONG", "SHORT", "SIGNED", "UNSIGNED", "STRUCT", "RETURN", "MAIN",
  "VOID", "WHILE", "FOR", "DO", "BREAK", "ENDIF", "identifier",
  "array_identifier", "func_identifier", "integer_constant",
  "string_constant", "float_constant", "character_constant", "ELSE",
  "leftshift_assignment_operator", "rightshift_assignment_operator",
  "XOR_assignment_operator", "OR_assignment_operator",
  "AND_assignment_operator", "modulo_assignment_operator",
  "multiplication_assignment_operator", "division_assignment_operator",
  "addition_assignment_operator", "subtraction_assignment_operator",
  "assignment_operator", "OR_operator", "AND_operator", "pipe_operator",
  "caret_operator", "amp_operator", "equality_operator",
  "inequality_operator", "lessthan_assignment_operator",
  "lessthan_operator", "greaterthan_assignment_operator",
  "greaterthan_operator", "leftshift_operator", "rightshift_operator",
  "add_operator", "subtract_operator", "multiplication_operator",
  "division_operator", "modulo_operator", "SIZEOF", "tilde_operator",
  "exclamation_operator", "increment_operator", "decrement_operator",
  "';'", "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept",
  "program", "declaration_list", "D", "declaration",
  "variable_declaration", "variable_declaration_list",
  "variable_declaration_identifier", "$@1", "$@2", "vdi",
  "identifier_array_type", "initilization_params", "initilization",
  "type_specifier", "unsigned_grammar", "signed_grammar", "long_grammar",
  "short_grammar", "function_declaration", "function_declaration_type",
  "function_declaration_param_statement", "$@3", "$@4", "params",
  "parameters_list", "$@5", "parameters_identifier_list",
  "parameters_identifier_list_breakup", "param_identifier", "$@6",
  "param_identifier_breakup", "statement", "compound_statement", "$@7",
  "statment_list", "expression_statment", "conditional_statements", "$@8",
  "$@9", "conditional_statements_breakup", "iterative_statements", "$@10",
  "$@11", "$@12", "$@13", "$@14", "$@15", "return_statement",
  "break_statement", "string_initilization", "array_initialization",
  "array_int_declarations", "array_int_declarations_breakup", "expression",
  "$@16", "$@17", "$@18", "$@19", "$@20", "@21", "simple_expression",
  "$@22", "and_expression", "@23", "unary_relation_expression", "@24",
  "regular_expression", "relational_operators", "sum_expression",
  "sum_operators", "term", "MULOP", "factor", "mutable", "$@25",
  "immutable", "call", "@26", "arguments", "arguments_list", "exp",
  "constant", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    59,    44,    91,    93,    40,    41,   123,
     125
};
# endif

#define YYPACT_NINF -84

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-84)))

#define YYTABLE_NINF -86

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      80,   -84,   -84,   -84,   -84,    38,    47,    94,    96,   -84,
      35,   -84,    80,   -84,    11,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,    38,    47,   -84,   -84,    38,    47,   -84,   -84,
     -84,   -84,   -14,   -84,   -20,   -84,   -84,    80,   -84,   -84,
     -84,   -84,   -84,   -19,   -19,   -84,    39,   -84,    -5,   -84,
      -3,    -8,   -84,   -84,   -84,   -84,   -84,    53,   -84,    29,
     -84,   -84,   -84,   -84,   -84,   -84,    -3,    59,    56,   -84,
      76,    28,    75,   -84,   -84,   -84,   -84,   -84,    43,    71,
     -84,   -84,   -84,    48,   191,   -84,    62,    -3,    45,    59,
      31,    -3,   -84,   -84,   -84,   -84,   -84,   -84,   -84,     4,
     -84,   -84,     4,   -84,   -84,   -84,     4,    89,   108,   -84,
      69,    80,   -84,    70,   -13,    72,    73,    78,   -84,   -84,
      39,   -84,   -84,    74,   -84,   -84,   -84,   126,   -84,   -84,
      82,    51,    -3,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,    56,    -3,    28,    75,   -84,   -21,   -84,
     -84,   -84,   -84,    81,   -84,   -84,    -3,   -84,    83,   -84,
      -3,   -84,   166,   191,   -84,   -84,   -84,   -84,   -84,   -84,
      85,    86,   -84,    88,    -3,    -3,    -3,    -3,    -3,    -3,
     -84,   -84,   124,   -84,   -34,   -84,    -3,    92,   166,    87,
     135,   -84,    51,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
      95,    90,   -84,   -30,   -84,   -84,   -84,    91,   -84,   124,
     -84,   -84,   191,   -84,    -3,    -3,   -84,   -84,   191,    -4,
     -23,   128,   -84,   -84,   -84,   191,   -84,    -3,    98,   -84,
     110,   -84,   191,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    24,    25,    26,    27,    42,    44,    40,    36,    32,
       0,     2,     5,     6,     0,     7,    47,    41,    28,    43,
      29,    37,    42,    44,    31,    33,    42,    44,    30,     1,
       4,     3,    11,    13,     0,    10,    45,    51,    38,    39,
      34,    35,    46,    18,    18,     8,     0,    52,     0,    50,
       0,     0,    12,    15,    14,    11,     9,     0,    48,   139,
     140,   156,   157,   158,   159,   117,     0,    16,   113,   116,
     119,   121,   129,   133,   138,   137,   143,   144,     0,     0,
      17,    57,    53,    56,    68,   145,     0,     0,     0,   110,
     138,     0,   114,   126,   127,   123,   125,   122,   124,     0,
     130,   131,     0,   134,   135,   136,     0,    23,     0,    20,
      60,     0,    54,     0,     0,     0,     0,     0,    73,    67,
       0,    49,    62,     0,    61,    63,    64,     0,    65,    66,
       0,   148,     0,   118,   142,   106,   102,   104,    98,   100,
      96,   108,   109,   111,     0,   120,   128,   132,     0,    19,
      21,    22,    91,     0,    58,    55,     0,    88,     0,    79,
       0,    90,    68,    68,    72,   151,   152,   153,   154,   155,
       0,   147,   150,     0,     0,     0,     0,     0,     0,     0,
     112,   115,     0,    59,     0,    89,     0,     0,    68,     0,
       0,   146,     0,   141,   107,   103,   105,    99,   101,    97,
      95,     0,    74,     0,    82,    70,    69,     0,   149,     0,
      93,    92,    68,    80,     0,     0,    94,    75,    68,     0,
       0,    78,    81,    83,    86,    68,    76,     0,     0,    77,
       0,    87,    68,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   140,   -84,   -84,    27,   -84,   116,   -84,   -84,
     119,   -84,   -84,   -84,     3,   -84,   -84,    57,    84,   -84,
     -84,   -84,   -84,   -84,   -84,   100,   -84,   -84,   -84,   -84,
     -84,   -84,   -83,   -84,   -84,    -2,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     107,   -84,   -29,   -84,   -59,   -84,   -84,   -84,   -84,   -84,
     -84,   -48,   -84,   112,   -84,   -82,   -84,   -84,   -84,   106,
     -84,   117,   -84,   114,   -50,   -84,   -84,   -84,   -84,   -84,
     -84,    30,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    31,    12,   119,    34,    35,    43,    44,
      52,    53,    80,   149,   120,    28,    24,    18,    20,    15,
      16,    36,    37,    84,    48,    49,    57,    82,   112,    83,
     110,   154,   188,   122,   123,   189,   124,   125,   212,   221,
     226,   126,   186,   218,   214,   227,   127,   228,   128,   129,
     109,   151,   201,   210,   130,   179,   177,   178,   175,   176,
     174,    89,   180,    68,   144,    69,    87,    70,    99,    71,
     102,    72,   106,    73,    90,    86,    75,    76,   131,   170,
     171,   172,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,   121,    67,    14,   152,   133,    91,    88,    59,    60,
      91,    61,    62,    63,    64,    14,    78,    91,    59,    60,
      50,    61,    62,    63,    64,    59,    60,    13,    61,    62,
      63,    64,    32,    33,   202,    29,    91,    74,   213,    13,
      47,    74,    17,    45,    46,   224,    51,    65,   182,    74,
     157,    19,    74,    42,    66,   158,    74,    65,    79,   223,
      55,    33,   181,    58,    66,   135,   136,   137,   138,   139,
     140,    66,   165,   173,    81,   166,   167,   168,   169,    38,
     190,   100,   101,    40,     1,     2,     3,     4,     5,     6,
       7,     8,   141,   142,    74,     9,    85,    92,    21,    91,
      25,   187,    22,    23,    26,    27,    74,    39,   184,   107,
     108,    41,   111,   134,    47,   194,   195,   196,   197,   198,
     199,    93,    94,    95,    96,    97,    98,   132,   148,   217,
     103,   104,   105,   152,   153,   222,    74,   156,   203,   159,
     160,   161,   229,   162,   163,   164,   185,   183,   200,   233,
     192,   207,    30,   191,   193,   204,   225,   206,   215,   209,
     211,   231,    56,    54,    74,    74,   219,   220,   230,   113,
       1,     2,     3,     4,     5,     6,     7,     8,   232,   114,
     216,     9,   115,   116,   -85,   117,   205,    59,    60,     0,
      61,    62,    63,    64,   113,     1,     2,     3,     4,     5,
       6,     7,     8,   143,   114,   145,     9,   115,   116,   -85,
     117,   155,    59,    60,   150,    61,    62,    63,    64,   146,
     147,     0,   208,     0,     0,     0,    65,     0,     0,   118,
       0,     0,     0,    66,     0,     0,   -71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,   118,     0,     0,     0,    66
};

static const yytype_int16 yycheck[] =
{
      50,    84,    50,     0,    25,    87,    40,    66,    21,    22,
      40,    24,    25,    26,    27,    12,    24,    40,    21,    22,
      39,    24,    25,    26,    27,    21,    22,     0,    24,    25,
      26,    27,    21,    22,    68,     0,    40,    87,    68,    12,
      37,    91,     4,    63,    64,    68,    65,    60,    69,    99,
      63,     4,   102,    67,    67,   114,   106,    60,    66,    63,
      21,    22,   144,    68,    67,    34,    35,    36,    37,    38,
      39,    67,    21,   132,    21,    24,    25,    26,    27,    22,
     163,    53,    54,    26,     4,     5,     6,     7,     8,     9,
      10,    11,    61,    62,   144,    15,    67,    41,     4,    40,
       4,   160,     8,     9,     8,     9,   156,    23,   156,    66,
      39,    27,    64,    68,   111,   174,   175,   176,   177,   178,
     179,    45,    46,    47,    48,    49,    50,    65,    39,   212,
      55,    56,    57,    25,    65,   218,   186,    67,   186,    67,
      67,    63,   225,    69,    18,    63,    63,    66,    24,   232,
      64,    16,    12,    68,    66,    63,    28,    70,    67,    64,
      70,    63,    46,    44,   214,   215,   214,   215,   227,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    68,    13,
     209,    15,    16,    17,    18,    19,   188,    21,    22,    -1,
      24,    25,    26,    27,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    91,    13,    99,    15,    16,    17,    18,
      19,   111,    21,    22,   107,    24,    25,    26,    27,   102,
     106,    -1,   192,    -1,    -1,    -1,    60,    -1,    -1,    63,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    63,    -1,    -1,    -1,    67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    15,
      72,    73,    75,    76,    85,    90,    91,     4,    88,     4,
      89,     4,     8,     9,    87,     4,     8,     9,    86,     0,
      73,    74,    21,    22,    77,    78,    92,    93,    88,    89,
      88,    89,    67,    79,    80,    63,    64,    85,    95,    96,
      39,    65,    81,    82,    81,    21,    78,    97,    68,    21,
      22,    24,    25,    26,    27,    60,    67,   132,   134,   136,
     138,   140,   142,   144,   145,   147,   148,   153,    24,    66,
      83,    21,    98,   100,    94,    67,   146,   137,   125,   132,
     145,    40,    41,    45,    46,    47,    48,    49,    50,   139,
      53,    54,   141,    55,    56,    57,   143,    66,    39,   121,
     101,    64,    99,     3,    13,    16,    17,    19,    63,    76,
      85,   103,   104,   105,   107,   108,   112,   117,   119,   120,
     125,   149,    65,   136,    68,    34,    35,    36,    37,    38,
      39,    61,    62,   134,   135,   140,   142,   144,    39,    84,
     121,   122,    25,    65,   102,    96,    67,    63,   125,    67,
      67,    63,    69,    18,    63,    21,    24,    25,    26,    27,
     150,   151,   152,   125,   131,   129,   130,   127,   128,   126,
     133,   136,    69,    66,   132,    63,   113,   125,   103,   106,
     103,    68,    64,    66,   125,   125,   125,   125,   125,   125,
      24,   123,    68,   132,    63,   106,    70,    16,   152,    64,
     124,    70,   109,    68,   115,    67,   123,   103,   114,   132,
     132,   110,   103,    63,    68,    28,   111,   116,   118,   103,
     125,    63,    68,   103
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    74,    74,    75,    75,    76,    77,
      77,    79,    78,    80,    78,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    86,    86,    86,    87,    87,    87,
      87,    88,    88,    89,    89,    90,    91,    93,    94,    92,
      95,    95,    97,    96,    98,    99,    99,   101,   100,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   105,   104,
     106,   106,   107,   107,   109,   110,   108,   111,   111,   113,
     114,   112,   115,   116,   112,   117,   118,   112,   119,   119,
     120,   121,   122,   123,   124,   124,   126,   125,   127,   125,
     128,   125,   129,   125,   130,   125,   131,   125,   125,   125,
     125,   133,   132,   132,   135,   134,   134,   137,   136,   136,
     138,   138,   139,   139,   139,   139,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   143,   144,   144,   145,
     146,   145,   147,   147,   147,   149,   148,   150,   150,   151,
     151,   152,   152,   152,   152,   152,   153,   153,   153,   153
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     1,     1,     3,     3,
       1,     0,     3,     0,     3,     1,     2,     2,     0,     3,
       2,     1,     1,     0,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     2,     2,     0,     1,     2,     2,
       0,     1,     0,     1,     0,     2,     3,     0,     0,     5,
       1,     0,     0,     3,     2,     2,     0,     0,     3,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       2,     0,     2,     1,     0,     0,     8,     2,     0,     0,
       0,     7,     0,     0,    11,     0,     0,     9,     2,     3,
       2,     2,     4,     2,     2,     0,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     2,     2,
       1,     0,     4,     1,     0,     4,     1,     0,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     1,     0,     5,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
        case 11:
#line 88 "parser.y" /* yacc.c:1646  */
    {if(duplicate(curid)){printf("Duplicate\n");exit(0);}insertSTnest(curid,currnest); ins();  }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 89 "parser.y" /* yacc.c:1646  */
    {if(duplicate(curid)){printf("Duplicate\n");exit(0);}insertSTnest(curid,currnest); ins();  }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 100 "parser.y" /* yacc.c:1646  */
    {if((yyval) < 1) {printf("Wrong array size\n"); exit(0);} }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 132 "parser.y" /* yacc.c:1646  */
    { strcpy(currfunctype, curtype); strcpy(currfunc, curid); check_duplicate(curid); insertSTF(curid); ins(); }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 135 "parser.y" /* yacc.c:1646  */
    {params_count=0;}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 135 "parser.y" /* yacc.c:1646  */
    {funcgen();}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 135 "parser.y" /* yacc.c:1646  */
    {funcgenend();}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 138 "parser.y" /* yacc.c:1646  */
    { insertSTparamscount(currfunc, params_count); }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 138 "parser.y" /* yacc.c:1646  */
    { insertSTparamscount(currfunc, params_count); }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 141 "parser.y" /* yacc.c:1646  */
    { check_params(curtype);}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 151 "parser.y" /* yacc.c:1646  */
    { ins();insertSTnest(curid,1); params_count++; }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 164 "parser.y" /* yacc.c:1646  */
    {currnest++;}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 164 "parser.y" /* yacc.c:1646  */
    {deletedata(currnest);currnest--;}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 175 "parser.y" /* yacc.c:1646  */
    {label1();if((yyvsp[-1])!=1){printf("Condition checking is not of type int\n");exit(0);}}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 175 "parser.y" /* yacc.c:1646  */
    {label2();}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 178 "parser.y" /* yacc.c:1646  */
    {label3();}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 179 "parser.y" /* yacc.c:1646  */
    {label3();}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 182 "parser.y" /* yacc.c:1646  */
    {label4();}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 182 "parser.y" /* yacc.c:1646  */
    {label1();if((yyvsp[-1])!=1){printf("Condition checking is not of type int\n");exit(0);}}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 182 "parser.y" /* yacc.c:1646  */
    {label5();}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 183 "parser.y" /* yacc.c:1646  */
    {label4();}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 183 "parser.y" /* yacc.c:1646  */
    {label1();if((yyvsp[-1])!=1){printf("Condition checking is not of type int\n");exit(0);}}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 183 "parser.y" /* yacc.c:1646  */
    {label5();}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 184 "parser.y" /* yacc.c:1646  */
    {label4();}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 184 "parser.y" /* yacc.c:1646  */
    {label1();label5();if((yyvsp[-1])!=1){printf("Condition checking is not of type int\n");exit(0);}}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 186 "parser.y" /* yacc.c:1646  */
    {if(strcmp(currfunctype,"void")) {printf("Returning void of a non-void function\n"); exit(0);}}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 187 "parser.y" /* yacc.c:1646  */
    { 	if(!strcmp(currfunctype, "void"))
										{ 
											yyerror("Function is void");
										}

										if((currfunctype[0]=='i' || currfunctype[0]=='c') && (yyvsp[-1])!=1)
										{
											printf("Expression doesn't match return type of function\n"); exit(0);
										}

									}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 203 "parser.y" /* yacc.c:1646  */
    {insV();}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 216 "parser.y" /* yacc.c:1646  */
    {push("=");}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 216 "parser.y" /* yacc.c:1646  */
    {   
																	  if((yyvsp[-3])==1 && (yyvsp[0])==1) 
																	  {
			                                                          (yyval)=1;
			                                                          } 
			                                                          else 
			                                                          {(yyval)=-1; printf("Type mismatch\n"); exit(0);} 
			                                                          codeassign();
			                                                       }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 225 "parser.y" /* yacc.c:1646  */
    {push("+=");}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 225 "parser.y" /* yacc.c:1646  */
    {  
																	  if((yyvsp[-3])==1 && (yyvsp[0])==1) 
			                                                          (yyval)=1; 
			                                                          else 
			                                                          {(yyval)=-1; printf("Type mismatch\n"); exit(0);} 
			                                                          codeassign();
			                                                       }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 232 "parser.y" /* yacc.c:1646  */
    {push("-=");}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 232 "parser.y" /* yacc.c:1646  */
    {	  
																	  if((yyvsp[-3])==1 && (yyvsp[0])==1) 
			                                                          (yyval)=1; 
			                                                          else 
			                                                          {(yyval)=-1; printf("Type mismatch\n"); exit(0);} 
			                                                          codeassign();
			                                                       }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 239 "parser.y" /* yacc.c:1646  */
    {push("*=");}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 239 "parser.y" /* yacc.c:1646  */
    {
																	  if((yyvsp[-3])==1 && (yyvsp[0])==1) 
			                                                          (yyval)=1; 
			                                                          else 
			                                                          {(yyval)=-1; printf("Type mismatch\n"); exit(0);}
			                                                          codeassign(); 
			                                                       }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 246 "parser.y" /* yacc.c:1646  */
    {push("/=");}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 246 "parser.y" /* yacc.c:1646  */
    { 
																	  if((yyvsp[-3])==1 && (yyvsp[0])==1) 
			                                                          (yyval)=1; 
			                                                          else 
			                                                          {(yyval)=-1; printf("Type mismatch\n"); exit(0);} 
			                                                       }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 252 "parser.y" /* yacc.c:1646  */
    {push("%=");}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 252 "parser.y" /* yacc.c:1646  */
    { 
																	  if((yyvsp[-3])==1 && (yyvsp[-1])==1) 
			                                                          (yyval)=1; 
			                                                          else 
			                                                          {(yyval)=-1; printf("Type mismatch\n"); exit(0);} 
			                                                          codeassign();
																	}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 259 "parser.y" /* yacc.c:1646  */
    { push("++");if((yyvsp[-1]) == 1) (yyval)=1; else (yyval)=-1; genunary();}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 260 "parser.y" /* yacc.c:1646  */
    {push("--");if((yyvsp[-1]) == 1) (yyval)=1; else (yyval)=-1;}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 261 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0]) == 1) (yyval)=1; else (yyval)=-1;}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 265 "parser.y" /* yacc.c:1646  */
    {push("||");}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 265 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-3]) == 1 && (yyvsp[-1])==1) (yyval)=1; else (yyval)=-1; codegen();}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 266 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0]) == 1) (yyval)=1; else (yyval)=-1;}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 269 "parser.y" /* yacc.c:1646  */
    {push("&&");}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 269 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-3]) == 1 && (yyvsp[-1])==1) (yyval)=1; else (yyval)=-1; codegen();}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 270 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0]) == 1) (yyval)=1; else (yyval)=-1;}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 274 "parser.y" /* yacc.c:1646  */
    {push("!");}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 274 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-1])==1) (yyval)=1; else (yyval)=-1; codegen();}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 275 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0]) == 1) (yyval)=1; else (yyval)=-1;}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 278 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2]) == 1 && (yyvsp[0])==1) (yyval)=1; else (yyval)=-1; codegen();}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 279 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0]) == 1) (yyval)=1; else (yyval)=-1;}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 282 "parser.y" /* yacc.c:1646  */
    {push(">=");}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 282 "parser.y" /* yacc.c:1646  */
    {push("<=");}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 282 "parser.y" /* yacc.c:1646  */
    {push(">");}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 282 "parser.y" /* yacc.c:1646  */
    {push("<");}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 282 "parser.y" /* yacc.c:1646  */
    {push("==");}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 282 "parser.y" /* yacc.c:1646  */
    {push("!=");}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 285 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2]) == 1 && (yyvsp[0])==1) (yyval)=1; else (yyval)=-1; codegen();}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 286 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0]) == 1) (yyval)=1; else (yyval)=-1;}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 289 "parser.y" /* yacc.c:1646  */
    {push("+");}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 290 "parser.y" /* yacc.c:1646  */
    {push("-");}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 293 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2]) == 1 && (yyvsp[0])==1) (yyval)=1; else (yyval)=-1; codegen();}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 294 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0]) == 1) (yyval)=1; else (yyval)=-1;}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 297 "parser.y" /* yacc.c:1646  */
    {push("*");}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 297 "parser.y" /* yacc.c:1646  */
    {push("/");}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 297 "parser.y" /* yacc.c:1646  */
    {push("%");}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 300 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0]) == 1) (yyval)=1; else (yyval)=-1;}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 301 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0]) == 1) (yyval)=1; else (yyval)=-1;}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 304 "parser.y" /* yacc.c:1646  */
    {
						  push(curid);
						  if(check_id_is_func(curid))
						  {printf("Function name used as Identifier\n"); exit(8);}
			              if(!checkscope(curid))
			              {printf("%s\n",curid);printf("Undeclared\n");exit(0);} 
			              if(!checkarray(curid))
			              {printf("%s\n",curid);printf("Array ID has no subscript\n");exit(0);}
			              if(gettype(curid,0)=='i' || gettype(curid,1)== 'c')
			              (yyval) = 1;
			              else
			              (yyval) = -1;
			              }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 317 "parser.y" /* yacc.c:1646  */
    {if(!checkscope(curid)){printf("%s\n",curid);printf("Undeclared\n");exit(0);}}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 318 "parser.y" /* yacc.c:1646  */
    {if(gettype(curid,0)=='i' || gettype(curid,1)== 'c')
			              		(yyval) = 1;
			              		else
			              		(yyval) = -1;
			              		}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 325 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-1])==1) (yyval)=1; else (yyval)=-1;}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 326 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0])==-1) (yyval)=-1; else (yyval)=1;}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 327 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0])==1) (yyval)=1; else (yyval)=-1;}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 330 "parser.y" /* yacc.c:1646  */
    {

			             if(!check_declaration(curid, "Function"))
			             { printf("Function not declared"); exit(0);} 
			             insertSTF(curid); 
						 strcpy(currfunccall,curid);
						 if(gettype(curid,0)=='i' || gettype(curid,1)== 'c')
						 {
			             (yyval) = 1;
			             }
			             else
			             (yyval) = -1;
                         call_params_count=0;
			             }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 345 "parser.y" /* yacc.c:1646  */
    { if(strcmp(currfunccall,"printf"))
							{ 
								if(getSTparamscount(currfunccall)!=call_params_count)
								{	
									yyerror("Number of arguments in function call doesn't match number of parameters");
									exit(8);
								}
							}
							callgen();
						 }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 360 "parser.y" /* yacc.c:1646  */
    { call_params_count++; }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 361 "parser.y" /* yacc.c:1646  */
    { call_params_count++; }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 363 "parser.y" /* yacc.c:1646  */
    {arggen(1);}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 363 "parser.y" /* yacc.c:1646  */
    {arggen(2);}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 363 "parser.y" /* yacc.c:1646  */
    {arggen(3);}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 363 "parser.y" /* yacc.c:1646  */
    {arggen(4);}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 363 "parser.y" /* yacc.c:1646  */
    {arggen(5);}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 366 "parser.y" /* yacc.c:1646  */
    {  insV(); codegencon(); (yyval)=1; }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 367 "parser.y" /* yacc.c:1646  */
    {  insV(); codegencon();(yyval)=-1;}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 368 "parser.y" /* yacc.c:1646  */
    {  insV(); codegencon();}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 369 "parser.y" /* yacc.c:1646  */
    {  insV(); codegencon();(yyval)=1; }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2186 "y.tab.c" /* yacc.c:1646  */
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
#line 371 "parser.y" /* yacc.c:1906  */


extern FILE *yyin;
extern int yylineno;
extern char *yytext;


void callgen()
{
	printf("refparam result\n");
	push("result");
	printf("call %s, %d\n",currfunccall,call_params_count);
}



int main(int argc , char **argv)
{
	yyin = fopen(argv[1], "r");
	printf("\n---------------------------------------------------------\n");
	printf("             3 - ADDRESS CODE                           |\n");
	printf("---------------------------------------------------------\n\n");
	yyparse();
	printf("---------------------------------------------------------\n\n");

	if(flag == 0)
	{
		printf("Status: Parsing Complete\n\n");
		printf("----------------------------------------------------------------------------------------------------\n");
		printf("                                        SYMBOL TABLE                                               |\n");
		printf("----------------------------------------------------------------------------------------------------\n");
		printST();

		printf("\n\n\n----------------------------------------\n");
		printf("           CONSTANT TABLE              |\n");
		printf("----------------------------------------\n");
		printCT();
	}
}

void yyerror(char *s)
{
	printf("%d %s %s\n", yylineno, s, yytext);
	flag=1;
	printf("Status: Parsing Failed\n");
	exit(7);
}

void ins()
{
	insertSTtype(curid,curtype);
}

void insV()
{
	insertSTvalue(curid,curval);
}

int yywrap()
{
	return 1;
}
