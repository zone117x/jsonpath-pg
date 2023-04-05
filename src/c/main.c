#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cJSON.h"

// #include "c.h"
// #include "postgres.h"
// #include "fmgr.h"
// #include "utils/jsonpath.h"
// #include "utils/numeric.h"
// #include "utils/memutils.h"
// #include "utils/elog.h"

// new
#include "jsonpath.h"

// Linker complains about these symbol if not declared
const char *progname = "my_app_name";
void json_errdetail() {}
void unicode_is_normalized_quickcheck() {}
void pg_log_generic() {}

// Determine the type of the jsonpath expression item
const char *json_path_item_type_to_string(JsonPathItemType type)
{
	switch (type)
	{
	case jpiNull:
		return "null";
	case jpiString:
		return "string";
	case jpiNumeric:
		return "numeric";
	case jpiBool:
		return "bool";
	case jpiAnd:
		return "&&";
	case jpiOr:
		return "||";
	case jpiNot:
		return "!";
	case jpiIsUnknown:
		return "is_unknown";
	case jpiEqual:
		return "==";
	case jpiNotEqual:
		return "!=";
	case jpiLess:
		return "<";
	case jpiGreater:
		return ">";
	case jpiLessOrEqual:
		return "<=";
	case jpiGreaterOrEqual:
		return ">=";
	case jpiPlus:
	case jpiAdd:
		return "+";
	case jpiMinus:
	case jpiSub:
		return "-";
	case jpiMul:
		return "*";
	case jpiDiv:
		return "/";
	case jpiMod:
		return "%";
	case jpiAnyArray:
		return "[*]";
	case jpiAnyKey:
		return ".*";
	case jpiIndexArray:
		return "[subscript]";
	case jpiAny:
		return ".**";
	case jpiKey:
		return ".key";
	case jpiCurrent:
		return "@";
	case jpiRoot:
		return "$";
	case jpiVariable:
		return "$variable";
	case jpiFilter:
		return "?";
	case jpiExists:
		return "exists";
	case jpiType:
		return "type";
	case jpiSize:
		return "size";
	case jpiAbs:
		return "abs";
	case jpiFloor:
		return "floor";
	case jpiCeiling:
		return "ceiling";
	case jpiDouble:
		return "double";
	case jpiDatetime:
		return "datetime";
	case jpiKeyValue:
		return "keyvalue";
	case jpiSubscript:
		return "subscript";
	case jpiLast:
		return "last";
	case jpiStartsWith:
		return "starts with";
	case jpiLikeRegex:
		return "like_regex";
	default:
		fprintf(stderr, "unrecognized jsonpath item type: %d\n", type);
		return "unknown";
	}
}

// Convert jsonpath expression item to an AST in JSON format
cJSON *json_path_parse_item_to_json(JsonPathParseItem *item)
{
	cJSON *array = cJSON_CreateArray();

	while (item)
	{
		cJSON *json_item = cJSON_CreateObject();
		cJSON_AddStringToObject(json_item, "type", json_path_item_type_to_string(item->type));

		switch (item->type)
		{
		case jpiNull:
		case jpiRoot:
		case jpiAnyArray:
		case jpiAnyKey:
		case jpiCurrent:
		case jpiLast:
		case jpiType:
		case jpiSize:
		case jpiAbs:
		case jpiFloor:
		case jpiCeiling:
		case jpiDouble:
		case jpiKeyValue:
			// No additional properties needed for these types
			break;

		case jpiString:
		case jpiVariable:
		case jpiKey:
			cJSON_AddStringToObject(json_item, "value", item->value.string.val);
			break;

		case jpiNumeric:
		{
			// char *num_str = numeric_normalize(item->value.numeric);
			// cJSON_AddStringToObject(json_item, "value", num_str);
			// pfree(num_str);
			cJSON_AddNumberToObject(json_item, "value", item->value.numeric);
		}
		break;

		case jpiBool:
			cJSON_AddBoolToObject(json_item, "value", item->value.boolean);
			break;

		case jpiAnd:
		case jpiOr:
		case jpiEqual:
		case jpiNotEqual:
		case jpiLess:
		case jpiGreater:
		case jpiLessOrEqual:
		case jpiGreaterOrEqual:
		case jpiAdd:
		case jpiSub:
		case jpiMul:
		case jpiDiv:
		case jpiMod:
		case jpiStartsWith:
			cJSON_AddItemToObject(json_item, "left", json_path_parse_item_to_json(item->value.args.left));
			cJSON_AddItemToObject(json_item, "right", json_path_parse_item_to_json(item->value.args.right));
			break;

		case jpiLikeRegex:
			cJSON_AddStringToObject(json_item, "pattern", item->value.like_regex.pattern);
			cJSON_AddItemToObject(json_item, "expr", json_path_parse_item_to_json(item->value.like_regex.expr));
			cJSON_AddNumberToObject(json_item, "flags", item->value.like_regex.flags);
			break;

		case jpiFilter:
		case jpiIsUnknown:
		case jpiNot:
		case jpiPlus:
		case jpiMinus:
		case jpiExists:
		case jpiDatetime:
			cJSON_AddItemToObject(json_item, "arg", json_path_parse_item_to_json(item->value.arg));
			break;

		case jpiIndexArray:
		{
			cJSON *elems = cJSON_CreateArray();
			for (int i = 0; i < item->value.array.nelems; i++)
			{
				cJSON *elem = cJSON_CreateObject();
				cJSON_AddItemToObject(elem, "from", json_path_parse_item_to_json(item->value.array.elems[i].from));
				cJSON_AddItemToObject(elem, "to", json_path_parse_item_to_json(item->value.array.elems[i].to));
				cJSON_AddItemToArray(elems, elem);
			}
			cJSON_AddItemToObject(json_item, "elems", elems);
		}
		break;

		case jpiAny:
			cJSON_AddNumberToObject(json_item, "first", item->value.anybounds.first);
			cJSON_AddNumberToObject(json_item, "last", item->value.anybounds.last);
			break;

		default:
			fprintf(stderr, "unrecognized jsonpath item type: %d\n", item->type);
			exit(1);
		}

		cJSON_AddItemToArray(array, json_item);

		item = item->next;
	}

	return array;
}

// Convert jsonpath expression item to an AST in JSON format
cJSON *json_path_parse_item_to_json2(JsonPathParseItem *item)
{
	cJSON *json_item;
	if (!item)
	{
		return cJSON_CreateNull();
	}

	json_item = cJSON_CreateObject();
	cJSON_AddStringToObject(json_item, "type", json_path_item_type_to_string(item->type));

	switch (item->type)
	{
	case jpiNull:
	case jpiRoot:
	case jpiAnyArray:
	case jpiAnyKey:
	case jpiCurrent:
	case jpiLast:
	case jpiType:
	case jpiSize:
	case jpiAbs:
	case jpiFloor:
	case jpiCeiling:
	case jpiDouble:
	case jpiKeyValue:
		// No additional properties needed for these types
		break;

	case jpiString:
	case jpiVariable:
	case jpiKey:
		cJSON_AddStringToObject(json_item, "value", item->value.string.val);
		break;

	case jpiNumeric:
	{
		// char *num_str = numeric_normalize(item->value.numeric);
		// cJSON_AddStringToObject(json_item, "value", num_str);
		// pfree(num_str);
		cJSON_AddNumberToObject(json_item, "value", item->value.numeric);
	}
	break;

	case jpiBool:
		cJSON_AddBoolToObject(json_item, "value", item->value.boolean);
		break;

	case jpiAnd:
	case jpiOr:
	case jpiEqual:
	case jpiNotEqual:
	case jpiLess:
	case jpiGreater:
	case jpiLessOrEqual:
	case jpiGreaterOrEqual:
	case jpiAdd:
	case jpiSub:
	case jpiMul:
	case jpiDiv:
	case jpiMod:
	case jpiStartsWith:
		cJSON_AddItemToObject(json_item, "left", json_path_parse_item_to_json(item->value.args.left));
		cJSON_AddItemToObject(json_item, "right", json_path_parse_item_to_json(item->value.args.right));
		break;

	case jpiLikeRegex:
		cJSON_AddStringToObject(json_item, "pattern", item->value.like_regex.pattern);
		cJSON_AddItemToObject(json_item, "expr", json_path_parse_item_to_json(item->value.like_regex.expr));
		cJSON_AddNumberToObject(json_item, "flags", item->value.like_regex.flags);
		break;

	case jpiFilter:
	case jpiIsUnknown:
	case jpiNot:
	case jpiPlus:
	case jpiMinus:
	case jpiExists:
	case jpiDatetime:
		cJSON_AddItemToObject(json_item, "arg", json_path_parse_item_to_json(item->value.arg));
		break;

	case jpiIndexArray:
	{
		cJSON *elems = cJSON_CreateArray();
		for (int i = 0; i < item->value.array.nelems; i++)
		{
			cJSON *elem = cJSON_CreateObject();
			cJSON_AddItemToObject(elem, "from", json_path_parse_item_to_json(item->value.array.elems[i].from));
			cJSON_AddItemToObject(elem, "to", json_path_parse_item_to_json(item->value.array.elems[i].to));
			cJSON_AddItemToArray(elems, elem);
		}
		cJSON_AddItemToObject(json_item, "elems", elems);
	}
	break;

	case jpiAny:
		cJSON_AddNumberToObject(json_item, "first", item->value.anybounds.first);
		cJSON_AddNumberToObject(json_item, "last", item->value.anybounds.last);
		break;

	default:
		fprintf(stderr, "unrecognized jsonpath item type: %d\n", item->type);
		exit(1);
	}

	if (item->next)
	{
		cJSON_AddItemToObject(json_item, "next", json_path_parse_item_to_json(item->next));
	}

	return json_item;
}

JsonPathParseResult *get_jsonpath_parse_result(const char *input) {
    int len = strlen(input);
    JsonPathParseResult *result = parsejsonpath(input, len, NULL);
    return result;
}

char *jsonpath_to_ast(const char *input) {
    JsonPathParseResult *result = get_jsonpath_parse_result(input);
    if (!result)
	{
		return NULL;
	}
	cJSON *json_ast = cJSON_CreateObject();
	cJSON *expr = json_path_parse_item_to_json(result->expr);
	cJSON_AddItemToObject(json_ast, "expr", expr);
	cJSON_AddBoolToObject(json_ast, "lax", result->lax);

	char *json_string = cJSON_PrintUnformatted(json_ast);
	char *return_string = malloc(strlen(json_string) + 1);
	strcpy(return_string, json_string);
	return_string[strlen(json_string)] = '\0';

	cJSON_Delete(json_ast);
	cJSON_free(json_string);

	return return_string;
}

#ifndef __EMSCRIPTEN__
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <json_path_expression>\n", argv[0]);
		exit(1);
	}

	const char *input = argv[1];
    char *json_string = jsonpath_to_ast(input);

    if (!json_string)
	{
		// Handle parsing error here, write error message to stderr
		fprintf(stderr, "Failed to parse jsonpath expression: %s\n", input);
		exit(1);
	}

	printf("%s\n", json_string);
	return 0;
}
#endif