/* A Bison parser, made by GNU Bison 3.7.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntaxAnalyser.y"

    #include <stdio.h>
    #include <math.h>
    #include "hashtbl.h"
    #define MAX_SIZE 100
	#define MAX_ERRORS 5
	#define MAX_LINE_SIZE 100

    HASHTBL *hashtbl;
    int scope = 0;

    extern FILE* fd;
	extern FILE* fd_help;

    extern int yylex();
    // extern FILE *yyin;
    int lines = 1;
    int errors = 0;
    char line_buffer[MAX_LINE_SIZE];
    extern void error_line();
    extern char str_buffer[MAX_SIZE];
    void yyerror(const char* message);

#line 95 "syntaxAnalyser.tab.c"

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

#include "syntaxAnalyser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_PROGRAM = 3,                  /* T_PROGRAM  */
  YYSYMBOL_T_PROCEDURE = 4,                /* T_PROCEDURE  */
  YYSYMBOL_T_CHAR = 5,                     /* T_CHAR  */
  YYSYMBOL_T_ARRAY = 6,                    /* T_ARRAY  */
  YYSYMBOL_T_SET = 7,                      /* T_SET  */
  YYSYMBOL_T_OF = 8,                       /* T_OF  */
  YYSYMBOL_T_RECORD = 9,                   /* T_RECORD  */
  YYSYMBOL_T_REAL = 10,                    /* T_REAL  */
  YYSYMBOL_T_READ = 11,                    /* T_READ  */
  YYSYMBOL_T_VAR = 12,                     /* T_VAR  */
  YYSYMBOL_T_FORWARD = 13,                 /* T_FORWARD  */
  YYSYMBOL_T_FOR = 14,                     /* T_FOR  */
  YYSYMBOL_T_COMMENT = 15,                 /* T_COMMENT  */
  YYSYMBOL_T_FUNCTION = 16,                /* T_FUNCTION  */
  YYSYMBOL_T_INTEGER = 17,                 /* T_INTEGER  */
  YYSYMBOL_T_IF = 18,                      /* T_IF  */
  YYSYMBOL_T_BOOLEAN = 19,                 /* T_BOOLEAN  */
  YYSYMBOL_T_BEGIN = 20,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 21,                     /* T_END  */
  YYSYMBOL_T_ELSE = 22,                    /* T_ELSE  */
  YYSYMBOL_T_TO = 23,                      /* T_TO  */
  YYSYMBOL_T_THEN = 24,                    /* T_THEN  */
  YYSYMBOL_T_TYPE = 25,                    /* T_TYPE  */
  YYSYMBOL_T_WHILE = 26,                   /* T_WHILE  */
  YYSYMBOL_T_WITH = 27,                    /* T_WITH  */
  YYSYMBOL_T_WRITE = 28,                   /* T_WRITE  */
  YYSYMBOL_T_DO = 29,                      /* T_DO  */
  YYSYMBOL_T_DOWNTO = 30,                  /* T_DOWNTO  */
  YYSYMBOL_T_CONST = 31,                   /* T_CONST  */
  YYSYMBOL_T_ID = 32,                      /* T_ID  */
  YYSYMBOL_T_RELOP = 33,                   /* T_RELOP  */
  YYSYMBOL_T_ADDOP = 34,                   /* T_ADDOP  */
  YYSYMBOL_T_OROP = 35,                    /* T_OROP  */
  YYSYMBOL_T_MULDIVANDOP = 36,             /* T_MULDIVANDOP  */
  YYSYMBOL_T_NOTOP = 37,                   /* T_NOTOP  */
  YYSYMBOL_T_LPAREN = 38,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 39,                  /* T_RPAREN  */
  YYSYMBOL_T_CCONST = 40,                  /* T_CCONST  */
  YYSYMBOL_T_SEMI = 41,                    /* T_SEMI  */
  YYSYMBOL_T_DOT = 42,                     /* T_DOT  */
  YYSYMBOL_T_DOTDOT = 43,                  /* T_DOTDOT  */
  YYSYMBOL_T_COMMA = 44,                   /* T_COMMA  */
  YYSYMBOL_T_EQU = 45,                     /* T_EQU  */
  YYSYMBOL_T_COLON = 46,                   /* T_COLON  */
  YYSYMBOL_T_ASSIGN = 47,                  /* T_ASSIGN  */
  YYSYMBOL_T_LBRACK = 48,                  /* T_LBRACK  */
  YYSYMBOL_T_RBRACK = 49,                  /* T_RBRACK  */
  YYSYMBOL_T_EOF = 50,                     /* T_EOF  */
  YYSYMBOL_T_INOP = 51,                    /* T_INOP  */
  YYSYMBOL_T_BCONST = 52,                  /* T_BCONST  */
  YYSYMBOL_T_STRINGS = 53,                 /* T_STRINGS  */
  YYSYMBOL_T_ICONST = 54,                  /* T_ICONST  */
  YYSYMBOL_T_RCONST = 55,                  /* T_RCONST  */
  YYSYMBOL_LOWER_THAN_ELSE = 56,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_fake = 57,                      /* fake  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_60_1 = 60,                      /* $@1  */
  YYSYMBOL_61_2 = 61,                      /* $@2  */
  YYSYMBOL_header = 62,                    /* header  */
  YYSYMBOL_declarations = 63,              /* declarations  */
  YYSYMBOL_constdefs = 64,                 /* constdefs  */
  YYSYMBOL_constant_defs = 65,             /* constant_defs  */
  YYSYMBOL_66_3 = 66,                      /* $@3  */
  YYSYMBOL_67_4 = 67,                      /* $@4  */
  YYSYMBOL_expression = 68,                /* expression  */
  YYSYMBOL_69_5 = 69,                      /* $@5  */
  YYSYMBOL_variable = 70,                  /* variable  */
  YYSYMBOL_expressions = 71,               /* expressions  */
  YYSYMBOL_constant = 72,                  /* constant  */
  YYSYMBOL_setexpression = 73,             /* setexpression  */
  YYSYMBOL_elexpressions = 74,             /* elexpressions  */
  YYSYMBOL_elexpression = 75,              /* elexpression  */
  YYSYMBOL_typedefs = 76,                  /* typedefs  */
  YYSYMBOL_type_defs = 77,                 /* type_defs  */
  YYSYMBOL_78_6 = 78,                      /* $@6  */
  YYSYMBOL_type_def = 79,                  /* type_def  */
  YYSYMBOL_dims = 80,                      /* dims  */
  YYSYMBOL_limits = 81,                    /* limits  */
  YYSYMBOL_limit = 82,                     /* limit  */
  YYSYMBOL_typename = 83,                  /* typename  */
  YYSYMBOL_standard_type = 84,             /* standard_type  */
  YYSYMBOL_fields = 85,                    /* fields  */
  YYSYMBOL_field = 86,                     /* field  */
  YYSYMBOL_identifiers = 87,               /* identifiers  */
  YYSYMBOL_vardefs = 88,                   /* vardefs  */
  YYSYMBOL_variable_defs = 89,             /* variable_defs  */
  YYSYMBOL_subprograms = 90,               /* subprograms  */
  YYSYMBOL_subprogram = 91,                /* subprogram  */
  YYSYMBOL_sub_header = 92,                /* sub_header  */
  YYSYMBOL_93_7 = 93,                      /* $@7  */
  YYSYMBOL_94_8 = 94,                      /* $@8  */
  YYSYMBOL_formal_parameters = 95,         /* formal_parameters  */
  YYSYMBOL_parameter_list = 96,            /* parameter_list  */
  YYSYMBOL_pass = 97,                      /* pass  */
  YYSYMBOL_comp_statement = 98,            /* comp_statement  */
  YYSYMBOL_99_9 = 99,                      /* $@9  */
  YYSYMBOL_statements = 100,               /* statements  */
  YYSYMBOL_statement = 101,                /* statement  */
  YYSYMBOL_assignment = 102,               /* assignment  */
  YYSYMBOL_if_statement = 103,             /* if_statement  */
  YYSYMBOL_104_10 = 104,                   /* $@10  */
  YYSYMBOL_if_tail = 105,                  /* if_tail  */
  YYSYMBOL_while_statement = 106,          /* while_statement  */
  YYSYMBOL_107_11 = 107,                   /* $@11  */
  YYSYMBOL_for_statement = 108,            /* for_statement  */
  YYSYMBOL_109_12 = 109,                   /* $@12  */
  YYSYMBOL_110_13 = 110,                   /* $@13  */
  YYSYMBOL_iter_space = 111,               /* iter_space  */
  YYSYMBOL_with_statement = 112,           /* with_statement  */
  YYSYMBOL_113_14 = 113,                   /* $@14  */
  YYSYMBOL_subprogram_call = 114,          /* subprogram_call  */
  YYSYMBOL_115_15 = 115,                   /* $@15  */
  YYSYMBOL_io_statement = 116,             /* io_statement  */
  YYSYMBOL_read_list = 117,                /* read_list  */
  YYSYMBOL_read_item = 118,                /* read_item  */
  YYSYMBOL_write_list = 119,               /* write_list  */
  YYSYMBOL_write_item = 120                /* write_item  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    63,    62,    66,    67,    69,    71,    72,
      73,    75,    75,    77,    77,    79,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    90,    92,    93,    94,
      95,    97,    98,    99,   100,   102,   103,   105,   106,   107,
     108,   110,   111,   113,   114,   116,   117,   119,   120,   121,
     123,   123,   125,   126,   128,   129,   130,   131,   132,   133,
     134,   136,   137,   139,   140,   142,   143,   144,   145,   146,
     147,   149,   150,   152,   153,   154,   155,   157,   158,   159,
     161,   163,   164,   166,   167,   168,   170,   171,   172,   174,
     175,   176,   178,   179,   180,   181,   183,   183,   185,   185,
     187,   189,   190,   191,   193,   194,   195,   197,   198,   200,
     200,   203,   204,   205,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   217,   218,   221,   221,   223,   225,   226,
     228,   228,   231,   232,   231,   235,   236,   238,   238,   241,
     242,   242,   245,   246,   247,   248,   250,   251,   253,   255,
     256,   258,   259
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_PROGRAM",
  "T_PROCEDURE", "T_CHAR", "T_ARRAY", "T_SET", "T_OF", "T_RECORD",
  "T_REAL", "T_READ", "T_VAR", "T_FORWARD", "T_FOR", "T_COMMENT",
  "T_FUNCTION", "T_INTEGER", "T_IF", "T_BOOLEAN", "T_BEGIN", "T_END",
  "T_ELSE", "T_TO", "T_THEN", "T_TYPE", "T_WHILE", "T_WITH", "T_WRITE",
  "T_DO", "T_DOWNTO", "T_CONST", "T_ID", "T_RELOP", "T_ADDOP", "T_OROP",
  "T_MULDIVANDOP", "T_NOTOP", "T_LPAREN", "T_RPAREN", "T_CCONST", "T_SEMI",
  "T_DOT", "T_DOTDOT", "T_COMMA", "T_EQU", "T_COLON", "T_ASSIGN",
  "T_LBRACK", "T_RBRACK", "T_EOF", "T_INOP", "T_BCONST", "T_STRINGS",
  "T_ICONST", "T_RCONST", "LOWER_THAN_ELSE", "fake", "$accept", "program",
  "$@1", "$@2", "header", "declarations", "constdefs", "constant_defs",
  "$@3", "$@4", "expression", "$@5", "variable", "expressions", "constant",
  "setexpression", "elexpressions", "elexpression", "typedefs",
  "type_defs", "$@6", "type_def", "dims", "limits", "limit", "typename",
  "standard_type", "fields", "field", "identifiers", "vardefs",
  "variable_defs", "subprograms", "subprogram", "sub_header", "$@7", "$@8",
  "formal_parameters", "parameter_list", "pass", "comp_statement", "$@9",
  "statements", "statement", "assignment", "if_statement", "$@10",
  "if_tail", "while_statement", "$@11", "for_statement", "$@12", "$@13",
  "iter_space", "with_statement", "$@14", "subprogram_call", "$@15",
  "io_statement", "read_list", "read_item", "write_list", "write_item", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
#endif

#define YYPACT_NINF (-176)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-109)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,    89,   124,    55,    43,  -176,   107,  -176,   134,  -176,
    -176,  -176,    86,   145,   119,   151,   143,   137,   160,   165,
     175,   176,    93,   100,   185,   101,   189,  -176,   218,   196,
    -176,  -176,   103,  -176,  -176,  -176,  -176,     1,     2,   126,
     219,   232,  -176,   129,   114,   236,   218,   218,   218,  -176,
      51,  -176,  -176,  -176,   250,   -17,  -176,  -176,   218,   247,
     262,   262,   206,   265,  -176,  -176,  -176,  -176,   261,   302,
     189,  -176,   -15,     8,  -176,  -176,  -176,  -176,   268,   267,
    -176,   281,    18,   189,   189,   277,   280,  -176,    12,   270,
     246,    73,  -176,   218,   218,   218,   218,   218,   218,   285,
     218,   250,   218,   135,  -176,   272,   283,  -176,   218,   218,
    -176,   284,   164,   123,  -176,    15,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,    22,    22,   122,    18,    20,
    -176,   159,  -176,  -176,   286,    53,   208,   126,   278,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,   203,   213,   218,
    -176,  -176,  -176,   218,   218,  -176,   269,   280,   280,  -176,
     269,   269,  -176,   250,     9,   250,   287,  -176,    23,   189,
     289,   292,   295,    95,   242,   292,   161,  -176,   191,   206,
    -176,   206,  -176,  -176,   288,    94,  -176,   290,  -176,   189,
    -176,   189,    18,  -176,  -176,  -176,  -176,  -176,   126,    18,
      18,   -10,   250,  -176,  -176,   218,  -176,  -176,   316,  -176,
     316,   217,  -176,  -176,   -17,    54,  -176,  -176,   206,  -176,
    -176,   139,  -176,   250,    72,  -176,   218,  -176,   250,  -176,
    -176,   122,   321,   208,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,   250,   189,   189,    18,  -176,  -176,   292,   291,   308,
     206,   206,   206,  -176,  -176,   161,    56,  -176,    18,  -176,
     221,   244,  -176,  -176,   218,   206,  -176,   308,  -176,  -176,
    -176,  -176,  -176,    18,    18,   149,   303,  -176,  -176,  -176,
    -176,   218,   218,   206,   250,   250,  -176
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    10,     0,     1,     0,    91,    49,     6,
       5,    13,     0,     2,     0,    85,     0,     9,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,     0,
      11,    98,    96,   109,     3,    90,    89,    10,    10,     0,
      48,    47,    82,     0,     0,    31,     0,     0,     0,    40,
       0,    39,    37,    38,    14,    24,    27,    29,     0,     0,
     103,   103,   122,     0,    94,    91,    92,    91,     0,     0,
       0,    70,     0,     0,    68,    69,    67,    52,     0,     0,
      50,     0,     0,    84,    83,     0,    22,    23,     0,     0,
      46,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,    99,     0,     0,   132,     0,     0,
     137,     0,   139,     0,   121,     0,   112,   114,   115,   116,
     117,   118,   119,   120,     4,     0,     0,     0,     0,     0,
      78,     0,    66,    65,     0,     0,     0,     0,     0,    81,
      76,    74,    73,    75,    72,    88,    71,     0,     0,     0,
      30,    28,    42,     0,     0,    41,    16,    20,    19,    21,
      17,    18,    32,    36,     0,    12,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,     0,   122,
     110,   122,    95,    93,    64,     0,    62,     0,    55,     0,
      56,     0,     0,    60,    59,    57,    58,    53,     0,     0,
       0,     0,    45,    43,    34,     0,    33,   102,   108,   101,
     108,     0,    97,    31,   148,     0,   147,   133,   122,   125,
     130,     0,   152,   151,     0,   150,     0,   124,   123,   113,
     111,     0,     0,     0,    79,    77,    80,    51,    87,    86,
      26,    35,     0,     0,     0,   144,   142,     0,     0,   129,
     122,   122,   122,   145,   143,     0,     0,    61,     0,    63,
       0,     0,   106,   146,     0,   122,   127,   129,   131,   138,
     149,   141,    54,     0,     0,     0,     0,   128,   126,   105,
     104,     0,     0,   122,   135,   136,   134
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,  -176,  -176,  -176,   231,  -176,  -176,  -176,  -176,
     -28,  -176,   -61,  -144,  -176,  -176,  -176,   180,  -176,  -176,
    -176,  -126,  -176,   104,  -124,  -121,   166,  -176,    19,   -24,
    -176,  -176,   170,  -176,  -176,  -176,  -176,   276,  -176,    88,
     -13,  -176,  -176,  -175,  -176,  -176,  -176,    74,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
      92,  -176,    85
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    21,    63,     3,     7,     8,    12,    59,    16,
     163,    85,    55,   164,    56,    57,    91,    92,    15,    25,
     138,    77,   185,   186,    78,   145,   146,   129,   130,   131,
      27,    44,    13,    22,    23,    61,    60,   104,   168,   169,
     114,    62,   115,   116,   117,   118,   250,   266,   119,   251,
     120,   172,   248,   276,   121,   175,   122,   226,   123,   215,
     216,   224,   225
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   113,    43,   187,   229,   201,   230,   188,    34,   134,
     204,   197,   196,   150,    64,    66,   179,   132,    86,    87,
      88,   189,    90,   140,   208,    99,    19,     1,   141,   240,
     101,   100,     6,     6,   205,   142,   180,   143,    20,   133,
      42,   190,    33,   249,     9,    93,    94,    95,    96,   135,
     144,   151,    89,   205,   194,   245,   181,    97,   206,   147,
     148,   191,   209,    98,   210,   156,   157,   158,   159,   160,
     161,   236,   237,   253,   165,   267,   268,   269,   238,   239,
     173,   174,   256,    45,    10,    46,     6,    17,    47,    48,
     277,    49,   195,   246,    35,   271,   218,    81,   247,    50,
     205,    37,    40,    51,  -100,    52,    53,   187,   286,   259,
     214,   254,   182,   183,   221,    83,   255,   154,   113,   219,
     113,     4,   155,   262,     5,   202,    90,    18,    93,    94,
      95,    96,    68,    69,    36,    70,   166,   272,   231,    11,
      97,    38,    41,   232,  -100,   211,    98,   167,   223,    19,
     228,    24,   279,   280,   184,    84,    72,   113,    71,    14,
      72,    20,    74,    26,    73,    99,    74,  -108,   252,    29,
     178,   100,   281,    81,    75,    82,    76,   241,    75,   282,
      76,    99,    93,    94,    95,    96,   214,   100,    28,   113,
     113,   113,    30,    45,    97,    46,    33,    31,    47,    48,
      98,    49,   177,    81,   113,   192,   -31,    32,   234,    50,
     235,   -31,   -31,    51,   222,    52,    53,   106,   260,   261,
     107,    42,   113,    45,   108,    46,    33,   223,    47,    48,
      39,    49,   109,   110,   111,   125,   275,   126,   112,    50,
      71,    58,    72,    51,   227,    52,    53,    81,    74,   199,
      45,    79,    46,   284,   285,    47,    48,    81,    49,   200,
      75,    81,    76,   244,    80,    81,    50,   273,    65,    67,
      51,   220,    52,    53,   -25,    93,    94,    95,    96,    93,
      94,    95,    96,    93,    94,    95,    96,    97,    81,   153,
     274,    97,   102,    98,   140,    97,   242,    98,   243,   141,
     103,    98,  -109,    94,    95,    96,   142,   124,   143,   127,
     128,   136,   137,   139,  -109,   149,    96,   162,   170,   152,
    -109,   171,   176,   198,   213,   193,   207,   217,   167,   258,
     265,   -70,   283,   233,   203,   257,   212,   105,   264,   263,
     270,   278
};

static const yytype_int16 yycheck[] =
{
      28,    62,    26,   127,   179,   149,   181,   128,    21,     1,
       1,   137,   136,     1,    13,    13,     1,    32,    46,    47,
      48,     1,    50,     5,     1,    42,     4,     3,    10,    39,
      58,    48,    31,    31,    44,    17,    21,    19,    16,    54,
      32,    21,    20,   218,     1,    33,    34,    35,    36,    73,
      32,    39,     1,    44,     1,     1,    41,    45,    49,    83,
      84,    41,    39,    51,    41,    93,    94,    95,    96,    97,
      98,   192,   198,     1,   102,   250,   251,   252,   199,   200,
     108,   109,   226,    32,    41,    34,    31,     1,    37,    38,
     265,    40,    39,    39,     1,    39,     1,    44,    44,    48,
      44,     1,     1,    52,     1,    54,    55,   231,   283,   233,
     171,    39,   125,   126,   175,     1,    44,    44,   179,    24,
     181,    32,    49,   244,     0,   153,   154,    41,    33,    34,
      35,    36,     6,     7,    41,     9,     1,   258,    44,    32,
      45,    41,    41,    49,    41,   169,    51,    12,   176,     4,
     178,    32,   273,   274,    32,    41,    34,   218,    32,    25,
      34,    16,    40,    12,    38,    42,    40,    32,    29,    32,
      47,    48,    23,    44,    52,    46,    54,   205,    52,    30,
      54,    42,    33,    34,    35,    36,   247,    48,    45,   250,
     251,   252,    32,    32,    45,    34,    20,    32,    37,    38,
      51,    40,    38,    44,   265,    46,    42,    32,   189,    48,
     191,    47,    48,    52,    53,    54,    55,    11,   242,   243,
      14,    32,   283,    32,    18,    34,    20,   255,    37,    38,
      45,    40,    26,    27,    28,    65,   264,    67,    32,    48,
      32,    45,    34,    52,    53,    54,    55,    44,    40,    46,
      32,    32,    34,   281,   282,    37,    38,    44,    40,    46,
      52,    44,    54,    46,    32,    44,    48,    46,    37,    38,
      52,    29,    54,    55,    38,    33,    34,    35,    36,    33,
      34,    35,    36,    33,    34,    35,    36,    45,    44,    43,
      46,    45,    45,    51,     5,    45,   208,    51,   210,    10,
      38,    51,    33,    34,    35,    36,    17,    42,    19,    48,
       8,    43,    45,    32,    45,    38,    36,    32,    46,    49,
      51,    38,    38,    45,    32,    39,    39,    32,    12,     8,
      22,    43,    29,    43,   154,   231,   170,    61,    47,   247,
     255,   267
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    59,    62,    32,     0,    31,    63,    64,     1,
      41,    32,    65,    90,    25,    76,    67,     1,    41,     4,
      16,    60,    91,    92,    32,    77,    12,    88,    45,    32,
      32,    32,    32,    20,    98,     1,    41,     1,    41,    45,
       1,    41,    32,    87,    89,    32,    34,    37,    38,    40,
      48,    52,    54,    55,    68,    70,    72,    73,    45,    66,
      94,    93,    99,    61,    13,    63,    13,    63,     6,     7,
       9,    32,    34,    38,    40,    52,    54,    79,    82,    32,
      32,    44,    46,     1,    41,    69,    68,    68,    68,     1,
      68,    74,    75,    33,    34,    35,    36,    45,    51,    42,
      48,    68,    45,    38,    95,    95,    11,    14,    18,    26,
      27,    28,    32,    70,    98,   100,   101,   102,   103,   106,
     108,   112,   114,   116,    42,    90,    90,    48,     8,    85,
      86,    87,    32,    54,     1,    87,    43,    45,    78,    32,
       5,    10,    17,    19,    32,    83,    84,    87,    87,    38,
       1,    39,    49,    43,    44,    49,    68,    68,    68,    68,
      68,    68,    32,    68,    71,    68,     1,    12,    96,    97,
      46,    38,   109,    68,    68,   113,    38,    38,    47,     1,
      21,    41,    98,    98,    32,    80,    81,    82,    83,     1,
      21,    41,    46,    39,     1,    39,    82,    79,    45,    46,
      46,    71,    68,    75,     1,    44,    49,    39,     1,    39,
      41,    87,    84,    32,    70,   117,   118,    32,     1,    24,
      29,    70,    53,    68,   119,   120,   115,    53,    68,   101,
     101,    44,    49,    43,    86,    86,    83,    79,    83,    83,
      39,    68,    97,    97,    46,     1,    39,    44,   110,   101,
     104,   107,    29,     1,    39,    44,    71,    81,     8,    82,
      87,    87,    83,   118,    47,    22,   105,   101,   101,   101,
     120,    39,    83,    46,    46,    68,   111,   101,   105,    83,
      83,    23,    30,    29,    68,    68,   101
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    60,    61,    59,    62,    62,    63,    64,    64,
      64,    66,    65,    67,    65,    65,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    69,    68,    68,    68,    68,
      68,    70,    70,    70,    70,    71,    71,    72,    72,    72,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    76,
      78,    77,    77,    77,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    83,    83,    84,    84,    84,    84,    85,    85,    85,
      86,    87,    87,    88,    88,    88,    89,    89,    89,    90,
      90,    90,    91,    91,    91,    91,    93,    92,    94,    92,
      92,    95,    95,    95,    96,    96,    96,    97,    97,    99,
      98,   100,   100,   100,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   102,   102,   104,   103,   103,   105,   105,
     107,   106,   109,   110,   108,   111,   111,   113,   112,   114,
     115,   114,   116,   116,   116,   116,   117,   117,   118,   119,
     119,   120,   120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     7,     3,     3,     3,     3,     3,
       0,     0,     6,     0,     4,     5,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     0,     5,     1,     3,     1,
       3,     1,     3,     4,     4,     3,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     3,     1,     3,     3,     0,
       0,     6,     3,     5,     6,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       3,     3,     1,     3,     3,     0,     5,     5,     3,     3,
       3,     0,     3,     5,     3,     5,     0,     6,     0,     4,
       2,     3,     3,     0,     6,     6,     4,     1,     0,     0,
       4,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     3,     0,     6,     5,     2,     0,
       0,     5,     0,     0,     8,     3,     3,     0,     5,     1,
       0,     5,     4,     4,     4,     4,     3,     1,     1,     3,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* $@1: %empty  */
#line 62 "syntaxAnalyser.y"
                                                                                        {scope++;}
#line 1692 "syntaxAnalyser.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 63 "syntaxAnalyser.y"
                                                                                        {hashtbl_get(hashtbl, scope);}
#line 1698 "syntaxAnalyser.tab.c"
    break;

  case 4: /* program: header declarations subprograms $@1 comp_statement $@2 T_DOT  */
#line 64 "syntaxAnalyser.y"
                                                                                        {hashtbl_get(hashtbl, scope); scope--; printf("Program ended with T_DOT.\n");}
#line 1704 "syntaxAnalyser.tab.c"
    break;

  case 5: /* header: T_PROGRAM T_ID T_SEMI  */
#line 66 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[-1].strval), NULL, scope); printf("HEADER -> T_PROGRAM T_ID T_SEMI\n");}
#line 1710 "syntaxAnalyser.tab.c"
    break;

  case 6: /* header: T_PROGRAM T_ID error  */
#line 67 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[-1].strval), NULL, scope); printf("HEADER -> T_PROGRAM T_ID\n"); yyerror("MISSING SEMI!\n"); yyerrok;}
#line 1716 "syntaxAnalyser.tab.c"
    break;

  case 7: /* declarations: constdefs typedefs vardefs  */
#line 69 "syntaxAnalyser.y"
                                                                                        {printf("DECLARATIONS -> constdefs typedefs vardefs\n");}
#line 1722 "syntaxAnalyser.tab.c"
    break;

  case 8: /* constdefs: T_CONST constant_defs T_SEMI  */
#line 71 "syntaxAnalyser.y"
                                                                                        {printf("CONSTDEFS -> T_CONST constant_defs T_SEMI\n");}
#line 1728 "syntaxAnalyser.tab.c"
    break;

  case 9: /* constdefs: T_CONST constant_defs error  */
#line 72 "syntaxAnalyser.y"
                                                                                        {printf("CONSTDEFS -> T_CONST constant_defs\n"); yyerror("MISSING SEMI!\n"); yyerrok;}
#line 1734 "syntaxAnalyser.tab.c"
    break;

  case 10: /* constdefs: %empty  */
#line 73 "syntaxAnalyser.y"
                                                                                        {printf("constdefs -> empty\n");}
#line 1740 "syntaxAnalyser.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 75 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1746 "syntaxAnalyser.tab.c"
    break;

  case 12: /* constant_defs: constant_defs T_SEMI T_ID $@3 T_EQU expression  */
#line 76 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT_DEFS -> constant_defs T_SEMI T_ID T_EQU expression\n");}
#line 1752 "syntaxAnalyser.tab.c"
    break;

  case 13: /* $@4: %empty  */
#line 77 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope);}
#line 1758 "syntaxAnalyser.tab.c"
    break;

  case 14: /* constant_defs: T_ID $@4 T_EQU expression  */
#line 78 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT_DEFS -> T_ID T_EQU expression\n");}
#line 1764 "syntaxAnalyser.tab.c"
    break;

  case 15: /* constant_defs: constant_defs error T_ID T_EQU expression  */
#line 79 "syntaxAnalyser.y"
                                                                                        {yyerror("MISSING SEMI!\n"); yyerrok;}
#line 1770 "syntaxAnalyser.tab.c"
    break;

  case 16: /* expression: expression T_RELOP expression  */
#line 81 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_RELOP expression\n");}
#line 1776 "syntaxAnalyser.tab.c"
    break;

  case 17: /* expression: expression T_EQU expression  */
#line 82 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_EQU expression\n");}
#line 1782 "syntaxAnalyser.tab.c"
    break;

  case 18: /* expression: expression T_INOP expression  */
#line 83 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_INOP expression\n");}
#line 1788 "syntaxAnalyser.tab.c"
    break;

  case 19: /* expression: expression T_OROP expression  */
#line 84 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_OROP expression\n");}
#line 1794 "syntaxAnalyser.tab.c"
    break;

  case 20: /* expression: expression T_ADDOP expression  */
#line 85 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_ADDOP expression\n");}
#line 1800 "syntaxAnalyser.tab.c"
    break;

  case 21: /* expression: expression T_MULDIVANDOP expression  */
#line 86 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_MULDIVANDOP expression\n");}
#line 1806 "syntaxAnalyser.tab.c"
    break;

  case 22: /* expression: T_ADDOP expression  */
#line 87 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> T_ADDOP expression\n");}
#line 1812 "syntaxAnalyser.tab.c"
    break;

  case 23: /* expression: T_NOTOP expression  */
#line 88 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> T_NOTOP expression\n");}
#line 1818 "syntaxAnalyser.tab.c"
    break;

  case 24: /* expression: variable  */
#line 89 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> variable\n");}
#line 1824 "syntaxAnalyser.tab.c"
    break;

  case 25: /* $@5: %empty  */
#line 90 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1830 "syntaxAnalyser.tab.c"
    break;

  case 26: /* expression: T_ID $@5 T_LPAREN expressions T_RPAREN  */
#line 91 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> T_LPAREN expressions T_RPAREN\n");}
#line 1836 "syntaxAnalyser.tab.c"
    break;

  case 27: /* expression: constant  */
#line 92 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> variable\n");}
#line 1842 "syntaxAnalyser.tab.c"
    break;

  case 28: /* expression: T_LPAREN expression T_RPAREN  */
#line 93 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> T_LPAREN expression T_RPAREN\n");}
#line 1848 "syntaxAnalyser.tab.c"
    break;

  case 29: /* expression: setexpression  */
#line 94 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> setexpression\n");}
#line 1854 "syntaxAnalyser.tab.c"
    break;

  case 30: /* expression: T_LPAREN expression error  */
#line 95 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> T_LPAREN expression\n"); yyerror("MISSING RPAREN!\n"); yyerrok;}
#line 1860 "syntaxAnalyser.tab.c"
    break;

  case 31: /* variable: T_ID  */
#line 97 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1866 "syntaxAnalyser.tab.c"
    break;

  case 32: /* variable: variable T_DOT T_ID  */
#line 98 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("VARIABLE -> variable T_DOT T_ID\n");}
#line 1872 "syntaxAnalyser.tab.c"
    break;

  case 33: /* variable: variable T_LBRACK expressions T_RBRACK  */
#line 99 "syntaxAnalyser.y"
                                                                                        {printf("VARIABLE -> variable T_LBRACK expressions T_RBRACK\n");}
#line 1878 "syntaxAnalyser.tab.c"
    break;

  case 34: /* variable: variable T_LBRACK expressions error  */
#line 100 "syntaxAnalyser.y"
                                                                                        {printf("VARIABLE -> variable T_LBRACK expressions\n"); yyerror("MISSING RPAREN!\n"); yyerrok;}
#line 1884 "syntaxAnalyser.tab.c"
    break;

  case 35: /* expressions: expressions T_COMMA expression  */
#line 102 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSIONS -> expression T_COMMA expression\n");}
#line 1890 "syntaxAnalyser.tab.c"
    break;

  case 36: /* expressions: expression  */
#line 103 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSIONS -> expression\n");}
#line 1896 "syntaxAnalyser.tab.c"
    break;

  case 37: /* constant: T_ICONST  */
#line 105 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT-> T_ICONST\n");}
#line 1902 "syntaxAnalyser.tab.c"
    break;

  case 38: /* constant: T_RCONST  */
#line 106 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT-> T_RCONST\n");}
#line 1908 "syntaxAnalyser.tab.c"
    break;

  case 39: /* constant: T_BCONST  */
#line 107 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT-> T_BCONST\n");}
#line 1914 "syntaxAnalyser.tab.c"
    break;

  case 40: /* constant: T_CCONST  */
#line 108 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT-> T_CCONST\n");}
#line 1920 "syntaxAnalyser.tab.c"
    break;

  case 41: /* setexpression: T_LBRACK elexpressions T_RBRACK  */
#line 110 "syntaxAnalyser.y"
                                                                                        {printf("SETEXPRESSION -> T_LBRACK elexpressions T_RBRACK\n");}
#line 1926 "syntaxAnalyser.tab.c"
    break;

  case 42: /* setexpression: T_LBRACK error T_RBRACK  */
#line 111 "syntaxAnalyser.y"
                                                                                        {printf("SETEXPRESSION -> T_LBRACK T_RBRACK\n"); yyerror("EMPTY BRACKETS BLOCK!"); yyerrok;}
#line 1932 "syntaxAnalyser.tab.c"
    break;

  case 43: /* elexpressions: elexpressions T_COMMA elexpression  */
#line 113 "syntaxAnalyser.y"
                                                                                        {printf("ELEXPRESSIONS -> elexpressions T_COMMA elexpression\n");}
#line 1938 "syntaxAnalyser.tab.c"
    break;

  case 44: /* elexpressions: elexpression  */
#line 114 "syntaxAnalyser.y"
                                                                                        {printf("ELEXPRESSIONS -> elexpression\n");}
#line 1944 "syntaxAnalyser.tab.c"
    break;

  case 45: /* elexpression: expression T_DOTDOT expression  */
#line 116 "syntaxAnalyser.y"
                                                                                        {printf("ELEXPRESSION -> expression T_DOTDOT expression\n");}
#line 1950 "syntaxAnalyser.tab.c"
    break;

  case 46: /* elexpression: expression  */
#line 117 "syntaxAnalyser.y"
                                                                                        {printf("ELEXPRESSION -> expression\n");}
#line 1956 "syntaxAnalyser.tab.c"
    break;

  case 47: /* typedefs: T_TYPE type_defs T_SEMI  */
#line 119 "syntaxAnalyser.y"
                                                                                        {printf("TYPEDEFS -> T_TYPE type_defs T_SEMI\n");}
#line 1962 "syntaxAnalyser.tab.c"
    break;

  case 48: /* typedefs: T_TYPE type_defs error  */
#line 120 "syntaxAnalyser.y"
                                                                                        {printf("TYPEDEFS -> T_TYPE type_defs\n"); yyerror("MISSING SEMI!"); yyerrok;}
#line 1968 "syntaxAnalyser.tab.c"
    break;

  case 49: /* typedefs: %empty  */
#line 121 "syntaxAnalyser.y"
                                                                                        {printf("typedefs -> empty\n");}
#line 1974 "syntaxAnalyser.tab.c"
    break;

  case 50: /* $@6: %empty  */
#line 123 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("TYPE_DEFS -> type_defs T_SEMI T_ID\n");}
#line 1980 "syntaxAnalyser.tab.c"
    break;

  case 51: /* type_defs: type_defs T_SEMI T_ID $@6 T_EQU type_def  */
#line 124 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEFS -> type_defs T_SEMI T_ID T_EQU type_def\n");}
#line 1986 "syntaxAnalyser.tab.c"
    break;

  case 52: /* type_defs: T_ID T_EQU type_def  */
#line 125 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[-1].strval), NULL, scope); printf("TYPE_DEFS -> T_ID T_EQU type_def\n");}
#line 1992 "syntaxAnalyser.tab.c"
    break;

  case 53: /* type_defs: type_defs error T_ID T_EQU type_def  */
#line 126 "syntaxAnalyser.y"
                                                                                        {yyerror("MISSING SEMI!"); yyerrok;}
#line 1998 "syntaxAnalyser.tab.c"
    break;

  case 54: /* type_def: T_ARRAY T_LBRACK dims T_RBRACK T_OF typename  */
#line 128 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_ARRAY T_LBRACK dims T_RBRACK T_OF typename\n");}
#line 2004 "syntaxAnalyser.tab.c"
    break;

  case 55: /* type_def: T_SET T_OF typename  */
#line 129 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_SET T_OF typename\n");}
#line 2010 "syntaxAnalyser.tab.c"
    break;

  case 56: /* type_def: T_RECORD fields T_END  */
#line 130 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_RECORD fields T_END\n");}
#line 2016 "syntaxAnalyser.tab.c"
    break;

  case 57: /* type_def: T_LPAREN identifiers T_RPAREN  */
#line 131 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_LPAREN identifiers T_RPAREN\n");}
#line 2022 "syntaxAnalyser.tab.c"
    break;

  case 58: /* type_def: limit T_DOTDOT limit  */
#line 132 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> limit T_DOTDOT limit\n");}
#line 2028 "syntaxAnalyser.tab.c"
    break;

  case 59: /* type_def: T_LPAREN identifiers error  */
#line 133 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_LPAREN identifiers\n"); yyerror("MISSING RPAREN!"); yyerrok;}
#line 2034 "syntaxAnalyser.tab.c"
    break;

  case 60: /* type_def: T_LPAREN error T_RPAREN  */
#line 134 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_LPAREN T_RPAREN\n"); yyerror("EMPTY BRACKETS BLOCK!"); yyerrok;}
#line 2040 "syntaxAnalyser.tab.c"
    break;

  case 61: /* dims: dims T_COMMA limits  */
#line 136 "syntaxAnalyser.y"
                                                                                        {printf("DIMS -> dims T_COMMA limits\n");}
#line 2046 "syntaxAnalyser.tab.c"
    break;

  case 62: /* dims: limits  */
#line 137 "syntaxAnalyser.y"
                                                                                        {printf("DIMS -> limits\n");}
#line 2052 "syntaxAnalyser.tab.c"
    break;

  case 63: /* limits: limit T_DOTDOT limit  */
#line 139 "syntaxAnalyser.y"
                                                                                        {printf("LIMITS -> limit T_DOTDOT limit\n");}
#line 2058 "syntaxAnalyser.tab.c"
    break;

  case 64: /* limits: T_ID  */
#line 140 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("LIMITS -> T_ID\n");}
#line 2064 "syntaxAnalyser.tab.c"
    break;

  case 67: /* limit: T_ICONST  */
#line 144 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT -> T_ICONST\n");}
#line 2070 "syntaxAnalyser.tab.c"
    break;

  case 68: /* limit: T_CCONST  */
#line 145 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT -> T_CCONST\n");}
#line 2076 "syntaxAnalyser.tab.c"
    break;

  case 69: /* limit: T_BCONST  */
#line 146 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT -> T_BCONST\n");}
#line 2082 "syntaxAnalyser.tab.c"
    break;

  case 70: /* limit: T_ID  */
#line 147 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("LIMIT -> T_ID\n");}
#line 2088 "syntaxAnalyser.tab.c"
    break;

  case 71: /* typename: standard_type  */
#line 149 "syntaxAnalyser.y"
                                                                                        {printf("TYPENAME -> standard_type\n");}
#line 2094 "syntaxAnalyser.tab.c"
    break;

  case 72: /* typename: T_ID  */
#line 150 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("TYPENAME -> T_ID\n");}
#line 2100 "syntaxAnalyser.tab.c"
    break;

  case 73: /* standard_type: T_INTEGER  */
#line 152 "syntaxAnalyser.y"
                                                                                        {printf("STANDARD_TYPE -> T_INTEGER\n");}
#line 2106 "syntaxAnalyser.tab.c"
    break;

  case 74: /* standard_type: T_REAL  */
#line 153 "syntaxAnalyser.y"
                                                                                        {printf("STANDARD_TYPE -> T_REAL\n");}
#line 2112 "syntaxAnalyser.tab.c"
    break;

  case 75: /* standard_type: T_BOOLEAN  */
#line 154 "syntaxAnalyser.y"
                                                                                        {printf("STANDARD_TYPE -> T_BOOLEAN\n");}
#line 2118 "syntaxAnalyser.tab.c"
    break;

  case 76: /* standard_type: T_CHAR  */
#line 155 "syntaxAnalyser.y"
                                                                                        {printf("STANDARD_TYPE -> T_CHAR\n");}
#line 2124 "syntaxAnalyser.tab.c"
    break;

  case 77: /* fields: fields T_SEMI field  */
#line 157 "syntaxAnalyser.y"
                                                                                        {printf("FIELDS -> fields T_SEMI field\n");}
#line 2130 "syntaxAnalyser.tab.c"
    break;

  case 78: /* fields: field  */
#line 158 "syntaxAnalyser.y"
                                                                                        {printf("FIELDS -> field\n");}
#line 2136 "syntaxAnalyser.tab.c"
    break;

  case 79: /* fields: fields error field  */
#line 159 "syntaxAnalyser.y"
                                                                                        {yyerror("MISSING SEMI!"); yyerrok;}
#line 2142 "syntaxAnalyser.tab.c"
    break;

  case 80: /* field: identifiers T_COLON typename  */
#line 161 "syntaxAnalyser.y"
                                                                                        {printf("FIELD -> identifiers T_COLON typename\n");}
#line 2148 "syntaxAnalyser.tab.c"
    break;

  case 81: /* identifiers: identifiers T_COMMA T_ID  */
#line 163 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("IDENTIFIERS -> identifiers T_COMMA T_ID\n");}
#line 2154 "syntaxAnalyser.tab.c"
    break;

  case 82: /* identifiers: T_ID  */
#line 164 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("IDENTIFIERS -> T_ID\n");}
#line 2160 "syntaxAnalyser.tab.c"
    break;

  case 83: /* vardefs: T_VAR variable_defs T_SEMI  */
#line 166 "syntaxAnalyser.y"
                                                                                        {printf("VARDEFS -> T_VAR variable_defs T_SEMI\n");}
#line 2166 "syntaxAnalyser.tab.c"
    break;

  case 84: /* vardefs: T_VAR variable_defs error  */
#line 167 "syntaxAnalyser.y"
                                                                                        {printf("VARDEFS -> T_VAR variable_defs\n"); yyerror("MISSING SEMI!\n"); yyerrok;}
#line 2172 "syntaxAnalyser.tab.c"
    break;

  case 85: /* vardefs: %empty  */
#line 168 "syntaxAnalyser.y"
                                                                                        {printf("VARDEFS -> empty\n");}
#line 2178 "syntaxAnalyser.tab.c"
    break;

  case 86: /* variable_defs: variable_defs T_SEMI identifiers T_COLON typename  */
#line 170 "syntaxAnalyser.y"
                                                                                        {printf("VARIABLE_DEFS -> variable_defs T_SEMI identifiers T_COLON typename\n");}
#line 2184 "syntaxAnalyser.tab.c"
    break;

  case 87: /* variable_defs: variable_defs error identifiers T_COLON typename  */
#line 171 "syntaxAnalyser.y"
                                                                                        {printf("VARIABLE_DEFS -> variable_defs identifiers T_COLON typename\n"); yyerror("MISSING SEMI!\n"); yyerrok;}
#line 2190 "syntaxAnalyser.tab.c"
    break;

  case 88: /* variable_defs: identifiers T_COLON typename  */
#line 172 "syntaxAnalyser.y"
                                                                                        {printf("VARIABLE_DEFS -> identifiers T_COLON typename\n");}
#line 2196 "syntaxAnalyser.tab.c"
    break;

  case 89: /* subprograms: subprograms subprogram T_SEMI  */
#line 174 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAMS -> subprograms subprogram T_SEMI\n");}
#line 2202 "syntaxAnalyser.tab.c"
    break;

  case 90: /* subprograms: subprograms subprogram error  */
#line 175 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAMS -> subprograms subprogram\n"); yyerror("MISSING SEMI!\n"); yyerrok;}
#line 2208 "syntaxAnalyser.tab.c"
    break;

  case 91: /* subprograms: %empty  */
#line 176 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAMS -> empty\n");}
#line 2214 "syntaxAnalyser.tab.c"
    break;

  case 92: /* subprogram: sub_header T_SEMI T_FORWARD  */
#line 178 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAM -> sub_header T_SEMI T_FORWARD\n"); hashtbl_get(hashtbl, scope); scope--;}
#line 2220 "syntaxAnalyser.tab.c"
    break;

  case 93: /* subprogram: sub_header T_SEMI declarations subprograms comp_statement  */
#line 179 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAM -> sub_header T_SEMI declarations subprograms comp_statement\n");}
#line 2226 "syntaxAnalyser.tab.c"
    break;

  case 94: /* subprogram: sub_header error T_FORWARD  */
#line 180 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAM -> sub_header T_FORWARD\n"); hashtbl_get(hashtbl, scope); scope--; yyerror("MISSING SEMI!\n"); yyerrok;}
#line 2232 "syntaxAnalyser.tab.c"
    break;

  case 95: /* subprogram: sub_header error declarations subprograms comp_statement  */
#line 181 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAM -> sub_header declarations subprograms comp_statement\n"); yyerror("MISSING SEMI!\n"); yyerrok;}
#line 2238 "syntaxAnalyser.tab.c"
    break;

  case 96: /* $@7: %empty  */
#line 183 "syntaxAnalyser.y"
                                                                                        {scope++; hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope);}
#line 2244 "syntaxAnalyser.tab.c"
    break;

  case 97: /* sub_header: T_FUNCTION T_ID $@7 formal_parameters T_COLON standard_type  */
#line 184 "syntaxAnalyser.y"
                                                                                        {printf("SUB_HEADER -> T_FUNCTION T_ID formal_parameters T_COLON standard_type\n");}
#line 2250 "syntaxAnalyser.tab.c"
    break;

  case 98: /* $@8: %empty  */
#line 185 "syntaxAnalyser.y"
                                                                                        {scope++; hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope);}
#line 2256 "syntaxAnalyser.tab.c"
    break;

  case 99: /* sub_header: T_PROCEDURE T_ID $@8 formal_parameters  */
#line 186 "syntaxAnalyser.y"
                                                                                        {printf("SUB_HEADER -> T_PROCEDURE T_ID formal_parameters\n");}
#line 2262 "syntaxAnalyser.tab.c"
    break;

  case 100: /* sub_header: T_FUNCTION T_ID  */
#line 187 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("SUB_HEADER -> T_FUNCTION T_ID\n");}
#line 2268 "syntaxAnalyser.tab.c"
    break;

  case 101: /* formal_parameters: T_LPAREN parameter_list T_RPAREN  */
#line 189 "syntaxAnalyser.y"
                                                                                        {printf("FORMAL_PARAMETERS -> T_LPAREN parameter_list T_RPAREN\n");}
#line 2274 "syntaxAnalyser.tab.c"
    break;

  case 102: /* formal_parameters: T_LPAREN error T_RPAREN  */
#line 190 "syntaxAnalyser.y"
                                                                                        {printf("FORMAL_PARAMETERS -> T_LPAREN T_RPAREN\n"); yyerror("EMPTY BRACKETS BLOCK!\n"); yyerrok;}
#line 2280 "syntaxAnalyser.tab.c"
    break;

  case 103: /* formal_parameters: %empty  */
#line 191 "syntaxAnalyser.y"
                                                                                        {printf("FORMAL_PARAMETERS -> empty\n");}
#line 2286 "syntaxAnalyser.tab.c"
    break;

  case 104: /* parameter_list: parameter_list T_SEMI pass identifiers T_COLON typename  */
#line 193 "syntaxAnalyser.y"
                                                                                        {printf("PARAMETER_LIST -> parameter_list T_SEMI pass identifiers T_COLON typename\n");}
#line 2292 "syntaxAnalyser.tab.c"
    break;

  case 105: /* parameter_list: parameter_list error pass identifiers T_COLON typename  */
#line 194 "syntaxAnalyser.y"
                                                                                        {printf("PARAMETER_LIST -> parameter_list pass identifiers T_COLON typename\n"); yyerror("MISSING SEMI!\n"); yyerrok;}
#line 2298 "syntaxAnalyser.tab.c"
    break;

  case 106: /* parameter_list: pass identifiers T_COLON typename  */
#line 195 "syntaxAnalyser.y"
                                                                                        {printf("PARAMETER_LIST -> pass identifiers T_COLON typename\n");}
#line 2304 "syntaxAnalyser.tab.c"
    break;

  case 107: /* pass: T_VAR  */
#line 197 "syntaxAnalyser.y"
                                                                                        {printf("PASS -> T_VAR\n");}
#line 2310 "syntaxAnalyser.tab.c"
    break;

  case 108: /* pass: %empty  */
#line 198 "syntaxAnalyser.y"
                                                                                        {printf("PASS -> empty\n");}
#line 2316 "syntaxAnalyser.tab.c"
    break;

  case 109: /* $@9: %empty  */
#line 200 "syntaxAnalyser.y"
                                                                                        {scope++;}
#line 2322 "syntaxAnalyser.tab.c"
    break;

  case 110: /* comp_statement: T_BEGIN $@9 statements T_END  */
#line 201 "syntaxAnalyser.y"
                                                                                        {hashtbl_get(hashtbl, scope); printf("COMP_STATEMENT -> T_BEGIN statements T_END\n"); scope--;}
#line 2328 "syntaxAnalyser.tab.c"
    break;

  case 111: /* statements: statements T_SEMI statement  */
#line 203 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENTS -> statements T_SEMI statement\n");}
#line 2334 "syntaxAnalyser.tab.c"
    break;

  case 112: /* statements: statement  */
#line 204 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENTS -> statement\n");}
#line 2340 "syntaxAnalyser.tab.c"
    break;

  case 113: /* statements: statements error statement  */
#line 205 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENTS -> statements statement\n"); yyerror("MISSING SEMI!\n"); yyerrok;}
#line 2346 "syntaxAnalyser.tab.c"
    break;

  case 114: /* statement: assignment  */
#line 207 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> assignment\n");}
#line 2352 "syntaxAnalyser.tab.c"
    break;

  case 115: /* statement: if_statement  */
#line 208 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> if_statement\n");}
#line 2358 "syntaxAnalyser.tab.c"
    break;

  case 116: /* statement: while_statement  */
#line 209 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> while_statement\n");}
#line 2364 "syntaxAnalyser.tab.c"
    break;

  case 117: /* statement: for_statement  */
#line 210 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> for_statement\n");}
#line 2370 "syntaxAnalyser.tab.c"
    break;

  case 118: /* statement: with_statement  */
#line 211 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> with_statement\n");}
#line 2376 "syntaxAnalyser.tab.c"
    break;

  case 119: /* statement: subprogram_call  */
#line 212 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> subprogram_call\n");}
#line 2382 "syntaxAnalyser.tab.c"
    break;

  case 120: /* statement: io_statement  */
#line 213 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> io_statement\n");}
#line 2388 "syntaxAnalyser.tab.c"
    break;

  case 121: /* statement: comp_statement  */
#line 214 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> comp_statement\n");}
#line 2394 "syntaxAnalyser.tab.c"
    break;

  case 122: /* statement: %empty  */
#line 215 "syntaxAnalyser.y"
                                                                                        {printf("statement -> empty\n");}
#line 2400 "syntaxAnalyser.tab.c"
    break;

  case 123: /* assignment: variable T_ASSIGN expression  */
#line 217 "syntaxAnalyser.y"
                                                                                        {printf("ASSIGNMENT -> variable T_ASSIGN expression\n");}
#line 2406 "syntaxAnalyser.tab.c"
    break;

  case 124: /* assignment: variable T_ASSIGN T_STRINGS  */
#line 218 "syntaxAnalyser.y"
                                                                                        {printf("ASSIGNMENT -> variable T_ASSIGN T_STRINGS\n");}
#line 2412 "syntaxAnalyser.tab.c"
    break;

  case 125: /* $@10: %empty  */
#line 221 "syntaxAnalyser.y"
                                                                                        {scope++;}
#line 2418 "syntaxAnalyser.tab.c"
    break;

  case 127: /* if_statement: T_IF expression error statement if_tail  */
#line 223 "syntaxAnalyser.y"
                                                                                        {yyerror("IF WITHOUT THEN!\n"); yyerrok;}
#line 2424 "syntaxAnalyser.tab.c"
    break;

  case 128: /* if_tail: T_ELSE statement  */
#line 225 "syntaxAnalyser.y"
                                                                                        {hashtbl_get(hashtbl, scope); scope--; printf("IF_TAIL -> T_ELSE statement\n");}
#line 2430 "syntaxAnalyser.tab.c"
    break;

  case 129: /* if_tail: %empty  */
#line 226 "syntaxAnalyser.y"
                                                                                        {hashtbl_get(hashtbl, scope); scope--; printf("IF_TAIL -> empty\n");}
#line 2436 "syntaxAnalyser.tab.c"
    break;

  case 130: /* $@11: %empty  */
#line 228 "syntaxAnalyser.y"
                                                                                        {scope++;}
#line 2442 "syntaxAnalyser.tab.c"
    break;

  case 131: /* while_statement: T_WHILE expression T_DO $@11 statement  */
#line 229 "syntaxAnalyser.y"
                                                                                        {hashtbl_get(hashtbl, scope); scope--; printf("WHILE_STATEMENT -> T_WHILE expression T_DO statement\n");}
#line 2448 "syntaxAnalyser.tab.c"
    break;

  case 132: /* $@12: %empty  */
#line 231 "syntaxAnalyser.y"
                                                                                        {scope++;}
#line 2454 "syntaxAnalyser.tab.c"
    break;

  case 133: /* $@13: %empty  */
#line 232 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[-2].strval), NULL, scope);}
#line 2460 "syntaxAnalyser.tab.c"
    break;

  case 134: /* for_statement: T_FOR $@12 T_ID $@13 T_ASSIGN iter_space T_DO statement  */
#line 233 "syntaxAnalyser.y"
                                                                                        {hashtbl_get(hashtbl, scope); scope--; printf("FOR_STATEMENT -> T_FOR T_ID T_ASSIGN iter_space T_DO statement\n");}
#line 2466 "syntaxAnalyser.tab.c"
    break;

  case 135: /* iter_space: expression T_TO expression  */
#line 235 "syntaxAnalyser.y"
                                                                                        {printf("ITER_SPACE -> expression T_TO expression\n");}
#line 2472 "syntaxAnalyser.tab.c"
    break;

  case 136: /* iter_space: expression T_DOWNTO expression  */
#line 236 "syntaxAnalyser.y"
                                                                                        {printf("ITER_SPACE -> expression T_DOWNTO expression\n");}
#line 2478 "syntaxAnalyser.tab.c"
    break;

  case 137: /* $@14: %empty  */
#line 238 "syntaxAnalyser.y"
                                                                                        {scope++;}
#line 2484 "syntaxAnalyser.tab.c"
    break;

  case 138: /* with_statement: T_WITH $@14 variable T_DO statement  */
#line 239 "syntaxAnalyser.y"
                                                                                        {printf("WITH_STATEMENT -> T_WITH variable T_DO statement\n"); scope--;}
#line 2490 "syntaxAnalyser.tab.c"
    break;

  case 139: /* subprogram_call: T_ID  */
#line 241 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope);}
#line 2496 "syntaxAnalyser.tab.c"
    break;

  case 140: /* $@15: %empty  */
#line 242 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[-1].strval), NULL, scope);}
#line 2502 "syntaxAnalyser.tab.c"
    break;

  case 141: /* subprogram_call: T_ID T_LPAREN $@15 expressions T_RPAREN  */
#line 243 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAM_CALL -> T_ID T_LPAREN expressions T_RPAREN\n");}
#line 2508 "syntaxAnalyser.tab.c"
    break;

  case 142: /* io_statement: T_READ T_LPAREN read_list T_RPAREN  */
#line 245 "syntaxAnalyser.y"
                                                                                        {printf("IO_STATEMENT -> T_READ T_LPAREN read_list T_RPAREN\n");}
#line 2514 "syntaxAnalyser.tab.c"
    break;

  case 143: /* io_statement: T_WRITE T_LPAREN write_list T_RPAREN  */
#line 246 "syntaxAnalyser.y"
                                                                                        {printf("IO_STATEMENT -> T_WRITE T_LPAREN write_list T_RPAREN\n");}
#line 2520 "syntaxAnalyser.tab.c"
    break;

  case 144: /* io_statement: T_READ T_LPAREN read_list error  */
#line 247 "syntaxAnalyser.y"
                                                                                        {yyerror("MISSING RPAREN!\n"); yyerrok;}
#line 2526 "syntaxAnalyser.tab.c"
    break;

  case 145: /* io_statement: T_WRITE T_LPAREN write_list error  */
#line 248 "syntaxAnalyser.y"
                                                                                        {yyerror("MISSING RPAREN!\n"); yyerrok;}
#line 2532 "syntaxAnalyser.tab.c"
    break;

  case 146: /* read_list: read_list T_COMMA read_item  */
#line 250 "syntaxAnalyser.y"
                                                                                        {printf("READ_LIST -> read_list T_COMMA read_item\n");}
#line 2538 "syntaxAnalyser.tab.c"
    break;

  case 147: /* read_list: read_item  */
#line 251 "syntaxAnalyser.y"
                                                                                        {printf("READ_LIST -> read_item\n");}
#line 2544 "syntaxAnalyser.tab.c"
    break;

  case 148: /* read_item: variable  */
#line 253 "syntaxAnalyser.y"
                                                                                        {printf("READ_ITEM -> variable\n");}
#line 2550 "syntaxAnalyser.tab.c"
    break;

  case 149: /* write_list: write_list T_COMMA write_item  */
#line 255 "syntaxAnalyser.y"
                                                                                        {printf("WRITE_LIST -> write_list T_COMMA write_item\n");}
#line 2556 "syntaxAnalyser.tab.c"
    break;

  case 150: /* write_list: write_item  */
#line 256 "syntaxAnalyser.y"
                                                                                        {printf("WRITE_LIST -> write_item\n");}
#line 2562 "syntaxAnalyser.tab.c"
    break;

  case 151: /* write_item: expression  */
#line 258 "syntaxAnalyser.y"
                                                                                        {printf("WRITE_ITEM -> expression\n");}
#line 2568 "syntaxAnalyser.tab.c"
    break;

  case 152: /* write_item: T_STRINGS  */
#line 259 "syntaxAnalyser.y"
                                                                                        {printf("WRITE_ITEM -> T_STRINGS\n");}
#line 2574 "syntaxAnalyser.tab.c"
    break;


#line 2578 "syntaxAnalyser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 261 "syntaxAnalyser.y"


// Function to increase number of errors, when found, and print the corresponding line.
void yyerror(const char* message){
	errors++;
	printf("(#%d) errors \"%s\" at token  in line (%d): %s\n", errors, message, lines, line_buffer);
	if(errors == MAX_ERRORS){
		printf("MAX ERRORS detected!");
		exit(-1);
	}
}
                    
// Main function that opens the file(given as argument) and reads it until EOF or MAX_ERRORS.
int main(int argc, char* argv[]){

	if(argc < 2){
		printf("No file given!");
		return(0);
	}

	fd = fopen(argv[1], "r");
	
	if(fd == NULL){
		perror("fopen");
		return -1;
	}
	fd_help = fopen(argv[1], "r");
	if(fd_help == NULL){
		perror("fopen");
		return -1;
	}
	

    hashtbl = hashtbl_create(5, NULL);
    if(hashtbl == NULL){
        fprintf(stderr, "HASHTBL CREATE ERROR\n");
        exit(-1);
    }

	yyparse();
    
    hashtbl_destroy(hashtbl);

	fclose(fd);
	fclose(fd_help);

	return(0);

}

