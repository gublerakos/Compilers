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

#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtbl.h"
#define MAX_STR_CONST 	200
#define MAX_LINE_SIZE	200
#define MAX_ERRORS		5


HASHTBL *hashtbl;


FILE *yyin2;

// extern void error_string();

extern int yylex();
extern char *yytext;
// yyin, giati auto einai to default fd apo opou paei na diavasei h yylex
//gia allo onoma, to yyparse kollaei atermona, giati de ginetai linking me to yylex
extern FILE *yyin;
extern void error_line();

extern int errors;
char line_buffer[MAX_LINE_SIZE];
extern int lines;

extern char string_buf[MAX_STR_CONST];
extern char *str_ptr;
int scope = 1;
// int error_count = 0;

void yyerror(const char *message);

#line 110 "syntaxAnalyser.tab.c"

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
  YYSYMBOL_header = 61,                    /* header  */
  YYSYMBOL_declarations = 62,              /* declarations  */
  YYSYMBOL_constdefs = 63,                 /* constdefs  */
  YYSYMBOL_constant_defs = 64,             /* constant_defs  */
  YYSYMBOL_65_2 = 65,                      /* $@2  */
  YYSYMBOL_66_3 = 66,                      /* $@3  */
  YYSYMBOL_expression = 67,                /* expression  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_variable = 69,                  /* variable  */
  YYSYMBOL_expressions = 70,               /* expressions  */
  YYSYMBOL_constant = 71,                  /* constant  */
  YYSYMBOL_setexpression = 72,             /* setexpression  */
  YYSYMBOL_elexpressions = 73,             /* elexpressions  */
  YYSYMBOL_elexpression = 74,              /* elexpression  */
  YYSYMBOL_typedefs = 75,                  /* typedefs  */
  YYSYMBOL_type_defs = 76,                 /* type_defs  */
  YYSYMBOL_77_5 = 77,                      /* $@5  */
  YYSYMBOL_type_def = 78,                  /* type_def  */
  YYSYMBOL_dims = 79,                      /* dims  */
  YYSYMBOL_limits = 80,                    /* limits  */
  YYSYMBOL_limit = 81,                     /* limit  */
  YYSYMBOL_typename = 82,                  /* typename  */
  YYSYMBOL_standard_type = 83,             /* standard_type  */
  YYSYMBOL_fields = 84,                    /* fields  */
  YYSYMBOL_field = 85,                     /* field  */
  YYSYMBOL_identifiers = 86,               /* identifiers  */
  YYSYMBOL_vardefs = 87,                   /* vardefs  */
  YYSYMBOL_variable_defs = 88,             /* variable_defs  */
  YYSYMBOL_subprograms = 89,               /* subprograms  */
  YYSYMBOL_subprogram = 90,                /* subprogram  */
  YYSYMBOL_sub_header = 91,                /* sub_header  */
  YYSYMBOL_92_6 = 92,                      /* $@6  */
  YYSYMBOL_93_7 = 93,                      /* $@7  */
  YYSYMBOL_formal_parameters = 94,         /* formal_parameters  */
  YYSYMBOL_parameter_list = 95,            /* parameter_list  */
  YYSYMBOL_pass = 96,                      /* pass  */
  YYSYMBOL_comp_statement = 97,            /* comp_statement  */
  YYSYMBOL_98_8 = 98,                      /* $@8  */
  YYSYMBOL_statements = 99,                /* statements  */
  YYSYMBOL_statement = 100,                /* statement  */
  YYSYMBOL_assignment = 101,               /* assignment  */
  YYSYMBOL_if_statement = 102,             /* if_statement  */
  YYSYMBOL_if_tail = 103,                  /* if_tail  */
  YYSYMBOL_while_statement = 104,          /* while_statement  */
  YYSYMBOL_for_statement = 105,            /* for_statement  */
  YYSYMBOL_106_9 = 106,                    /* $@9  */
  YYSYMBOL_iter_space = 107,               /* iter_space  */
  YYSYMBOL_with_statement = 108,           /* with_statement  */
  YYSYMBOL_subprogram_call = 109,          /* subprogram_call  */
  YYSYMBOL_110_10 = 110,                   /* $@10  */
  YYSYMBOL_io_statement = 111,             /* io_statement  */
  YYSYMBOL_read_list = 112,                /* read_list  */
  YYSYMBOL_read_item = 113,                /* read_item  */
  YYSYMBOL_write_list = 114,               /* write_list  */
  YYSYMBOL_write_item = 115                /* write_item  */
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
#define YYLAST   338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  282

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
       0,    73,    73,    72,    76,    77,    79,    81,    82,    83,
      85,    85,    87,    87,    89,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   100,   102,   103,   104,   105,
     107,   108,   109,   110,   112,   113,   115,   116,   117,   118,
     120,   121,   123,   124,   126,   127,   129,   130,   131,   133,
     133,   135,   136,   138,   139,   140,   141,   142,   143,   144,
     146,   147,   149,   150,   152,   153,   154,   155,   156,   157,
     159,   160,   162,   163,   164,   165,   167,   168,   169,   171,
     173,   174,   176,   177,   178,   180,   181,   182,   184,   185,
     186,   188,   189,   190,   191,   193,   193,   195,   195,   197,
     199,   200,   201,   203,   204,   205,   207,   208,   210,   210,
     213,   214,   215,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   227,   228,   231,   232,   234,   235,   237,   240,
     239,   243,   244,   246,   248,   249,   249,   252,   253,   254,
     255,   257,   258,   260,   262,   263,   265,   266
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
  "$@1", "header", "declarations", "constdefs", "constant_defs", "$@2",
  "$@3", "expression", "$@4", "variable", "expressions", "constant",
  "setexpression", "elexpressions", "elexpression", "typedefs",
  "type_defs", "$@5", "type_def", "dims", "limits", "limit", "typename",
  "standard_type", "fields", "field", "identifiers", "vardefs",
  "variable_defs", "subprograms", "subprogram", "sub_header", "$@6", "$@7",
  "formal_parameters", "parameter_list", "pass", "comp_statement", "$@8",
  "statements", "statement", "assignment", "if_statement", "if_tail",
  "while_statement", "for_statement", "$@9", "iter_space",
  "with_statement", "subprogram_call", "$@10", "io_statement", "read_list",
  "read_item", "write_list", "write_item", YY_NULLPTR
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

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-108)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      32,     6,    41,    11,    38,  -144,    13,  -144,    45,  -144,
    -144,  -144,    47,     5,    57,    80,    50,   105,   111,   120,
     144,  -144,    52,    89,  -144,    76,   123,   148,  -144,   215,
     110,  -144,  -144,   137,   275,  -144,  -144,    -7,     2,    63,
      62,   149,   177,  -144,    79,   141,   135,   215,   215,   215,
    -144,    12,  -144,  -144,  -144,   247,   -16,  -144,  -144,   215,
     139,   150,   150,   195,   207,   215,   215,   219,   218,   258,
     102,  -144,    22,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,   209,   254,   148,  -144,
     -20,    30,  -144,  -144,  -144,  -144,   221,   220,  -144,   234,
     189,   148,   148,   233,   240,  -144,   112,   229,   276,   109,
    -144,   215,   215,   215,   215,   215,   215,   255,   215,   247,
     215,    15,  -144,   242,   219,  -144,   132,   239,  -144,    78,
     182,  -144,   206,   275,  -144,   275,     5,     5,   163,   189,
      77,  -144,   125,  -144,  -144,   252,    60,   245,    62,   249,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,   152,   166,
     215,  -144,  -144,  -144,   215,   215,  -144,   280,   240,   240,
    -144,   280,   280,  -144,   247,    10,   247,   265,  -144,   133,
     148,   313,   -16,    71,  -144,   261,   275,   275,   275,   275,
    -144,   247,    73,  -144,   215,  -144,   247,  -144,  -144,  -144,
    -144,   274,   126,  -144,   277,  -144,   148,  -144,   148,   189,
    -144,  -144,  -144,  -144,  -144,    62,   189,   189,    83,   247,
    -144,  -144,   215,  -144,  -144,   310,  -144,   310,   179,  -144,
    -144,  -144,   219,   215,   302,   302,  -144,  -144,  -144,  -144,
     182,   174,   163,   318,   245,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,   247,   148,   148,   189,  -144,   156,   299,   275,
    -144,  -144,  -144,  -144,  -144,   189,  -144,   180,   185,  -144,
     215,   215,   275,  -144,  -144,   189,   189,   247,   247,  -144,
    -144,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     0,     1,     0,    89,    48,     5,
       4,    12,     0,     0,     0,    84,     0,     8,     7,     0,
       0,   108,     0,     0,     2,     0,     0,     0,     6,     0,
       0,    10,    97,    95,   121,    90,    88,     9,     9,     0,
       0,    47,    46,    81,     0,     0,    30,     0,     0,     0,
      39,     0,    38,    36,    37,    13,    23,    26,    28,     0,
       0,   102,   102,     0,     0,     0,     0,     0,     0,   134,
       0,   120,     0,   111,   113,   114,   115,   116,   117,   118,
     119,    93,    89,    91,    89,     3,     0,     0,     0,    69,
       0,     0,    67,    68,    66,    51,     0,     0,    49,     0,
       0,    83,    82,     0,    21,    22,     0,     0,    45,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,    98,     0,     0,   129,     0,     0,    30,     0,
       0,   135,     0,   121,   109,   121,     0,     0,     0,     0,
       0,    77,     0,    65,    64,     0,     0,     0,     0,     0,
      80,    75,    73,    72,    74,    71,    87,    70,     0,     0,
       0,    29,    27,    41,     0,     0,    40,    15,    19,    18,
      20,    16,    17,    31,    35,     0,    11,     0,   106,     0,
       0,     0,   143,     0,   142,     0,   121,   121,   121,   121,
     147,   146,     0,   145,     0,   123,   122,   112,   110,    94,
      92,    63,     0,    61,     0,    54,     0,    55,     0,     0,
      59,    58,    56,    57,    52,     0,     0,     0,     0,    44,
      42,    33,     0,    32,   101,   107,   100,   107,     0,    96,
     139,   137,     0,     0,   127,   127,   128,   133,   140,   138,
       0,     0,     0,     0,     0,    78,    76,    79,    50,    86,
      85,    25,    34,     0,     0,     0,   141,     0,     0,   121,
     125,   124,   144,   136,    60,     0,    62,     0,     0,   105,
       0,     0,   121,   126,    53,     0,     0,   131,   132,   130,
     104,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,    -9,  -144,  -144,  -144,  -144,   -29,
    -144,   -27,  -143,  -144,  -144,  -144,   164,  -144,  -144,  -144,
    -138,  -144,    91,  -133,  -136,   153,  -144,   -21,   -26,  -144,
    -144,   118,  -144,  -144,  -144,  -144,   273,  -144,    23,    -5,
    -144,  -144,  -131,  -144,  -144,   101,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,   106,  -144,    97
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    39,     3,     7,     8,    12,    60,    16,   174,
     103,    56,   175,    57,    58,   109,   110,    15,    26,   149,
      95,   202,   203,    96,   156,   157,   140,   141,   142,    28,
      45,    13,    22,    23,    62,    61,   122,   179,   180,    71,
      34,    72,    73,    74,    75,   260,    76,    77,   185,   258,
      78,    79,   194,    80,   183,   184,   192,   193
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    44,   197,   205,   198,   204,    81,    70,    24,    19,
     214,   221,   143,   107,   213,    83,   177,   218,   104,   105,
     106,    20,   108,   133,     6,    21,   117,   178,    82,    84,
     119,   145,   118,     6,   144,     1,   126,   127,     4,     9,
     129,     5,     6,   134,    46,    11,    47,  -107,    17,    48,
      49,   241,    50,    35,   222,   234,   235,   236,   237,   223,
      51,   211,    43,   135,    52,   146,    53,    54,    86,    87,
      14,    88,   230,   247,   238,   158,   159,   248,   206,    10,
     249,   250,   167,   168,   169,   170,   171,   172,    18,    25,
      37,   176,    27,    36,    89,    29,    90,   182,   207,   212,
      91,   191,    92,   196,    99,    85,    70,   189,    70,   204,
     231,   266,   239,   161,    93,   232,    94,   240,   208,   269,
     117,    40,   251,    99,    41,   100,   118,   222,   273,   274,
      38,   199,   200,   186,   225,   219,   108,    30,   -99,   280,
     281,   279,   101,    31,   117,   111,   112,   113,   114,   132,
     118,   162,    32,   165,   228,    59,   187,   115,   166,    70,
      70,    70,    70,   116,    42,   111,   112,   113,   114,    99,
     242,   209,   226,   -24,   227,   243,    33,   115,   -99,   270,
      43,    97,   102,   116,   120,   245,   271,   246,   121,   111,
     112,   113,   114,   252,   151,   201,    99,    90,   216,   152,
     136,   115,   137,    92,   257,   182,   153,   116,   154,    98,
      99,   191,   217,   263,    46,    93,    47,    94,   222,    48,
      49,   155,    50,    99,    99,   255,   275,   267,   268,    99,
      51,   276,    70,   124,    52,   190,    53,    54,    46,   125,
      47,   277,   278,    48,    49,    70,    50,    46,   253,    47,
     254,   128,    48,    49,    51,    50,   130,   138,    52,   195,
      53,    54,   139,    51,   147,   148,   150,    52,   188,    53,
      54,   160,   111,   112,   113,   114,   114,    89,   163,    90,
     111,   112,   113,   114,   115,    92,    63,   173,   181,    64,
     116,   210,   115,    65,   215,    21,   131,    93,   116,    94,
     -30,    66,    67,    68,   224,   -30,   -30,    69,   233,   111,
     112,   113,   114,  -108,   112,   113,   114,   -69,   151,   164,
     244,   115,   178,   152,   259,  -108,   265,   116,   272,   220,
     153,  -108,   154,   264,   229,   123,   261,   262,   256
};

static const yytype_int16 yycheck[] =
{
      29,    27,   133,   139,   135,   138,    13,    34,    13,     4,
     148,     1,    32,     1,   147,    13,     1,   160,    47,    48,
      49,    16,    51,     1,    31,    20,    42,    12,    37,    38,
      59,     1,    48,    31,    54,     3,    65,    66,    32,     1,
      67,     0,    31,    21,    32,    32,    34,    32,     1,    37,
      38,   194,    40,     1,    44,   186,   187,   188,   189,    49,
      48,     1,    32,    41,    52,    91,    54,    55,     6,     7,
      25,     9,     1,   209,     1,   101,   102,   215,     1,    41,
     216,   217,   111,   112,   113,   114,   115,   116,    41,    32,
       1,   120,    12,    41,    32,    45,    34,   124,    21,    39,
      38,   130,    40,   132,    44,    42,   133,    29,   135,   242,
      39,   244,    39,     1,    52,    44,    54,    44,    41,   255,
      42,    45,    39,    44,     1,    46,    48,    44,   259,   265,
      41,   136,   137,     1,     1,   164,   165,    32,     1,   275,
     276,   272,     1,    32,    42,    33,    34,    35,    36,    47,
      48,    39,    32,    44,   180,    45,    24,    45,    49,   186,
     187,   188,   189,    51,    41,    33,    34,    35,    36,    44,
      44,    46,    39,    38,    41,    49,    32,    45,    41,    23,
      32,    32,    41,    51,    45,   206,    30,   208,    38,    33,
      34,    35,    36,   222,     5,    32,    44,    34,    46,    10,
      82,    45,    84,    40,   233,   232,    17,    51,    19,    32,
      44,   240,    46,    39,    32,    52,    34,    54,    44,    37,
      38,    32,    40,    44,    44,    46,    46,   253,   254,    44,
      48,    46,   259,    38,    52,    53,    54,    55,    32,    32,
      34,   270,   271,    37,    38,   272,    40,    32,   225,    34,
     227,    32,    37,    38,    48,    40,    38,    48,    52,    53,
      54,    55,     8,    48,    43,    45,    32,    52,    29,    54,
      55,    38,    33,    34,    35,    36,    36,    32,    49,    34,
      33,    34,    35,    36,    45,    40,    11,    32,    46,    14,
      51,    39,    45,    18,    45,    20,    38,    52,    51,    54,
      42,    26,    27,    28,    39,    47,    48,    32,    47,    33,
      34,    35,    36,    33,    34,    35,    36,    43,     5,    43,
      43,    45,    12,    10,    22,    45,     8,    51,    29,   165,
      17,    51,    19,   242,   181,    62,   235,   240,   232
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    59,    61,    32,     0,    31,    62,    63,     1,
      41,    32,    64,    89,    25,    75,    66,     1,    41,     4,
      16,    20,    90,    91,    97,    32,    76,    12,    87,    45,
      32,    32,    32,    32,    98,     1,    41,     1,    41,    60,
      45,     1,    41,    32,    86,    88,    32,    34,    37,    38,
      40,    48,    52,    54,    55,    67,    69,    71,    72,    45,
      65,    93,    92,    11,    14,    18,    26,    27,    28,    32,
      69,    97,    99,   100,   101,   102,   104,   105,   108,   109,
     111,    13,    62,    13,    62,    42,     6,     7,     9,    32,
      34,    38,    40,    52,    54,    78,    81,    32,    32,    44,
      46,     1,    41,    68,    67,    67,    67,     1,    67,    73,
      74,    33,    34,    35,    36,    45,    51,    42,    48,    67,
      45,    38,    94,    94,    38,    32,    67,    67,    32,    69,
      38,    38,    47,     1,    21,    41,    89,    89,    48,     8,
      84,    85,    86,    32,    54,     1,    86,    43,    45,    77,
      32,     5,    10,    17,    19,    32,    82,    83,    86,    86,
      38,     1,    39,    49,    43,    44,    49,    67,    67,    67,
      67,    67,    67,    32,    67,    70,    67,     1,    12,    95,
      96,    46,    69,   112,   113,   106,     1,    24,    29,    29,
      53,    67,   114,   115,   110,    53,    67,   100,   100,    97,
      97,    32,    79,    80,    81,    82,     1,    21,    41,    46,
      39,     1,    39,    81,    78,    45,    46,    46,    70,    67,
      74,     1,    44,    49,    39,     1,    39,    41,    86,    83,
       1,    39,    44,    47,   100,   100,   100,   100,     1,    39,
      44,    70,    44,    49,    43,    85,    85,    82,    78,    82,
      82,    39,    67,    96,    96,    46,   113,    67,   107,    22,
     103,   103,   115,    39,    80,     8,    81,    86,    86,    82,
      23,    30,    29,   100,    82,    46,    46,    67,    67,   100,
      82,    82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    60,    59,    61,    61,    62,    63,    63,    63,
      65,    64,    66,    64,    64,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    67,    67,    67,    67,    67,
      69,    69,    69,    69,    70,    70,    71,    71,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    77,
      76,    76,    76,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    83,    83,    83,    84,    84,    84,    85,
      86,    86,    87,    87,    87,    88,    88,    88,    89,    89,
      89,    90,    90,    90,    90,    92,    91,    93,    91,    91,
      94,    94,    94,    95,    95,    95,    96,    96,    98,    97,
      99,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   106,
     105,   107,   107,   108,   109,   110,   109,   111,   111,   111,
     111,   112,   112,   113,   114,   114,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     3,     3,     3,     3,     3,     0,
       0,     6,     0,     4,     5,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     0,     5,     1,     3,     1,     3,
       1,     3,     4,     4,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     1,     3,     1,     3,     3,     0,     0,
       6,     3,     5,     6,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     3,
       3,     1,     3,     3,     0,     5,     5,     3,     3,     0,
       3,     3,     5,     3,     5,     0,     6,     0,     4,     2,
       3,     3,     0,     6,     6,     4,     1,     0,     0,     4,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     3,     5,     5,     2,     0,     4,     0,
       7,     3,     3,     4,     1,     0,     5,     4,     4,     4,
       4,     3,     1,     1,     3,     1,     1,     1
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
#line 73 "syntaxAnalyser.y"
                                                                                        {hashtbl_get(hashtbl, scope);}
#line 1695 "syntaxAnalyser.tab.c"
    break;

  case 3: /* program: header declarations subprograms comp_statement $@1 T_DOT  */
#line 74 "syntaxAnalyser.y"
                                                                                        {scope--;  hashtbl_get(hashtbl, scope);printf("Program ended with T_DOT.\n");}
#line 1701 "syntaxAnalyser.tab.c"
    break;

  case 4: /* header: T_PROGRAM T_ID T_SEMI  */
#line 76 "syntaxAnalyser.y"
                                                                                        {printf("HEADER -> T_PROGRAM T_ID T_SEMI\n"); hashtbl_insert(hashtbl, (yyvsp[-1].strval), NULL, scope);}
#line 1707 "syntaxAnalyser.tab.c"
    break;

  case 5: /* header: T_PROGRAM T_ID error  */
#line 77 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[-1].strval), NULL, scope); printf("HEADER -> T_PROGRAM T_ID\n"); printf("MISSING SEMI in header!\n"); }
#line 1713 "syntaxAnalyser.tab.c"
    break;

  case 6: /* declarations: constdefs typedefs vardefs  */
#line 79 "syntaxAnalyser.y"
                                                                                        {printf("DECLARATIONS -> constdefs typedefs vardefs\n");}
#line 1719 "syntaxAnalyser.tab.c"
    break;

  case 7: /* constdefs: T_CONST constant_defs T_SEMI  */
#line 81 "syntaxAnalyser.y"
                                                                                        {printf("CONSTDEFS -> T_CONST constant_defs T_SEMI\n");}
#line 1725 "syntaxAnalyser.tab.c"
    break;

  case 8: /* constdefs: T_CONST constant_defs error  */
#line 82 "syntaxAnalyser.y"
                                                                                        {printf("CONSTDEFS -> T_CONST constant_defs\n"); printf("MISSING SEMI in constdefs!\n"); }
#line 1731 "syntaxAnalyser.tab.c"
    break;

  case 9: /* constdefs: %empty  */
#line 83 "syntaxAnalyser.y"
                                                                                        {printf("constdefs -> empty\n");}
#line 1737 "syntaxAnalyser.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 85 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1743 "syntaxAnalyser.tab.c"
    break;

  case 11: /* constant_defs: constant_defs T_SEMI T_ID $@2 T_EQU expression  */
#line 86 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT_DEFS -> constant_defs T_SEMI T_ID T_EQU expression\n");}
#line 1749 "syntaxAnalyser.tab.c"
    break;

  case 12: /* $@3: %empty  */
#line 87 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope);}
#line 1755 "syntaxAnalyser.tab.c"
    break;

  case 13: /* constant_defs: T_ID $@3 T_EQU expression  */
#line 88 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT_DEFS -> T_ID T_EQU expression\n");}
#line 1761 "syntaxAnalyser.tab.c"
    break;

  case 14: /* constant_defs: constant_defs error T_ID T_EQU expression  */
#line 89 "syntaxAnalyser.y"
                                                                                        {printf("MISSING SEMI in constant_defs!\n"); }
#line 1767 "syntaxAnalyser.tab.c"
    break;

  case 15: /* expression: expression T_RELOP expression  */
#line 91 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_RELOP expression\n");}
#line 1773 "syntaxAnalyser.tab.c"
    break;

  case 16: /* expression: expression T_EQU expression  */
#line 92 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_EQU expression\n");}
#line 1779 "syntaxAnalyser.tab.c"
    break;

  case 17: /* expression: expression T_INOP expression  */
#line 93 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_INOP expression\n");}
#line 1785 "syntaxAnalyser.tab.c"
    break;

  case 18: /* expression: expression T_OROP expression  */
#line 94 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_OROP expression\n");}
#line 1791 "syntaxAnalyser.tab.c"
    break;

  case 19: /* expression: expression T_ADDOP expression  */
#line 95 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_ADDOP expression\n");}
#line 1797 "syntaxAnalyser.tab.c"
    break;

  case 20: /* expression: expression T_MULDIVANDOP expression  */
#line 96 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> expression T_MULDIVANDOP expression\n");}
#line 1803 "syntaxAnalyser.tab.c"
    break;

  case 21: /* expression: T_ADDOP expression  */
#line 97 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> T_ADDOP expression\n");}
#line 1809 "syntaxAnalyser.tab.c"
    break;

  case 22: /* expression: T_NOTOP expression  */
#line 98 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> T_NOTOP expression\n");}
#line 1815 "syntaxAnalyser.tab.c"
    break;

  case 23: /* expression: variable  */
#line 99 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> variable\n");}
#line 1821 "syntaxAnalyser.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 100 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1827 "syntaxAnalyser.tab.c"
    break;

  case 25: /* expression: T_ID $@4 T_LPAREN expressions T_RPAREN  */
#line 101 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> T_LPAREN expressions T_RPAREN\n");}
#line 1833 "syntaxAnalyser.tab.c"
    break;

  case 26: /* expression: constant  */
#line 102 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> variable\n");}
#line 1839 "syntaxAnalyser.tab.c"
    break;

  case 27: /* expression: T_LPAREN expression T_RPAREN  */
#line 103 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> T_LPAREN expression T_RPAREN\n");}
#line 1845 "syntaxAnalyser.tab.c"
    break;

  case 28: /* expression: setexpression  */
#line 104 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> setexpression\n");}
#line 1851 "syntaxAnalyser.tab.c"
    break;

  case 29: /* expression: T_LPAREN expression error  */
#line 105 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSION -> T_LPAREN expression\n"); printf("MISSING RPAREN in expression!\n"); }
#line 1857 "syntaxAnalyser.tab.c"
    break;

  case 30: /* variable: T_ID  */
#line 107 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1863 "syntaxAnalyser.tab.c"
    break;

  case 31: /* variable: variable T_DOT T_ID  */
#line 108 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("VARIABLE -> variable T_DOT T_ID\n");}
#line 1869 "syntaxAnalyser.tab.c"
    break;

  case 32: /* variable: variable T_LBRACK expressions T_RBRACK  */
#line 109 "syntaxAnalyser.y"
                                                                                        {printf("VARIABLE -> variable T_LBRACK expressions T_RBRACK\n");}
#line 1875 "syntaxAnalyser.tab.c"
    break;

  case 33: /* variable: variable T_LBRACK expressions error  */
#line 110 "syntaxAnalyser.y"
                                                                                        {printf("VARIABLE -> variable T_LBRACK expressions\n"); printf("MISSING RPAREN in variable!\n"); }
#line 1881 "syntaxAnalyser.tab.c"
    break;

  case 34: /* expressions: expressions T_COMMA expression  */
#line 112 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSIONS -> expression T_COMMA expression\n");}
#line 1887 "syntaxAnalyser.tab.c"
    break;

  case 35: /* expressions: expression  */
#line 113 "syntaxAnalyser.y"
                                                                                        {printf("EXPRESSIONS -> expression\n");}
#line 1893 "syntaxAnalyser.tab.c"
    break;

  case 36: /* constant: T_ICONST  */
#line 115 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT-> T_ICONST\n");}
#line 1899 "syntaxAnalyser.tab.c"
    break;

  case 37: /* constant: T_RCONST  */
#line 116 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT-> T_RCONST\n");}
#line 1905 "syntaxAnalyser.tab.c"
    break;

  case 38: /* constant: T_BCONST  */
#line 117 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT-> T_BCONST\n");}
#line 1911 "syntaxAnalyser.tab.c"
    break;

  case 39: /* constant: T_CCONST  */
#line 118 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT-> T_CCONST\n");}
#line 1917 "syntaxAnalyser.tab.c"
    break;

  case 40: /* setexpression: T_LBRACK elexpressions T_RBRACK  */
#line 120 "syntaxAnalyser.y"
                                                                                        {printf("SETEXPRESSION -> T_LBRACK elexpressions T_RBRACK\n");}
#line 1923 "syntaxAnalyser.tab.c"
    break;

  case 41: /* setexpression: T_LBRACK error T_RBRACK  */
#line 121 "syntaxAnalyser.y"
                                                                                        {printf("SETEXPRESSION -> T_LBRACK T_RBRACK\n"); printf("EMPTY BRACKETS BLOCK in setexpression!\n"); }
#line 1929 "syntaxAnalyser.tab.c"
    break;

  case 42: /* elexpressions: elexpressions T_COMMA elexpression  */
#line 123 "syntaxAnalyser.y"
                                                                                        {printf("ELEXPRESSIONS -> elexpressions T_COMMA elexpression\n");}
#line 1935 "syntaxAnalyser.tab.c"
    break;

  case 43: /* elexpressions: elexpression  */
#line 124 "syntaxAnalyser.y"
                                                                                        {printf("ELEXPRESSIONS -> elexpression\n");}
#line 1941 "syntaxAnalyser.tab.c"
    break;

  case 44: /* elexpression: expression T_DOTDOT expression  */
#line 126 "syntaxAnalyser.y"
                                                                                        {printf("ELEXPRESSION -> expression T_DOTDOT expression\n");}
#line 1947 "syntaxAnalyser.tab.c"
    break;

  case 45: /* elexpression: expression  */
#line 127 "syntaxAnalyser.y"
                                                                                        {printf("ELEXPRESSION -> expression\n");}
#line 1953 "syntaxAnalyser.tab.c"
    break;

  case 46: /* typedefs: T_TYPE type_defs T_SEMI  */
#line 129 "syntaxAnalyser.y"
                                                                                        {printf("TYPEDEFS -> T_TYPE type_defs T_SEMI\n");}
#line 1959 "syntaxAnalyser.tab.c"
    break;

  case 47: /* typedefs: T_TYPE type_defs error  */
#line 130 "syntaxAnalyser.y"
                                                                                        {printf("TYPEDEFS -> T_TYPE type_defs\n"); printf("MISSING SEMI in typedefs!\n"); }
#line 1965 "syntaxAnalyser.tab.c"
    break;

  case 48: /* typedefs: %empty  */
#line 131 "syntaxAnalyser.y"
                                                                                        {printf("typedefs -> empty\n");}
#line 1971 "syntaxAnalyser.tab.c"
    break;

  case 49: /* $@5: %empty  */
#line 133 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("TYPE_DEFS -> type_defs T_SEMI T_ID\n");}
#line 1977 "syntaxAnalyser.tab.c"
    break;

  case 50: /* type_defs: type_defs T_SEMI T_ID $@5 T_EQU type_def  */
#line 134 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEFS -> type_defs T_SEMI T_ID T_EQU type_def\n");}
#line 1983 "syntaxAnalyser.tab.c"
    break;

  case 51: /* type_defs: T_ID T_EQU type_def  */
#line 135 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[-2].strval), NULL, scope); printf("TYPE_DEFS -> T_ID T_EQU type_def\n");}
#line 1989 "syntaxAnalyser.tab.c"
    break;

  case 52: /* type_defs: type_defs error T_ID T_EQU type_def  */
#line 136 "syntaxAnalyser.y"
                                                                                        {printf("MISSING SEMI in type_defs!\n"); }
#line 1995 "syntaxAnalyser.tab.c"
    break;

  case 53: /* type_def: T_ARRAY T_LBRACK dims T_RBRACK T_OF typename  */
#line 138 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_ARRAY T_LBRACK dims T_RBRACK T_OF typename\n");}
#line 2001 "syntaxAnalyser.tab.c"
    break;

  case 54: /* type_def: T_SET T_OF typename  */
#line 139 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_SET T_OF typename\n");}
#line 2007 "syntaxAnalyser.tab.c"
    break;

  case 55: /* type_def: T_RECORD fields T_END  */
#line 140 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_RECORD fields T_END\n");}
#line 2013 "syntaxAnalyser.tab.c"
    break;

  case 56: /* type_def: T_LPAREN identifiers T_RPAREN  */
#line 141 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_LPAREN identifiers T_RPAREN\n");}
#line 2019 "syntaxAnalyser.tab.c"
    break;

  case 57: /* type_def: limit T_DOTDOT limit  */
#line 142 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> limit T_DOTDOT limit\n");}
#line 2025 "syntaxAnalyser.tab.c"
    break;

  case 58: /* type_def: T_LPAREN identifiers error  */
#line 143 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_LPAREN identifiers\n"); printf("MISSING RPAREN in type_def!\n"); }
#line 2031 "syntaxAnalyser.tab.c"
    break;

  case 59: /* type_def: T_LPAREN error T_RPAREN  */
#line 144 "syntaxAnalyser.y"
                                                                                        {printf("TYPE_DEF -> T_LPAREN T_RPAREN\n"); printf("EMPTY BRACKETS BLOCK in type_def!\n"); }
#line 2037 "syntaxAnalyser.tab.c"
    break;

  case 60: /* dims: dims T_COMMA limits  */
#line 146 "syntaxAnalyser.y"
                                                                                        {printf("DIMS -> dims T_COMMA limits\n");}
#line 2043 "syntaxAnalyser.tab.c"
    break;

  case 61: /* dims: limits  */
#line 147 "syntaxAnalyser.y"
                                                                                        {printf("DIMS -> limits\n");}
#line 2049 "syntaxAnalyser.tab.c"
    break;

  case 62: /* limits: limit T_DOTDOT limit  */
#line 149 "syntaxAnalyser.y"
                                                                                        {printf("LIMITS -> limit T_DOTDOT limit\n");}
#line 2055 "syntaxAnalyser.tab.c"
    break;

  case 63: /* limits: T_ID  */
#line 150 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("LIMITS -> T_ID\n");}
#line 2061 "syntaxAnalyser.tab.c"
    break;

  case 66: /* limit: T_ICONST  */
#line 154 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT -> T_ICONST\n");}
#line 2067 "syntaxAnalyser.tab.c"
    break;

  case 67: /* limit: T_CCONST  */
#line 155 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT -> T_CCONST\n");}
#line 2073 "syntaxAnalyser.tab.c"
    break;

  case 68: /* limit: T_BCONST  */
#line 156 "syntaxAnalyser.y"
                                                                                        {printf("CONSTANT -> T_BCONST\n");}
#line 2079 "syntaxAnalyser.tab.c"
    break;

  case 69: /* limit: T_ID  */
#line 157 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("LIMIT -> T_ID\n");}
#line 2085 "syntaxAnalyser.tab.c"
    break;

  case 70: /* typename: standard_type  */
#line 159 "syntaxAnalyser.y"
                                                                                        {printf("TYPENAME -> standard_type\n");}
#line 2091 "syntaxAnalyser.tab.c"
    break;

  case 71: /* typename: T_ID  */
#line 160 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("TYPENAME -> T_ID\n");}
#line 2097 "syntaxAnalyser.tab.c"
    break;

  case 72: /* standard_type: T_INTEGER  */
#line 162 "syntaxAnalyser.y"
                                                                                        {printf("STANDARD_TYPE -> T_INTEGER\n");}
#line 2103 "syntaxAnalyser.tab.c"
    break;

  case 73: /* standard_type: T_REAL  */
#line 163 "syntaxAnalyser.y"
                                                                                        {printf("STANDARD_TYPE -> T_REAL\n");}
#line 2109 "syntaxAnalyser.tab.c"
    break;

  case 74: /* standard_type: T_BOOLEAN  */
#line 164 "syntaxAnalyser.y"
                                                                                        {printf("STANDARD_TYPE -> T_BOOLEAN\n");}
#line 2115 "syntaxAnalyser.tab.c"
    break;

  case 75: /* standard_type: T_CHAR  */
#line 165 "syntaxAnalyser.y"
                                                                                        {printf("STANDARD_TYPE -> T_CHAR\n");}
#line 2121 "syntaxAnalyser.tab.c"
    break;

  case 76: /* fields: fields T_SEMI field  */
#line 167 "syntaxAnalyser.y"
                                                                                        {printf("FIELDS -> fields T_SEMI field\n");}
#line 2127 "syntaxAnalyser.tab.c"
    break;

  case 77: /* fields: field  */
#line 168 "syntaxAnalyser.y"
                                                                                        {printf("FIELDS -> field\n");}
#line 2133 "syntaxAnalyser.tab.c"
    break;

  case 78: /* fields: fields error field  */
#line 169 "syntaxAnalyser.y"
                                                                                        {printf("MISSING SEMI in fields!\n"); }
#line 2139 "syntaxAnalyser.tab.c"
    break;

  case 79: /* field: identifiers T_COLON typename  */
#line 171 "syntaxAnalyser.y"
                                                                                        {printf("FIELD -> identifiers T_COLON typename\n");}
#line 2145 "syntaxAnalyser.tab.c"
    break;

  case 80: /* identifiers: identifiers T_COMMA T_ID  */
#line 173 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("IDENTIFIERS -> identifiers T_COMMA T_ID\n");}
#line 2151 "syntaxAnalyser.tab.c"
    break;

  case 81: /* identifiers: T_ID  */
#line 174 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("IDENTIFIERS -> T_ID\n");}
#line 2157 "syntaxAnalyser.tab.c"
    break;

  case 82: /* vardefs: T_VAR variable_defs T_SEMI  */
#line 176 "syntaxAnalyser.y"
                                                                                        {printf("VARDEFS -> T_VAR variable_defs T_SEMI\n");}
#line 2163 "syntaxAnalyser.tab.c"
    break;

  case 83: /* vardefs: T_VAR variable_defs error  */
#line 177 "syntaxAnalyser.y"
                                                                                        {printf("VARDEFS -> T_VAR variable_defs\n"); printf("MISSING SEMI in vardefs!\n"); }
#line 2169 "syntaxAnalyser.tab.c"
    break;

  case 84: /* vardefs: %empty  */
#line 178 "syntaxAnalyser.y"
                                                                                        {printf("VARDEFS -> empty\n");}
#line 2175 "syntaxAnalyser.tab.c"
    break;

  case 85: /* variable_defs: variable_defs T_SEMI identifiers T_COLON typename  */
#line 180 "syntaxAnalyser.y"
                                                                                        {printf("VARIABLE_DEFS -> variable_defs T_SEMI identifiers T_COLON typename\n");}
#line 2181 "syntaxAnalyser.tab.c"
    break;

  case 86: /* variable_defs: variable_defs error identifiers T_COLON typename  */
#line 181 "syntaxAnalyser.y"
                                                                                        {printf("VARIABLE_DEFS -> variable_defs identifiers T_COLON typename\n"); printf("MISSING SEMI in variable_defs!\n"); }
#line 2187 "syntaxAnalyser.tab.c"
    break;

  case 87: /* variable_defs: identifiers T_COLON typename  */
#line 182 "syntaxAnalyser.y"
                                                                                        {printf("VARIABLE_DEFS -> identifiers T_COLON typename\n");}
#line 2193 "syntaxAnalyser.tab.c"
    break;

  case 88: /* subprograms: subprograms subprogram T_SEMI  */
#line 184 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAMS -> subprograms subprogram T_SEMI\n");}
#line 2199 "syntaxAnalyser.tab.c"
    break;

  case 89: /* subprograms: %empty  */
#line 185 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAMS -> empty\n");}
#line 2205 "syntaxAnalyser.tab.c"
    break;

  case 90: /* subprograms: subprograms subprogram error  */
#line 186 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAMS -> subprograms subprogram\n"); printf("MISSING SEMI in subprograms!\n"); }
#line 2211 "syntaxAnalyser.tab.c"
    break;

  case 91: /* subprogram: sub_header T_SEMI T_FORWARD  */
#line 188 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAM -> sub_header T_SEMI T_FORWARD\n"); hashtbl_get(hashtbl, scope); scope--;}
#line 2217 "syntaxAnalyser.tab.c"
    break;

  case 92: /* subprogram: sub_header T_SEMI declarations subprograms comp_statement  */
#line 189 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAM -> sub_header T_SEMI declarations subprograms comp_statement\n");hashtbl_get(hashtbl, scope); scope--;}
#line 2223 "syntaxAnalyser.tab.c"
    break;

  case 93: /* subprogram: sub_header error T_FORWARD  */
#line 190 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAM -> sub_header T_FORWARD\n"); hashtbl_get(hashtbl, scope); scope--; printf("MISSING SEMI in subprogram!\n"); }
#line 2229 "syntaxAnalyser.tab.c"
    break;

  case 94: /* subprogram: sub_header error declarations subprograms comp_statement  */
#line 191 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAM -> sub_header declarations subprograms comp_statement\n"); printf("MISSING SEMI in subprogram!\n"); }
#line 2235 "syntaxAnalyser.tab.c"
    break;

  case 95: /* $@6: %empty  */
#line 193 "syntaxAnalyser.y"
                                                                                        {scope++; hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope);}
#line 2241 "syntaxAnalyser.tab.c"
    break;

  case 96: /* sub_header: T_FUNCTION T_ID $@6 formal_parameters T_COLON standard_type  */
#line 194 "syntaxAnalyser.y"
                                                                                        {printf("SUB_HEADER -> T_FUNCTION T_ID formal_parameters T_COLON standard_type\n");}
#line 2247 "syntaxAnalyser.tab.c"
    break;

  case 97: /* $@7: %empty  */
#line 195 "syntaxAnalyser.y"
                                                                                        {scope++; hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope);}
#line 2253 "syntaxAnalyser.tab.c"
    break;

  case 98: /* sub_header: T_PROCEDURE T_ID $@7 formal_parameters  */
#line 196 "syntaxAnalyser.y"
                                                                                        {printf("SUB_HEADER -> T_PROCEDURE T_ID formal_parameters\n");}
#line 2259 "syntaxAnalyser.tab.c"
    break;

  case 99: /* sub_header: T_FUNCTION T_ID  */
#line 197 "syntaxAnalyser.y"
                                                                                        {scope++; hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); printf("SUB_HEADER -> T_FUNCTION T_ID\n");}
#line 2265 "syntaxAnalyser.tab.c"
    break;

  case 100: /* formal_parameters: T_LPAREN parameter_list T_RPAREN  */
#line 199 "syntaxAnalyser.y"
                                                                                        {printf("FORMAL_PARAMETERS -> T_LPAREN parameter_list T_RPAREN\n");}
#line 2271 "syntaxAnalyser.tab.c"
    break;

  case 101: /* formal_parameters: T_LPAREN error T_RPAREN  */
#line 200 "syntaxAnalyser.y"
                                                                                        {printf("FORMAL_PARAMETERS -> T_LPAREN T_RPAREN\n"); printf("EMPTY BRACKETS BLOCK in formal_parameters!\n"); }
#line 2277 "syntaxAnalyser.tab.c"
    break;

  case 102: /* formal_parameters: %empty  */
#line 201 "syntaxAnalyser.y"
                                                                                        {printf("FORMAL_PARAMETERS -> empty\n");}
#line 2283 "syntaxAnalyser.tab.c"
    break;

  case 103: /* parameter_list: parameter_list T_SEMI pass identifiers T_COLON typename  */
#line 203 "syntaxAnalyser.y"
                                                                                        {printf("PARAMETER_LIST -> parameter_list T_SEMI pass identifiers T_COLON typename\n");}
#line 2289 "syntaxAnalyser.tab.c"
    break;

  case 104: /* parameter_list: parameter_list error pass identifiers T_COLON typename  */
#line 204 "syntaxAnalyser.y"
                                                                                        {printf("PARAMETER_LIST -> parameter_list pass identifiers T_COLON typename\n"); printf("MISSING SEMI in parameter_list!\n"); }
#line 2295 "syntaxAnalyser.tab.c"
    break;

  case 105: /* parameter_list: pass identifiers T_COLON typename  */
#line 205 "syntaxAnalyser.y"
                                                                                        {printf("PARAMETER_LIST -> pass identifiers T_COLON typename\n");}
#line 2301 "syntaxAnalyser.tab.c"
    break;

  case 106: /* pass: T_VAR  */
#line 207 "syntaxAnalyser.y"
                                                                                        {printf("PASS -> T_VAR\n");}
#line 2307 "syntaxAnalyser.tab.c"
    break;

  case 107: /* pass: %empty  */
#line 208 "syntaxAnalyser.y"
                                                                                        {printf("PASS -> empty\n");}
#line 2313 "syntaxAnalyser.tab.c"
    break;

  case 108: /* $@8: %empty  */
#line 210 "syntaxAnalyser.y"
                                                                                        {scope++;}
#line 2319 "syntaxAnalyser.tab.c"
    break;

  case 109: /* comp_statement: T_BEGIN $@8 statements T_END  */
#line 211 "syntaxAnalyser.y"
                                                                                        {hashtbl_get(hashtbl, scope); printf("COMP_STATEMENT -> T_BEGIN statements T_END\n"); scope--;}
#line 2325 "syntaxAnalyser.tab.c"
    break;

  case 110: /* statements: statements T_SEMI statement  */
#line 213 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENTS -> statements T_SEMI statement\n");}
#line 2331 "syntaxAnalyser.tab.c"
    break;

  case 111: /* statements: statement  */
#line 214 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENTS -> statement\n");}
#line 2337 "syntaxAnalyser.tab.c"
    break;

  case 112: /* statements: statements error statement  */
#line 215 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENTS -> statements statement\n"); printf("MISSING SEMI in statements!\n"); }
#line 2343 "syntaxAnalyser.tab.c"
    break;

  case 113: /* statement: assignment  */
#line 217 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> assignment\n");}
#line 2349 "syntaxAnalyser.tab.c"
    break;

  case 114: /* statement: if_statement  */
#line 218 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> if_statement\n");}
#line 2355 "syntaxAnalyser.tab.c"
    break;

  case 115: /* statement: while_statement  */
#line 219 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> while_statement\n");}
#line 2361 "syntaxAnalyser.tab.c"
    break;

  case 116: /* statement: for_statement  */
#line 220 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> for_statement\n");}
#line 2367 "syntaxAnalyser.tab.c"
    break;

  case 117: /* statement: with_statement  */
#line 221 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> with_statement\n");}
#line 2373 "syntaxAnalyser.tab.c"
    break;

  case 118: /* statement: subprogram_call  */
#line 222 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> subprogram_call\n");}
#line 2379 "syntaxAnalyser.tab.c"
    break;

  case 119: /* statement: io_statement  */
#line 223 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> io_statement\n");}
#line 2385 "syntaxAnalyser.tab.c"
    break;

  case 120: /* statement: comp_statement  */
#line 224 "syntaxAnalyser.y"
                                                                                        {printf("STATEMENT -> comp_statement\n");}
#line 2391 "syntaxAnalyser.tab.c"
    break;

  case 121: /* statement: %empty  */
#line 225 "syntaxAnalyser.y"
                                                                                        {printf("statement -> empty\n");}
#line 2397 "syntaxAnalyser.tab.c"
    break;

  case 122: /* assignment: variable T_ASSIGN expression  */
#line 227 "syntaxAnalyser.y"
                                                                                        {printf("ASSIGNMENT -> variable T_ASSIGN expression\n");}
#line 2403 "syntaxAnalyser.tab.c"
    break;

  case 123: /* assignment: variable T_ASSIGN T_STRINGS  */
#line 228 "syntaxAnalyser.y"
                                                                                        {printf("ASSIGNMENT -> variable T_ASSIGN T_STRINGS\n");}
#line 2409 "syntaxAnalyser.tab.c"
    break;

  case 124: /* if_statement: T_IF expression T_THEN statement if_tail  */
#line 231 "syntaxAnalyser.y"
                                                                                        {printf("IF_STATEMENT -> T_IF expression T_THEN statement if_tail\n");}
#line 2415 "syntaxAnalyser.tab.c"
    break;

  case 125: /* if_statement: T_IF expression error statement if_tail  */
#line 232 "syntaxAnalyser.y"
                                                                                        {printf("IF WITHOUT THEN!\n"); }
#line 2421 "syntaxAnalyser.tab.c"
    break;

  case 126: /* if_tail: T_ELSE statement  */
#line 234 "syntaxAnalyser.y"
                                                                                        {printf("IF_TAIL -> T_ELSE statement\n");}
#line 2427 "syntaxAnalyser.tab.c"
    break;

  case 127: /* if_tail: %empty  */
#line 235 "syntaxAnalyser.y"
                                                                                        {printf("IF_TAIL -> empty\n");}
#line 2433 "syntaxAnalyser.tab.c"
    break;

  case 128: /* while_statement: T_WHILE expression T_DO statement  */
#line 237 "syntaxAnalyser.y"
                                                                                        {printf("WHILE_STATEMENT -> T_WHILE expression T_DO statement\n");}
#line 2439 "syntaxAnalyser.tab.c"
    break;

  case 129: /* $@9: %empty  */
#line 240 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[-1].strval), NULL, scope);}
#line 2445 "syntaxAnalyser.tab.c"
    break;

  case 130: /* for_statement: T_FOR T_ID $@9 T_ASSIGN iter_space T_DO statement  */
#line 241 "syntaxAnalyser.y"
                                                                                        {printf("FOR_STATEMENT -> T_FOR T_ID T_ASSIGN iter_space T_DO statement\n");}
#line 2451 "syntaxAnalyser.tab.c"
    break;

  case 131: /* iter_space: expression T_TO expression  */
#line 243 "syntaxAnalyser.y"
                                                                                        {printf("ITER_SPACE -> expression T_TO expression\n");}
#line 2457 "syntaxAnalyser.tab.c"
    break;

  case 132: /* iter_space: expression T_DOWNTO expression  */
#line 244 "syntaxAnalyser.y"
                                                                                        {printf("ITER_SPACE -> expression T_DOWNTO expression\n");}
#line 2463 "syntaxAnalyser.tab.c"
    break;

  case 133: /* with_statement: T_WITH variable T_DO statement  */
#line 246 "syntaxAnalyser.y"
                                                                                        {printf("WITH_STATEMENT -> T_WITH variable T_DO statement\n");}
#line 2469 "syntaxAnalyser.tab.c"
    break;

  case 134: /* subprogram_call: T_ID  */
#line 248 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope);}
#line 2475 "syntaxAnalyser.tab.c"
    break;

  case 135: /* $@10: %empty  */
#line 249 "syntaxAnalyser.y"
                                                                                        {hashtbl_insert(hashtbl, (yyvsp[-1].strval), NULL, scope);}
#line 2481 "syntaxAnalyser.tab.c"
    break;

  case 136: /* subprogram_call: T_ID T_LPAREN $@10 expressions T_RPAREN  */
#line 250 "syntaxAnalyser.y"
                                                                                        {printf("SUBPROGRAM_CALL -> T_ID T_LPAREN expressions T_RPAREN\n");}
#line 2487 "syntaxAnalyser.tab.c"
    break;

  case 137: /* io_statement: T_READ T_LPAREN read_list T_RPAREN  */
#line 252 "syntaxAnalyser.y"
                                                                                        {printf("IO_STATEMENT -> T_READ T_LPAREN read_list T_RPAREN\n");}
#line 2493 "syntaxAnalyser.tab.c"
    break;

  case 138: /* io_statement: T_WRITE T_LPAREN write_list T_RPAREN  */
#line 253 "syntaxAnalyser.y"
                                                                                        {printf("IO_STATEMENT -> T_WRITE T_LPAREN write_list T_RPAREN\n");}
#line 2499 "syntaxAnalyser.tab.c"
    break;

  case 139: /* io_statement: T_READ T_LPAREN read_list error  */
#line 254 "syntaxAnalyser.y"
                                                                                        {printf("MISSING RPAREN in io_statement!\n"); }
#line 2505 "syntaxAnalyser.tab.c"
    break;

  case 140: /* io_statement: T_WRITE T_LPAREN write_list error  */
#line 255 "syntaxAnalyser.y"
                                                                                        {printf("MISSING RPAREN in io_statement!\n"); }
#line 2511 "syntaxAnalyser.tab.c"
    break;

  case 141: /* read_list: read_list T_COMMA read_item  */
#line 257 "syntaxAnalyser.y"
                                                                                        {printf("READ_LIST -> read_list T_COMMA read_item\n");}
#line 2517 "syntaxAnalyser.tab.c"
    break;

  case 142: /* read_list: read_item  */
#line 258 "syntaxAnalyser.y"
                                                                                        {printf("READ_LIST -> read_item\n");}
#line 2523 "syntaxAnalyser.tab.c"
    break;

  case 143: /* read_item: variable  */
#line 260 "syntaxAnalyser.y"
                                                                                        {printf("READ_ITEM -> variable\n");}
#line 2529 "syntaxAnalyser.tab.c"
    break;

  case 144: /* write_list: write_list T_COMMA write_item  */
#line 262 "syntaxAnalyser.y"
                                                                                        {printf("WRITE_LIST -> write_list T_COMMA write_item\n");}
#line 2535 "syntaxAnalyser.tab.c"
    break;

  case 145: /* write_list: write_item  */
#line 263 "syntaxAnalyser.y"
                                                                                        {printf("WRITE_LIST -> write_item\n");}
#line 2541 "syntaxAnalyser.tab.c"
    break;

  case 146: /* write_item: expression  */
#line 265 "syntaxAnalyser.y"
                                                                                        {printf("WRITE_ITEM -> expression\n");}
#line 2547 "syntaxAnalyser.tab.c"
    break;

  case 147: /* write_item: T_STRINGS  */
#line 266 "syntaxAnalyser.y"
                                                                                        {printf("WRITE_ITEM -> T_STRINGS\n");}
#line 2553 "syntaxAnalyser.tab.c"
    break;


#line 2557 "syntaxAnalyser.tab.c"

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

#line 268 "syntaxAnalyser.y"


// Function to increase number of errors, when found, and print the corresponding line.
void yyerror(const char* message){
	errors++;
    
	printf("(#%d) errors \"%s\" in line (%d): %s<-\n", errors, message, lines-1, line_buffer);
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

	yyin = fopen(argv[1], "r");
	
	if(yyin == NULL){
		perror("fopen");
		return -1;
	}
	yyin2 = fopen(argv[1], "r");
	if(yyin2 == NULL){
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

	fclose(yyin);
	fclose(yyin2);

	return(0);

}



