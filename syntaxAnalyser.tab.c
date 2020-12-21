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

    #define YYSTYPE double
    #include <stdio.h>
    #include <math.h>

#line 77 "syntaxAnalyser.tab.c"

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
  YYSYMBOL_header = 60,                    /* header  */
  YYSYMBOL_declarations = 61,              /* declarations  */
  YYSYMBOL_constdefs = 62,                 /* constdefs  */
  YYSYMBOL_constant_defs = 63,             /* constant_defs  */
  YYSYMBOL_expression = 64,                /* expression  */
  YYSYMBOL_variable = 65,                  /* variable  */
  YYSYMBOL_expressions = 66,               /* expressions  */
  YYSYMBOL_constant = 67,                  /* constant  */
  YYSYMBOL_setexpression = 68,             /* setexpression  */
  YYSYMBOL_elexpressions = 69,             /* elexpressions  */
  YYSYMBOL_elexpression = 70,              /* elexpression  */
  YYSYMBOL_typedefs = 71,                  /* typedefs  */
  YYSYMBOL_type_defs = 72,                 /* type_defs  */
  YYSYMBOL_type_def = 73,                  /* type_def  */
  YYSYMBOL_dims = 74,                      /* dims  */
  YYSYMBOL_limits = 75,                    /* limits  */
  YYSYMBOL_limit = 76,                     /* limit  */
  YYSYMBOL_typename = 77,                  /* typename  */
  YYSYMBOL_standard_type = 78,             /* standard_type  */
  YYSYMBOL_fields = 79,                    /* fields  */
  YYSYMBOL_field = 80,                     /* field  */
  YYSYMBOL_identifiers = 81,               /* identifiers  */
  YYSYMBOL_vardefs = 82,                   /* vardefs  */
  YYSYMBOL_variable_defs = 83,             /* variable_defs  */
  YYSYMBOL_subprograms = 84,               /* subprograms  */
  YYSYMBOL_subprogram = 85,                /* subprogram  */
  YYSYMBOL_sub_header = 86,                /* sub_header  */
  YYSYMBOL_formal_parameters = 87,         /* formal_parameters  */
  YYSYMBOL_parameter_list = 88,            /* parameter_list  */
  YYSYMBOL_pass = 89,                      /* pass  */
  YYSYMBOL_comp_statement = 90,            /* comp_statement  */
  YYSYMBOL_statements = 91,                /* statements  */
  YYSYMBOL_statement = 92,                 /* statement  */
  YYSYMBOL_assignment = 93,                /* assignment  */
  YYSYMBOL_if_statement = 94,              /* if_statement  */
  YYSYMBOL_while_statement = 95,           /* while_statement  */
  YYSYMBOL_for_statement = 96,             /* for_statement  */
  YYSYMBOL_iter_space = 97,                /* iter_space  */
  YYSYMBOL_with_statement = 98,            /* with_statement  */
  YYSYMBOL_subprogram_call = 99,           /* subprogram_call  */
  YYSYMBOL_io_statement = 100,             /* io_statement  */
  YYSYMBOL_read_list = 101,                /* read_list  */
  YYSYMBOL_read_item = 102,                /* read_item  */
  YYSYMBOL_write_list = 103,               /* write_list  */
  YYSYMBOL_write_item = 104                /* write_item  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

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
static const yytype_uint8 yyrline[] =
{
       0,    41,    41,    43,    45,    47,    48,    50,    51,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    67,    68,    69,    71,    72,    74,    75,    76,
      77,    79,    80,    82,    83,    85,    86,    88,    89,    91,
      92,    94,    95,    96,    97,    98,   100,   101,   103,   104,
     106,   107,   108,   109,   110,   111,   113,   114,   116,   117,
     118,   119,   121,   122,   124,   126,   127,   129,   130,   132,
     133,   135,   136,   138,   139,   141,   142,   143,   145,   146,
     148,   149,   151,   152,   154,   156,   157,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   169,   170,   173,   174,
     177,   179,   181,   182,   184,   186,   187,   189,   190,   192,
     193,   195,   197,   198,   200,   201
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
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
  "header", "declarations", "constdefs", "constant_defs", "expression",
  "variable", "expressions", "constant", "setexpression", "elexpressions",
  "elexpression", "typedefs", "type_defs", "type_def", "dims", "limits",
  "limit", "typename", "standard_type", "fields", "field", "identifiers",
  "vardefs", "variable_defs", "subprograms", "subprogram", "sub_header",
  "formal_parameters", "parameter_list", "pass", "comp_statement",
  "statements", "statement", "assignment", "if_statement",
  "while_statement", "for_statement", "iter_space", "with_statement",
  "subprogram_call", "io_statement", "read_list", "read_item",
  "write_list", "write_item", YY_NULLPTR
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

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-106)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,    28,     8,    -9,    31,  -150,    37,  -150,    56,  -150,
      39,    50,    73,    80,    92,   131,    89,   117,   126,   196,
     114,   125,   130,   133,   140,   162,  -150,   163,   131,   131,
     131,  -150,    85,  -150,  -150,  -150,   217,     9,  -150,  -150,
     157,   170,    12,   173,   180,   131,   131,   183,   182,   123,
      48,  -150,    14,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,     5,  -150,     0,   189,  -150,    74,   185,   131,
     193,  -150,   197,  -150,   204,    58,  -150,   131,   131,   131,
     131,   131,   131,   202,   131,   131,   223,  -150,   195,   183,
     214,    -8,   155,  -150,   -19,    98,   131,   122,  -150,   196,
    -150,  -150,   216,   258,   162,  -150,   -12,   162,  -150,  -150,
    -150,  -150,   227,   222,   239,    69,   162,   217,    72,  -150,
     131,   131,  -150,   224,   193,   193,  -150,   224,   224,  -150,
      59,   217,  -150,    90,   162,   208,     9,   103,  -150,   131,
     196,   196,   196,  -150,   217,   104,  -150,   143,  -150,   217,
    -150,    73,     7,    69,    27,  -150,   199,  -150,  -150,   159,
     165,     0,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
     200,  -150,   131,   217,  -150,  -150,  -150,   223,   210,  -150,
    -150,   183,    64,   243,   251,  -150,  -150,  -150,    98,  -150,
    -150,   231,   160,  -150,   233,  -150,  -150,   162,    69,  -150,
    -150,  -150,    69,   217,   162,    69,  -150,   131,   131,   196,
     196,  -150,     7,   269,   165,  -150,  -150,  -150,   219,  -150,
     217,   217,  -150,  -150,  -150,    69,  -150,    69,  -150,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     6,     0,     1,     0,    72,    38,     3,
       0,     0,     0,     0,    68,     0,     5,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     4,    22,     0,     0,
       0,    30,     0,    29,    27,    28,     8,    17,    19,    21,
       0,    79,    77,     0,     0,     0,     0,     0,     0,    22,
       0,    94,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    71,     6,     2,     0,    37,    66,     0,     0,     0,
      15,    16,     0,    32,    36,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    76,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,    84,    95,
      73,    72,     0,     0,     0,    55,     0,     0,    53,    54,
      52,    40,     0,     0,     0,     0,    67,    26,     0,    20,
       0,     0,    31,     9,    13,    12,    14,    10,    11,    23,
       0,     7,    82,     0,     0,     0,   111,     0,   110,     0,
      95,    95,    95,   115,   114,     0,   113,     0,    97,    96,
      85,     0,     0,     0,     0,    63,     0,    51,    50,     0,
       0,     0,    65,    61,    59,    58,    60,    57,    70,    56,
       0,    18,     0,    35,    33,    24,    78,    83,     0,    75,
     107,     0,     0,     0,    99,   100,   104,   108,     0,   106,
      74,    49,     0,    47,     0,    42,    43,     0,     0,    44,
      45,    39,     0,    25,     0,     0,   109,     0,     0,    95,
      95,   112,     0,     0,     0,    62,    64,    69,     0,    81,
     102,   103,   101,    98,    46,     0,    48,     0,    41,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,   218,  -150,  -150,   -15,   -14,   -72,  -150,
    -150,  -150,   158,  -150,  -150,   120,  -150,    66,  -141,  -149,
     147,  -150,    86,   -24,  -150,  -150,   184,  -150,  -150,   242,
    -150,   109,   -10,  -150,   -96,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,   106,  -150,   100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    11,   117,    37,   118,    38,
      39,    75,    76,    14,    24,   111,   192,   193,   112,   168,
     169,   154,   155,   156,    26,    68,    12,    20,    21,    87,
     133,   134,    51,    52,    53,    54,    55,    56,    57,   183,
      58,    59,    60,   137,   138,   145,   146
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    67,    22,   150,   195,    50,   102,   103,     5,   104,
     142,   194,   130,    70,    71,    72,   140,    74,   100,   200,
     157,     1,     6,    83,   147,    77,    78,    79,    80,    84,
      91,    92,   105,    94,   106,    98,     6,    81,   107,   191,
     108,   106,   158,    82,   184,   185,   186,   108,   196,   216,
      86,    83,   109,   217,   110,    99,   219,    84,   -79,   109,
       4,   110,   123,   124,   125,   126,   127,   128,   197,    10,
     131,   194,     9,   226,   163,   136,   228,    17,   229,   164,
     144,    13,   149,   159,    15,    50,   165,   207,   166,    18,
      83,    16,   170,    19,   208,    97,    84,    77,    78,    79,
      80,   167,   121,   172,    25,   173,    74,   122,   175,    81,
     178,   171,    23,   222,   223,    82,   172,    27,   114,    28,
     115,    40,    29,    30,   182,    31,    50,    50,    50,   176,
      27,   177,    28,    32,    73,    29,    30,    33,    31,    34,
      35,   190,   180,   187,  -105,  -105,    32,   181,   188,    41,
      33,   143,    34,    35,    27,    61,    28,   203,    42,    29,
      30,    96,    31,    27,  -105,    28,    62,   136,    29,    30,
      32,    31,    63,   144,    33,   148,    34,    35,    64,    32,
     218,    65,   189,    33,   141,    34,    35,   172,    77,    78,
      79,    80,   220,   221,    66,    50,    50,   105,   199,   106,
      81,    69,    85,   114,   212,   108,    82,    43,    86,   213,
      44,    89,    90,   163,    45,    93,    19,   109,   164,   110,
      95,   113,    46,    47,    48,   165,   116,   166,    49,    80,
      77,    78,    79,    80,   129,   132,   119,    77,    78,    79,
      80,   135,    81,   114,   114,   198,   202,   120,    82,    81,
      77,    78,    79,    80,   114,    82,   205,  -106,    78,    79,
      80,   139,    81,   114,   152,   227,   153,   161,    82,  -106,
     160,   162,   209,   210,   -55,  -106,   214,   225,   224,   174,
     101,   201,   179,   215,    88,   151,   204,   206,   211
};

static const yytype_uint8 yycheck[] =
{
      15,    25,    12,    99,   153,    19,     6,     7,     0,     9,
      29,   152,    84,    28,    29,    30,    24,    32,    13,   160,
      32,     3,    31,    42,    96,    33,    34,    35,    36,    48,
      45,    46,    32,    47,    34,    21,    31,    45,    38,    32,
      40,    34,    54,    51,   140,   141,   142,    40,    21,   198,
      38,    42,    52,   202,    54,    41,   205,    48,    46,    52,
      32,    54,    77,    78,    79,    80,    81,    82,    41,    32,
      85,   212,    41,   214,     5,    89,   225,     4,   227,    10,
      95,    25,    97,   107,    45,    99,    17,    23,    19,    16,
      42,    41,   116,    20,    30,    47,    48,    33,    34,    35,
      36,    32,    44,    44,    12,   120,   121,    49,    49,    45,
     134,    39,    32,   209,   210,    51,    44,    32,    44,    34,
      46,    32,    37,    38,   139,    40,   140,   141,   142,    39,
      32,    41,    34,    48,    49,    37,    38,    52,    40,    54,
      55,   151,    39,    39,    21,    22,    48,    44,    44,    32,
      52,    53,    54,    55,    32,    41,    34,   172,    32,    37,
      38,    38,    40,    32,    41,    34,    41,   181,    37,    38,
      48,    40,    42,   188,    52,    53,    54,    55,    45,    48,
     204,    41,    39,    52,    29,    54,    55,    44,    33,    34,
      35,    36,   207,   208,    32,   209,   210,    32,    39,    34,
      45,    38,    45,    44,    44,    40,    51,    11,    38,    49,
      14,    38,    32,     5,    18,    32,    20,    52,    10,    54,
      38,    32,    26,    27,    28,    17,    41,    19,    32,    36,
      33,    34,    35,    36,    32,    12,    39,    33,    34,    35,
      36,    46,    45,    44,    44,    46,    46,    43,    51,    45,
      33,    34,    35,    36,    44,    51,    46,    33,    34,    35,
      36,    47,    45,    44,    48,    46,     8,    45,    51,    45,
      43,    32,    29,    22,    43,    51,    43,     8,   212,   121,
      62,   161,   135,   197,    42,   101,   177,   181,   188
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    59,    60,    32,     0,    31,    61,    62,    41,
      32,    63,    84,    25,    71,    45,    41,     4,    16,    20,
      85,    86,    90,    32,    72,    12,    82,    32,    34,    37,
      38,    40,    48,    52,    54,    55,    64,    65,    67,    68,
      32,    32,    32,    11,    14,    18,    26,    27,    28,    32,
      65,    90,    91,    92,    93,    94,    95,    96,    98,    99,
     100,    41,    41,    42,    45,    41,    32,    81,    83,    38,
      64,    64,    64,    49,    64,    69,    70,    33,    34,    35,
      36,    45,    51,    42,    48,    45,    38,    87,    87,    38,
      32,    64,    64,    32,    65,    38,    38,    47,    21,    41,
      13,    61,     6,     7,     9,    32,    34,    38,    40,    52,
      54,    73,    76,    32,    44,    46,    41,    64,    66,    39,
      43,    44,    49,    64,    64,    64,    64,    64,    64,    32,
      66,    64,    12,    88,    89,    46,    65,   101,   102,    47,
      24,    29,    29,    53,    64,   103,   104,    66,    53,    64,
      92,    84,    48,     8,    79,    80,    81,    32,    54,    81,
      43,    45,    32,     5,    10,    17,    19,    32,    77,    78,
      81,    39,    44,    64,    70,    49,    39,    41,    81,    78,
      39,    44,    64,    97,    92,    92,    92,    39,    44,    39,
      90,    32,    74,    75,    76,    77,    21,    41,    46,    39,
      76,    73,    46,    64,    89,    46,   102,    23,    30,    29,
      22,   104,    44,    49,    43,    80,    77,    77,    81,    77,
      64,    64,    92,    92,    75,     8,    76,    46,    77,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    61,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    65,    66,    66,    67,    67,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    76,    76,    76,    77,    77,    78,    78,
      78,    78,    79,    79,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    91,    91,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    94,
      95,    96,    97,    97,    98,    99,    99,   100,   100,   101,
     101,   102,   103,   103,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     3,     3,     0,     5,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     4,     1,
       3,     1,     1,     3,     4,     3,     1,     1,     1,     1,
       1,     3,     2,     3,     1,     3,     1,     3,     0,     5,
       3,     6,     3,     3,     3,     3,     3,     1,     3,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     3,     1,     3,     0,     5,
       3,     3,     0,     3,     5,     5,     3,     2,     3,     0,
       6,     4,     1,     0,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     3,     6,     4,
       4,     6,     3,     3,     4,     1,     4,     4,     4,     3,
       1,     1,     3,     1,     1,     1
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
  case 6: /* constdefs: %empty  */
#line 48 "syntaxAnalyser.y"
                                                                                        {printf("constdefs -> empty\n");}
#line 1341 "syntaxAnalyser.tab.c"
    break;

  case 27: /* constant: T_ICONST  */
#line 74 "syntaxAnalyser.y"
                                                                                        {printf("constant-> T_ICONST");}
#line 1347 "syntaxAnalyser.tab.c"
    break;

  case 28: /* constant: T_RCONST  */
#line 75 "syntaxAnalyser.y"
                                                                                        {printf("constant-> T_RCONST");}
#line 1353 "syntaxAnalyser.tab.c"
    break;

  case 29: /* constant: T_BCONST  */
#line 76 "syntaxAnalyser.y"
                                                                                        {printf("constant-> T_BCONST");}
#line 1359 "syntaxAnalyser.tab.c"
    break;

  case 30: /* constant: T_CCONST  */
#line 77 "syntaxAnalyser.y"
                                                                                        {printf("constant-> T_CCONST");}
#line 1365 "syntaxAnalyser.tab.c"
    break;

  case 38: /* typedefs: %empty  */
#line 89 "syntaxAnalyser.y"
                                                                                        {printf("typedefs -> empty\n");}
#line 1371 "syntaxAnalyser.tab.c"
    break;

  case 52: /* limit: T_ICONST  */
#line 108 "syntaxAnalyser.y"
                                                                                        {printf("constant-> T_ICONST");}
#line 1377 "syntaxAnalyser.tab.c"
    break;

  case 53: /* limit: T_CCONST  */
#line 109 "syntaxAnalyser.y"
                                                                                        {printf("constant-> T_CCONST");}
#line 1383 "syntaxAnalyser.tab.c"
    break;

  case 54: /* limit: T_BCONST  */
#line 110 "syntaxAnalyser.y"
                                                                                        {printf("constant-> T_BCONST");}
#line 1389 "syntaxAnalyser.tab.c"
    break;

  case 68: /* vardefs: %empty  */
#line 130 "syntaxAnalyser.y"
                                                                                        {printf("vardefs -> empty\n");}
#line 1395 "syntaxAnalyser.tab.c"
    break;

  case 72: /* subprograms: %empty  */
#line 136 "syntaxAnalyser.y"
                                                                                        {printf("subprograms -> empty\n");}
#line 1401 "syntaxAnalyser.tab.c"
    break;

  case 79: /* formal_parameters: %empty  */
#line 146 "syntaxAnalyser.y"
                                                                                        {printf("formal_parameters -> empty\n");}
#line 1407 "syntaxAnalyser.tab.c"
    break;

  case 83: /* pass: %empty  */
#line 152 "syntaxAnalyser.y"
                                                                                        {printf("pass -> empty\n");}
#line 1413 "syntaxAnalyser.tab.c"
    break;

  case 95: /* statement: %empty  */
#line 167 "syntaxAnalyser.y"
                                                                                        {printf("statement -> empty\n");}
#line 1419 "syntaxAnalyser.tab.c"
    break;


#line 1423 "syntaxAnalyser.tab.c"

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
      yyerror (YY_("syntax error"));
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


#if !defined yyoverflow
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

  return yyresult;
}

#line 203 "syntaxAnalyser.y"

                    

