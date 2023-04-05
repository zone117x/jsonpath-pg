/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse jsonpath_yyparse
#define yylex   jsonpath_yylex
#define yyerror jsonpath_yyerror
#define yylval  jsonpath_yylval
#define yychar  jsonpath_yychar
#define yydebug jsonpath_yydebug
#define yynerrs jsonpath_yynerrs


/* Tokens.  */
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




/* Copy the first part of user declarations.  */
// #line 1 "jsonpath_gram.y"

/*-------------------------------------------------------------------------
 *
 * jsonpath_gram.y
 *	 Grammar definitions for jsonpath datatype
 *
 * Transforms tokenized jsonpath into tree of JsonPathParseItem structs.
 *
 * Copyright (c) 2019-2023, PostgreSQL Global Development Group
 *
 * IDENTIFICATION
 *	src/backend/utils/adt/jsonpath_gram.y
 *
 *-------------------------------------------------------------------------
 */

#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// #include "postgres.h"

// #include "catalog/pg_collation.h"
// #include "fmgr.h"
#include "jsonpath_internal.h"
// #include "miscadmin.h"
// #include "nodes/pg_list.h"
// #include "regex/regex.h"
// #include "utils/builtins.h"

#define PG_UINT32_MAX	(0xFFFFFFFFU)
#define PG_INT32_MAX	(0x7FFFFFFF)
#define PG_INT32_MIN	(-0x7FFFFFFF-1)

#define NIL						((List *) NULL)

#define REG_BASIC	000000		/* BREs (convenience) */
#define REG_EXTENDED	000001	/* EREs */
#define REG_ADVF	000002		/* advanced features in EREs */
#define REG_ADVANCED	000003	/* AREs (which are also EREs) */
#define REG_QUOTE	000004		/* no special characters, none */
#define REG_NOSPEC	REG_QUOTE	/* historical synonym */
#define REG_ICASE	000010		/* ignore case */
#define REG_NOSUB	000020		/* caller doesn't need subexpr match data */
#define REG_EXPANDED	000040	/* expanded format, white space & comments */
#define REG_NLSTOP	000100		/* \n doesn't match . or [^ ] */
#define REG_NLANCH	000200		/* ^ matches after \n, $ before */
#define REG_NEWLINE 000300		/* newlines are line terminators */
#define REG_PEND	000400		/* ugh -- backward-compatibility hack */
#define REG_EXPECT	001000		/* report details on partial/limited matches */
#define REG_BOSONLY 002000		/* temporary kludge for BOS-only matches */
#define REG_DUMP	004000		/* none of your business :-) */
#define REG_FAKE	010000		/* none of your business :-) */
#define REG_PROGRESS	020000	/* none of your business :-) */

#define Assert(condition)	((void)true)
#define check_list_invariants(l)  ((void) 0)

#define Max(x, y)		((x) > (y) ? (x) : (y))

#define likely(x)	__builtin_expect((x) != 0, 1)
#define unlikely(x) __builtin_expect((x) != 0, 0)

#define LIST_HEADER_OVERHEAD  \
	((int) ((offsetof(List, initial_elements) - 1) / sizeof(ListCell) + 1))
	
typedef unsigned int pg_wchar;

const uint8_t pg_leftmost_one_pos[256] = {
	0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
};

static const int8_t hexlookup[128] = {
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1,
	-1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};

/*
 * Locate the n'th cell (counting from 0) of the list.
 * It is an assertion failure if there is no such cell.
 */
static inline ListCell *
list_nth_cell(const List *list, int n)
{
	Assert(list != NIL);
	Assert(n >= 0 && n < list->length);
	return &list->elements[n];
}
#define lfirst(lc)				((lc)->ptr_value)
#define linitial(l)				lfirst(list_nth_cell(l, 0))
#define llast(l)				lfirst(list_last_cell(l))

enum {
	T_List = 1,
};
#define list_make_ptr_cell(v)	((ListCell) {.ptr_value = (v)})
#define list_make1(x1) \
	list_make1_impl(T_List, list_make_ptr_cell(x1))
#define list_make2(x1,x2) \
	list_make2_impl(T_List, list_make_ptr_cell(x1), list_make_ptr_cell(x2))


static inline ListCell *
list_last_cell(const List *list)
{
	Assert(list != NIL);
	return &list->elements[list->length - 1];
}

static inline int
pg_leftmost_one_pos32(uint32 word)
{
#ifdef HAVE__BUILTIN_CLZ
	Assert(word != 0);

	return 31 - __builtin_clz(word);
#elif defined(_MSC_VER)
	unsigned long result;
	bool		non_zero;

	non_zero = _BitScanReverse(&result, word);
	Assert(non_zero);
	return (int) result;
#else
	int			shift = 32 - 8;

	Assert(word != 0);

	while ((word >> shift) == 0)
		shift -= 8;

	return shift + pg_leftmost_one_pos[(word >> shift) & 255];
#endif							/* HAVE__BUILTIN_CLZ */
}

static inline uint32
pg_nextpower2_32(uint32 num)
{
	Assert(num > 0 && num <= PG_UINT32_MAX / 2 + 1);

	/*
	 * A power 2 number has only 1 bit set.  Subtracting 1 from such a number
	 * will turn on all previous bits resulting in no common bits being set
	 * between num and num-1.
	 */
	if ((num & (num - 1)) == 0)
		return num;				/* already power 2 */

	return ((uint32) 1) << (pg_leftmost_one_pos32(num) + 1);
}

static List *
new_list(NodeTag type, int min_size)
{
	List	   *newlist;
	int			max_size;

	Assert(min_size > 0);

	/*
	 * We allocate all the requested cells, and possibly some more, as part of
	 * the same palloc request as the List header.  This is a big win for the
	 * typical case of short fixed-length lists.  It can lose if we allocate a
	 * moderately long list and then it gets extended; we'll be wasting more
	 * initial_elements[] space than if we'd made the header small.  However,
	 * rounding up the request as we do in the normal code path provides some
	 * defense against small extensions.
	 */

#ifndef DEBUG_LIST_MEMORY_USAGE

	/*
	 * Normally, we set up a list with some extra cells, to allow it to grow
	 * without a repalloc.  Prefer cell counts chosen to make the total
	 * allocation a power-of-2, since palloc would round it up to that anyway.
	 * (That stops being true for very large allocations, but very long lists
	 * are infrequent, so it doesn't seem worth special logic for such cases.)
	 *
	 * The minimum allocation is 8 ListCell units, providing either 4 or 5
	 * available ListCells depending on the machine's word width.  Counting
	 * palloc's overhead, this uses the same amount of space as a one-cell
	 * list did in the old implementation, and less space for any longer list.
	 *
	 * We needn't worry about integer overflow; no caller passes min_size
	 * that's more than twice the size of an existing list, so the size limits
	 * within palloc will ensure that we don't overflow here.
	 */
	max_size = pg_nextpower2_32(Max(8, min_size + LIST_HEADER_OVERHEAD));
	max_size -= LIST_HEADER_OVERHEAD;
#else

	/*
	 * For debugging, don't allow any extra space.  This forces any cell
	 * addition to go through enlarge_list() and thus move the existing data.
	 */
	max_size = min_size;
#endif

	newlist = (List *) calloc(1, offsetof(List, initial_elements) +
							  max_size * sizeof(ListCell));
	newlist->type = type;
	newlist->length = min_size;
	newlist->max_length = max_size;
	newlist->elements = newlist->initial_elements;

	return newlist;
}

List *
list_make1_impl(NodeTag t, ListCell datum1)
{
	List	   *list = new_list(t, 1);

	list->elements[0] = datum1;
	check_list_invariants(list);
	return list;
}

List *
list_make2_impl(NodeTag t, ListCell datum1, ListCell datum2)
{
	List	   *list = new_list(t, 2);

	list->elements[0] = datum1;
	list->elements[1] = datum2;
	check_list_invariants(list);
	return list;
}

static void
enlarge_list(List *list, int min_size)
{
	int			new_max_len;

	Assert(min_size > list->max_length);	/* else we shouldn't be here */

#ifndef DEBUG_LIST_MEMORY_USAGE

	/*
	 * As above, we prefer power-of-two total allocations; but here we need
	 * not account for list header overhead.
	 */

	/* clamp the minimum value to 16, a semi-arbitrary small power of 2 */
	new_max_len = pg_nextpower2_32(Max(16, min_size));

#else
	/* As above, don't allocate anything extra */
	new_max_len = min_size;
#endif

	if (list->elements == list->initial_elements)
	{
		/*
		 * Replace original in-line allocation with a separate palloc block.
		 * Ensure it is in the same memory context as the List header.  (The
		 * previous List implementation did not offer any guarantees about
		 * keeping all list cells in the same context, but it seems reasonable
		 * to create such a guarantee now.)
		 */
		list->elements = 
		list->elements = (ListCell *)calloc(1, new_max_len * sizeof(ListCell));
		memcpy(list->elements, list->initial_elements,
			   list->length * sizeof(ListCell));

		/*
		 * We must not move the list header, so it's unsafe to try to reclaim
		 * the initial_elements[] space via repalloc.  In debugging builds,
		 * however, we can clear that space and/or mark it inaccessible.
		 * (wipe_mem includes VALGRIND_MAKE_MEM_NOACCESS.)
		 */
#ifdef CLOBBER_FREED_MEMORY
		wipe_mem(list->initial_elements,
				 list->max_length * sizeof(ListCell));
#else

#endif
	}
	else
	{
#ifndef DEBUG_LIST_MEMORY_USAGE
		/* Normally, let repalloc deal with enlargement */
		list->elements = (ListCell *) realloc(list->elements,
											   new_max_len * sizeof(ListCell));
#else
		/*
		 * repalloc() might enlarge the space in-place, which we don't want
		 * for debugging purposes, so forcibly move the data somewhere else.
		 */
		ListCell   *newelements;

		newelements = (ListCell *)
			MemoryContextAlloc(GetMemoryChunkContext(list),
							   new_max_len * sizeof(ListCell));
		memcpy(newelements, list->elements,
			   list->length * sizeof(ListCell));
		pfree(list->elements);
		list->elements = newelements;
#endif
	}

	list->max_length = new_max_len;
}

static void
new_tail_cell(List *list)
{
	/* Enlarge array if necessary */
	if (list->length >= list->max_length)
		enlarge_list(list, list->length + 1);
	list->length++;
}

List *
lappend(List *list, void *datum)
{
	Assert(IsPointerList(list));

	if (list == NIL)
		list = new_list(T_List, 1);
	else
		new_tail_cell(list);

	llast(list) = datum;
	check_list_invariants(list);
	return list;
}

/*
 * State structs for various looping macros below.
 */
typedef struct ForEachState
{
	const List *l;				/* list we're looping through */
	int			i;				/* current element index */
} ForEachState;

#define foreach(cell, lst)	\
	for (ForEachState cell##__state = {(lst), 0}; \
		 (cell##__state.l != NIL && \
		  cell##__state.i < cell##__state.l->length) ? \
		 (cell = &cell##__state.l->elements[cell##__state.i], true) : \
		 (cell = NULL, false); \
		 cell##__state.i++)

#define for_each_from(cell, lst, N)	\
	for (ForEachState cell##__state = for_each_from_setup(lst, N); \
		 (cell##__state.l != NIL && \
		  cell##__state.i < cell##__state.l->length) ? \
		 (cell = &cell##__state.l->elements[cell##__state.i], true) : \
		 (cell = NULL, false); \
		 cell##__state.i++)

static inline ForEachState
for_each_from_setup(const List *lst, int N)
{
	ForEachState r = {lst, N};

	Assert(N >= 0);
	return r;
}

static inline int
list_length(const List *l)
{
	return l ? l->length : 0;
}

int32
pg_strtoint32_safe(const char *s, Node *escontext)
{
	const char *ptr = s;
	const char *firstdigit;
	uint32		tmp = 0;
	bool		neg = false;

	/* skip leading spaces */
	while (likely(*ptr) && isspace((unsigned char) *ptr))
		ptr++;

	/* handle sign */
	if (*ptr == '-')
	{
		ptr++;
		neg = true;
	}
	else if (*ptr == '+')
		ptr++;

	/* process digits */
	if (ptr[0] == '0' && (ptr[1] == 'x' || ptr[1] == 'X'))
	{
		firstdigit = ptr += 2;

		while (*ptr)
		{
			if (isxdigit((unsigned char) *ptr))
			{
				if (unlikely(tmp > -(PG_INT32_MIN / 16)))
					goto out_of_range;

				tmp = tmp * 16 + hexlookup[(unsigned char) *ptr++];
			}
			else if (*ptr == '_')
			{
				/* underscore must be followed by more digits */
				ptr++;
				if (*ptr == '\0' || !isxdigit((unsigned char) *ptr))
					goto invalid_syntax;
			}
			else
				break;
		}
	}
	else if (ptr[0] == '0' && (ptr[1] == 'o' || ptr[1] == 'O'))
	{
		firstdigit = ptr += 2;

		while (*ptr)
		{
			if (*ptr >= '0' && *ptr <= '7')
			{
				if (unlikely(tmp > -(PG_INT32_MIN / 8)))
					goto out_of_range;

				tmp = tmp * 8 + (*ptr++ - '0');
			}
			else if (*ptr == '_')
			{
				/* underscore must be followed by more digits */
				ptr++;
				if (*ptr == '\0' || *ptr < '0' || *ptr > '7')
					goto invalid_syntax;
			}
			else
				break;
		}
	}
	else if (ptr[0] == '0' && (ptr[1] == 'b' || ptr[1] == 'B'))
	{
		firstdigit = ptr += 2;

		while (*ptr)
		{
			if (*ptr >= '0' && *ptr <= '1')
			{
				if (unlikely(tmp > -(PG_INT32_MIN / 2)))
					goto out_of_range;

				tmp = tmp * 2 + (*ptr++ - '0');
			}
			else if (*ptr == '_')
			{
				/* underscore must be followed by more digits */
				ptr++;
				if (*ptr == '\0' || *ptr < '0' || *ptr > '1')
					goto invalid_syntax;
			}
			else
				break;
		}
	}
	else
	{
		firstdigit = ptr;

		while (*ptr)
		{
			if (isdigit((unsigned char) *ptr))
			{
				if (unlikely(tmp > -(PG_INT32_MIN / 10)))
					goto out_of_range;

				tmp = tmp * 10 + (*ptr++ - '0');
			}
			else if (*ptr == '_')
			{
				/* underscore may not be first */
				if (unlikely(ptr == firstdigit))
					goto invalid_syntax;
				/* and it must be followed by more digits */
				ptr++;
				if (*ptr == '\0' || !isdigit((unsigned char) *ptr))
					goto invalid_syntax;
			}
			else
				break;
		}
	}

	/* require at least one digit */
	if (unlikely(ptr == firstdigit))
		goto invalid_syntax;

	/* allow trailing whitespace, but not other trailing chars */
	while (*ptr != '\0' && isspace((unsigned char) *ptr))
		ptr++;

	if (unlikely(*ptr != '\0'))
		goto invalid_syntax;

	if (neg)
	{
		/* check the negative equivalent will fit without overflowing */
		if (tmp > (uint32) (-(PG_INT32_MIN + 1)) + 1)
			goto out_of_range;
		return -((int32) tmp);
	}

	if (tmp > PG_INT32_MAX)
		goto out_of_range;

	return (int32) tmp;

out_of_range:
	return false;

invalid_syntax:
	return false;
}

int32
pg_strtoint32(const char *s)
{
	return pg_strtoint32_safe(s, NULL);
}

static JsonPathParseItem *makeItemType(JsonPathItemType type);
static JsonPathParseItem *makeItemString(JsonPathString *s);
static JsonPathParseItem *makeItemVariable(JsonPathString *s);
static JsonPathParseItem *makeItemKey(JsonPathString *s);
static JsonPathParseItem *makeItemNumeric(JsonPathString *s);
static JsonPathParseItem *makeItemBool(bool val);
static JsonPathParseItem *makeItemBinary(JsonPathItemType type,
										 JsonPathParseItem *la,
										 JsonPathParseItem *ra);
static JsonPathParseItem *makeItemUnary(JsonPathItemType type,
										JsonPathParseItem *a);
static JsonPathParseItem *makeItemList(List *list);
static JsonPathParseItem *makeIndexArray(List *list);
static JsonPathParseItem *makeAny(int first, int last);
static bool makeItemLikeRegex(JsonPathParseItem *expr,
							  JsonPathString *pattern,
							  JsonPathString *flags,
							  JsonPathParseItem ** result,
							  struct Node *escontext);

/*
 * Bison doesn't allocate anything that needs to live across parser calls,
 * so we can easily have it use palloc instead of malloc.  This prevents
 * memory leaks if we error out during parsing.
 */
#define YYMALLOC malloc
#define YYFREE   free

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
// #line 67 "jsonpath_gram.y"
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
/* Line 193 of yacc.c.  */
// #line 251 "jsonpath_gram.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
// #line 264 "jsonpath_gram.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
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
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    48,    44,     2,     2,
      46,    47,    42,    40,    50,    41,    55,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,     9,    11,    13,    15,    16,
      18,    20,    22,    24,    26,    28,    30,    32,    34,    36,
      38,    40,    42,    46,    51,    53,    57,    61,    65,    68,
      74,    79,    83,    89,    91,    93,    95,    97,    99,   101,
     103,   108,   113,   116,   118,   122,   125,   128,   132,   136,
     140,   144,   148,   150,   154,   156,   160,   164,   168,   170,
     172,   174,   179,   186,   189,   192,   194,   197,   202,   208,
     213,   215,   217,   218,   220,   222,   224,   226,   228,   230,
     232,   234,   236,   238,   240,   242,   244,   246,   248,   250,
     252,   254,   256,   258,   260,   262,   264,   266,   268,   270,
     272,   274,   276,   278,   280
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    60,    59,    -1,    -1,    68,    -1,    64,
      -1,    25,    -1,    26,    -1,    -1,    11,    -1,     4,    -1,
       5,    -1,     6,    -1,    12,    -1,    13,    -1,    14,    -1,
      20,    -1,    21,    -1,    18,    -1,    23,    -1,    19,    -1,
      22,    -1,    46,    64,    47,    -1,     9,    46,    68,    47,
      -1,    63,    -1,    68,    62,    68,    -1,    64,    16,    64,
      -1,    64,    15,    64,    -1,    17,    63,    -1,    46,    64,
      47,     7,     8,    -1,    68,    28,    29,    65,    -1,    68,
      30,    11,    -1,    68,    30,    11,    31,    11,    -1,    11,
      -1,    14,    -1,    61,    -1,    48,    -1,    49,    -1,    27,
      -1,    66,    -1,    46,    68,    47,    74,    -1,    46,    64,
      47,    74,    -1,    67,    74,    -1,    67,    -1,    46,    68,
      47,    -1,    40,    68,    -1,    41,    68,    -1,    68,    40,
      68,    -1,    68,    41,    68,    -1,    68,    42,    68,    -1,
      68,    43,    68,    -1,    68,    44,    68,    -1,    68,    -1,
      68,     3,    68,    -1,    69,    -1,    70,    50,    69,    -1,
      51,    42,    52,    -1,    51,    70,    52,    -1,    13,    -1,
      27,    -1,    24,    -1,    24,    53,    72,    54,    -1,    24,
      53,    72,     3,    72,    54,    -1,    55,    77,    -1,    55,
      42,    -1,    71,    -1,    55,    73,    -1,    55,    79,    46,
      47,    -1,    55,    39,    46,    76,    47,    -1,    56,    46,
      64,    47,    -1,    11,    -1,    75,    -1,    -1,    78,    -1,
      10,    -1,    11,    -1,     3,    -1,     4,    -1,     5,    -1,
       6,    -1,     7,    -1,     8,    -1,     9,    -1,    25,    -1,
      26,    -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,
      36,    -1,    37,    -1,    39,    -1,    38,    -1,    27,    -1,
      28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,
      38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   123,   127,   128,   132,   133,   134,   138,
     139,   140,   141,   142,   143,   144,   148,   149,   150,   151,
     152,   153,   157,   158,   162,   163,   164,   165,   166,   167,
     169,   171,   178,   188,   189,   193,   194,   195,   196,   200,
     201,   202,   203,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   219,   220,   224,   225,   229,   230,   234,   235,
     239,   240,   241,   246,   247,   248,   249,   250,   251,   253,
     257,   261,   262,   266,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   297,   298,
     299,   300,   301,   302,   303
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TO_P", "NULL_P", "TRUE_P", "FALSE_P",
  "IS_P", "UNKNOWN_P", "EXISTS_P", "IDENT_P", "STRING_P", "NUMERIC_P",
  "INT_P", "VARIABLE_P", "OR_P", "AND_P", "NOT_P", "LESS_P", "LESSEQUAL_P",
  "EQUAL_P", "NOTEQUAL_P", "GREATEREQUAL_P", "GREATER_P", "ANY_P",
  "STRICT_P", "LAX_P", "LAST_P", "STARTS_P", "WITH_P", "LIKE_REGEX_P",
  "FLAG_P", "ABS_P", "SIZE_P", "TYPE_P", "FLOOR_P", "DOUBLE_P",
  "CEILING_P", "KEYVALUE_P", "DATETIME_P", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "'('", "')'", "'$'", "'@'", "','", "'['", "']'", "'{'",
  "'}'", "'.'", "'?'", "$accept", "result", "expr_or_predicate", "mode",
  "scalar_value", "comp_op", "delimited_predicate", "predicate",
  "starts_with_initial", "path_primary", "accessor_expr", "expr",
  "index_elem", "index_list", "array_accessor", "any_level", "any_path",
  "accessor_op", "datetime_template", "opt_datetime_template", "key",
  "key_name", "method", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      43,    45,    42,    47,    37,   295,    40,    41,    36,    64,
      44,    91,    93,   123,   125,    46,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    67,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      75,    76,    76,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      79,    79,    79,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     1,     3,     3,     3,     2,     5,
       4,     3,     5,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     2,     1,     3,     2,     2,     3,     3,     3,
       3,     3,     1,     3,     1,     3,     3,     3,     1,     1,
       1,     4,     6,     2,     2,     1,     2,     4,     5,     4,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     6,     7,     0,     0,     1,    10,    11,    12,     0,
       9,    13,    14,    15,     0,    38,     0,     0,     0,    36,
      37,     2,    35,    24,     5,    39,    43,     4,     0,     0,
      28,     0,    45,    46,     0,     0,     0,     0,     0,     0,
       0,    65,    42,    18,    20,    16,    17,    21,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    44,    27,    26,     0,    52,    54,     0,    76,
      77,    78,    79,    80,    81,    82,    74,    75,    60,    83,
      84,    93,    94,    95,    96,    97,    85,    86,    87,    88,
      89,    90,    92,    91,    64,    66,    63,    73,     0,     0,
       0,    31,    47,    48,    49,    50,    51,    25,    23,    22,
       0,     0,    41,    40,    56,     0,     0,    57,     0,    72,
       0,     0,    33,    34,    30,     0,    29,    53,    55,    58,
      59,     0,    70,    71,     0,    67,    69,    32,     0,    61,
      68,     0,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    21,     4,    22,    56,    23,    24,   124,    25,
      26,    59,    67,    68,    41,   131,    95,   112,   133,   134,
      96,    97,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -44
static const yytype_int16 yypact[] =
{
       7,   -44,   -44,    18,    51,   -44,   -44,   -44,   -44,   -43,
     -44,   -44,   -44,   -44,    -3,   -44,   114,   114,    51,   -44,
     -44,   -44,   -44,   -44,    10,   -44,   -35,   195,   114,    51,
     -44,    51,   -44,   -44,    14,   165,    51,    51,    68,   140,
      -9,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,    37,
      60,   114,   114,   114,   114,   114,   114,    46,    20,   195,
      30,     3,   -35,    59,   -44,    24,    -2,   -44,   -41,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,    31,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,    48,    50,    52,    61,
      67,    69,    78,    83,   -44,   -44,   -44,   -44,    84,    51,
      17,   100,    79,    79,   -44,   -44,   -44,    62,   -44,   -44,
     -35,    75,   -44,   -44,   -44,   114,   114,   -44,    -8,   121,
      86,    54,   -44,   -44,   -44,   123,   -44,    62,   -44,   -44,
     -44,    -1,   -44,   -44,    88,   -44,   -44,   -44,    -8,   -44,
     -44,    82,   -44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,   -44,   -44,   -44,   -44,   124,   -14,   -44,   -44,
     -44,    -4,    21,   -44,   -44,     1,   -44,   -18,   -44,   -44,
     -44,   -44,   -44
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -105
static const yytype_int16 yytable[] =
{
      27,   115,   138,    28,    34,   129,     9,    -3,    42,   116,
     111,   117,    32,    33,    35,    58,    38,    60,     5,   130,
      39,    40,    63,    64,    57,    36,    37,    35,   122,    36,
      37,   123,     1,     2,    66,    36,    37,    99,    51,    52,
      53,    54,    55,    29,   113,    36,    37,   102,   103,   104,
     105,   106,   107,   139,    38,     6,     7,     8,    39,    40,
       9,    61,    10,    11,    12,    13,   100,   109,    14,    36,
      37,   101,     6,     7,     8,    37,   114,   110,    15,    10,
      11,    12,    13,   126,   118,   121,    51,    52,    53,    54,
      55,    16,    17,   108,   -98,    15,   -99,    18,  -100,    19,
      20,   136,    51,    52,    53,    54,    55,  -101,    16,    17,
      65,   127,    66,  -102,    31,  -103,    19,    20,     6,     7,
       8,    53,    54,    55,  -104,    10,    11,    12,    13,   119,
     120,   125,   132,   135,   137,   140,   142,   128,    30,   141,
       0,    15,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,    16,    17,     0,     0,     0,     0,
      31,     0,    19,    20,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,    94,    43,    44,    45,    46,    47,    48,     0,
       0,     0,     0,    49,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    52,    53,    54,    55,
       0,     0,    62,    43,    44,    45,    46,    47,    48,     0,
       0,     0,     0,    49,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    52,    53,    54,    55
};

static const yytype_int16 yycheck[] =
{
       4,     3,     3,    46,    18,    13,     9,     0,    26,    50,
       7,    52,    16,    17,    18,    29,    51,    31,     0,    27,
      55,    56,    36,    37,    28,    15,    16,    31,    11,    15,
      16,    14,    25,    26,    38,    15,    16,    46,    40,    41,
      42,    43,    44,    46,    62,    15,    16,    51,    52,    53,
      54,    55,    56,    54,    51,     4,     5,     6,    55,    56,
       9,    47,    11,    12,    13,    14,    29,    47,    17,    15,
      16,    11,     4,     5,     6,    16,    52,    47,    27,    11,
      12,    13,    14,     8,    53,    99,    40,    41,    42,    43,
      44,    40,    41,    47,    46,    27,    46,    46,    46,    48,
      49,    47,    40,    41,    42,    43,    44,    46,    40,    41,
      42,   115,   116,    46,    46,    46,    48,    49,     4,     5,
       6,    42,    43,    44,    46,    11,    12,    13,    14,    46,
      46,    31,    11,    47,    11,    47,    54,   116,    14,   138,
      -1,    27,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      46,    -1,    48,    49,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    47,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    26,    58,    60,     0,     4,     5,     6,     9,
      11,    12,    13,    14,    17,    27,    40,    41,    46,    48,
      49,    59,    61,    63,    64,    66,    67,    68,    46,    46,
      63,    46,    68,    68,    64,    68,    15,    16,    51,    55,
      56,    71,    74,    18,    19,    20,    21,    22,    23,    28,
      30,    40,    41,    42,    43,    44,    62,    68,    64,    68,
      64,    47,    47,    64,    64,    42,    68,    69,    70,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    42,    73,    77,    78,    79,    46,
      29,    11,    68,    68,    68,    68,    68,    68,    47,    47,
      47,     7,    74,    74,    52,     3,    50,    52,    53,    46,
      46,    64,    11,    14,    65,    31,     8,    68,    69,    13,
      27,    72,    11,    75,    76,    47,    47,    11,     3,    54,
      47,    72,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


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
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (result, escontext, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, result, escontext)
#endif

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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, result, escontext); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, JsonPathParseResult **result, struct Node *escontext)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, result, escontext)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    JsonPathParseResult **result;
    struct Node *escontext;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (result);
  YYUSE (escontext);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, JsonPathParseResult **result, struct Node *escontext)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, result, escontext)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    JsonPathParseResult **result;
    struct Node *escontext;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, result, escontext);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, JsonPathParseResult **result, struct Node *escontext)
#else
static void
yy_reduce_print (yyvsp, yyrule, result, escontext)
    YYSTYPE *yyvsp;
    int yyrule;
    JsonPathParseResult **result;
    struct Node *escontext;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , result, escontext);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, result, escontext); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, JsonPathParseResult **result, struct Node *escontext)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, result, escontext)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    JsonPathParseResult **result;
    struct Node *escontext;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (result);
  YYUSE (escontext);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (JsonPathParseResult **result, struct Node *escontext);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (JsonPathParseResult **result, struct Node *escontext)
#else
int
yyparse (result, escontext)
    JsonPathParseResult **result;
    struct Node *escontext;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
// #line 117 "jsonpath_gram.y"
    {
										*result = calloc(1, sizeof(JsonPathParseResult));
										(*result)->expr = (yyvsp[(2) - (2)].value);
										(*result)->lax = (yyvsp[(1) - (2)].boolean);
										(void) yynerrs;
									;}
    break;

  case 3:
// #line 123 "jsonpath_gram.y"
    { *result = NULL; ;}
    break;

  case 4:
// #line 127 "jsonpath_gram.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value); ;}
    break;

  case 5:
// #line 128 "jsonpath_gram.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value); ;}
    break;

  case 6:
// #line 132 "jsonpath_gram.y"
    { (yyval.boolean) = false; ;}
    break;

  case 7:
// #line 133 "jsonpath_gram.y"
    { (yyval.boolean) = true; ;}
    break;

  case 8:
// #line 134 "jsonpath_gram.y"
    { (yyval.boolean) = true; ;}
    break;

  case 9:
// #line 138 "jsonpath_gram.y"
    { (yyval.value) = makeItemString(&(yyvsp[(1) - (1)].str)); ;}
    break;

  case 10:
// #line 139 "jsonpath_gram.y"
    { (yyval.value) = makeItemString(NULL); ;}
    break;

  case 11:
// #line 140 "jsonpath_gram.y"
    { (yyval.value) = makeItemBool(true); ;}
    break;

  case 12:
// #line 141 "jsonpath_gram.y"
    { (yyval.value) = makeItemBool(false); ;}
    break;

  case 13:
// #line 142 "jsonpath_gram.y"
    { (yyval.value) = makeItemNumeric(&(yyvsp[(1) - (1)].str)); ;}
    break;

  case 14:
// #line 143 "jsonpath_gram.y"
    { (yyval.value) = makeItemNumeric(&(yyvsp[(1) - (1)].str)); ;}
    break;

  case 15:
// #line 144 "jsonpath_gram.y"
    { (yyval.value) = makeItemVariable(&(yyvsp[(1) - (1)].str)); ;}
    break;

  case 16:
// #line 148 "jsonpath_gram.y"
    { (yyval.optype) = jpiEqual; ;}
    break;

  case 17:
// #line 149 "jsonpath_gram.y"
    { (yyval.optype) = jpiNotEqual; ;}
    break;

  case 18:
// #line 150 "jsonpath_gram.y"
    { (yyval.optype) = jpiLess; ;}
    break;

  case 19:
// #line 151 "jsonpath_gram.y"
    { (yyval.optype) = jpiGreater; ;}
    break;

  case 20:
// #line 152 "jsonpath_gram.y"
    { (yyval.optype) = jpiLessOrEqual; ;}
    break;

  case 21:
// #line 153 "jsonpath_gram.y"
    { (yyval.optype) = jpiGreaterOrEqual; ;}
    break;

  case 22:
// #line 157 "jsonpath_gram.y"
    { (yyval.value) = (yyvsp[(2) - (3)].value); ;}
    break;

  case 23:
// #line 158 "jsonpath_gram.y"
    { (yyval.value) = makeItemUnary(jpiExists, (yyvsp[(3) - (4)].value)); ;}
    break;

  case 24:
// #line 162 "jsonpath_gram.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value); ;}
    break;

  case 25:
// #line 163 "jsonpath_gram.y"
    { (yyval.value) = makeItemBinary((yyvsp[(2) - (3)].optype), (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 26:
// #line 164 "jsonpath_gram.y"
    { (yyval.value) = makeItemBinary(jpiAnd, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 27:
// #line 165 "jsonpath_gram.y"
    { (yyval.value) = makeItemBinary(jpiOr, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 28:
// #line 166 "jsonpath_gram.y"
    { (yyval.value) = makeItemUnary(jpiNot, (yyvsp[(2) - (2)].value)); ;}
    break;

  case 29:
// #line 168 "jsonpath_gram.y"
    { (yyval.value) = makeItemUnary(jpiIsUnknown, (yyvsp[(2) - (5)].value)); ;}
    break;

  case 30:
// #line 170 "jsonpath_gram.y"
    { (yyval.value) = makeItemBinary(jpiStartsWith, (yyvsp[(1) - (4)].value), (yyvsp[(4) - (4)].value)); ;}
    break;

  case 31:
// #line 172 "jsonpath_gram.y"
    {
		JsonPathParseItem *jppitem;
		if (! makeItemLikeRegex((yyvsp[(1) - (3)].value), &(yyvsp[(3) - (3)].str), NULL, &jppitem, escontext))
			YYABORT;
		(yyval.value) = jppitem;
	;}
    break;

  case 32:
// #line 179 "jsonpath_gram.y"
    {
		JsonPathParseItem *jppitem;
		if (! makeItemLikeRegex((yyvsp[(1) - (5)].value), &(yyvsp[(3) - (5)].str), &(yyvsp[(5) - (5)].str), &jppitem, escontext))
			YYABORT;
		(yyval.value) = jppitem;
	;}
    break;

  case 33:
// #line 188 "jsonpath_gram.y"
    { (yyval.value) = makeItemString(&(yyvsp[(1) - (1)].str)); ;}
    break;

  case 34:
// #line 189 "jsonpath_gram.y"
    { (yyval.value) = makeItemVariable(&(yyvsp[(1) - (1)].str)); ;}
    break;

  case 35:
// #line 193 "jsonpath_gram.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value); ;}
    break;

  case 36:
// #line 194 "jsonpath_gram.y"
    { (yyval.value) = makeItemType(jpiRoot); ;}
    break;

  case 37:
// #line 195 "jsonpath_gram.y"
    { (yyval.value) = makeItemType(jpiCurrent); ;}
    break;

  case 38:
// #line 196 "jsonpath_gram.y"
    { (yyval.value) = makeItemType(jpiLast); ;}
    break;

  case 39:
// #line 200 "jsonpath_gram.y"
    { (yyval.elems) = list_make1((yyvsp[(1) - (1)].value)); ;}
    break;

  case 40:
// #line 201 "jsonpath_gram.y"
    { (yyval.elems) = list_make2((yyvsp[(2) - (4)].value), (yyvsp[(4) - (4)].value)); ;}
    break;

  case 41:
// #line 202 "jsonpath_gram.y"
    { (yyval.elems) = list_make2((yyvsp[(2) - (4)].value), (yyvsp[(4) - (4)].value)); ;}
    break;

  case 42:
// #line 203 "jsonpath_gram.y"
    { (yyval.elems) = lappend((yyvsp[(1) - (2)].elems), (yyvsp[(2) - (2)].value)); ;}
    break;

  case 43:
// #line 207 "jsonpath_gram.y"
    { (yyval.value) = makeItemList((yyvsp[(1) - (1)].elems)); ;}
    break;

  case 44:
// #line 208 "jsonpath_gram.y"
    { (yyval.value) = (yyvsp[(2) - (3)].value); ;}
    break;

  case 45:
// #line 209 "jsonpath_gram.y"
    { (yyval.value) = makeItemUnary(jpiPlus, (yyvsp[(2) - (2)].value)); ;}
    break;

  case 46:
// #line 210 "jsonpath_gram.y"
    { (yyval.value) = makeItemUnary(jpiMinus, (yyvsp[(2) - (2)].value)); ;}
    break;

  case 47:
// #line 211 "jsonpath_gram.y"
    { (yyval.value) = makeItemBinary(jpiAdd, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 48:
// #line 212 "jsonpath_gram.y"
    { (yyval.value) = makeItemBinary(jpiSub, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 49:
// #line 213 "jsonpath_gram.y"
    { (yyval.value) = makeItemBinary(jpiMul, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 50:
// #line 214 "jsonpath_gram.y"
    { (yyval.value) = makeItemBinary(jpiDiv, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 51:
// #line 215 "jsonpath_gram.y"
    { (yyval.value) = makeItemBinary(jpiMod, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 52:
// #line 219 "jsonpath_gram.y"
    { (yyval.value) = makeItemBinary(jpiSubscript, (yyvsp[(1) - (1)].value), NULL); ;}
    break;

  case 53:
// #line 220 "jsonpath_gram.y"
    { (yyval.value) = makeItemBinary(jpiSubscript, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 54:
// #line 224 "jsonpath_gram.y"
    { (yyval.indexs) = list_make1((yyvsp[(1) - (1)].value)); ;}
    break;

  case 55:
// #line 225 "jsonpath_gram.y"
    { (yyval.indexs) = lappend((yyvsp[(1) - (3)].indexs), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 56:
// #line 229 "jsonpath_gram.y"
    { (yyval.value) = makeItemType(jpiAnyArray); ;}
    break;

  case 57:
// #line 230 "jsonpath_gram.y"
    { (yyval.value) = makeIndexArray((yyvsp[(2) - (3)].indexs)); ;}
    break;

  case 58:
// #line 234 "jsonpath_gram.y"
    { (yyval.integer) = pg_strtoint32((yyvsp[(1) - (1)].str).val); ;}
    break;

  case 59:
// #line 235 "jsonpath_gram.y"
    { (yyval.integer) = -1; ;}
    break;

  case 60:
// #line 239 "jsonpath_gram.y"
    { (yyval.value) = makeAny(0, -1); ;}
    break;

  case 61:
// #line 240 "jsonpath_gram.y"
    { (yyval.value) = makeAny((yyvsp[(3) - (4)].integer), (yyvsp[(3) - (4)].integer)); ;}
    break;

  case 62:
// #line 242 "jsonpath_gram.y"
    { (yyval.value) = makeAny((yyvsp[(3) - (6)].integer), (yyvsp[(5) - (6)].integer)); ;}
    break;

  case 63:
// #line 246 "jsonpath_gram.y"
    { (yyval.value) = (yyvsp[(2) - (2)].value); ;}
    break;

  case 64:
// #line 247 "jsonpath_gram.y"
    { (yyval.value) = makeItemType(jpiAnyKey); ;}
    break;

  case 65:
// #line 248 "jsonpath_gram.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value); ;}
    break;

  case 66:
// #line 249 "jsonpath_gram.y"
    { (yyval.value) = (yyvsp[(2) - (2)].value); ;}
    break;

  case 67:
// #line 250 "jsonpath_gram.y"
    { (yyval.value) = makeItemType((yyvsp[(2) - (4)].optype)); ;}
    break;

  case 68:
// #line 252 "jsonpath_gram.y"
    { (yyval.value) = makeItemUnary(jpiDatetime, (yyvsp[(4) - (5)].value)); ;}
    break;

  case 69:
// #line 253 "jsonpath_gram.y"
    { (yyval.value) = makeItemUnary(jpiFilter, (yyvsp[(3) - (4)].value)); ;}
    break;

  case 70:
// #line 257 "jsonpath_gram.y"
    { (yyval.value) = makeItemString(&(yyvsp[(1) - (1)].str)); ;}
    break;

  case 71:
// #line 261 "jsonpath_gram.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value); ;}
    break;

  case 72:
// #line 262 "jsonpath_gram.y"
    { (yyval.value) = NULL; ;}
    break;

  case 73:
// #line 266 "jsonpath_gram.y"
    { (yyval.value) = makeItemKey(&(yyvsp[(1) - (1)].str)); ;}
    break;

  case 98:
// #line 297 "jsonpath_gram.y"
    { (yyval.optype) = jpiAbs; ;}
    break;

  case 99:
// #line 298 "jsonpath_gram.y"
    { (yyval.optype) = jpiSize; ;}
    break;

  case 100:
// #line 299 "jsonpath_gram.y"
    { (yyval.optype) = jpiType; ;}
    break;

  case 101:
// #line 300 "jsonpath_gram.y"
    { (yyval.optype) = jpiFloor; ;}
    break;

  case 102:
// #line 301 "jsonpath_gram.y"
    { (yyval.optype) = jpiDouble; ;}
    break;

  case 103:
// #line 302 "jsonpath_gram.y"
    { (yyval.optype) = jpiCeiling; ;}
    break;

  case 104:
// #line 303 "jsonpath_gram.y"
    { (yyval.optype) = jpiKeyValue; ;}
    break;


/* Line 1267 of yacc.c.  */
// #line 2047 "jsonpath_gram.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (result, escontext, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (result, escontext, yymsg);
	  }
	else
	  {
	    yyerror (result, escontext, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, result, escontext);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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
		  yystos[yystate], yyvsp, result, escontext);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (result, escontext, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, result, escontext);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, result, escontext);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


// #line 305 "jsonpath_gram.y"


/*
 * The helper functions below allocate and fill JsonPathParseItem's of various
 * types.
 */

static JsonPathParseItem *
makeItemType(JsonPathItemType type)
{
	JsonPathParseItem *v = calloc(1, sizeof(*v));

	v->type = type;
	v->next = NULL;

	return v;
}

static JsonPathParseItem *
makeItemString(JsonPathString *s)
{
	JsonPathParseItem *v;

	if (s == NULL)
	{
		v = makeItemType(jpiNull);
	}
	else
	{
		v = makeItemType(jpiString);
		v->value.string.val = s->val;
		v->value.string.len = s->len;
	}

	return v;
}

static JsonPathParseItem *
makeItemVariable(JsonPathString *s)
{
	JsonPathParseItem *v;

	v = makeItemType(jpiVariable);
	v->value.string.val = s->val;
	v->value.string.len = s->len;

	return v;
}

static JsonPathParseItem *
makeItemKey(JsonPathString *s)
{
	JsonPathParseItem *v;

	v = makeItemString(s);
	v->type = jpiKey;

	return v;
}

static JsonPathParseItem *
makeItemNumeric(JsonPathString *s)
{
	JsonPathParseItem *v;

	// convert char* to double
	double converted = strtod(s->val, NULL);
	v = makeItemType(jpiNumeric);
	v->value.numeric = converted;

	return v;
}

static JsonPathParseItem *
makeItemBool(bool val)
{
	JsonPathParseItem *v = makeItemType(jpiBool);

	v->value.boolean = val;

	return v;
}

static JsonPathParseItem *
makeItemBinary(JsonPathItemType type, JsonPathParseItem *la, JsonPathParseItem *ra)
{
	JsonPathParseItem *v = makeItemType(type);

	v->value.args.left = la;
	v->value.args.right = ra;

	return v;
}

static JsonPathParseItem *
makeItemUnary(JsonPathItemType type, JsonPathParseItem *a)
{
	JsonPathParseItem *v;

	if (type == jpiPlus && a->type == jpiNumeric && !a->next)
		return a;

	if (type == jpiMinus && a->type == jpiNumeric && !a->next)
	{
		v = makeItemType(jpiNumeric);
		v->value.numeric = a->value.numeric;
		return v;
	}

	v = makeItemType(type);

	v->value.arg = a;

	return v;
}

static JsonPathParseItem *
makeItemList(List *list)
{
	JsonPathParseItem *head,
			   *end;
	ListCell   *cell;

	head = end = (JsonPathParseItem *) linitial(list);

	if (list_length(list) == 1)
		return head;

	/* append items to the end of already existing list */
	while (end->next)
		end = end->next;

	for_each_from(cell, list, 1)
	{
		JsonPathParseItem *c = (JsonPathParseItem *) lfirst(cell);

		end->next = c;
		end = c;
	}

	return head;
}

static JsonPathParseItem *
makeIndexArray(List *list)
{
	JsonPathParseItem *v = makeItemType(jpiIndexArray);
	ListCell   *cell;
	int			i = 0;

	Assert(list != NIL);
	v->value.array.nelems = list_length(list);

	v->value.array.elems = calloc(1, sizeof(v->value.array.elems[0]) *
								  v->value.array.nelems);

	foreach(cell, list)
	{
		JsonPathParseItem *jpi = lfirst(cell);

		Assert(jpi->type == jpiSubscript);

		v->value.array.elems[i].from = jpi->value.args.left;
		v->value.array.elems[i++].to = jpi->value.args.right;
	}

	return v;
}

static JsonPathParseItem *
makeAny(int first, int last)
{
	JsonPathParseItem *v = makeItemType(jpiAny);

	v->value.anybounds.first = (first >= 0) ? first : PG_UINT32_MAX;
	v->value.anybounds.last = (last >= 0) ? last : PG_UINT32_MAX;

	return v;
}

static bool
makeItemLikeRegex(JsonPathParseItem *expr, JsonPathString *pattern,
				  JsonPathString *flags, JsonPathParseItem ** result,
				  struct Node *escontext)
{
	JsonPathParseItem *v = makeItemType(jpiLikeRegex);
	int			i;
	int			cflags;

	v->value.like_regex.expr = expr;
	v->value.like_regex.pattern = pattern->val;
	v->value.like_regex.patternlen = pattern->len;

	/* Parse the flags string, convert to bitmask.  Duplicate flags are OK. */
	v->value.like_regex.flags = 0;
	for (i = 0; flags && i < flags->len; i++)
	{
		switch (flags->val[i])
		{
			case 'i':
				v->value.like_regex.flags |= JSP_REGEX_ICASE;
				break;
			case 's':
				v->value.like_regex.flags |= JSP_REGEX_DOTALL;
				break;
			case 'm':
				v->value.like_regex.flags |= JSP_REGEX_MLINE;
				break;
			case 'x':
				v->value.like_regex.flags |= JSP_REGEX_WSPACE;
				break;
			case 'q':
				v->value.like_regex.flags |= JSP_REGEX_QUOTE;
				break;
			default:
				return false;
				break;
		}
	}

	/* Convert flags to what pg_regcomp needs */
	if ( !jspConvertRegexFlags(v->value.like_regex.flags, &cflags, escontext))
		 return false;

	*result = v;

	return true;
}

/*
 * Convert from XQuery regex flags to those recognized by our regex library.
 */
bool
jspConvertRegexFlags(uint32 xflags, int *result, struct Node *escontext)
{
	/* By default, XQuery is very nearly the same as Spencer's AREs */
	int			cflags = REG_ADVANCED;

	/* Ignore-case means the same thing, too, modulo locale issues */
	if (xflags & JSP_REGEX_ICASE)
		cflags |= REG_ICASE;

	/* Per XQuery spec, if 'q' is specified then 'm', 's', 'x' are ignored */
	if (xflags & JSP_REGEX_QUOTE)
	{
		cflags &= ~REG_ADVANCED;
		cflags |= REG_QUOTE;
	}
	else
	{
		/* Note that dotall mode is the default in POSIX */
		if (!(xflags & JSP_REGEX_DOTALL))
			cflags |= REG_NLSTOP;
		if (xflags & JSP_REGEX_MLINE)
			cflags |= REG_NLANCH;

		/*
		 * XQuery's 'x' mode is related to Spencer's expanded mode, but it's
		 * not really enough alike to justify treating JSP_REGEX_WSPACE as
		 * REG_EXPANDED.  For now we treat 'x' as unimplemented; perhaps in
		 * future we'll modify the regex library to have an option for
		 * XQuery-style ignore-whitespace mode.
		 */
		if (xflags & JSP_REGEX_WSPACE)
			return false;
	}

	*result = cflags;

	return true;
}

