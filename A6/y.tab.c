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

	#include "program.hh"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern "C" void yyerror(const char *s);
	extern int yylex(void);
	extern int yylineno;
	Symbol_Table* global_sym_table = new Symbol_Table();
	Symbol_Table* local_sym_table = new Symbol_Table();

	/*current procedure */
	string current_procedure_name = "";

#line 81 "y.tab.c" /* yacc.c:339  */

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
    INTEGER_NUMBER = 258,
    DOUBLE_NUMBER = 259,
    NAME = 260,
    BBNUM = 261,
    RETURN = 262,
    INTEGER = 263,
    FLOAT = 264,
    ASSIGN = 265,
    VOID = 266,
    UMINUS = 267,
    WHILE = 268,
    IF = 269,
    DO = 270,
    ELSE = 271,
    PRINT = 272,
    EQUAL = 273,
    LESS_THAN = 274,
    GREATER_THAN = 275,
    LESS_THAN_EQUAL = 276,
    GREATER_THAN_EQUAL = 277,
    NOT_EQUAL = 278,
    AND = 279,
    OR = 280,
    NOT = 281,
    NOT_ELSE = 282
  };
#endif
/* Tokens.  */
#define INTEGER_NUMBER 258
#define DOUBLE_NUMBER 259
#define NAME 260
#define BBNUM 261
#define RETURN 262
#define INTEGER 263
#define FLOAT 264
#define ASSIGN 265
#define VOID 266
#define UMINUS 267
#define WHILE 268
#define IF 269
#define DO 270
#define ELSE 271
#define PRINT 272
#define EQUAL 273
#define LESS_THAN 274
#define GREATER_THAN 275
#define LESS_THAN_EQUAL 276
#define GREATER_THAN_EQUAL 277
#define NOT_EQUAL 278
#define AND 279
#define OR 280
#define NOT 281
#define NOT_ELSE 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "parser.y" /* yacc.c:355  */

	int integer_value;
	double double_value;
	std::string * string_value;
	list<Ast *> * ast_list;
	Ast * ast;
	Sequence_Ast * seq_ast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	Basic_Block * basic_block;
	Procedure * procedure;
	list<Symbol_Table_Entry *> * symbol_entry_list;
	Data_Type data_type;
	Call_Ast* call_ast;

#line 191 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

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
      34,    35,    31,    29,    37,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    28,    36,
       2,     2,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    88,    92,   104,   140,   146,   152,   158,
     166,   170,   176,   183,   193,   197,   217,   215,   276,   279,
     285,   290,   310,   323,   326,   332,   336,   352,   361,   368,
     379,   382,   391,   395,   399,   404,   408,   412,   419,   434,
     440,   444,   450,   454,   460,   465,   470,   475,   480,   486,
     491,   496,   501,   506,   511,   520,   541,   558,   563,   567,
     580,   584,   590,   594,   598,   612,   618,   624,   630,   636,
     642,   649
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_NUMBER", "DOUBLE_NUMBER",
  "NAME", "BBNUM", "RETURN", "INTEGER", "FLOAT", "ASSIGN", "VOID",
  "UMINUS", "WHILE", "IF", "DO", "ELSE", "PRINT", "EQUAL", "LESS_THAN",
  "GREATER_THAN", "LESS_THAN_EQUAL", "GREATER_THAN_EQUAL", "NOT_EQUAL",
  "AND", "OR", "NOT", "'?'", "':'", "'+'", "'-'", "'*'", "'/'", "NOT_ELSE",
  "'('", "')'", "';'", "','", "'{'", "'}'", "$accept", "program",
  "dec_def_list", "procedure_declaration", "type",
  "declaration_param_list", "procedure_definition_list",
  "procedure_definition", "$@1", "optional_formal_param_list",
  "formal_param_list", "local_variable_declaration_list",
  "optional_variable_declaration_list", "variable_declaration_list",
  "variable_declaration", "variable_list", "statement_list", "statement",
  "sequence_statement", "iteration_statement", "selection_statement",
  "log_expression", "rel_expression", "assignment_statement",
  "print_statement", "actual_param_list", "call_stmt", "return_stmt",
  "arith_expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    63,    58,    43,
      45,    42,    47,   282,    40,    41,    59,    44,   123,   125
};
# endif

#define YYPACT_NINF -76

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-76)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      46,   -76,   -76,    10,    31,   -76,    46,    16,    76,   -76,
      46,     3,   -76,   -76,    22,    77,    53,   -76,   -76,    76,
      76,   -76,    62,    41,    72,   -33,    54,    56,   -17,    68,
     -76,    76,   -76,    55,    76,    71,    76,    79,    82,    72,
      85,   -76,   -76,   -76,   112,   -76,   -76,    83,   -76,   -76,
      76,   117,   -76,   -76,    76,   -76,   -76,    21,   -76,    -7,
      36,    90,    92,    87,   130,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,    93,   -76,   -76,   -76,   -76,
      93,    93,    93,   -76,    44,   -76,   110,    93,    93,   121,
     100,    73,   129,    -5,   -76,   181,   -76,   -16,   148,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,   -76,    81,   182,   103,   -76,   -76,   -76,   102,
      93,   -76,   -76,   -76,   119,   166,   181,   181,   181,   181,
     181,   181,    78,    78,   -76,   -76,    87,    87,    93,   -76,
     181,    93,   -76,   128,   191,   181,    87,   109,   -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,     0,     0,     2,     0,     0,     3,    14,
       0,     0,     1,     5,    28,     0,     0,    15,     4,    18,
      18,    27,     0,     0,    13,     0,     0,    19,     0,     0,
      29,    18,    21,     0,     0,     0,     0,     0,    16,     0,
       0,     8,    12,     9,     0,     6,     7,     0,    16,    20,
      23,     0,    30,    22,    24,    25,    28,     0,    26,     0,
       0,     0,     0,     0,     0,    30,    17,    39,    31,    33,
      34,    32,    35,    36,    37,     0,    58,    62,    63,    64,
       0,     0,     0,    61,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,    56,    38,    55,     0,
       0,    48,    71,    44,    45,     0,    49,    51,    53,    52,
      54,    50,    65,    66,    67,    68,     0,     0,     0,    59,
      57,     0,    40,    42,     0,    70,     0,     0,    43,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,     4,   -76,    45,   133,   -76,   146,   -76,   -14,
     -76,   -76,   -76,   -76,   -21,   -76,    91,   -76,   -63,   -76,
     -76,   -75,   -76,   -76,   -76,   -76,   -76,   -76,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    25,     8,     9,    47,    26,
      27,    52,    53,    54,    10,    15,    57,    67,    68,    69,
      70,    84,    85,    71,    72,    93,    73,    74,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      89,    86,    33,    75,    34,    94,    29,    97,    99,   100,
      13,   101,   113,   114,    18,    11,    92,    40,    37,   121,
      34,    14,    96,    98,   123,   124,    59,    76,    60,    55,
     119,    12,   120,    58,    61,    62,    63,    19,    64,    77,
      78,    79,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    16,     1,     2,    20,     3,    23,    65,
      66,   140,    80,   144,    24,    24,    81,    30,    99,   100,
      82,   101,    83,   142,   143,    31,    39,    32,    59,    42,
      60,    44,   145,   148,     1,     2,    61,    62,    63,    35,
      64,    41,    59,    36,    60,    51,    77,    78,    79,    51,
      61,    62,    63,    38,    64,    99,   100,    43,   101,   110,
     111,    65,   117,    21,    22,    45,   136,    49,    46,    80,
      48,    50,    56,    81,    87,    65,    88,    82,   102,   103,
     104,   105,   106,   107,   115,    90,   116,   138,   139,   108,
     109,   110,   111,    99,   146,   149,   112,   102,   103,   104,
     105,   106,   107,    28,    17,     0,    91,     0,   108,   109,
     110,   111,     0,     0,     0,   118,   102,   103,   104,   105,
     106,   107,     0,     0,     0,     0,     0,   108,   109,   110,
     111,     0,     0,   122,   102,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   141,   108,   109,   110,   111,   102,
     103,   104,   105,   106,   107,     0,    99,   100,     0,   101,
     108,   109,   110,   111,     0,    99,   100,   137,   101,     0,
       0,     0,     0,     0,     0,     0,   147
};

static const yytype_int16 yycheck[] =
{
      63,    60,    35,    10,    37,    80,    20,    82,    24,    25,
       6,    27,    87,    88,    10,     5,    75,    31,    35,    35,
      37,     5,    81,    82,    99,   100,     5,    34,     7,    50,
      35,     0,    37,    54,    13,    14,    15,    34,    17,     3,
       4,     5,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     8,     8,     9,    34,    11,     5,    38,
      39,   120,    26,   138,    19,    20,    30,     5,    24,    25,
      34,    27,    36,   136,   137,    34,    31,     5,     5,    34,
       7,    36,   141,   146,     8,     9,    13,    14,    15,    35,
      17,    36,     5,    37,     7,    50,     3,     4,     5,    54,
      13,    14,    15,    35,    17,    24,    25,    36,    27,    31,
      32,    38,    39,    36,    37,    36,    35,     5,    36,    26,
      35,    38,     5,    30,    34,    38,    34,    34,    18,    19,
      20,    21,    22,    23,    13,     5,    36,    34,    36,    29,
      30,    31,    32,    24,    16,    36,    36,    18,    19,    20,
      21,    22,    23,    20,     8,    -1,    65,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    36,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    -1,    -1,    35,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    18,
      19,    20,    21,    22,    23,    -1,    24,    25,    -1,    27,
      29,    30,    31,    32,    -1,    24,    25,    35,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    11,    41,    42,    43,    44,    46,    47,
      54,     5,     0,    42,     5,    55,    44,    47,    42,    34,
      34,    36,    37,     5,    44,    45,    49,    50,    45,    49,
       5,    34,     5,    35,    37,    35,    37,    35,    35,    44,
      49,    36,    44,    36,    44,    36,    36,    48,    35,     5,
      38,    44,    51,    52,    53,    54,     5,    56,    54,     5,
       7,    13,    14,    15,    17,    38,    39,    57,    58,    59,
      60,    63,    64,    66,    67,    10,    34,     3,     4,     5,
      26,    30,    34,    36,    61,    62,    68,    34,    34,    58,
       5,    56,    68,    65,    61,    68,    68,    61,    68,    24,
      25,    27,    18,    19,    20,    21,    22,    23,    29,    30,
      31,    32,    36,    61,    61,    13,    36,    39,    36,    35,
      37,    35,    35,    61,    61,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    35,    35,    34,    36,
      68,    28,    58,    58,    61,    68,    16,    35,    58,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    43,    43,    43,    43,
      44,    44,    45,    45,    46,    46,    48,    47,    49,    49,
      50,    50,    51,    52,    52,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    63,    64,    65,    65,    66,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     6,     6,     6,     6,
       1,     1,     3,     1,     1,     2,     0,    10,     0,     1,
       4,     2,     1,     0,     1,     1,     2,     3,     1,     3,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       5,     7,     5,     7,     3,     3,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     0,     5,
       3,     2,     1,     1,     1,     3,     3,     3,     3,     2,
       5,     3
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
        case 2:
#line 83 "parser.y" /* yacc.c:1646  */
    {
								(*global_sym_table).set_table_scope(global);
								program_object.set_global_table(*global_sym_table);
							}
#line 1407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 89 "parser.y" /* yacc.c:1646  */
    {
								/* no actions */
							}
#line 1415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 93 "parser.y" /* yacc.c:1646  */
    {
								
								/*push variables in global_symbol_table */
								for(list<Symbol_Table_Entry*>::iterator it = (*(yyvsp[-1].symbol_entry_list)).begin(); it != (*(yyvsp[-1].symbol_entry_list)).end(); it++) {
									(*it)->set_symbol_scope(global);
									Symbol_Table x;
									x.push_symbol(*it);
									x.set_table_scope(global);
									(*global_sym_table).append_list(x, (*it)->get_lineno());
								}
							}
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 105 "parser.y" /* yacc.c:1646  */
    {
								/*no actions */
							}
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 141 "parser.y" /* yacc.c:1646  */
    {
								(yyval.procedure) = new Procedure((yyvsp[-5].data_type), *(yyvsp[-4].string_value), yylineno);
								program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
								program_object.print();
							}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 147 "parser.y" /* yacc.c:1646  */
    {
								(yyval.procedure) = new Procedure((yyvsp[-5].data_type), *(yyvsp[-4].string_value), yylineno);
								program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
								program_object.print();
							}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 153 "parser.y" /* yacc.c:1646  */
    {
								(yyval.procedure) = new Procedure(void_data_type, *(yyvsp[-4].string_value), yylineno);
								program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
								program_object.print();
							}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "parser.y" /* yacc.c:1646  */
    {
								(yyval.procedure) = new Procedure(void_data_type, *(yyvsp[-4].string_value), yylineno);
								program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
								program_object.print();
							}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 167 "parser.y" /* yacc.c:1646  */
    {
								(yyval.data_type) = int_data_type;
							}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 171 "parser.y" /* yacc.c:1646  */
    {
								(yyval.data_type) = double_data_type;
							}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 177 "parser.y" /* yacc.c:1646  */
    {
									(yyval.symbol_table) = (yyvsp[-2].symbol_table);
									string d = "dummy";
									Symbol_Table_Entry *x = new Symbol_Table_Entry(d, (yyvsp[0].data_type), yylineno);
									(yyval.symbol_table)->push_symbol(x);
								}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 184 "parser.y" /* yacc.c:1646  */
    {
									(yyval.symbol_table) = new Symbol_Table();
									string d = "dummy";
									Symbol_Table_Entry *x = new Symbol_Table_Entry(d, (yyvsp[0].data_type), yylineno);
									(yyval.symbol_table)->push_symbol(x);
								}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 194 "parser.y" /* yacc.c:1646  */
    {

								}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 198 "parser.y" /* yacc.c:1646  */
    {
									
								}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 217 "parser.y" /* yacc.c:1646  */
    {
									current_procedure_name = *(yyvsp[-3].string_value);
								}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 223 "parser.y" /* yacc.c:1646  */
    {	
									/* TODO: check declarations for this name. If it exists, signature should match.
									Then set names of parameters, create new local variables for the parameters.
									if it doesn't exist create new entry in proc map. */

									(yyval.procedure) = new Procedure((yyvsp[-9].data_type), *(yyvsp[-8].string_value), yylineno);
									(yyval.procedure)->set_formal_param_list(*(yyvsp[-6].symbol_table));

									if(program_object.is_procedure_exists(*(yyvsp[-8].string_value)))
									{
										Procedure *declared_proc = program_object.get_procedure_prototype(*(yyvsp[-8].string_value));

										if(declared_proc->is_proc_defined()) {
											cerr << "cs316: Error: Line "<<yylineno<<": procedure already defined\n";
										}

										if((yyvsp[-9].data_type) != declared_proc->get_return_type()) {
											cerr << "cs316: Error: Line "<<yylineno<<": return type in declaration and definition not matching\n";
										}

										list<Symbol_Table_Entry *> decl_table = declared_proc->get_formal_param_list().get_table();
										list<Symbol_Table_Entry *> def_table = (yyvsp[-6].symbol_table)->get_table();

										list<Symbol_Table_Entry *>::iterator it1 = decl_table.begin();
										list<Symbol_Table_Entry *>::iterator it2 = def_table.begin();
										int i=0;
										while(it1 != decl_table.end() && it2 != def_table.end()) {
											if((*it1)->get_data_type() != (*it2)->get_data_type())
											{
												cerr << "cs316: Error: Line "<<yylineno<<": Declared and defined parameter types don't match\n";
											}
										}
										if(it1 != decl_table.end() || it2 != def_table.end()) {
											cerr << "cs316: Error: Line "<<yylineno<<": Declared and defined parameter counts don't match\n";
										}

										/*paramter types match */
									}
									else {
										program_object.set_proc_to_map(*(yyvsp[-8].string_value), (yyval.procedure));
									}


									(*local_sym_table).set_table_scope(local);
									(*(yyval.procedure)).set_local_list((*local_sym_table));
									(*(yyval.procedure)).set_ast_list(*((yyvsp[-1].ast_list)));

									local_sym_table = new Symbol_Table;
									program_object.set_procedure((yyval.procedure), yylineno);
								}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 276 "parser.y" /* yacc.c:1646  */
    {
									(yyval.symbol_table) = new Symbol_Table();
								}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 280 "parser.y" /* yacc.c:1646  */
    {
									(yyval.symbol_table) = (yyvsp[0].symbol_table);
								}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 286 "parser.y" /* yacc.c:1646  */
    {
									Symbol_Table_Entry *ste = new Symbol_Table_Entry(*(yyvsp[0].string_value), (yyvsp[-1].data_type), yylineno);
									(yyval.symbol_table)->push_symbol(ste);
								}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 291 "parser.y" /* yacc.c:1646  */
    {
									(yyval.symbol_table) = new Symbol_Table();
									Symbol_Table_Entry *ste = new Symbol_Table_Entry(*(yyvsp[0].string_value), (yyvsp[-1].data_type), yylineno);
									(yyval.symbol_table)->push_symbol(ste);
								}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 311 "parser.y" /* yacc.c:1646  */
    {
											for(list<Symbol_Table_Entry*>::iterator it = (*(yyvsp[0].symbol_entry_list)).begin(); it != (*(yyvsp[0].symbol_entry_list)).end(); it++) {
												(*it)->set_symbol_scope(local);
												Symbol_Table x;
												x.push_symbol(*it);
												x.set_table_scope(local);
												(*local_sym_table).append_list(x, (*it)->get_lineno());
											}
										}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 323 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_entry_list) = new list<Symbol_Table_Entry *>();
										}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 327 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_entry_list) = (yyvsp[0].symbol_entry_list);
										}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 333 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_entry_list) = (yyvsp[0].symbol_entry_list);
										}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 337 "parser.y" /* yacc.c:1646  */
    {
											for(list<Symbol_Table_Entry*>::iterator it = (*(yyvsp[0].symbol_entry_list)).begin(); it != (*(yyvsp[0].symbol_entry_list)).end(); it++) {
												(*((yyvsp[-1].symbol_entry_list))).push_back(*it);
											}
											(yyval.symbol_entry_list) = (yyvsp[-1].symbol_entry_list);
										}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 353 "parser.y" /* yacc.c:1646  */
    {
											for(list<Symbol_Table_Entry*>::iterator it = (*(yyvsp[-1].symbol_entry_list)).begin(); it != (*(yyvsp[-1].symbol_entry_list)).end(); it++) {
												(*it)->set_data_type((yyvsp[-2].data_type));
											}
											(yyval.symbol_entry_list) = (yyvsp[-1].symbol_entry_list);
										}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 362 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_entry_list) = new list<Symbol_Table_Entry *>();
											*(yyvsp[0].string_value) = *(yyvsp[0].string_value) + "_";
											Symbol_Table_Entry* a = new Symbol_Table_Entry(*(yyvsp[0].string_value), int_data_type,yylineno);
											(*(yyval.symbol_entry_list)).push_back(a);
										}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 369 "parser.y" /* yacc.c:1646  */
    {
											*(yyvsp[0].string_value) = *(yyvsp[0].string_value) + "_";
											Symbol_Table_Entry* b = new Symbol_Table_Entry(*(yyvsp[0].string_value), int_data_type,yylineno);
											(*(yyvsp[-2].symbol_entry_list)).push_back(b); /* TODO: Clarify from the TA */
											(yyval.symbol_entry_list) = (yyvsp[-2].symbol_entry_list);
										}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 379 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast_list) = new list<Ast *>();
							}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 383 "parser.y" /* yacc.c:1646  */
    {
								(*(yyvsp[-1].ast_list)).push_back((yyvsp[0].ast));
								(yyval.ast_list) = (yyvsp[-1].ast_list);
							}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 392 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 396 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 400 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 405 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 409 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].call_ast);
							}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 413 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 420 "parser.y" /* yacc.c:1646  */
    {
								if((*(yyvsp[-1].ast_list)).empty()) 	/*body empty */
								{
									yyerror("cs316: Error: Block of statements cannot be empty");
									exit(1);
								}
			
								Sequence_Ast* temp = new Sequence_Ast(yylineno);
								for(list<Ast*>::iterator it = (*(yyvsp[-1].ast_list)).begin(); it != (*(yyvsp[-1].ast_list)).end(); it++) {
									temp->ast_push_back(*it);
								}
								(yyval.ast) = temp;
							}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 435 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 441 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno, 0); 	/*last arg is bool do_form */
							}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 445 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[-5].ast), yylineno, 1); 	/*last arg is bool do_form */	
							}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 451 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Selection_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), NULL, yylineno);
							}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 455 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Selection_Statement_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
							}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 461 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_and, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 466 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_or, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 471 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Logical_Expr_Ast(NULL, _logical_not, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 476 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
								(*(yyval.ast)).check_ast();
							}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 481 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[-1].ast);
							}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 487 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), equalto, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 492 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), not_equalto, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 497 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), less_than, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 502 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), less_equalto, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 507 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), greater_than, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 512 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), greater_equalto, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 522 "parser.y" /* yacc.c:1646  */
    {
								*(yyvsp[-3].string_value) = *(yyvsp[-3].string_value) + "_";
								if(!(*local_sym_table).is_empty() && (*local_sym_table).variable_in_symbol_list_check(*(yyvsp[-3].string_value))){ 
									Ast* lhs1 = new Name_Ast(*(yyvsp[-3].string_value), (*local_sym_table).get_symbol_table_entry(*(yyvsp[-3].string_value)), yylineno);
									(yyval.ast) = new Assignment_Ast(lhs1,(yyvsp[-1].ast),yylineno);
									(*(yyval.ast)).check_ast();
								}
								else if(!(*global_sym_table).is_empty() && (*global_sym_table).variable_in_symbol_list_check(*(yyvsp[-3].string_value))){
									Ast* lhs2 = new Name_Ast(*(yyvsp[-3].string_value), (*global_sym_table).get_symbol_table_entry(*(yyvsp[-3].string_value)), yylineno);
									(yyval.ast) = new Assignment_Ast(lhs2,(yyvsp[-1].ast),yylineno);
									(*(yyval.ast)).check_ast();
								}
								else{
									yyerror("cs316: Error: Variable has not been declared/defined");
									exit(1);
								}
							}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 542 "parser.y" /* yacc.c:1646  */
    {
								*(yyvsp[-1].string_value) = *(yyvsp[-1].string_value) + "_";
								if(!(*local_sym_table).is_empty() && (*local_sym_table).variable_in_symbol_list_check(*(yyvsp[-1].string_value))){ 
									Ast* var = new Name_Ast(*(yyvsp[-1].string_value), (*local_sym_table).get_symbol_table_entry(*(yyvsp[-1].string_value)), yylineno);
									(yyval.ast) = new Print_Ast(var, yylineno);
								}
								else if(!(*global_sym_table).is_empty() && (*global_sym_table).variable_in_symbol_list_check(*(yyvsp[-1].string_value))){
									Ast* var = new Name_Ast(*(yyvsp[-1].string_value), (*global_sym_table).get_symbol_table_entry(*(yyvsp[-1].string_value)), yylineno);
									(yyval.ast) = new Print_Ast(var, yylineno);
								}
								else{
									yyerror("cs316: Error: Variable has not been declared/defined");
									exit(1);
								}
							}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 559 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast_list)->push_back((yyvsp[0].ast));
							}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 563 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast_list) = new list<Ast*>();
							}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 568 "parser.y" /* yacc.c:1646  */
    {
								/*what does this check exactly */
								if(! program_object.is_procedure_exists(*(yyvsp[-4].string_value))) {
									yyerror("Unknown procedure.");
									exit(1);
								}
								(yyval.call_ast) = new Call_Ast(*(yyvsp[-4].string_value), yylineno);
								(yyval.call_ast)->set_actual_param_list(*(yyvsp[-2].ast_list));
								Procedure *proc = program_object.get_procedure_prototype(*(yyvsp[-4].string_value));
								(yyval.call_ast)->check_actual_formal_param(proc->get_formal_param_list());
							}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 581 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Return_Ast((yyvsp[-1].ast), current_procedure_name, yylineno);
							}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 585 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Return_Ast(NULL, current_procedure_name, yylineno);
							}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 591 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Number_Ast<int>((yyvsp[0].integer_value), int_data_type, yylineno);
							}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 595 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Number_Ast<double>((yyvsp[0].double_value), double_data_type, yylineno);
							}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 599 "parser.y" /* yacc.c:1646  */
    {
								*(yyvsp[0].string_value) = *(yyvsp[0].string_value) + "_";
								if(!(*local_sym_table).is_empty() && (*local_sym_table).variable_in_symbol_list_check(*((yyvsp[0].string_value)))){
									(yyval.ast) = new Name_Ast(*(yyvsp[0].string_value), (*local_sym_table).get_symbol_table_entry(*(yyvsp[0].string_value)), yylineno);
								}
								else if(!(*global_sym_table).is_empty() && (*global_sym_table).variable_in_symbol_list_check(*(yyvsp[0].string_value))){
									(yyval.ast) = new Name_Ast(*(yyvsp[0].string_value), (*global_sym_table).get_symbol_table_entry(*(yyvsp[0].string_value)), yylineno);
								}
								else{
									yyerror("cs316: Error: Variable has not been declared/defined");
									exit(1);
								}
							}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 613 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Plus_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
								(*(yyval.ast)).set_data_type((*(yyvsp[-2].ast)).get_data_type());
							}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 619 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Minus_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
								(*(yyval.ast)).set_data_type((*(yyvsp[-2].ast)).get_data_type());
							}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 625 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Mult_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
								(*(yyval.ast)).set_data_type((*(yyvsp[-2].ast)).get_data_type());
							}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 631 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Divide_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
								(*(yyval.ast)).set_data_type((*(yyvsp[-2].ast)).get_data_type());
							}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 637 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new UMinus_Ast((yyvsp[0].ast),NULL,yylineno);
								(*(yyval.ast)).check_ast();
								(*(yyval.ast)).set_data_type((*(yyvsp[0].ast)).get_data_type());
							}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 643 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Conditional_Expression_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
								(*(yyvsp[-4].ast)).check_ast();
								(*(yyval.ast)).check_ast();

							}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 650 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[-1].ast);
							}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2131 "y.tab.c" /* yacc.c:1646  */
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
#line 656 "parser.y" /* yacc.c:1906  */
