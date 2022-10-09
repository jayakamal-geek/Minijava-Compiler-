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
#line 1 "A1.y"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#include <assert.h>

extern int yylex();
extern void yyerror(char *);

typedef struct Macro
{
    int argCount, type;
    char *id, *sub;
    char** args;
} Macro;

Macro macroList[1000];
int macroCount = 0;

void callError()
{
    printf("//Failed to parse input code\n");
    exit(0);    //succesful exit
}

char** getArgs(int* ptr, char* args)
{
    *ptr = 0;
    if(!args) return NULL;

    else
    {
        int len = strlen(args), count=0, k=0, j=0;
        for(int i=0; i<len; i++)
        {
            if(args[i] == ',') count++;
        }

        char** argList = (char**)malloc((count+3)*sizeof(char*));
        for(int i=0; i<=count; i++)
            argList[i] = (char*)malloc((len+5)*sizeof(char));
        
        for(int i=0; i<l; i++)
        {
            if(args[i]!=',' && args[i]!='\0')
            {
                argList[j][k] = args[i];
                k++;
            }

            else
            {
                argList[j][k] = '\0';
                k=0; j++;
            }
        }

        *ptr = count+1;
        return argList;
    }
}

int containsMacro(char* ID)
{
    for(int i=0; i<macroCount; i++)
    {
        if(strcmp(macroList[i].id, ID) == 0)
            return 1;
    }
    return 0;
}

int getIndex(char* idName)
{
    for(int i=0; i<macroCount; i++)
    {
        if(strcmp(macroList[i].id, ID) == 0)
            return i;
    }

    return -1;
}

void insertMacro(char* ID, char* Sub, char* argList, int typeFlag)
{
    if(containsMacro(ID)) callError();

    else
    {
        int index = macroCount, argCountRef;
        macroCount++;

        macroList[index].id = ID;
        macroList[index].sub = Sub;
        macroList[index].type = typeFlag;
        macroList[index].args = getArgs(&argCountRef, argList);
        macroList[index].argCount = argCountRef;
    }
}

int check(char a)
{
    if(a>='a' && a<='z' || a>='A' && a<='Z' ||a>='0' &&a<='9' || a=='_')
        return 1;
    return 0;
}

char* substitute(char* id, char* args, int type)
{
    char* tempArgs = NULL;
    char** argList = NULL;
    int index = getIndex(id), num = 0, pos = 0, k = 0, len;
    if(index == -1 || !args) callError();

    argList = getArgs(&num, args);
    if(macroList[index].argCount != num) callError();
    len = num;
    num = strlen(macroList[index].sub);
    char* tempL = (char*)malloc((num+5)*sizeof(char)); tempL[0] = '\0';
    tempArgs = (char*)malloc(10000*sizeof(char)); tempArgs[0] = '\0';

    for(int i=0; i<num; i++)
    {
        char temp = macroList[index].sub[i]
        if(!check(temp))
        {
            tempL[k] = '\0';
            for(int j=0; j<len; j++)
            {
                if(strcmp(tempL, macroList[index].sub)==0)
                {
                    k = 0;
                    pos = pos + strlen(argList[j]);
                    strcat(tempArgs, argList[j]);
                    tempL[0] = '\0';
                    break;
                }

                tempL[k] = '\0'; k = 0;
                pos = pos + strlen(tempL);
                strcat(tempArgs, tempL);     
                tempArgs[pos++] = macroList[index].sub[i];
                final[pos] = '\0';
            }
        }

        else tempL[k++] = macroList[index].sub[i];
    }

    return tempArgs;
}

#line 224 "A1.tab.c"

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
#ifndef YY_YY_A1_TAB_H_INCLUDED
# define YY_YY_A1_TAB_H_INCLUDED
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
    SEMICOLON = 258,
    CLASS = 259,
    IF = 260,
    ELSE = 261,
    ERROR = 262,
    WHILE = 263,
    LPARAN = 264,
    RPARAN = 265,
    LCPARAN = 266,
    RCPARAN = 267,
    LSPARAN = 268,
    RSPARAN = 269,
    LESSTHAN = 270,
    GREATERTHAN = 271,
    EQUALS = 272,
    PLUS = 273,
    MINUS = 274,
    STAR = 275,
    DIV = 276,
    END = 277,
    PUBLIC = 278,
    STATIC = 279,
    VOID = 280,
    MAIN = 281,
    NEW = 282,
    FALSE = 283,
    TRUE = 284,
    THIS = 285,
    WORDINT = 286,
    AND = 287,
    OR = 288,
    NOT = 289,
    DOT = 290,
    LENGTH = 291,
    SYSTEM = 292,
    STRING = 293,
    COMMA = 294,
    EXT = 295,
    BOOLE = 296,
    RET = 297,
    DEFINE = 298,
    OTHER = 299,
    INT = 300,
    IDENTIFIER = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 155 "A1.y"

    char * strval;

#line 327 "A1.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_A1_TAB_H_INCLUDED  */



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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   186,   186,   187,   191,   193,   195,   198,   200,   203,
     205,   209,   212,   214,   217,   219,   222,   224,   227,   229,
     232,   235,   241,   245,   251,   256,   261,   263,   265,   267,
     270,   273,   276,   279,   284,   288,   293,   297,   299,   302,
     307,   310,   313,   316,   319,   322,   325,   328,   331,   334,
     338,   342,   346,   351,   354,   356,   358,   360,   362,   364,
     368,   372,   375,   377,   378,   380,   385,   389,   394,   398
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "CLASS", "IF", "ELSE",
  "ERROR", "WHILE", "LPARAN", "RPARAN", "LCPARAN", "RCPARAN", "LSPARAN",
  "RSPARAN", "LESSTHAN", "GREATERTHAN", "EQUALS", "PLUS", "MINUS", "STAR",
  "DIV", "END", "PUBLIC", "STATIC", "VOID", "MAIN", "NEW", "FALSE", "TRUE",
  "THIS", "WORDINT", "AND", "OR", "NOT", "DOT", "LENGTH", "SYSTEM",
  "STRING", "COMMA", "EXT", "BOOLE", "RET", "DEFINE", "OTHER", "INT",
  "IDENTIFIER", "$accept", "goal", "prog", "MacroDefinitionStar",
  "TypeDeclarationStar", "TypeIdentifierStar", "TypeIdentifierSemicolon",
  "MethodDeclarationStar", "CommaTypeIdentifierStar", "StatementStar",
  "CommaExpressionStar", "CommaIdentifierStar", "MainClass",
  "TypeDeclaration", "MethodDeclaration", "Type", "Statement",
  "MacroStatement", "Expression", "MacroExpression", "PrimaryExpression",
  "MacroDefinition", "MacroDefStatement", "MacroDefExpression",
  "Identifier", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF (-102)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -102,    19,  -102,     8,  -102,   -38,   -38,    22,  -102,  -102,
    -102,  -102,    42,    26,   -38,  -102,    22,    33,    12,    -4,
    -102,    37,    29,  -102,  -102,   -38,    58,   103,    13,     0,
      98,    76,    62,   103,   -16,  -102,  -102,  -102,   103,  -102,
      93,  -102,   185,    96,    97,    99,    13,   100,    95,    13,
    -102,   149,    83,   -38,    70,   102,  -102,  -102,   105,    87,
     -38,  -102,  -102,   109,   110,   121,   114,  -102,  -102,   103,
     103,   103,   103,   103,   103,   103,   -38,  -102,    68,   103,
     103,   123,   103,  -102,  -102,   151,   103,   103,   103,    13,
    -102,   -38,   126,  -102,  -102,   138,    98,   107,  -102,   103,
     133,   132,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   143,
    -102,  -102,   145,   146,  -102,   147,   150,  -102,   154,   156,
     155,   152,   158,  -102,  -102,   159,   170,   172,  -102,  -102,
     165,    18,    13,    13,   169,  -102,    21,   167,  -102,  -102,
    -102,    44,  -102,   173,  -102,  -102,  -102,  -102,   103,   182,
    -102,  -102,   186,   103,   179,   -38,   -38,    23,  -102,    13,
    -102,   188,  -102,  -102,   191,  -102,  -102,  -102,     6,    24,
     196,   160,   149,   197,    70,   175,   103,  -102,   -38,   200,
     210,     6,  -102,   103,   202,   174,   205,  -102,   103,   215,
     216,   217,   218,   219,  -102,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     0,     1,     0,     0,     7,     4,    64,
      63,    69,     0,     0,     0,     3,     7,     0,     0,     0,
       6,     0,     0,    20,     9,     0,     0,     0,    16,     0,
      12,     0,     0,     0,     0,    56,    55,    58,     0,    54,
       0,    51,    48,    57,     0,     0,    16,     0,     0,    16,
      37,     0,     0,     0,     0,    28,    27,     8,     0,    12,
       0,    29,     9,     0,     0,     0,     0,    61,    68,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,    66,    15,     0,     0,     0,     0,    16,
      19,     0,     0,    22,    11,     0,    12,     0,    62,     0,
       0,     0,    57,    41,    42,    43,    44,    45,    40,     0,
      53,    18,     0,     0,    30,     0,     0,    18,     0,     0,
       0,     0,     0,    26,    10,     0,     0,     0,    60,    46,
       0,     0,     0,     0,     0,    38,     0,     0,    32,    67,
      65,     0,    23,     0,    59,    50,    18,    52,     0,    34,
      36,    31,     0,     0,     0,     0,     0,     0,    17,     0,
      39,     0,     9,    14,     0,    49,    35,    33,    16,     0,
       0,     0,    29,     0,     0,     0,     0,     9,     0,     0,
       0,    16,    13,     0,     0,     0,     0,    24,     0,     0,
       0,     0,     0,     0,    25,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,  -102,  -102,   220,   -58,  -102,   -54,  -102,   -43,
    -101,  -102,  -102,  -102,  -102,   -52,   -33,  -102,    -6,  -102,
     153,  -102,  -102,  -102,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,    15,    30,    57,    58,   169,    48,
     131,    29,     7,    16,    59,    60,    49,    50,    40,    41,
      42,     8,     9,    10,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      12,    13,    91,    81,    96,    94,    84,    24,    11,    19,
      52,    44,     5,    23,    45,    65,   136,    46,    44,     4,
      31,    45,    22,    51,    46,    61,    14,    64,   147,    66,
      11,   152,    67,   165,   173,    18,    25,    55,    27,    53,
      28,    51,   125,    47,    51,   157,   121,    56,    90,    61,
      47,     6,    11,    17,   154,    95,    21,   148,    11,    11,
     148,    26,   148,   174,   102,   102,   102,   102,   102,   102,
     102,   109,   111,   112,   113,    55,   115,    33,   110,   117,
     118,   119,   120,    32,    51,    56,   122,    62,    63,   155,
      11,    61,    88,   127,    89,    34,    35,    36,    37,   149,
     150,    55,    38,    68,   168,    78,    79,    83,    80,    82,
      54,    56,    33,    39,    11,    92,    11,    93,    97,   181,
      98,    54,   178,   100,   146,   171,   166,    51,    51,    55,
      34,    35,    36,    37,    99,   114,    61,    38,   185,    56,
     123,   124,   158,   128,    11,   126,   129,   161,    39,    11,
     163,   164,   130,   135,    51,   132,   133,   134,    85,   138,
      33,   116,    86,   172,   140,   139,    87,   141,   137,    61,
     180,   142,   151,   182,    33,   145,   172,   186,    34,    35,
      36,    37,   190,   143,   153,    38,   144,   156,   159,   160,
     162,   167,    34,    35,    36,    37,    39,    11,    69,    38,
      70,   170,   176,    71,    72,    73,    74,   175,   177,   183,
      39,    11,   179,   184,   187,   189,   188,    75,   191,   192,
      76,    77,   101,   103,   104,   105,   106,   107,   108,   193,
     194,   195,     0,     0,     0,     0,    20
};

static const yytype_int16 yycheck[] =
{
       5,     6,    54,    46,    62,    59,    49,    11,    46,    14,
      10,     5,     4,    18,     8,    31,   117,    11,     5,     0,
      25,     8,    10,    28,    11,    30,     4,    33,    10,    34,
      46,    10,    38,    10,    10,     9,    40,    31,     9,    39,
      11,    46,    96,    37,    49,   146,    89,    41,    53,    54,
      37,    43,    46,    11,    10,    60,    23,    39,    46,    46,
      39,    24,    39,    39,    69,    70,    71,    72,    73,    74,
      75,    76,    78,    79,    80,    31,    82,     9,    10,    85,
      86,    87,    88,    25,    89,    41,    91,    11,    26,   141,
      46,    96,     9,    99,    11,    27,    28,    29,    30,   132,
     133,    31,    34,    10,   162,     9,     9,    12,     9,     9,
      23,    41,     9,    45,    46,    13,    46,    12,     9,   177,
      10,    23,   174,     9,   130,   168,   159,   132,   133,    31,
      27,    28,    29,    30,    13,    12,   141,    34,   181,    41,
      14,     3,   148,    10,    46,    38,    14,   153,    45,    46,
     155,   156,     9,     3,   159,    10,    10,    10,     9,     3,
       9,    10,    13,   168,    12,    10,    17,     9,    14,   174,
     176,    12,     3,   178,     9,    10,   181,   183,    27,    28,
      29,    30,   188,    13,    17,    34,    14,    14,     6,     3,
      11,     3,    27,    28,    29,    30,    45,    46,    13,    34,
      15,    10,    42,    18,    19,    20,    21,    11,    11,     9,
      45,    46,    37,     3,    12,    10,    42,    32,     3,     3,
      35,    36,    69,    70,    71,    72,    73,    74,    75,    12,
      12,    12,    -1,    -1,    -1,    -1,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,    50,     0,     4,    43,    59,    68,    69,
      70,    46,    71,    71,     4,    51,    60,    11,     9,    71,
      51,    23,    10,    71,    11,    40,    24,     9,    11,    58,
      52,    71,    25,     9,    27,    28,    29,    30,    34,    45,
      65,    66,    67,    71,     5,     8,    11,    37,    56,    63,
      64,    71,    10,    39,    23,    31,    41,    53,    54,    61,
      62,    71,    11,    26,    65,    31,    71,    65,    10,    13,
      15,    18,    19,    20,    21,    32,    35,    36,     9,     9,
       9,    56,     9,    12,    56,     9,    13,    17,     9,    11,
      71,    62,    13,    12,    54,    71,    52,     9,    10,    13,
       9,    67,    71,    67,    67,    67,    67,    67,    67,    71,
      10,    65,    65,    65,    12,    65,    10,    65,    65,    65,
      65,    56,    71,    14,     3,    54,    38,    65,    10,    14,
       9,    57,    10,    10,    10,     3,    57,    14,     3,    10,
      12,     9,    12,    13,    14,    10,    65,    10,    39,    63,
      63,     3,    10,    17,    10,    62,    14,    57,    65,     6,
       3,    65,    11,    71,    71,    10,    63,     3,    52,    55,
      10,    56,    71,    10,    39,    11,    42,    11,    62,    37,
      65,    52,    71,     9,     3,    56,    65,    12,    42,    10,
      65,     3,     3,    12,    12,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    50,    50,    51,    51,    52,    52,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     0,     2,     0,     2,     0,
       3,     2,     0,     4,     0,     2,     0,     3,     0,     3,
       0,    21,     6,     8,    12,    15,     3,     1,     1,     1,
       3,     5,     4,     7,     5,     7,     5,     1,     4,     6,
       3,     3,     3,     3,     3,     3,     4,     2,     1,     7,
       5,     1,     5,     3,     1,     1,     1,     1,     1,     5,
       4,     2,     3,     1,     1,     9,     7,     9,     7,     1
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
#line 186 "A1.y"
                                                                   {printf("%s",(yyvsp[0].strval));exit(0);}
#line 1635 "A1.tab.c"
    break;

  case 3:
#line 187 "A1.y"
                                                                       {(yyval.strval)=(char*)malloc((strlen((yyvsp[-1].strval))+strlen((yyvsp[0].strval))+10)*sizeof(char));
                                                                        strcpy((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),(yyvsp[0].strval));
                                                                        free((yyvsp[-1].strval));free((yyvsp[0].strval));}
#line 1643 "A1.tab.c"
    break;

  case 6:
#line 195 "A1.y"
                                                                        {(yyval.strval)=(char*)malloc((strlen((yyvsp[-1].strval))+strlen((yyvsp[0].strval))+5)*sizeof(char));
                                                                        strcpy((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-1].strval));free((yyvsp[0].strval));}
#line 1650 "A1.tab.c"
    break;

  case 7:
#line 198 "A1.y"
                                                                        {(yyval.strval)=(char*)malloc(2*sizeof(char));strcpy((yyval.strval),"");}
#line 1656 "A1.tab.c"
    break;

  case 8:
#line 200 "A1.y"
                                                                        {(yyval.strval)=(char*)malloc((strlen((yyvsp[-1].strval))+strlen((yyvsp[0].strval))+5)*sizeof(char));
                                                                        strcpy((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-1].strval));free((yyvsp[0].strval));}
#line 1663 "A1.tab.c"
    break;

  case 9:
#line 203 "A1.y"
                                                                        {(yyval.strval)=(char*)malloc(2*sizeof(char));strcpy((yyval.strval),"");}
#line 1669 "A1.tab.c"
    break;

  case 10:
#line 205 "A1.y"
                                                                        {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[-1].strval))+4)*sizeof(char));
                                                                         strcpy((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),";");
                                                                         free((yyvsp[-2].strval));free((yyvsp[-1].strval));}
#line 1677 "A1.tab.c"
    break;

  case 11:
#line 209 "A1.y"
                                                                       {(yyval.strval)=(char*)malloc((strlen((yyvsp[-1].strval))+strlen((yyvsp[0].strval))+5)*sizeof(char));
                                                                        strcpy((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-1].strval));free((yyvsp[0].strval));}
#line 1684 "A1.tab.c"
    break;

  case 12:
#line 212 "A1.y"
                                                                        {(yyval.strval)=(char*)malloc(2*sizeof(char));strcpy((yyval.strval),"");}
#line 1690 "A1.tab.c"
    break;

  case 13:
#line 214 "A1.y"
                                                                       {(yyval.strval)=(char*)malloc((strlen((yyvsp[-3].strval))+strlen((yyvsp[-1].strval))+strlen((yyvsp[0].strval))+10)*sizeof(char));
                                                                        strcpy((yyval.strval),(yyvsp[-3].strval));strcat((yyval.strval),",");strcat((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval)," ");strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[0].strval));free((yyvsp[-3].strval));free((yyvsp[-1].strval));}
#line 1697 "A1.tab.c"
    break;

  case 14:
#line 217 "A1.y"
                                                                        {(yyval.strval)=(char*)malloc(2*sizeof(char));strcpy((yyval.strval),"");}
#line 1703 "A1.tab.c"
    break;

  case 15:
#line 219 "A1.y"
                                                        {(yyval.strval)=(char*)malloc((strlen((yyvsp[-1].strval))+strlen((yyvsp[0].strval))+3)*sizeof(char));
                                                        strcpy((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-1].strval));free((yyvsp[0].strval));}
#line 1710 "A1.tab.c"
    break;

  case 16:
#line 222 "A1.y"
                                                        {(yyval.strval)=(char*)malloc(2*sizeof(char));strcpy((yyval.strval),"");}
#line 1716 "A1.tab.c"
    break;

  case 17:
#line 224 "A1.y"
                                                          {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[0].strval))+3)*sizeof(char));
                                                           strcpy((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),",");strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-2].strval));free((yyvsp[0].strval));}
#line 1723 "A1.tab.c"
    break;

  case 18:
#line 227 "A1.y"
                                                          {(yyval.strval)=(char*)malloc(2*sizeof(char));strcpy((yyval.strval),"");}
#line 1729 "A1.tab.c"
    break;

  case 19:
#line 229 "A1.y"
                                                          {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[0].strval))+3)*sizeof(char));
                                                           strcpy((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),",");strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-2].strval));free((yyvsp[0].strval));}
#line 1736 "A1.tab.c"
    break;

  case 20:
#line 232 "A1.y"
                                                           {(yyval.strval)=(char*)malloc(2*sizeof(char));strcpy((yyval.strval),"");}
#line 1742 "A1.tab.c"
    break;

  case 21:
#line 236 "A1.y"
                            {(yyval.strval)=(char*)malloc((strlen((yyvsp[-19].strval))+strlen((yyvsp[-9].strval))+strlen((yyvsp[-4].strval))+100)*sizeof(char));
                            strcpy((yyval.strval),"class ");strcat((yyval.strval),(yyvsp[-19].strval));strcat((yyval.strval),"{public static void main (String[] ");strcat((yyval.strval),(yyvsp[-9].strval));strcat((yyval.strval),"){System.out.println(");strcat((yyval.strval),(yyvsp[-4].strval));strcat((yyval.strval),");}}");
                            free((yyvsp[-19].strval));free((yyvsp[-9].strval));free((yyvsp[-4].strval));}
#line 1750 "A1.tab.c"
    break;

  case 22:
#line 242 "A1.y"
                            {(yyval.strval)=(char*)malloc((strlen((yyvsp[-4].strval))+strlen((yyvsp[-2].strval))+strlen((yyvsp[-1].strval))+50)*sizeof(char));
                            strcpy((yyval.strval),"class ");strcat((yyval.strval),(yyvsp[-4].strval));strcat((yyval.strval),"{");strcat((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),(yyvsp[-1].strval));
                            strcat((yyval.strval),"}");free((yyvsp[-4].strval));free((yyvsp[-2].strval));free((yyvsp[-1].strval));}
#line 1758 "A1.tab.c"
    break;

  case 23:
#line 246 "A1.y"
                            {(yyval.strval)=(char*)malloc((strlen((yyvsp[-6].strval))+strlen((yyvsp[-4].strval))+strlen((yyvsp[-2].strval))+strlen((yyvsp[-1].strval))+50)*sizeof(char));
                            strcpy((yyval.strval),"class ");strcat((yyval.strval),(yyvsp[-6].strval));strcat((yyval.strval)," extends ");strcat((yyval.strval),(yyvsp[-4].strval));strcat((yyval.strval),"{");strcat((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),(yyvsp[-1].strval));
                            strcat((yyval.strval),"}");free((yyvsp[-6].strval));free((yyvsp[-4].strval));free((yyvsp[-2].strval));free((yyvsp[-1].strval));}
#line 1766 "A1.tab.c"
    break;

  case 24:
#line 252 "A1.y"
                            {(yyval.strval)=(char*)malloc((strlen((yyvsp[-10].strval))+strlen((yyvsp[-9].strval))+strlen((yyvsp[-5].strval))+strlen((yyvsp[-4].strval))+strlen((yyvsp[-2].strval))+50)*sizeof(char));
                            strcpy((yyval.strval),"public ");strcat((yyval.strval),(yyvsp[-10].strval));strcat((yyval.strval),(yyvsp[-9].strval));strcat((yyval.strval),"(){");strcat((yyval.strval),(yyvsp[-5].strval));strcat((yyval.strval),(yyvsp[-4].strval));
                            strcat((yyval.strval),"return ");strcat((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),";}");free((yyvsp[-10].strval));free((yyvsp[-9].strval));free((yyvsp[-5].strval));free((yyvsp[-4].strval));free((yyvsp[-2].strval));}
#line 1774 "A1.tab.c"
    break;

  case 25:
#line 257 "A1.y"
                            {(yyval.strval)=(char*)malloc((strlen((yyvsp[-13].strval))+strlen((yyvsp[-12].strval))+strlen((yyvsp[-10].strval))+strlen((yyvsp[-9].strval))+strlen((yyvsp[-8].strval))+strlen((yyvsp[-5].strval))+strlen((yyvsp[-4].strval))+strlen((yyvsp[-2].strval))+50)*sizeof(char));
                            strcpy((yyval.strval),"public ");strcat((yyval.strval),(yyvsp[-13].strval));strcat((yyval.strval),(yyvsp[-12].strval));strcat((yyval.strval),"(");strcat((yyval.strval),(yyvsp[-10].strval));strcat((yyval.strval),(yyvsp[-9].strval));strcat((yyval.strval),(yyvsp[-8].strval));strcat((yyval.strval),"){");
                            strcat((yyval.strval),(yyvsp[-5].strval));strcat((yyval.strval),(yyvsp[-4].strval));strcat((yyval.strval),"return ");strcat((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),";}");free((yyvsp[-13].strval));free((yyvsp[-12].strval));free((yyvsp[-10].strval));free((yyvsp[-9].strval));free((yyvsp[-8].strval));free((yyvsp[-5].strval));free((yyvsp[-4].strval));free((yyvsp[-2].strval));}
#line 1782 "A1.tab.c"
    break;

  case 26:
#line 261 "A1.y"
                                        {(yyval.strval)=(char*)malloc(10*sizeof(char));strcpy((yyval.strval),"int[] ");}
#line 1788 "A1.tab.c"
    break;

  case 27:
#line 263 "A1.y"
                                {(yyval.strval)=(char*)malloc(10*sizeof(char));strcpy((yyval.strval),"boolean ");}
#line 1794 "A1.tab.c"
    break;

  case 28:
#line 265 "A1.y"
                                {(yyval.strval)=(char*)malloc(10*sizeof(char));strcpy((yyval.strval),"int ");}
#line 1800 "A1.tab.c"
    break;

  case 29:
#line 267 "A1.y"
                                 {(yyval.strval)=(char*)malloc((strlen((yyvsp[0].strval))+3)*sizeof(char));
                                    strcpy((yyval.strval),(yyvsp[0].strval));strcat((yyval.strval)," ");free((yyvsp[0].strval));}
#line 1807 "A1.tab.c"
    break;

  case 30:
#line 270 "A1.y"
                                                                                            {(yyval.strval)=(char*)malloc((strlen((yyvsp[-1].strval))+10)*sizeof(char));
                                                                                    strcpy((yyval.strval),"{");strcat((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),"}");free((yyvsp[-1].strval));}
#line 1814 "A1.tab.c"
    break;

  case 31:
#line 273 "A1.y"
                                                                                        {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+30)*sizeof(char));
                                                                                    strcpy((yyval.strval),"System.out.println(");strcat((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),");");free((yyvsp[-2].strval));}
#line 1821 "A1.tab.c"
    break;

  case 32:
#line 276 "A1.y"
                                                                                        {(yyval.strval)=(char*)malloc((strlen((yyvsp[-3].strval))+strlen((yyvsp[-1].strval))+10)*sizeof(char));
                                                                                    strcpy((yyval.strval),(yyvsp[-3].strval));strcat((yyval.strval),"=");strcat((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),";");free((yyvsp[-3].strval));free((yyvsp[-1].strval));}
#line 1828 "A1.tab.c"
    break;

  case 33:
#line 279 "A1.y"
                                                                                            {(yyval.strval)=(char*)malloc((strlen((yyvsp[-6].strval))+strlen((yyvsp[-4].strval))+strlen((yyvsp[-1].strval))+10)*sizeof(char));
                                                                                           strcpy((yyval.strval),(yyvsp[-6].strval));strcat((yyval.strval),"[");strcat((yyval.strval),(yyvsp[-4].strval));strcat((yyval.strval),"]=");
                                                                                           strcat((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),";");
                                                                                           free((yyvsp[-6].strval));free((yyvsp[-4].strval));free((yyvsp[-1].strval));}
#line 1837 "A1.tab.c"
    break;

  case 34:
#line 284 "A1.y"
                                                                                            {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[0].strval))+15)*sizeof(char));
                                                                                        strcpy((yyval.strval),"if");strcat((yyval.strval),"(");strcat((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),")");strcat((yyval.strval),(yyvsp[0].strval));
                                                                                        free((yyvsp[-2].strval));free((yyvsp[0].strval));}
#line 1845 "A1.tab.c"
    break;

  case 35:
#line 288 "A1.y"
                                                                                            {(yyval.strval)=(char*)malloc((strlen((yyvsp[-4].strval))+strlen((yyvsp[-2].strval))+strlen((yyvsp[0].strval))+15)*sizeof(char));
                                                                                           strcpy((yyval.strval),"if(");strcat((yyval.strval),(yyvsp[-4].strval));strcat((yyval.strval),")");strcat((yyval.strval),(yyvsp[-2].strval));
                                                                                           strcat((yyval.strval),"else ");strcat((yyval.strval),(yyvsp[0].strval));
                                                                                           free((yyvsp[-4].strval));free((yyvsp[-2].strval));free((yyvsp[0].strval));}
#line 1854 "A1.tab.c"
    break;

  case 36:
#line 293 "A1.y"
                                                                                            {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[0].strval))+15)*sizeof(char));
                                                                                        strcpy((yyval.strval),"while(");strcat((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),")");strcat((yyval.strval),(yyvsp[0].strval));
                                                                                        free((yyvsp[-2].strval));free((yyvsp[0].strval));}
#line 1862 "A1.tab.c"
    break;

  case 37:
#line 297 "A1.y"
                                                                                            {(yyval.strval)=(yyvsp[0].strval);}
#line 1868 "A1.tab.c"
    break;

  case 38:
#line 299 "A1.y"
                                                                                           { (yyval.strval)=substitute((yyvsp[-3].strval),NULL,1);
                                                                                            free((yyvsp[-3].strval));}
#line 1875 "A1.tab.c"
    break;

  case 39:
#line 302 "A1.y"
                                                                                          {char* temp=(char*)malloc((strlen((yyvsp[-3].strval))+strlen((yyvsp[-2].strval))+10)*sizeof(char));
                                                                                            strcpy(temp,(yyvsp[-3].strval));strcat(temp,(yyvsp[-2].strval));
                                                                                            (yyval.strval)=substitute((yyvsp[-5].strval),temp,1);
                                                                                            free((yyvsp[-5].strval));free((yyvsp[-3].strval));free((yyvsp[-2].strval));}
#line 1884 "A1.tab.c"
    break;

  case 40:
#line 307 "A1.y"
                                                                      {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[0].strval))+10)*sizeof(char));
                                                                strcpy((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),"&");strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-2].strval));free((yyvsp[0].strval));}
#line 1891 "A1.tab.c"
    break;

  case 41:
#line 310 "A1.y"
                                                                      {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[0].strval))+10)*sizeof(char));
                                                                strcpy((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),"<");strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-2].strval));free((yyvsp[0].strval));}
#line 1898 "A1.tab.c"
    break;

  case 42:
#line 313 "A1.y"
                                                                    {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[0].strval))+10)*sizeof(char));
                                                                strcpy((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),"+");strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-2].strval));free((yyvsp[0].strval));}
#line 1905 "A1.tab.c"
    break;

  case 43:
#line 316 "A1.y"
                                                                    {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[0].strval))+10)*sizeof(char));
                                                                strcpy((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),"-");strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-2].strval));free((yyvsp[0].strval));}
#line 1912 "A1.tab.c"
    break;

  case 44:
#line 319 "A1.y"
                                                                     {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[0].strval))+10)*sizeof(char));
                                                                strcpy((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),"*");strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-2].strval));free((yyvsp[0].strval));}
#line 1919 "A1.tab.c"
    break;

  case 45:
#line 322 "A1.y"
                                                                        {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[0].strval))+10)*sizeof(char));
                                                                    strcpy((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),"/");strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[-2].strval));free((yyvsp[0].strval));}
#line 1926 "A1.tab.c"
    break;

  case 46:
#line 325 "A1.y"
                                                                             {(yyval.strval)=(char*)malloc((strlen((yyvsp[-3].strval))+strlen((yyvsp[-1].strval))+10)*sizeof(char));
                                                                            strcpy((yyval.strval),(yyvsp[-3].strval));strcat((yyval.strval),"[");strcat((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),"]");free((yyvsp[-3].strval));free((yyvsp[-1].strval));}
#line 1933 "A1.tab.c"
    break;

  case 47:
#line 328 "A1.y"
                                                                        {(yyval.strval)=(char*)malloc((strlen((yyvsp[-1].strval))+10)*sizeof(char));
                                                                    strcpy((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),".length");free((yyvsp[-1].strval));}
#line 1940 "A1.tab.c"
    break;

  case 48:
#line 331 "A1.y"
                                                                        {(yyval.strval)=(char*)malloc((strlen((yyvsp[0].strval))+10)*sizeof(char));
                                                                    strcpy((yyval.strval),(yyvsp[0].strval));free((yyvsp[0].strval));}
#line 1947 "A1.tab.c"
    break;

  case 49:
#line 334 "A1.y"
                                                                                                      {(yyval.strval)=(char*)malloc((strlen((yyvsp[-6].strval))+strlen((yyvsp[-4].strval))+strlen((yyvsp[-2].strval))+strlen((yyvsp[-1].strval))+15)*sizeof(char));
                                                                                                    strcpy((yyval.strval),(yyvsp[-6].strval));strcat((yyval.strval),".");strcat((yyval.strval),(yyvsp[-4].strval));strcat((yyval.strval),"(");
                                                                                                    strcat((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),")");free((yyvsp[-6].strval));free((yyvsp[-4].strval));free((yyvsp[-2].strval));free((yyvsp[-1].strval));}
#line 1955 "A1.tab.c"
    break;

  case 50:
#line 338 "A1.y"
                                                                          {(yyval.strval)=(char*)malloc((strlen((yyvsp[-4].strval))+strlen((yyvsp[-2].strval))+10)*sizeof(char));
                                                                            strcpy((yyval.strval),(yyvsp[-4].strval));strcat((yyval.strval),".");strcat((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),"()");
                                                                            free((yyvsp[-4].strval));free((yyvsp[-2].strval));}
#line 1963 "A1.tab.c"
    break;

  case 51:
#line 343 "A1.y"
                            {(yyval.strval)=(yyvsp[0].strval);}
#line 1969 "A1.tab.c"
    break;

  case 52:
#line 346 "A1.y"
                                                                                {char* temp=(char*)malloc((strlen((yyvsp[-2].strval))+strlen((yyvsp[-1].strval))+10)*sizeof(char));
                                                                                strcpy(temp,(yyvsp[-2].strval));strcat(temp,(yyvsp[-1].strval));
                                                                                (yyval.strval)=substitute((yyvsp[-4].strval),temp,0);
                                                                                free((yyvsp[-4].strval));free((yyvsp[-2].strval));free((yyvsp[-1].strval));}
#line 1978 "A1.tab.c"
    break;

  case 53:
#line 351 "A1.y"
                                                                                { (yyval.strval)=substitute((yyvsp[-2].strval),NULL,0);
                                                                                free((yyvsp[-2].strval));}
#line 1985 "A1.tab.c"
    break;

  case 54:
#line 354 "A1.y"
                                                                                        {(yyval.strval)=(char*)malloc((strlen((yyvsp[0].strval))+5)*sizeof(char));strcpy((yyval.strval),(yyvsp[0].strval));}
#line 1991 "A1.tab.c"
    break;

  case 55:
#line 356 "A1.y"
                                                                                {(yyval.strval)=(char*)malloc(10*sizeof(char));strcpy((yyval.strval),"true");}
#line 1997 "A1.tab.c"
    break;

  case 56:
#line 358 "A1.y"
                                                                                {(yyval.strval)=(char*)malloc(10*sizeof(char));strcpy((yyval.strval),"false");}
#line 2003 "A1.tab.c"
    break;

  case 57:
#line 360 "A1.y"
                                                                                {(yyval.strval)=(yyvsp[0].strval);}
#line 2009 "A1.tab.c"
    break;

  case 58:
#line 362 "A1.y"
                                                                                {(yyval.strval)=(char*)malloc(10*sizeof(char));strcpy((yyval.strval),"this");}
#line 2015 "A1.tab.c"
    break;

  case 59:
#line 364 "A1.y"
                                                                                {(yyval.strval)=(char*)malloc((strlen((yyvsp[-1].strval))+20)*sizeof(char));
                                                                                strcpy((yyval.strval),"new ");strcat((yyval.strval),"int [");strcat((yyval.strval),(yyvsp[-1].strval));
                                                                                strcat((yyval.strval),"]");free((yyvsp[-1].strval));}
#line 2023 "A1.tab.c"
    break;

  case 60:
#line 368 "A1.y"
                                                                                {(yyval.strval)=(char*)malloc((strlen((yyvsp[-2].strval))+20)*sizeof(char));
                                                                                strcpy((yyval.strval),"new ");strcat((yyval.strval),(yyvsp[-2].strval));strcat((yyval.strval),"()"); 
                                                                                free((yyvsp[-2].strval));}
#line 2031 "A1.tab.c"
    break;

  case 61:
#line 372 "A1.y"
                                                                                {(yyval.strval)=(char*)malloc((strlen((yyvsp[0].strval))+20)*sizeof(char));
                                                                                strcpy((yyval.strval),"!");strcat((yyval.strval),(yyvsp[0].strval));free((yyvsp[0].strval));}
#line 2038 "A1.tab.c"
    break;

  case 62:
#line 375 "A1.y"
                                                                                {(yyval.strval)=(char*)malloc((strlen((yyvsp[-1].strval))+20)*sizeof(char));
                                                                                strcpy((yyval.strval),"(");strcat((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),")");free((yyvsp[-1].strval));}
#line 2045 "A1.tab.c"
    break;

  case 65:
#line 381 "A1.y"
                            {   char* temp=(char*)malloc((strlen((yyvsp[-5].strval))+strlen((yyvsp[-4].strval))+3)*sizeof(char));strcpy(temp,(yyvsp[-5].strval));strcat(temp,(yyvsp[-4].strval));
                                char* temp2=(char*)malloc((strlen((yyvsp[-1].strval))+5)*sizeof(char));strcpy(temp2,"{");strcat(temp2,(yyvsp[-1].strval));strcat(temp2,"}");
                                insertMacro((yyvsp[-7].strval),temp,temp2,1);free((yyvsp[-5].strval));free((yyvsp[-4].strval));free((yyvsp[-1].strval));
                            }
#line 2054 "A1.tab.c"
    break;

  case 66:
#line 386 "A1.y"
                                {char* temp2=(char*)malloc((strlen((yyvsp[-1].strval))+5)*sizeof(char));strcpy(temp2,"{");strcat(temp2,(yyvsp[-1].strval));strcat(temp2,"}");
                                insertMacro((yyvsp[-5].strval),NULL,temp2,1);free((yyvsp[-1].strval));}
#line 2061 "A1.tab.c"
    break;

  case 67:
#line 390 "A1.y"
                        {   char* temp=(char*)malloc((strlen((yyvsp[-5].strval))+strlen((yyvsp[-4].strval))+3)*sizeof(char));strcpy(temp,(yyvsp[-5].strval));strcat(temp,(yyvsp[-4].strval));
                                char* temp2=(char*)malloc((strlen((yyvsp[-1].strval))+5)*sizeof(char));strcpy(temp2,"(");strcat(temp2,(yyvsp[-1].strval));strcat(temp2,")");
                                insertMacro((yyvsp[-7].strval),temp,temp2,0);free((yyvsp[-5].strval));free((yyvsp[-4].strval));free((yyvsp[-1].strval));
                            }
#line 2070 "A1.tab.c"
    break;

  case 68:
#line 395 "A1.y"
                            {char* temp2=(char*)malloc((strlen((yyvsp[-1].strval))+5)*sizeof(char));strcpy(temp2,"(");strcat(temp2,(yyvsp[-1].strval));strcat(temp2,")");
                                insertMacro((yyvsp[-5].strval),NULL,temp2,0);free((yyvsp[-1].strval));}
#line 2077 "A1.tab.c"
    break;

  case 69:
#line 398 "A1.y"
                                                                                        {(yyval.strval)=(char*)malloc((strlen((yyvsp[0].strval))+5)*sizeof(char));strcpy((yyval.strval),(yyvsp[0].strval));}
#line 2083 "A1.tab.c"
    break;


#line 2087 "A1.tab.c"

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
