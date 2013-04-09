#ifndef BISON_LIB2_H
# define BISON_LIB2_H

#ifndef YYSTYPE
typedef union {
  double valor;
  char* cadena;
} yystype;
# define YYSTYPE yystype
#endif
extern YYSTYPE reglval;
# define	NUMBER	257
# define	VAR	258
# define	SUMA	259
# define	REST	260
# define	PROD	261


#endif /* not BISON_LIB2_H */