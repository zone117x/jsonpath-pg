/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#pragma once

#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TO_P = 258,
     NULL_P = 259,
     TRUE_P = 260,
     FALSE_P = 261,
     IS_P = 262,
     UNKNOWN_P = 263,
     EXISTS_P = 264,
     IDENT_P = 265,
     STRING_P = 266,
     NUMERIC_P = 267,
     INT_P = 268,
     VARIABLE_P = 269,
     OR_P = 270,
     AND_P = 271,
     NOT_P = 272,
     LESS_P = 273,
     LESSEQUAL_P = 274,
     EQUAL_P = 275,
     NOTEQUAL_P = 276,
     GREATEREQUAL_P = 277,
     GREATER_P = 278,
     ANY_P = 279,
     STRICT_P = 280,
     LAX_P = 281,
     LAST_P = 282,
     STARTS_P = 283,
     WITH_P = 284,
     LIKE_REGEX_P = 285,
     FLAG_P = 286,
     ABS_P = 287,
     SIZE_P = 288,
     TYPE_P = 289,
     FLOOR_P = 290,
     DOUBLE_P = 291,
     CEILING_P = 292,
     KEYVALUE_P = 293,
     DATETIME_P = 294,
     UMINUS = 295
   };
#endif
/* Tokens.  */
#define TO_P 258
#define NULL_P 259
#define TRUE_P 260
#define FALSE_P 261
#define IS_P 262
#define UNKNOWN_P 263
#define EXISTS_P 264
#define IDENT_P 265
#define STRING_P 266
#define NUMERIC_P 267
#define INT_P 268
#define VARIABLE_P 269
#define OR_P 270
#define AND_P 271
#define NOT_P 272
#define LESS_P 273
#define LESSEQUAL_P 274
#define EQUAL_P 275
#define NOTEQUAL_P 276
#define GREATEREQUAL_P 277
#define GREATER_P 278
#define ANY_P 279
#define STRICT_P 280
#define LAX_P 281
#define LAST_P 282
#define STARTS_P 283
#define WITH_P 284
#define LIKE_REGEX_P 285
#define FLAG_P 286
#define ABS_P 287
#define SIZE_P 288
#define TYPE_P 289
#define FLOOR_P 290
#define DOUBLE_P 291
#define CEILING_P 292
#define KEYVALUE_P 293
#define DATETIME_P 294
#define UMINUS 295

typedef uint32 TransactionId;
typedef unsigned int Oid;

typedef union ListCell
{
	void	   *ptr_value;
	int			int_value;
	Oid			oid_value;
	TransactionId xid_value;
} ListCell;

typedef struct List
{
	NodeTag		type;			/* T_List, T_IntList, T_OidList, or T_XidList */
	int			length;			/* number of elements currently present */
	int			max_length;		/* allocated length of elements[] */
	ListCell   *elements;		/* re-allocatable array of cells */
	/* We may allocate some cells along with the List header: */
	ListCell	initial_elements[];
	/* If elements == initial_elements, it's not a separate allocation */
} List;

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 67 "jsonpath_gram.y"
{
	JsonPathString		str;
	List			   *elems;	/* list of JsonPathParseItem */
	List			   *indexs;	/* list of integers */
	JsonPathParseItem  *value;
	JsonPathParseResult *result;
	JsonPathItemType	optype;
	bool				boolean;
	int					integer;
}
/* Line 1529 of yacc.c.  */
#line 140 "jsonpath_gram.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



