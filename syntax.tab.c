/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

#include "lex.yy.c"
#include "stdio.h"

#include "node.h"
#include "error.h"

void yyerror(const char* msg) {}

struct Node *root_node = NULL;

#line 82 "syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ERR = 258,
    INT = 259,
    FLOAT = 260,
    CHAR = 261,
    ID = 262,
    TYPE = 263,
    STRUCT = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    RETURN = 268,
    FOR = 269,
    DOT = 270,
    SEMI = 271,
    COMMA = 272,
    ASSIGN = 273,
    PLUS = 274,
    MINUS = 275,
    MUL = 276,
    DIV = 277,
    AND = 278,
    OR = 279,
    NOT = 280,
    LP = 281,
    RP = 282,
    LB = 283,
    RB = 284,
    LC = 285,
    RC = 286,
    LT = 287,
    LE = 288,
    GT = 289,
    GE = 290,
    NE = 291,
    EQ = 292,
    NEG = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "syntax.y"
 struct Node *node;

#line 176 "syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
    yy_state_t yyss_alloc;
    YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   491

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

#define YYUNDEFTOK  2
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
        {
                0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
                35,    36,    37,    38
        };

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
        {
                0,    52,    52,    61,    68,    75,    83,    90,    98,   101,
                108,   114,   127,   133,   143,   153,   165,   171,   180,   187,
                196,   200,   204,   216,   224,   228,   238,   244,   252,   264,
                271,   279,   286,   292,   300,   303,   306,   316,   328,   338,
                355,   362,   370,   377,   380,   387,   393,   405,   411,   419,
                427,   435,   438,   441,   449,   457,   465,   473,   481,   489,
                497,   505,   513,   521,   529,   537,   545,   548,   555,   562,
                571,   575,   583,   586,   595,   603,   609,   615,   621,   630,
                638
        };
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
        {
                "$end", "error", "$undefined", "ERR", "INT", "FLOAT", "CHAR", "ID",
                "TYPE", "STRUCT", "IF", "ELSE", "WHILE", "RETURN", "FOR", "DOT", "SEMI",
                "COMMA", "ASSIGN", "PLUS", "MINUS", "MUL", "DIV", "AND", "OR", "NOT",
                "LP", "RP", "LB", "RB", "LC", "RC", "LT", "LE", "GT", "GE", "NE", "EQ",
                "NEG", "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList",
                "Specifier", "StructSpecifier", "VarDec", "FunDec", "VarList",
                "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
                "Dec", "Exp", "Args", YY_NULLPTR
        };
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
        {
                380,    -6,   -60,     1,    12,   -60,   380,    92,   -60,   -60,
                34,   -60,   -60,   -60,    26,   -60,    14,   109,    51,    15,
                67,   -60,   -60,   104,   106,   342,   -60,   104,   104,    96,
                342,    19,   -60,   104,     0,   111,   -60,   -60,    94,    53,
                43,   119,   129,    46,   -60,   -60,   -60,   122,   122,   108,
                -60,   386,   -60,   -60,   -60,   -60,   125,   126,   134,   455,
                143,   455,   455,   455,   -60,   140,    53,    69,   371,   -60,
                104,   157,   -60,   -60,    47,   -60,   359,   455,   455,    97,
                455,    54,    54,   121,   -60,   -60,   158,   455,   168,   -60,
                395,   455,   455,   455,   455,   455,   455,   455,   455,   455,
                455,   455,   455,   455,   -60,   282,   -60,   -60,   -60,   156,
                -60,   144,    50,   167,   190,   176,   -60,   213,   169,   -60,
                -60,   305,   -60,   -60,   390,    -8,    -8,    54,    54,   436,
                413,   236,   463,   463,   463,   463,   463,   463,   -60,   455,
                181,   -60,    53,    53,   -60,   455,   -60,   -60,   -60,   -60,
                173,   -60,   259,    53,   171,   -60,    53,   -60
        };

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
        {
                0,     0,    12,     0,     0,     2,     0,     0,    13,     9,
                15,     1,     3,    18,    16,     6,     0,    10,     0,     0,
                0,     8,     5,     0,     0,     0,     7,     0,     0,     0,
                0,     0,    22,     0,     0,    25,    16,    11,     0,    30,
                47,     0,    45,     0,    14,    40,    21,    27,    26,     0,
                19,     0,    17,    76,    77,    78,    75,     0,     0,     0,
                0,     0,     0,     0,    32,     0,    30,     0,     0,    44,
                0,     0,    42,    20,     0,    23,     0,     0,     0,     0,
                0,    67,    68,     0,    28,    29,     0,     0,     0,    31,
                0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
                0,     0,     0,     0,    49,    48,    46,    43,    24,     0,
                71,    80,     0,     0,     0,     0,    33,     0,     0,    65,
                34,    51,    74,    52,    50,    61,    62,    63,    64,    53,
                54,     0,    55,    56,    57,    58,    59,    60,    72,     0,
                0,    69,     0,     0,    35,     0,    66,    73,    79,    70,
                36,    38,     0,     0,     0,    37,     0,    39
        };

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
        {
                -60,   -60,   200,   -60,   184,     5,   -60,    22,   -60,   164,
                -60,   201,   154,   110,    84,   -60,   -22,   -60,   -59,    82
        };

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
        {
                -1,     4,     5,     6,    16,    28,     8,    40,    18,    34,
                35,    64,    65,    66,    29,    30,    41,    42,    67,   112
        };

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
        {
                79,    49,    81,    82,    83,     7,    43,    88,    10,   105,
                9,     7,    11,    93,    94,    21,    27,   111,   113,   114,
                97,   117,    13,     2,     3,    33,    36,    50,   121,    17,
                22,   124,   125,   126,   127,   128,   129,   130,   131,   132,
                133,   134,   135,   136,   137,    17,   -41,    71,   106,    46,
                13,   140,    20,    47,    36,    48,    33,    53,    54,    55,
                56,    68,    72,    57,    19,    58,    59,    60,    31,    88,
                86,    24,    87,    61,   108,     2,     3,   141,    62,    63,
                111,    25,    97,    25,    88,    89,   152,    90,    91,    92,
                93,    94,    95,    96,    32,    13,    47,    97,   115,    14,
                87,    98,    99,   100,   101,   102,   103,    13,    15,    39,
                38,    36,    88,   116,    45,    90,    91,    92,    93,    94,
                95,    96,   118,    52,    87,    97,    23,    44,    51,    98,
                99,   100,   101,   102,   103,    69,    88,    24,    73,    90,
                91,    92,    93,    94,    95,    96,    70,    87,   119,    97,
                24,    76,    77,    98,    99,   100,   101,   102,   103,    88,
                78,   139,    90,    91,    92,    93,    94,    95,    96,    80,
                87,    84,    97,   107,   120,   122,    98,    99,   100,   101,
                102,   103,    88,   138,   153,    90,    91,    92,    93,    94,
                95,    96,   144,    87,   142,    97,   146,   149,   156,    98,
                99,   100,   101,   102,   103,    88,    12,    37,    90,    91,
                92,    93,    94,    95,    96,    75,    87,   143,    97,    26,
                85,   148,    98,    99,   100,   101,   102,   103,    88,   145,
                0,    90,    91,    92,    93,    94,    95,    96,     0,    87,
                0,    97,     0,     0,     0,    98,    99,   100,   101,   102,
                103,    88,   150,   151,    90,    91,    92,    93,    94,    95,
                96,     0,    87,   155,    97,   147,   157,     0,    98,    99,
                100,   101,   102,   103,    88,   154,     0,    90,    91,    92,
                93,    94,    95,    96,     0,    87,     0,    97,     0,     0,
                0,    98,    99,   100,   101,   102,   103,    88,     0,     0,
                90,    91,    92,    93,    94,    95,    96,     0,   -42,     0,
                97,     0,     0,     0,    98,    99,   100,   101,   102,   103,
                88,     0,     0,    90,    91,    92,    93,    94,    95,    96,
                0,     0,     0,    97,     0,     0,     0,    98,    99,   100,
                101,   102,   103,    27,     0,     0,   -41,   -41,   -41,   -41,
                2,     3,   -41,     0,   -41,   -41,   -41,     0,     0,     0,
                109,     0,   -41,    53,    54,    55,    56,   -41,   -41,     0,
                0,     0,   -41,   -41,   104,    53,    54,    55,    56,    61,
                -4,     1,     0,     0,    62,    63,   110,    74,     2,     3,
                0,    61,     0,     0,     2,     3,    62,    63,   123,    53,
                54,    55,    56,     0,     0,    88,     0,     0,    90,    91,
                92,    93,    94,    95,    96,    61,     0,     0,    97,     0,
                62,    63,    98,    99,   100,   101,   102,   103,    88,     0,
                0,     0,    91,    92,    93,    94,    95,     0,     0,     0,
                0,    97,     0,     0,     0,    98,    99,   100,   101,   102,
                103,    88,     0,     0,     0,    91,    92,    93,    94,    53,
                54,    55,    56,     0,    97,     0,     0,     0,    98,    99,
                100,   101,   102,   103,     0,    61,     0,     0,    88,     0,
                62,    63,    91,    92,    93,    94,     0,     0,     0,     0,
                0,    97
        };

static const yytype_int16 yycheck[] =
        {
                59,     1,    61,    62,    63,     0,    28,    15,     7,    68,
                16,     6,     0,    21,    22,     1,     1,    76,    77,    78,
                28,    80,     3,     8,     9,    20,     7,    27,    87,     7,
                16,    90,    91,    92,    93,    94,    95,    96,    97,    98,
                99,   100,   101,   102,   103,    23,    31,     1,    70,    30,
                3,     1,    26,    31,     7,    33,    51,     4,     5,     6,
                7,    18,    16,    10,    30,    12,    13,    14,     1,    15,
                1,    28,     3,    20,    27,     8,     9,    27,    25,    26,
                139,    30,    28,    30,    15,    16,   145,    18,    19,    20,
                21,    22,    23,    24,    27,     3,    74,    28,     1,     7,
                3,    32,    33,    34,    35,    36,    37,     3,    16,    25,
                4,     7,    15,    16,    30,    18,    19,    20,    21,    22,
                23,    24,     1,    29,     3,    28,    17,    31,    17,    32,
                33,    34,    35,    36,    37,    16,    15,    28,    30,    18,
                19,    20,    21,    22,    23,    24,    17,     3,    27,    28,
                28,    26,    26,    32,    33,    34,    35,    36,    37,    15,
                26,    17,    18,    19,    20,    21,    22,    23,    24,    26,
                3,    31,    28,    16,    16,     7,    32,    33,    34,    35,
                36,    37,    15,    27,    11,    18,    19,    20,    21,    22,
                23,    24,    16,     3,    27,    28,    27,    16,    27,    32,
                33,    34,    35,    36,    37,    15,     6,    23,    18,    19,
                20,    21,    22,    23,    24,    51,     3,    27,    28,    18,
                66,   139,    32,    33,    34,    35,    36,    37,    15,    16,
                -1,    18,    19,    20,    21,    22,    23,    24,    -1,     3,
                -1,    28,    -1,    -1,    -1,    32,    33,    34,    35,    36,
                37,    15,   142,   143,    18,    19,    20,    21,    22,    23,
                24,    -1,     3,   153,    28,    29,   156,    -1,    32,    33,
                34,    35,    36,    37,    15,    16,    -1,    18,    19,    20,
                21,    22,    23,    24,    -1,     3,    -1,    28,    -1,    -1,
                -1,    32,    33,    34,    35,    36,    37,    15,    -1,    -1,
                18,    19,    20,    21,    22,    23,    24,    -1,     3,    -1,
                28,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
                15,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
                -1,    -1,    -1,    28,    -1,    -1,    -1,    32,    33,    34,
                35,    36,    37,     1,    -1,    -1,     4,     5,     6,     7,
                8,     9,    10,    -1,    12,    13,    14,    -1,    -1,    -1,
                1,    -1,    20,     4,     5,     6,     7,    25,    26,    -1,
                -1,    -1,    30,    31,     3,     4,     5,     6,     7,    20,
                0,     1,    -1,    -1,    25,    26,    27,     1,     8,     9,
                -1,    20,    -1,    -1,     8,     9,    25,    26,     3,     4,
                5,     6,     7,    -1,    -1,    15,    -1,    -1,    18,    19,
                20,    21,    22,    23,    24,    20,    -1,    -1,    28,    -1,
                25,    26,    32,    33,    34,    35,    36,    37,    15,    -1,
                -1,    -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,
                -1,    28,    -1,    -1,    -1,    32,    33,    34,    35,    36,
                37,    15,    -1,    -1,    -1,    19,    20,    21,    22,     4,
                5,     6,     7,    -1,    28,    -1,    -1,    -1,    32,    33,
                34,    35,    36,    37,    -1,    20,    -1,    -1,    15,    -1,
                25,    26,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
                -1,    28
        };

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
        {
                0,     1,     8,     9,    40,    41,    42,    44,    45,    16,
                7,     0,    41,     3,     7,    16,    43,    46,    47,    30,
                26,     1,    16,    17,    28,    30,    50,     1,    44,    53,
                54,     1,    27,    44,    48,    49,     7,    43,     4,    53,
                46,    55,    56,    55,    31,    53,    30,    46,    46,     1,
                27,    17,    29,     4,     5,     6,     7,    10,    12,    13,
                14,    20,    25,    26,    50,    51,    52,    57,    18,    16,
                17,     1,    16,    30,     1,    48,    26,    26,    26,    57,
                26,    57,    57,    57,    31,    51,     1,     3,    15,    16,
                18,    19,    20,    21,    22,    23,    24,    28,    32,    33,
                34,    35,    36,    37,     3,    57,    55,    16,    27,     1,
                27,    57,    58,    57,    57,     1,    16,    57,     1,    27,
                16,    57,     7,     3,    57,    57,    57,    57,    57,    57,
                57,    57,    57,    57,    57,    57,    57,    57,    27,    17,
                1,    27,    27,    27,    16,    16,    27,    29,    58,    16,
                52,    52,    57,    11,    16,    52,    27,    52
        };

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
        {
                0,    39,    40,    41,    41,    42,    42,    42,    42,    42,
                43,    43,    44,    44,    45,    45,    46,    46,    46,    47,
                47,    47,    47,    48,    48,    48,    49,    49,    50,    51,
                51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
                53,    53,    54,    54,    54,    55,    55,    56,    56,    56,
                57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
                57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
                57,    57,    57,    57,    57,    57,    57,    57,    57,    58,
                58
        };

/* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
        {
                0,     2,     1,     2,     0,     3,     2,     3,     3,     2,
                1,     3,     1,     1,     5,     2,     1,     4,     1,     4,
                5,     4,     3,     3,     4,     1,     2,     2,     4,     2,
                0,     2,     1,     3,     3,     4,     5,     7,     5,     8,
                2,     0,     3,     4,     3,     1,     3,     1,     3,     3,
                3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
                3,     3,     3,     3,     3,     3,     4,     2,     2,     4,
                5,     3,     4,     4,     3,     1,     1,     1,     1,     3,
                1
        };


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
    FILE *yyoutput = yyo;
    YYUSE (yyoutput);
    if (!yyvaluep)
        return;
# ifdef YYPRINT
        if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
            YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    YYUSE (yytype);
    YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
    YYFPRINTF (yyo, "%s %s (",
               yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

    yy_symbol_value_print (yyo, yytype, yyvaluep);
    YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
    int yylno = yyrline[yyrule];
    int yynrhs = yyr2[yyrule];
    int yyi;
    YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
               yyrule - 1, yylno);
    /* The symbols being reduced.  */
    for (yyi = 0; yyi < yynrhs; yyi++)
    {
        YYFPRINTF (stderr, "   $%d = ", yyi + 1);
        yy_symbol_print (stderr,
                         yystos[+yyssp[yyi + 1 - yynrhs]],
                         &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
    yynewstate:
    /* In all cases, when you get here, the value and location stacks
       have just been pushed.  So pushing a state here evens the stacks.  */
    yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
    yysetstate:
    YYDPRINTF ((stderr, "Entering state %d\n", yystate));
    YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
    YY_IGNORE_USELESS_CAST_BEGIN
    *yyssp = YY_CAST (yy_state_t, yystate);
    YY_IGNORE_USELESS_CAST_END

    if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
        goto yyexhaustedlab;
#else
    {
        /* Get the current used size of the three stacks, in elements.  */
        YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
        {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
        /* Extend the stack our own way.  */
        if (YYMAXDEPTH <= yystacksize)
            goto yyexhaustedlab;
        yystacksize *= 2;
        if (YYMAXDEPTH < yystacksize)
            yystacksize = YYMAXDEPTH;

        {
            yy_state_t *yyss1 = yyss;
            union yyalloc *yyptr =
                    YY_CAST (union yyalloc *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
            if (! yyptr)
                goto yyexhaustedlab;
            YYSTACK_RELOCATE (yyss_alloc, yyss);
            YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
            if (yyss1 != yyssa)
                YYSTACK_FREE (yyss1);
        }
# endif

        yyssp = yyss + yysize - 1;
        yyvsp = yyvs + yysize - 1;

        YY_IGNORE_USELESS_CAST_BEGIN
        YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                YY_CAST (long, yystacksize)));
        YY_IGNORE_USELESS_CAST_END

        if (yyss + yystacksize - 1 <= yyssp)
            YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
    yystate = yyn;
    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    *++yyvsp = yylval;
    YY_IGNORE_MAYBE_UNINITIALIZED_END

    /* Discard the shifted token.  */
    yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 52 "syntax.y"
        {
            root_node = new_node(233, "Program", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            (yyval.node) = root_node;
        }
#line 1524 "syntax.tab.c"
            break;

        case 3:
#line 61 "syntax.y"
        {
            root_node = new_node(233, "ExtDefList", "NULL", (yyvsp[-1].node)->lineno);
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExtDefList);
            (yyval.node) = root_node;
        }
#line 1536 "syntax.tab.c"
            break;

        case 4:
#line 68 "syntax.y"
        {
            (yyval.node) = NULL;
        }
#line 1544 "syntax.tab.c"
            break;

        case 5:
#line 75 "syntax.y"
        {
            root_node = new_node(233, "ExtDef", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::Declare);
            (yyval.node) = root_node;
        }
#line 1557 "syntax.tab.c"
            break;

        case 6:
#line 83 "syntax.y"
        {
            root_node = new_node(233, "ExtDef", "NULL", (yyvsp[-1].node)->lineno);
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::StructDef);
            (yyval.node) = root_node;
        }
#line 1569 "syntax.tab.c"
            break;

        case 7:
#line 90 "syntax.y"
        {
            root_node = new_node(233, "ExtDef", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::FuncDef);
            (yyval.node) = root_node;
        }
#line 1582 "syntax.tab.c"
            break;

        case 8:
#line 98 "syntax.y"
        {
            syntax_error((yyvsp[-1].node) -> lineno, "Missing semicolon ';'");
        }
#line 1590 "syntax.tab.c"
            break;

        case 9:
#line 101 "syntax.y"
        {
            syntax_error((yyvsp[0].node) -> lineno, "Missing specifier");
        }
#line 1598 "syntax.tab.c"
            break;

        case 10:
#line 108 "syntax.y"
        {
            root_node = new_node(233, "ExtDecList", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExtDecListSingle);
            (yyval.node) = root_node;
        }
#line 1609 "syntax.tab.c"
            break;

        case 11:
#line 114 "syntax.y"
        {
            root_node = new_node(233, "ExtDecList", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExtDecListMultiple);
            (yyval.node) = root_node;
        }
#line 1622 "syntax.tab.c"
            break;

        case 12:
#line 127 "syntax.y"
        {
            root_node = new_node(233, "Specifier", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::Specifier);
            (yyval.node) = root_node;
        }
#line 1633 "syntax.tab.c"
            break;

        case 13:
#line 133 "syntax.y"
        {
            root_node = new_node(233, "Specifier", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::StructSpecifier);
            (yyval.node) = root_node;
        }
#line 1644 "syntax.tab.c"
            break;

        case 14:
#line 143 "syntax.y"
        {
            root_node = new_node(233, "StructSpecifier", "NULL", (yyvsp[-4].node)->lineno);
            insert_node(root_node, (yyvsp[-4].node));
            insert_node(root_node, (yyvsp[-3].node));
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::StructSpecifierWithBody);
            (yyval.node) = root_node;
        }
#line 1659 "syntax.tab.c"
            break;

        case 15:
#line 153 "syntax.y"
        {
            root_node = new_node(233, "StructSpecifier", "NULL", (yyvsp[-1].node)->lineno);
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::StructSpecifierNoBody);
            (yyval.node) = root_node;
        }
#line 1671 "syntax.tab.c"
            break;

        case 16:
#line 165 "syntax.y"
        {
            root_node = new_node(233, "VarDec", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::VarDec);
            (yyval.node) = root_node;
        }
#line 1682 "syntax.tab.c"
            break;

        case 17:
#line 171 "syntax.y"
        {
            root_node = new_node(233, "VarDec", "NULL", (yyvsp[-3].node)->lineno);
            insert_node(root_node, (yyvsp[-3].node));
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::VarDecArray);
            (yyval.node) = root_node;
        }
#line 1696 "syntax.tab.c"
            break;

        case 18:
#line 180 "syntax.y"
        {
            syntax_error(0, "error");
        }
#line 1704 "syntax.tab.c"
            break;

        case 19:
#line 187 "syntax.y"
        {
            root_node = new_node(233, "FunDec", "NULL", (yyvsp[-3].node)->lineno);
            insert_node(root_node, (yyvsp[-3].node));
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::FunDecArgs);
            (yyval.node) = root_node;
        }
#line 1718 "syntax.tab.c"
            break;

        case 20:
#line 196 "syntax.y"
        {
            unput('{');
            syntax_error((yyvsp[-4].node) -> lineno, "Missing closing parenthesis ')'");
        }
#line 1727 "syntax.tab.c"
            break;

        case 21:
#line 200 "syntax.y"
        {
            unput('{');
            syntax_error((yyvsp[-3].node) -> lineno, "Missing closing parenthesis ')'");
        }
#line 1736 "syntax.tab.c"
            break;

        case 22:
#line 204 "syntax.y"
        {
            root_node = new_node(233, "FunDec", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::FunDec);
            (yyval.node) = root_node;
        }
#line 1749 "syntax.tab.c"
            break;

        case 23:
#line 216 "syntax.y"
        {
            root_node = new_node(233, "VarList", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::VarList);
            (yyval.node) = root_node;
        }
#line 1762 "syntax.tab.c"
            break;

        case 24:
#line 224 "syntax.y"
        {
            unput(')');
            syntax_error((yyvsp[-3].node)->lineno, "Extra Comma");
        }
#line 1771 "syntax.tab.c"
            break;

        case 25:
#line 228 "syntax.y"
        {
            root_node = new_node(233, "VarList", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ParamDec);
            (yyval.node) = root_node;
        }
#line 1782 "syntax.tab.c"
            break;

        case 26:
#line 238 "syntax.y"
        {
            root_node = new_node(233, "ParamDec", "NULL", (yyvsp[-1].node)->lineno);
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            (yyval.node) = root_node;
        }
#line 1793 "syntax.tab.c"
            break;

        case 27:
#line 244 "syntax.y"
        {
            syntax_error((yyvsp[0].node) -> lineno, "Missing semicolon ';'");
        }
#line 1801 "syntax.tab.c"
            break;

        case 28:
#line 252 "syntax.y"
        {
            root_node = new_node(233, "CompSt", "NULL", (yyvsp[-3].node)->lineno);
            insert_node(root_node, (yyvsp[-3].node));
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            (yyval.node) = root_node;
        }
#line 1814 "syntax.tab.c"
            break;

        case 29:
#line 264 "syntax.y"
        {
            root_node = new_node(233, "StmtList", "NULL", (yyvsp[-1].node)->lineno);
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::StmtList);
            (yyval.node) = root_node;
        }
#line 1826 "syntax.tab.c"
            break;

        case 30:
#line 271 "syntax.y"
        {
            root_node = new_node(0, "NULL", "NULL", 0);
            (yyval.node) = root_node;
        }
#line 1835 "syntax.tab.c"
            break;

        case 31:
#line 279 "syntax.y"
        {
            root_node = new_node(233, "Stmt", "NULL", (yyvsp[-1].node)->lineno);
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::StmtExp);
            (yyval.node) = root_node;
        }
#line 1847 "syntax.tab.c"
            break;

        case 32:
#line 286 "syntax.y"
        {
            root_node = new_node(233, "Stmt", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::StmtCompSt);
            (yyval.node) = root_node;
        }
#line 1858 "syntax.tab.c"
            break;

        case 33:
#line 292 "syntax.y"
        {
            root_node = new_node(233, "Stmt", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::StmtReturn);
            (yyval.node) = root_node;
        }
#line 1871 "syntax.tab.c"
            break;

        case 34:
#line 300 "syntax.y"
        {
            syntax_error((yyvsp[-2].node) -> lineno, "Missing semicolon ';'");
        }
#line 1879 "syntax.tab.c"
            break;

        case 35:
#line 303 "syntax.y"
        {
            syntax_error((yyvsp[-3].node) -> lineno, "Missing semicolon ';'");
        }
#line 1887 "syntax.tab.c"
            break;

        case 36:
#line 306 "syntax.y"
        {
            root_node = new_node(233, "Stmt", "NULL", (yyvsp[-4].node)->lineno);
            insert_node(root_node, (yyvsp[-4].node));
            insert_node(root_node, (yyvsp[-3].node));
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::StmtIf);
            (yyval.node) = root_node;
        }
#line 1902 "syntax.tab.c"
            break;

        case 37:
#line 316 "syntax.y"
        {
            root_node = new_node(233, "Stmt", "NULL", (yyvsp[-6].node)->lineno);
            insert_node(root_node, (yyvsp[-6].node));
            insert_node(root_node, (yyvsp[-5].node));
            insert_node(root_node, (yyvsp[-4].node));
            insert_node(root_node, (yyvsp[-3].node));
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::StmtIfElse);
            (yyval.node) = root_node;
        }
#line 1919 "syntax.tab.c"
            break;

        case 38:
#line 328 "syntax.y"
        {
            root_node = new_node(233, "Stmt", "NULL", (yyvsp[-4].node)->lineno);
            insert_node(root_node, (yyvsp[-4].node));
            insert_node(root_node, (yyvsp[-3].node));
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::StmtWhile);
            (yyval.node) = root_node;
        }
#line 1934 "syntax.tab.c"
            break;

        case 39:
#line 338 "syntax.y"
        {
            root_node = new_node(233, "Stmt", "NULL", (yyvsp[-7].node)->lineno);
            insert_node(root_node, (yyvsp[-7].node));
            insert_node(root_node, (yyvsp[-6].node));
            insert_node(root_node, (yyvsp[-5].node));
            insert_node(root_node, (yyvsp[-4].node));
            insert_node(root_node, (yyvsp[-3].node));
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            (yyval.node) = root_node;
        }
#line 1951 "syntax.tab.c"
            break;

        case 40:
#line 355 "syntax.y"
        {
            root_node = new_node(233, "DefList", "NULL", (yyvsp[-1].node)->lineno);
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::DefList);
            (yyval.node) = root_node;
        }
#line 1963 "syntax.tab.c"
            break;

        case 41:
#line 362 "syntax.y"
        {
            root_node = new_node(0, "NULL", "NULL", 0);
            (yyval.node) = root_node;
        }
#line 1972 "syntax.tab.c"
            break;

        case 42:
#line 370 "syntax.y"
        {
            root_node = new_node(233, "Def", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            (yyval.node) = root_node;
        }
#line 1984 "syntax.tab.c"
            break;

        case 43:
#line 377 "syntax.y"
        {
            syntax_error((yyvsp[-3].node) -> lineno, "Missing semicolon ';'");
        }
#line 1992 "syntax.tab.c"
            break;

        case 44:
#line 380 "syntax.y"
        {
            syntax_error((yyvsp[-1].node) -> lineno, "Missing specifier");
        }
#line 2000 "syntax.tab.c"
            break;

        case 45:
#line 387 "syntax.y"
        {
            root_node = new_node(233, "DecList", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::VarDecListSingle);
            (yyval.node) = root_node;
        }
#line 2011 "syntax.tab.c"
            break;

        case 46:
#line 393 "syntax.y"
        {
            root_node = new_node(233, "DecList", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::VarDecListMultiple);
            (yyval.node) = root_node;
        }
#line 2024 "syntax.tab.c"
            break;

        case 47:
#line 405 "syntax.y"
        {
            root_node = new_node(233, "Dec", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::Dec);
            (yyval.node) = root_node;
        }
#line 2035 "syntax.tab.c"
            break;

        case 48:
#line 411 "syntax.y"
        {
            root_node = new_node(233, "Dec", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::DecWithAssign);
            (yyval.node) = root_node;
        }
#line 2048 "syntax.tab.c"
            break;

        case 49:
#line 419 "syntax.y"
        {
            syntax_error(0, "error");
        }
#line 2056 "syntax.tab.c"
            break;

        case 50:
#line 427 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpAssign);
            (yyval.node) = root_node;
        }
#line 2069 "syntax.tab.c"
            break;

        case 51:
#line 435 "syntax.y"
        {
            syntax_error(0, "error");
        }
#line 2077 "syntax.tab.c"
            break;

        case 52:
#line 438 "syntax.y"
        {
            syntax_error(0, "error");
        }
#line 2085 "syntax.tab.c"
            break;

        case 53:
#line 441 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpAnd);
            (yyval.node) = root_node;
        }
#line 2098 "syntax.tab.c"
            break;

        case 54:
#line 449 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpOr);
            (yyval.node) = root_node;
        }
#line 2111 "syntax.tab.c"
            break;

        case 55:
#line 457 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpLT);
            (yyval.node) = root_node;
        }
#line 2124 "syntax.tab.c"
            break;

        case 56:
#line 465 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpLE);
            (yyval.node) = root_node;
        }
#line 2137 "syntax.tab.c"
            break;

        case 57:
#line 473 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpGT);
            (yyval.node) = root_node;
        }
#line 2150 "syntax.tab.c"
            break;

        case 58:
#line 481 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpGE);
            (yyval.node) = root_node;
        }
#line 2163 "syntax.tab.c"
            break;

        case 59:
#line 489 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpNE);
            (yyval.node) = root_node;
        }
#line 2176 "syntax.tab.c"
            break;

        case 60:
#line 497 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpEQ);
            (yyval.node) = root_node;
        }
#line 2189 "syntax.tab.c"
            break;

        case 61:
#line 505 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpPlus);
            (yyval.node) = root_node;
        }
#line 2202 "syntax.tab.c"
            break;

        case 62:
#line 513 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpMinus);
            (yyval.node) = root_node;
        }
#line 2215 "syntax.tab.c"
            break;

        case 63:
#line 521 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpMul);
            (yyval.node) = root_node;
        }
#line 2228 "syntax.tab.c"
            break;

        case 64:
#line 529 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpDiv);
            (yyval.node) = root_node;
        }
#line 2241 "syntax.tab.c"
            break;

        case 65:
#line 537 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpBracketWrapped);
            (yyval.node) = root_node;
        }
#line 2254 "syntax.tab.c"
            break;

        case 66:
#line 545 "syntax.y"
        {
            syntax_error((yyvsp[-3].node) -> lineno, "Missing closing parenthesis ')'");
        }
#line 2262 "syntax.tab.c"
            break;

        case 67:
#line 548 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-1].node)->lineno);
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpNegative);
            (yyval.node) = root_node;
        }
#line 2274 "syntax.tab.c"
            break;

        case 68:
#line 555 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-1].node)->lineno);
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpNot);
            (yyval.node) = root_node;
        }
#line 2286 "syntax.tab.c"
            break;

        case 69:
#line 562 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-3].node)->lineno);
            insert_node(root_node, (yyvsp[-3].node));
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpArgsFuncCall);
            (yyval.node) = root_node;
        }
#line 2300 "syntax.tab.c"
            break;

        case 70:
#line 571 "syntax.y"
        {
            unput(';');
            syntax_error((yyvsp[-4].node) -> lineno, "Missing closing parenthesis ')'");
        }
#line 2309 "syntax.tab.c"
            break;

        case 71:
#line 575 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpFuncCall);
            (yyval.node) = root_node;
        }
#line 2322 "syntax.tab.c"
            break;

        case 72:
#line 583 "syntax.y"
        {
            syntax_error((yyvsp[-3].node) -> lineno, "Missing closing parenthesis ')'");
        }
#line 2330 "syntax.tab.c"
            break;

        case 73:
#line 586 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-3].node)->lineno);
            insert_node(root_node, (yyvsp[-3].node));
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpArrayIndex);
            (yyval.node) = root_node;
        }
#line 2344 "syntax.tab.c"
            break;

        case 74:
#line 595 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpFieldAccess);
            (yyval.node) = root_node;
        }
#line 2357 "syntax.tab.c"
            break;

        case 75:
#line 603 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpId);
            (yyval.node) = root_node;
        }
#line 2368 "syntax.tab.c"
            break;

        case 76:
#line 609 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpInt);
            (yyval.node) = root_node;
        }
#line 2379 "syntax.tab.c"
            break;

        case 77:
#line 615 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpFloat);
            (yyval.node) = root_node;
        }
#line 2390 "syntax.tab.c"
            break;

        case 78:
#line 621 "syntax.y"
        {
            root_node = new_node(233, "Exp", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ExpChar);
            (yyval.node) = root_node;
        }
#line 2401 "syntax.tab.c"
            break;

        case 79:
#line 630 "syntax.y"
        {
            root_node = new_node(233, "Args", "NULL", (yyvsp[-2].node)->lineno);
            insert_node(root_node, (yyvsp[-2].node));
            insert_node(root_node, (yyvsp[-1].node));
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ArgsMultiple);
            (yyval.node) = root_node;
        }
#line 2414 "syntax.tab.c"
            break;

        case 80:
#line 638 "syntax.y"
        {
            root_node = new_node(233, "Args", "NULL", (yyvsp[0].node)->lineno);
            insert_node(root_node, (yyvsp[0].node));
            set_node_type(root_node, NodeType::ArgsSingle);
            (yyval.node) = root_node;
        }
#line 2425 "syntax.tab.c"
            break;


#line 2429 "syntax.tab.c"

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
    {
        const int yylhs = yyr1[yyn] - YYNTOKENS;
        const int yyi = yypgoto[yylhs] + *yyssp;
        yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
                   ? yytable[yyi]
                   : yydefgoto[yylhs]);
    }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
    /* Pacify compilers when the user code never invokes YYERROR and the
       label yyerrorlab therefore never appears in user code.  */
    if (0)
        YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                    yystos[+*yyssp], yyvsp);
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
#line 647 "syntax.y"

