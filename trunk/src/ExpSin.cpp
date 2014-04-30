/* A Bison parser, made from ExpSin.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

#define yyparse expparse
#define yylex explex
#define yyerror experror
#define yylval explval
#define yychar expchar
#define yydebug expdebug
#define yynerrs expnerrs

# define	NUMBER	257
# define	LP	258
# define	RP	259
# define	IF	260
# define	THEN	261
# define	SIYSOLOSI	262
# define	AND	263
# define	OR	264
# define	XOR	265
# define	LT	266
# define	GT	267
# define	LET	268
# define	GET	269
# define	NEQ	270
# define	EQUAL	271
# define	PLUS	272
# define	MINUS	273
# define	PROD	274
# define	DIV	275
# define	RESTO	276
# define	NOT	277

#line 1 "ExpSin.y"

	#include "ExpAna.h"

	int yylex();
	inline void yyerror(const char *msg) { }

	bool Resultado;
	bool ErrorLexico;
	bool ErrorSintactico;
	char *ExpresionAEvaluar;
        QString cadena = "";
  QMap<QString,double> *MappingValores;
  QMap<QString,double> *MappingMissing;
        QString cadena2;
        bool botonCancelar = false;
        bool mens1 = true;

#line 13 "ExpSin.y"
#ifndef YYSTYPE
typedef union {
	double valor;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		45
#define	YYFLAG		-32768
#define	YYNTBASE	24

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 277 ? yytranslate[x] : 26)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
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
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     2,     4,     6,    10,    14,    18,    22,    26,
      30,    34,    38,    42,    46,    49,    54,    58,    62,    66,
      70,    74
};
static const short yyrhs[] =
{
      25,     0,     1,     0,     3,     0,     4,    25,     5,     0,
      25,    12,    25,     0,    25,    13,    25,     0,    25,    14,
      25,     0,    25,    15,    25,     0,    25,    16,    25,     0,
      25,    17,    25,     0,    25,     9,    25,     0,    25,    10,
      25,     0,    25,    11,    25,     0,    23,    25,     0,     6,
      25,     7,    25,     0,    25,    18,    25,     0,    25,    19,
      25,     0,    25,    20,    25,     0,    25,    21,    25,     0,
      25,    22,    25,     0,    25,     8,    25,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,    31,    32,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "NUMBER", "LP", "RP", "IF", "THEN", 
  "SIYSOLOSI", "AND", "OR", "XOR", "LT", "GT", "LET", "GET", "NEQ", 
  "EQUAL", "PLUS", "MINUS", "PROD", "DIV", "RESTO", "NOT", "result", 
  "expression", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    24,    24,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     4,     3,     3,     3,     3,
       3,     3
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       0,     2,     3,     0,     0,     0,     1,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,    21,    11,    12,
      13,     5,     6,     7,     8,     9,    10,    16,    17,    18,
      19,    20,    15,     0,     0,     0
};

static const short yydefgoto[] =
{
      43,     6
};

static const short yypact[] =
{
      21,-32768,-32768,    25,    25,    25,    72,    41,    57,-32768,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,-32768,    25,    86,    20,    20,
      20,    91,    91,    91,    91,    91,    91,   -17,   -17,   -16,
     -16,-32768,    72,    26,    30,-32768
};

static const short yypgoto[] =
{
  -32768,    -3
};


#define	YYLAST		113


static const short yytable[] =
{
       7,     8,     9,    22,    23,    24,    24,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     1,    42,     2,     3,    44,     4,     2,     3,
      45,     4,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     5,     0,    25,     0,     5,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    26,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    20,
      21,    22,    23,    24
};

static const short yycheck[] =
{
       3,     4,     5,    20,    21,    22,    22,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     1,    26,     3,     4,     0,     6,     3,     4,
       0,     6,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    23,    -1,     5,    -1,    23,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    18,
      19,    20,    21,    22
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
//#line 3 "C:/Documents and Settings/Proyecto/Escritorio/bison/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#ifdef YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif
#endif

//#line 315 "C:/Documents and Settings/Proyecto/Escritorio/bison/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;      
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);
  
#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 1:
#line 31 "ExpSin.y"
{ Resultado = yyvsp[0].valor; ;
    //cadena = yyvsp[0].valor;
    break;}
case 2:
#line 32 "ExpSin.y"
{ ErrorSintactico = true; ;
    //cadena = (QString)yylval;
    break;}
case 3:
#line 35 "ExpSin.y"
{ yyval.valor = yyvsp[0].valor; ;
    //cadena = "NUMBER";
    break;}
case 4:
#line 36 "ExpSin.y"
{ yyval.valor = yyvsp[-1].valor ; ;
    //cadena = "( or )";
    break;}
case 5:
#line 37 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor < yyvsp[0].valor); ;
    //cadena = "<";
    break;}
case 6:
#line 38 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor > yyvsp[0].valor); ;
    //cadena = ">";
    break;}
case 7:
#line 39 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor <= yyvsp[0].valor); ;
    //cadena = "<=";
    break;}
case 8:
#line 40 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor >= yyvsp[0].valor); ;
    //cadena = ">=";
    break;}
case 9:
#line 41 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor != yyvsp[0].valor); ;
    //cadena = "NEQ";
    break;}
case 10:
#line 42 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor == yyvsp[0].valor); ;
    //cadena = "EQUAL";
    break;}
case 11:
#line 43 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor && yyvsp[0].valor); ;
    //cadena = "AND";
    break;}
case 12:
#line 44 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor || yyvsp[0].valor); ;
    //cadena = "OR";
    break;}
case 13:
#line 45 "ExpSin.y"
{ yyval.valor = ((!yyvsp[-2].valor && yyvsp[0].valor) || (yyvsp[-2].valor && !yyvsp[0].valor)); ;
    //cadena = "XOR";
    break;}
case 14:
#line 46 "ExpSin.y"
{ yyval.valor = !yyvsp[0].valor; ;
    //cadena = "NOT";
    break;}
case 15:
#line 47 "ExpSin.y"
{ yyval.valor = (!yyvsp[-2].valor || yyvsp[0].valor); ;
    //cadena = "IF THEN";
    break;}
case 16:
#line 48 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor + yyvsp[0].valor); ;
    //cadena = "PLUS";
    break;}
case 17:
#line 49 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor - yyvsp[0].valor); ;
    //cadena = "MINUS";
    break;}
case 18:
#line 50 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor * yyvsp[0].valor); ;
    //cadena = "PROD";
    break;}
case 19:
#line 51 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor / yyvsp[0].valor); ;
    //cadena = "DIV";
    break;}
case 20:
#line 52 "ExpSin.y"
{ yyval.valor = (yyvsp[-2].valor - (floor(yyvsp[-2].valor / yyvsp[0].valor) * yyvsp[0].valor)); ;
    //cadena = "RESTO";
    break;}
case 21:
#line 53 "ExpSin.y"
{ yyval.valor = !((!yyvsp[-2].valor && yyvsp[0].valor) || (yyvsp[-2].valor && !yyvsp[0].valor)); ;
  //cadena = "SIYSOLOSI";
    break;}
}

//#line 705 "C:/Documents and Settings/Proyecto/Escritorio/bison/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");      
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

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

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 55 "ExpSin.y"


char *yyinputptr;
char *yyinputlim;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluar la expresión con las variables y los valores definidos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TResultado EvaluarExpresion(char* Expresion, QMap<QString,double> *MapValores)
{
  ExpresionAEvaluar = Expresion;
  //MappingValores = &MapValores->toStdMap();
  MappingValores = MapValores;
	ErrorLexico = false;
	ErrorSintactico = false;
	yyinputptr = ExpresionAEvaluar;
	yyinputlim = ExpresionAEvaluar + strlen(ExpresionAEvaluar);
  yyparse();

	if ((ErrorSintactico == false) && (ErrorLexico == false))
		return (TResultado)Resultado;					/* Sin errores */
	if ((ErrorSintactico == true) && (ErrorLexico == false))
		return ERROR_SINTACTICO;				/* Error sintáctico */
	if ((ErrorSintactico == false) && (ErrorLexico == true))
		return ERROR_LEXICO;							/* Error léxico */
	if ((ErrorSintactico == true) && (ErrorLexico == true))
		return ERROR_SINTACTICO_Y_LEXICO;	/* Error sintáctico y léxico */

  return (TResultado)Resultado;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluar la expresión con los missing y los valores definidos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TResultado EvaluarExpresion(char* Expresion, QMap<QString,double> *MapValores, QMap <QString, double> *MapMissing)
{
    int ret;
  ExpresionAEvaluar = Expresion;
  //MappingValores = &MapValores->toStdMap();
  MappingValores = MapValores;
  MappingMissing = MapMissing;
  ErrorLexico = false;
  ErrorSintactico = false;
  yyinputptr = ExpresionAEvaluar;
  yyinputlim = ExpresionAEvaluar + strlen(ExpresionAEvaluar);
  yyparse();  
        if ((ErrorSintactico == false) && (ErrorLexico == false)){
                return (TResultado)Resultado;	}				/* Sin errores */
        if ((ErrorSintactico == true) && (ErrorLexico == false)){
            QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0), "Error Sintactico\n" + yychar, QMessageBox::Ok, QMessageBox::NoButton);
            return ERROR_SINTACTICO;}				/* Error sintáctico */
        if ((ErrorSintactico == false) && (ErrorLexico == true)){
            QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0), "Error Lexico\n" + cadena2, QMessageBox::Ok, QMessageBox::NoButton);
                return ERROR_LEXICO;	}						/* Error léxico */
        if ((ErrorSintactico == true) && (ErrorLexico == true)){
            //QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8), cadena, QMessageBox::Ok, QMessageBox::NoButton);
            QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0), "Error Sintactico y Lexico\n" + cadena2 , QMessageBox::Ok, QMessageBox::NoButton);
            return ERROR_SINTACTICO_Y_LEXICO;}	/* Error sintáctico y léxico */

  return (TResultado)Resultado;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluar la expresión con los missing y los valores definidos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TResultado EvaluarExpresionFiltros(char* Expresion, QMap<QString,double> *MapValores, QMap <QString, double> *MapMissing)
{
    int ret;
  ExpresionAEvaluar = Expresion;
  //MappingValores = &MapValores->toStdMap();
  MappingValores = MapValores;
  MappingMissing = MapMissing;
  ErrorLexico = false;
  ErrorSintactico = false;
  yyinputptr = ExpresionAEvaluar;
  yyinputlim = ExpresionAEvaluar + strlen(ExpresionAEvaluar);
  yyparse();
  if ((!cadena.isEmpty()) && (!botonCancelar)) {
     if (mens1) {
       ret = QMessageBox::warning(0, QApplication::translate("", "Warning en un filtro", 0), "En el filtro " + (QString)Expresion + ".\nEl operador " + cadena + " devuelve TRUE (1) ó FALSE (0).", "Ok" , "Ignorar mensajes");
       if (ret == 1) botonCancelar = true;
       //QMessageBox::warning(0, QApplication::translate("", "Warning en un edit", 0), "valor ret " + QString::number(ret, 10), "Ok");
     }else
       ret = QMessageBox::warning(0, QApplication::translate("", "Warning en un filtro", 0), "En el filtro " + (QString)Expresion + ".\nEl operador " + cadena + " devuelve TRUE (1) ó FALSE (0).", "Ok");
  }
  cadena = "";
        if ((ErrorSintactico == false) && (ErrorLexico == false)){
                return (TResultado)Resultado;	}				/* Sin errores */
        if ((ErrorSintactico == true) && (ErrorLexico == false)){
            QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0), "Error Sintactico\n" + yychar, QMessageBox::Ok, QMessageBox::NoButton);
            return ERROR_SINTACTICO;}				/* Error sintáctico */
        if ((ErrorSintactico == false) && (ErrorLexico == true)){
            QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0), "Error Lexico\n" + cadena2, QMessageBox::Ok, QMessageBox::NoButton);
                return ERROR_LEXICO;	}						/* Error léxico */
        if ((ErrorSintactico == true) && (ErrorLexico == true)){
            //QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0), cadena, QMessageBox::Ok, QMessageBox::NoButton);
            QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0), "Error Sintactico y Lexico\n" + cadena2 , QMessageBox::Ok, QMessageBox::NoButton);
            return ERROR_SINTACTICO_Y_LEXICO;}	/* Error sintáctico y léxico */

  return (TResultado)Resultado;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluar la expresión con los missing y los valores definidos, dando el mensaje de error.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TResultado EvaluarExpresion(char* Expresion, QMap<QString,double> *MapValores, QMap <QString, double> *MapMissing, QString *mensaje)
{
  int ret;
  ExpresionAEvaluar = Expresion;
  //MappingValores = &MapValores->toStdMap();
  MappingValores = MapValores;
  MappingMissing = MapMissing;
  ErrorLexico = false;
  ErrorSintactico = false;
  //cadena = "";
  yyinputptr = ExpresionAEvaluar;
  yyinputlim = ExpresionAEvaluar + strlen(ExpresionAEvaluar);
  yyparse();
  if ((!cadena.isEmpty()) && (!botonCancelar)) {
     if (mens1) {
       ret = QMessageBox::warning(0, QApplication::translate("", "Warning en una regla", 0), "En la regla " + (QString)Expresion + ".\nEl operador " + cadena + " devuelve TRUE (1) ó FALSE (0).", "Ok" , "Ignorar mensajes");
       if (ret == 1) botonCancelar = true;
       //QMessageBox::warning(0, QApplication::translate("", "Warning en un edit", 0), "valor ret " + QString::number(ret, 10), "Ok");
     }else
       ret = QMessageBox::warning(0, QApplication::translate("", "Warning en una regla", 0), "En la regla " + (QString)Expresion + ".\nEl operador " + cadena + " devuelve TRUE (1) ó FALSE (0).", "Ok");
     cadena = "";
  }
  //QMessageBox::warning(0, QApplication::translate("", "Warning en un edit", 0), "valor ret " + QString::number(ret, 10) + " cadena " + cadena, "Ok");

  if ((ErrorSintactico == false) && (ErrorLexico == false)){
     return (TResultado)Resultado;	}				/* Sin errores */
  if ((ErrorSintactico == true) && (ErrorLexico == false)){
     *mensaje = "";
     return ERROR_SINTACTICO;}				/* Error sintáctico */
  if ((ErrorSintactico == false) && (ErrorLexico == true)){
     *mensaje = cadena2;
     return ERROR_LEXICO;	}						/* Error léxico */
  if ((ErrorSintactico == true) && (ErrorLexico == true)){
     *mensaje = cadena2;
     return ERROR_SINTACTICO_Y_LEXICO;}	/* Error sintáctico y léxico */

  return (TResultado)Resultado;
}
