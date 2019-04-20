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
	Data_Type current_procedure_type = int_data_type;

#line 82 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "parser.y" /* yacc.c:355  */

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

#line 166 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 183 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

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
       0,    72,    72,    78,    86,    96,   102,   110,   118,   126,
     136,   140,   146,   153,   163,   167,   175,   173,   242,   240,
     306,   309,   315,   321,   330,   343,   346,   352,   356,   365,
     374,   381,   392,   395,   402,   406,   410,   415,   419,   423,
     430,   445,   451,   455,   461,   465,   471,   476,   481,   486,
     491,   497,   502,   507,   512,   517,   522,   531,   552,   569,
     573,   579,   584,   589,   610,   618,   627,   631,   635,   649,
     655,   661,   667,   673,   679,   686
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
  "procedure_definition", "$@1", "$@2", "optional_formal_param_list",
  "formal_param_list", "local_variable_declaration_list",
  "optional_variable_declaration_list", "variable_declaration_list",
  "variable_declaration", "variable_list", "statement_list", "statement",
  "sequence_statement", "iteration_statement", "selection_statement",
  "log_expression", "rel_expression", "assignment_statement",
  "print_statement", "actual_param_list", "optional_actual_param_list",
  "call_stmt", "return_stmt", "arith_expression", YY_NULLPTR
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

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,   -87,   -87,     8,    43,   -87,    -1,    63,    33,   -87,
      -1,    50,   -87,   -87,    54,   -17,    96,    97,   -87,   -87,
      66,    66,   -87,   100,    75,    80,   111,    36,    83,    85,
      46,    95,   -87,    66,    66,   -87,    81,    66,    88,    66,
      92,    99,   111,    98,   101,   -87,   -87,   -87,    94,   134,
     -87,   -87,   103,   -87,   -87,    66,   -87,    66,   135,   -87,
     -87,    66,   -87,   -87,   -87,    52,   -87,    65,    -7,    89,
     115,   118,    93,   153,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   108,   108,   -87,   -87,   -87,
     108,   108,   108,   -87,   126,   -87,   125,   108,   108,   146,
     124,    82,   144,   131,   136,   196,   -87,   196,   -87,     4,
     163,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   -87,   102,   197,   138,   -87,   -87,
     -87,   108,   133,   -87,   -87,   -87,   154,   181,   196,   196,
     196,   196,   196,   196,    29,    29,   -87,   -87,    93,    93,
     108,   196,   -87,   108,   -87,   161,   206,   196,    93,   143,
     -87,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,     0,     0,     2,     0,     0,     3,    14,
       0,     0,     1,     5,    30,     0,     0,     0,    15,     4,
      20,    20,    29,     0,     0,     0,    13,     0,     0,    21,
       0,     0,    31,    20,    20,    23,     0,     0,    18,     0,
       0,    16,     0,     0,     0,     8,    12,     9,     0,     0,
       6,     7,     0,    18,    16,    25,    22,    25,     0,    32,
      24,    26,    27,    32,    30,     0,    28,     0,     0,     0,
       0,     0,     0,     0,    32,    19,    41,    33,    35,    36,
      34,    37,    38,    39,    17,     0,    62,    66,    67,    68,
       0,     0,     0,    65,     0,    49,     0,     0,     0,     0,
       0,     0,     0,    61,     0,    60,    48,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,     0,     0,     0,    58,    40,
      57,     0,     0,    50,    75,    46,    47,     0,    51,    53,
      55,    54,    56,    52,    69,    70,    71,    72,     0,     0,
       0,    59,    63,     0,    42,    44,     0,    74,     0,     0,
      45,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,    27,   -87,     1,   149,   -87,   179,   -87,   -87,
     -19,   -87,   132,   -87,   -87,   -25,   -87,   -58,   -87,   -72,
     -87,   -87,   -86,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    27,     8,     9,    52,    48,
      28,    29,    59,    60,    61,    10,    15,    65,    76,    77,
      78,    79,    94,    95,    80,    81,   103,   104,    82,    83,
     107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      99,    96,    31,    85,   106,    67,   109,     1,     2,    17,
       3,   125,   126,    11,    43,    44,   101,   102,   105,    22,
      23,    26,    26,   108,   110,   135,   136,    86,   111,   112,
      62,   113,    62,    13,    42,    42,    66,    19,    46,   133,
      49,     1,     2,    12,    16,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    58,    68,    58,    69,
     122,   123,    58,   151,   156,    70,    71,    72,    14,    73,
      68,    36,    69,    37,     1,     2,   154,   155,    70,    71,
      72,    40,    73,    37,    20,   157,   160,    68,    21,    69,
      74,    75,    87,    88,    89,    70,    71,    72,    68,    73,
      69,    24,    25,    74,    84,    32,    70,    71,    72,    33,
      73,    87,    88,    89,    34,    90,    35,    45,    38,    91,
      74,   129,    39,    92,    47,    93,   111,   112,    50,   113,
      41,    74,    55,    53,    90,    51,    54,   148,    91,    56,
      64,    57,    92,   114,   115,   116,   117,   118,   119,    97,
     111,   112,    98,   113,   120,   121,   122,   123,   100,   127,
     128,   124,   114,   115,   116,   117,   118,   119,   131,   152,
      30,   132,   150,   120,   121,   122,   123,   158,   111,   161,
     130,   114,   115,   116,   117,   118,   119,    18,     0,    63,
       0,     0,   120,   121,   122,   123,     0,     0,   134,   114,
     115,   116,   117,   118,   119,     0,     0,     0,     0,   153,
     120,   121,   122,   123,   114,   115,   116,   117,   118,   119,
       0,   111,   112,     0,   113,   120,   121,   122,   123,     0,
     111,   112,   149,   113,     0,     0,     0,     0,     0,     0,
       0,   159
};

static const yytype_int16 yycheck[] =
{
      72,    69,    21,    10,    90,    63,    92,     8,     9,     8,
      11,    97,    98,     5,    33,    34,    74,    85,    86,    36,
      37,    20,    21,    91,    92,   111,   112,    34,    24,    25,
      55,    27,    57,     6,    33,    34,    61,    10,    37,    35,
      39,     8,     9,     0,    11,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    55,     5,    57,     7,
      31,    32,    61,   131,   150,    13,    14,    15,     5,    17,
       5,    35,     7,    37,     8,     9,   148,   149,    13,    14,
      15,    35,    17,    37,    34,   153,   158,     5,    34,     7,
      38,    39,     3,     4,     5,    13,    14,    15,     5,    17,
       7,     5,     5,    38,    39,     5,    13,    14,    15,    34,
      17,     3,     4,     5,    34,    26,     5,    36,    35,    30,
      38,    39,    37,    34,    36,    36,    24,    25,    36,    27,
      35,    38,    38,    35,    26,    36,    35,    35,    30,     5,
       5,    38,    34,    18,    19,    20,    21,    22,    23,    34,
      24,    25,    34,    27,    29,    30,    31,    32,     5,    13,
      36,    36,    18,    19,    20,    21,    22,    23,    37,    36,
      21,    35,    34,    29,    30,    31,    32,    16,    24,    36,
      36,    18,    19,    20,    21,    22,    23,     8,    -1,    57,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    35,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    18,    19,    20,    21,    22,    23,
      -1,    24,    25,    -1,    27,    29,    30,    31,    32,    -1,
      24,    25,    35,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    11,    41,    42,    43,    44,    46,    47,
      55,     5,     0,    42,     5,    56,    11,    44,    47,    42,
      34,    34,    36,    37,     5,     5,    44,    45,    50,    51,
      45,    50,     5,    34,    34,     5,    35,    37,    35,    37,
      35,    35,    44,    50,    50,    36,    44,    36,    49,    44,
      36,    36,    48,    35,    35,    38,     5,    38,    44,    52,
      53,    54,    55,    52,     5,    57,    55,    57,     5,     7,
      13,    14,    15,    17,    38,    39,    58,    59,    60,    61,
      64,    65,    68,    69,    39,    10,    34,     3,     4,     5,
      26,    30,    34,    36,    62,    63,    70,    34,    34,    59,
       5,    57,    70,    66,    67,    70,    62,    70,    70,    62,
      70,    24,    25,    27,    18,    19,    20,    21,    22,    23,
      29,    30,    31,    32,    36,    62,    62,    13,    36,    39,
      36,    37,    35,    35,    35,    62,    62,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    35,    35,
      34,    70,    36,    28,    59,    59,    62,    70,    16,    35,
      59,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    43,    43,    43,    43,
      44,    44,    45,    45,    46,    46,    48,    47,    49,    47,
      50,    50,    51,    51,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    64,    65,    66,
      66,    67,    67,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     6,     6,     6,     6,
       1,     1,     3,     1,     1,     2,     0,    10,     0,    10,
       0,     1,     4,     2,     1,     0,     1,     1,     2,     3,
       1,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     5,     7,     5,     7,     3,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     3,
       1,     1,     0,     5,     3,     2,     1,     1,     1,     3,
       3,     3,     3,     2,     5,     3
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
#line 73 "parser.y" /* yacc.c:1646  */
    {
								(*global_sym_table).set_table_scope(global);
								program_object.set_global_table(*global_sym_table);
							}
#line 1394 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "parser.y" /* yacc.c:1646  */
    {
								/* check for parameterless void main function */
								if(!(program_object.is_procedure_exists("main") && program_object.get_procedure_prototype("main")->get_return_type() == void_data_type)) {
									cerr << "cs316: Error: Line "<<yylineno<<":  Main should be defined and its type should be void\n";
									exit(1);
								}
							}
#line 1406 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "parser.y" /* yacc.c:1646  */
    {
								for(list<Symbol_Table_Entry*>::iterator it = (*(yyvsp[-1].symbol_entry_list)).begin(); it != (*(yyvsp[-1].symbol_entry_list)).end(); it++) {
									(*it)->set_symbol_scope(global);
									Symbol_Table x;
									x.push_symbol(*it);
									x.set_table_scope(global);
									(*global_sym_table).append_list(x, (*it)->get_lineno());
								}
							}
#line 1420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "parser.y" /* yacc.c:1646  */
    {
								/*no actions */
							}
#line 1428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 103 "parser.y" /* yacc.c:1646  */
    {	
								if(*(yyvsp[-4].string_value) != "main")
									*(yyvsp[-4].string_value) = *(yyvsp[-4].string_value) + "_";
								(yyval.procedure) = new Procedure((yyvsp[-5].data_type), *(yyvsp[-4].string_value), yylineno);
								(yyval.procedure)->set_formal_param_list(*(yyvsp[-2].symbol_table));
								program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
							}
#line 1440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 111 "parser.y" /* yacc.c:1646  */
    {
								if(*(yyvsp[-4].string_value) != "main")
									*(yyvsp[-4].string_value) = *(yyvsp[-4].string_value) + "_";
								(yyval.procedure) = new Procedure((yyvsp[-5].data_type), *(yyvsp[-4].string_value), yylineno);
								(yyval.procedure)->set_formal_param_list(*(yyvsp[-2].symbol_table));
								program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
							}
#line 1452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 119 "parser.y" /* yacc.c:1646  */
    {
								if(*(yyvsp[-4].string_value) != "main")
									*(yyvsp[-4].string_value) = *(yyvsp[-4].string_value) + "_";
								(yyval.procedure) = new Procedure(void_data_type, *(yyvsp[-4].string_value), yylineno);
								(yyval.procedure)->set_formal_param_list(*(yyvsp[-2].symbol_table));
								program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
							}
#line 1464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "parser.y" /* yacc.c:1646  */
    {
								if(*(yyvsp[-4].string_value) != "main")
									*(yyvsp[-4].string_value) = *(yyvsp[-4].string_value) + "_";
								(yyval.procedure) = new Procedure(void_data_type, *(yyvsp[-4].string_value), yylineno);
								(yyval.procedure)->set_formal_param_list(*(yyvsp[-2].symbol_table));
								program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
							}
#line 1476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 137 "parser.y" /* yacc.c:1646  */
    {
								(yyval.data_type) = int_data_type;
							}
#line 1484 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 141 "parser.y" /* yacc.c:1646  */
    {
								(yyval.data_type) = double_data_type;
							}
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 147 "parser.y" /* yacc.c:1646  */
    {
									(yyval.symbol_table) = (yyvsp[-2].symbol_table);
									string d = "dummy";
									Symbol_Table_Entry *x = new Symbol_Table_Entry(d, (yyvsp[0].data_type), yylineno);
									(yyval.symbol_table)->push_symbol(x);
								}
#line 1503 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 154 "parser.y" /* yacc.c:1646  */
    {
									(yyval.symbol_table) = new Symbol_Table();
									string d = "dummy";
									Symbol_Table_Entry *x = new Symbol_Table_Entry(d, (yyvsp[0].data_type), yylineno);
									(yyval.symbol_table)->push_symbol(x);
								}
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 164 "parser.y" /* yacc.c:1646  */
    {
									/*no actions */
								}
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 168 "parser.y" /* yacc.c:1646  */
    {
									/*no actions */
								}
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 175 "parser.y" /* yacc.c:1646  */
    {
									if(*(yyvsp[-3].string_value) != "main")
										*(yyvsp[-3].string_value) = *(yyvsp[-3].string_value) + "_";
									current_procedure_name = *(yyvsp[-3].string_value);
									current_procedure_type = (yyvsp[-4].data_type);
									(*local_sym_table).append_list(*(yyvsp[-1].symbol_table), yylineno);
								}
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 185 "parser.y" /* yacc.c:1646  */
    {
									(yyval.procedure) = new Procedure((yyvsp[-9].data_type), *(yyvsp[-8].string_value), yylineno);
									(yyvsp[-6].symbol_table)->set_table_scope(formal);
									(yyval.procedure)->set_formal_param_list(*(yyvsp[-6].symbol_table));

									if(program_object.is_procedure_exists(*(yyvsp[-8].string_value)))
									{
										Procedure *declared_proc = program_object.get_procedure_prototype(*(yyvsp[-8].string_value));

										if(declared_proc->is_proc_defined()) {
											cerr << "cs316: Error: Line "<<yylineno<<": procedure already defined\n";
											exit(1);
										}

										if((yyvsp[-9].data_type) != declared_proc->get_return_type()) {
											cerr << "cs316: Error: Line "<<yylineno<<": return type in declaration and definition not matching\n";
											exit(1);
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
												exit(1);
											}
											it1++;
											it2++;
										}
										if(decl_table.size() != def_table.size()) {
											declared_proc->get_formal_param_list().print(cerr);
											cerr << "cs316: Error: Line "<<yylineno<<": Declared and defined parameter counts don't match\n";
											exit(1);
										}

										/*paramters match */
									}
									else {
										program_object.set_proc_to_map(*(yyvsp[-8].string_value), (yyval.procedure));
									}


									(*local_sym_table).set_table_scope(local);
									(*(yyval.procedure)).set_local_list((*local_sym_table));
									(*(yyval.procedure)).set_ast_list(*((yyvsp[-1].ast_list)));
									// $$->set_proc_is_defined();
									local_sym_table = new Symbol_Table;
									program_object.set_procedure((yyval.procedure), yylineno);
								}
#line 1601 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 242 "parser.y" /* yacc.c:1646  */
    {
									if(*(yyvsp[-3].string_value) != "main")
										*(yyvsp[-3].string_value) = *(yyvsp[-3].string_value) + "_";
									current_procedure_name = *(yyvsp[-3].string_value);
									current_procedure_type = void_data_type;
									(*local_sym_table).append_list(*(yyvsp[-1].symbol_table), yylineno);
								}
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 252 "parser.y" /* yacc.c:1646  */
    {	
									(yyval.procedure) = new Procedure(void_data_type, *(yyvsp[-8].string_value), yylineno);
									(yyvsp[-6].symbol_table)->set_table_scope(formal);
									(yyval.procedure)->set_formal_param_list(*(yyvsp[-6].symbol_table));

									if(program_object.is_procedure_exists(*(yyvsp[-8].string_value)))
									{
										Procedure *declared_proc = program_object.get_procedure_prototype(*(yyvsp[-8].string_value));

										if(declared_proc->is_proc_defined()) {
											cerr << "cs316: Error: Line "<<yylineno<<": procedure already defined\n";
											exit(1);
										}

										if(void_data_type != declared_proc->get_return_type()) {
											cerr << "cs316: Error: Line "<<yylineno<<": return type in declaration and definition not matching\n";
											exit(1);
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
												exit(1);
											}
											it1++;
											it2++;
										}
										if(decl_table.size() != def_table.size()) {
											cerr << "cs316: Error: Line "<<yylineno<<": Declared and defined parameter counts don't match\n";
											exit(1);
										}
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
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 306 "parser.y" /* yacc.c:1646  */
    {
									(yyval.symbol_table) = new Symbol_Table();
								}
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 310 "parser.y" /* yacc.c:1646  */
    {
									(yyval.symbol_table) = (yyvsp[0].symbol_table);
								}
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 316 "parser.y" /* yacc.c:1646  */
    {
									*(yyvsp[0].string_value) = *(yyvsp[0].string_value) + "_";
									Symbol_Table_Entry *ste = new Symbol_Table_Entry(*(yyvsp[0].string_value), (yyvsp[-1].data_type), yylineno);
									(yyval.symbol_table)->push_symbol(ste);
								}
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 322 "parser.y" /* yacc.c:1646  */
    {
									*(yyvsp[0].string_value) = *(yyvsp[0].string_value) + "_";
									(yyval.symbol_table) = new Symbol_Table();
									Symbol_Table_Entry *ste = new Symbol_Table_Entry(*(yyvsp[0].string_value), (yyvsp[-1].data_type), yylineno);
									(yyval.symbol_table)->push_symbol(ste);
								}
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 331 "parser.y" /* yacc.c:1646  */
    {
											for(list<Symbol_Table_Entry*>::iterator it = (*(yyvsp[0].symbol_entry_list)).begin(); it != (*(yyvsp[0].symbol_entry_list)).end(); it++) {
												(*it)->set_symbol_scope(local);
												Symbol_Table x;
												x.push_symbol(*it);
												x.set_table_scope(local);
												(*local_sym_table).append_list(x, (*it)->get_lineno());
											}
										}
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 343 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_entry_list) = new list<Symbol_Table_Entry *>();
										}
#line 1727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 347 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_entry_list) = (yyvsp[0].symbol_entry_list);
										}
#line 1735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 353 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_entry_list) = (yyvsp[0].symbol_entry_list);
										}
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 357 "parser.y" /* yacc.c:1646  */
    {
											for(list<Symbol_Table_Entry*>::iterator it = (*(yyvsp[0].symbol_entry_list)).begin(); it != (*(yyvsp[0].symbol_entry_list)).end(); it++) {
												(*((yyvsp[-1].symbol_entry_list))).push_back(*it);
											}
											(yyval.symbol_entry_list) = (yyvsp[-1].symbol_entry_list);
										}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 366 "parser.y" /* yacc.c:1646  */
    {
											for(list<Symbol_Table_Entry*>::iterator it = (*(yyvsp[-1].symbol_entry_list)).begin(); it != (*(yyvsp[-1].symbol_entry_list)).end(); it++) {
												(*it)->set_data_type((yyvsp[-2].data_type));
											}
											(yyval.symbol_entry_list) = (yyvsp[-1].symbol_entry_list);
										}
#line 1765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 375 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_entry_list) = new list<Symbol_Table_Entry *>();
											*(yyvsp[0].string_value) = *(yyvsp[0].string_value) + "_";
											Symbol_Table_Entry* a = new Symbol_Table_Entry(*(yyvsp[0].string_value), int_data_type,yylineno);
											(*(yyval.symbol_entry_list)).push_back(a);
										}
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 382 "parser.y" /* yacc.c:1646  */
    {
											*(yyvsp[0].string_value) = *(yyvsp[0].string_value) + "_";
											Symbol_Table_Entry* b = new Symbol_Table_Entry(*(yyvsp[0].string_value), int_data_type,yylineno);
											(*(yyvsp[-2].symbol_entry_list)).push_back(b); /* TODO: Clarify from the TA */
											(yyval.symbol_entry_list) = (yyvsp[-2].symbol_entry_list);
										}
#line 1787 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 392 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast_list) = new list<Ast *>();
							}
#line 1795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 396 "parser.y" /* yacc.c:1646  */
    {
								(*(yyvsp[-1].ast_list)).push_back((yyvsp[0].ast));
								(yyval.ast_list) = (yyvsp[-1].ast_list);
							}
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 403 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1812 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 407 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 411 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 416 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1836 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 420 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].call_ast);
							}
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 424 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1852 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 431 "parser.y" /* yacc.c:1646  */
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
#line 1870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 446 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
							}
#line 1878 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 452 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno, 0); 	/*last arg is bool do_form */
							}
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 456 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[-5].ast), yylineno, 1); 	/*last arg is bool do_form */	
							}
#line 1894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 462 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Selection_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), NULL, yylineno);
							}
#line 1902 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 466 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Selection_Statement_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
							}
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 472 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_and, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1919 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 477 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_or, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 482 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Logical_Expr_Ast(NULL, _logical_not, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1937 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 487 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[0].ast);
								(*(yyval.ast)).check_ast();
							}
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 492 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[-1].ast);
							}
#line 1954 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 498 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), equalto, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1963 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 503 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), not_equalto, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1972 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 508 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), less_than, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1981 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 513 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), less_equalto, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 518 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), greater_than, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 1999 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 523 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), greater_equalto, (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
							}
#line 2008 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 533 "parser.y" /* yacc.c:1646  */
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
#line 2030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 553 "parser.y" /* yacc.c:1646  */
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
#line 2050 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 570 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast_list)->push_back((yyvsp[0].ast));
							}
#line 2058 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 574 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast_list) = new list<Ast*>();
								(yyval.ast_list)->push_back((yyvsp[0].ast));
							}
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 580 "parser.y" /* yacc.c:1646  */
    {
									(yyval.ast_list) = (yyvsp[0].ast_list);
								}
#line 2075 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 584 "parser.y" /* yacc.c:1646  */
    {
									(yyval.ast_list) = new list<Ast*>();
								}
#line 2083 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 590 "parser.y" /* yacc.c:1646  */
    {
								if(*(yyvsp[-4].string_value) != "main")
										*(yyvsp[-4].string_value) = *(yyvsp[-4].string_value) + "_";
								/* What does this check exactly ? */
								if(! program_object.is_procedure_exists(*(yyvsp[-4].string_value))) {
									cerr << "cs316: Error: Line "<<yylineno<<": Unknown procedure.\n";
									exit(1);
								}
								(yyval.call_ast) = new Call_Ast(*(yyvsp[-4].string_value), yylineno);
								(yyval.call_ast)->set_actual_param_list(*(yyvsp[-2].ast_list));
								Procedure *proc = program_object.get_procedure_prototype(*(yyvsp[-4].string_value));


								(yyval.call_ast)->check_actual_formal_param(proc->get_formal_param_list());
								// /*debug */
								// proc->get_formal_param_list().print(cerr);
								// /*debug */
							}
#line 2106 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 611 "parser.y" /* yacc.c:1646  */
    {
								if(!(current_procedure_type == (*(yyvsp[-1].ast)).get_data_type())) {
									cerr << "cs316: Error: Line "<<yylineno<<":  Return datatype didn't match with the definition datatype\n";
									exit(1);
								}
								(yyval.ast) = new Return_Ast((yyvsp[-1].ast), current_procedure_name, yylineno);
							}
#line 2118 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 619 "parser.y" /* yacc.c:1646  */
    {
								if(!(current_procedure_type == void_data_type)) {
									cerr << "cs316: Error: Line "<<yylineno<<":  Return datatype didn't match with the definition datatype\n";
									exit(1);
								}
								(yyval.ast) = new Return_Ast(NULL, current_procedure_name, yylineno);
							}
#line 2130 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 628 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Number_Ast<int>((yyvsp[0].integer_value), int_data_type, yylineno);
							}
#line 2138 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 632 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Number_Ast<double>((yyvsp[0].double_value), double_data_type, yylineno);
							}
#line 2146 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 636 "parser.y" /* yacc.c:1646  */
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
#line 2164 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 650 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Plus_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
								(*(yyval.ast)).set_data_type((*(yyvsp[-2].ast)).get_data_type());
							}
#line 2174 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 656 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Minus_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
								(*(yyval.ast)).set_data_type((*(yyvsp[-2].ast)).get_data_type());
							}
#line 2184 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 662 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Mult_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
								(*(yyval.ast)).set_data_type((*(yyvsp[-2].ast)).get_data_type());
							}
#line 2194 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 668 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Divide_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
								(*(yyval.ast)).check_ast();
								(*(yyval.ast)).set_data_type((*(yyvsp[-2].ast)).get_data_type());
							}
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 674 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new UMinus_Ast((yyvsp[0].ast),NULL,yylineno);
								(*(yyval.ast)).check_ast();
								(*(yyval.ast)).set_data_type((*(yyvsp[0].ast)).get_data_type());
							}
#line 2214 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 680 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new Conditional_Expression_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
								(*(yyvsp[-4].ast)).check_ast();
								(*(yyval.ast)).check_ast();

							}
#line 2225 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 687 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = (yyvsp[-1].ast);
							}
#line 2233 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2237 "parser.tab.c" /* yacc.c:1646  */
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
#line 693 "parser.y" /* yacc.c:1906  */
