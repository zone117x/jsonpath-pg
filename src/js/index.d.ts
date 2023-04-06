export interface JsonpathParseEmscriptenModule {
    _free_all_allocations: () => void;
}
export declare function initJsonpathParseModule(): JsonpathParseEmscriptenModule;
export declare class InvalidJsonpathExpression extends Error {
    constructor(message: string);
}

/**
 *
 * @param jsonpathExpression The jsonpath expression to parse
 * @returns
 */
export declare function jsonpathToAst(jsonpathExpression: string): JsonpathAst;
export default jsonpathToAst;
export declare const getWasmModule: () => JsonpathParseEmscriptenModule;

export interface JsonpathAst {
    expr: JsonpathItem[];
    lax: boolean;
}

export type JsonpathTypeID =
    | "null"
    | "string"
    | "numeric"
    | "bool"
    | "&&"
    | "||"
    | "!"
    | "is_unknown"
    | "=="
    | "!="
    | "<"
    | ">"
    | "<="
    | ">="
    | "+"
    | "-"
    | "*"
    | "/"
    | "%"
    | "[*]"
    | ".*"
    | "[subscript]"
    | ".**"
    | ".key"
    | "@"
    | "$"
    | "$variable"
    | "?"
    | "exists"
    | "type"
    | "size"
    | "abs"
    | "floor"
    | "ceiling"
    | "double"
    | "datetime"
    | "keyvalue"
    | "subscript"
    | "last"
    | "starts with"
    | "like_regex";

export interface JsonpathItemType {
    type: JsonpathTypeID;
}

export interface JsonpathNull extends JsonpathItemType {
    type: "null";
}

export interface JsonpathRoot extends JsonpathItemType {
    type: "$";
}

export interface JsonpathAnyArray extends JsonpathItemType {
    type: "[*]";
}

export interface JsonpathAnyKey extends JsonpathItemType {
    type: ".**";
}

export interface JsonpathCurrent extends JsonpathItemType {
    type: "@";
}

export interface JsonpathLast extends JsonpathItemType {
    type: "last";
}

export interface JsonpathType extends JsonpathItemType {
    type: "type";
}

export interface JsonpathSize extends JsonpathItemType {
    type: "size";
}

export interface JsonpathAbs extends JsonpathItemType {
    type: "abs";
}

export interface JsonpathFloor extends JsonpathItemType {
    type: "floor";
}

export interface JsonpathCeiling extends JsonpathItemType {
    type: "ceiling";
}

export interface JsonpathDouble extends JsonpathItemType {
    type: "double";
}

export interface JsonpathKeyValue extends JsonpathItemType {
    type: "keyvalue";
}

export interface JsonpathString extends JsonpathItemType {
    type: "string";
    value: string;
}

export interface JsonpathVariable extends JsonpathItemType {
    type: "$variable";
    value: string;
}

export interface JsonpathKey extends JsonpathItemType {
    type: ".key";
    value: string;
}

export interface JsonpathNumeric extends JsonpathItemType {
    type: "numeric";
    value: number;
}

export interface JsonpathBool extends JsonpathItemType {
    type: "bool";
    value: boolean;
}

export interface JsonpathBinaryOperation extends JsonpathItemType {
    left: JsonpathItem[];
    right: JsonpathItem[];
}

export interface JsonpathAnd extends JsonpathBinaryOperation {
    type: "&&";
}

export interface JsonpathOr extends JsonpathBinaryOperation {
    type: "||";
}

export interface JsonpathEqual extends JsonpathBinaryOperation {
    type: "==";
}

export interface JsonpathNotEqual extends JsonpathBinaryOperation {
    type: "!=";
}

export interface JsonpathLess extends JsonpathBinaryOperation {
    type: "<";
}

export interface JsonpathGreater extends JsonpathBinaryOperation {
    type: ">";
}

export interface JsonpathLessOrEqual extends JsonpathBinaryOperation {
    type: "<=";
}

export interface JsonpathGreaterOrEqual extends JsonpathBinaryOperation {
    type: ">=";
}

export interface JsonpathAdd extends JsonpathBinaryOperation {
    type: "+";
}

export interface JsonpathSub extends JsonpathBinaryOperation {
    type: "-";
}

export interface JsonpathMul extends JsonpathBinaryOperation {
    type: "*";
}

export interface JsonpathDiv extends JsonpathBinaryOperation {
    type: "/";
}

export interface JsonpathMod extends JsonpathBinaryOperation {
    type: "%";
}

export interface JsonpathStartsWith extends JsonpathBinaryOperation {
    type: "starts with";
}

export interface JsonpathLikeRegex extends JsonpathItemType {
    type: "like_regex";
    pattern: string;
    expr: JsonpathItem[];
    flags: number;
}

export interface JsonpathUnaryOperation extends JsonpathItemType {
    arg: JsonpathItem[];
}

export interface JsonpathFilter extends JsonpathUnaryOperation {
    type: "?";
}

export interface JsonpathIsUnknown extends JsonpathUnaryOperation {
    type: "is_unknown";
}

export interface JsonpathNot extends JsonpathUnaryOperation {
    type: "!";
}

export interface JsonpathPlus extends JsonpathUnaryOperation {
    type: "+";
}

export interface JsonpathMinus extends JsonpathUnaryOperation {
    type: "-";
}

export interface JsonpathExists extends JsonpathUnaryOperation {
    type: "exists";
}

export interface JsonpathDatetime extends JsonpathUnaryOperation {
    type: "datetime";
}

export interface JsonpathIndexArray extends JsonpathItemType {
    type: "[subscript]";
    elems: {
        from: JsonpathItem[];
        to: JsonpathItem[];
    };
}

export interface JsonpathAny extends JsonpathItemType {
    type: ".*";
    first: number;
    last: number;
}

export type JsonpathItem =
    | JsonpathNull
    | JsonpathRoot
    | JsonpathAnyArray
    | JsonpathAnyKey
    | JsonpathCurrent
    | JsonpathLast
    | JsonpathType
    | JsonpathSize
    | JsonpathAbs
    | JsonpathFloor
    | JsonpathCeiling
    | JsonpathDouble
    | JsonpathKeyValue
    | JsonpathString
    | JsonpathVariable
    | JsonpathKey
    | JsonpathNumeric
    | JsonpathBool
    | JsonpathAnd
    | JsonpathOr
    | JsonpathEqual
    | JsonpathNotEqual
    | JsonpathLess
    | JsonpathGreater
    | JsonpathLessOrEqual
    | JsonpathGreaterOrEqual
    | JsonpathAdd
    | JsonpathSub
    | JsonpathMul
    | JsonpathDiv
    | JsonpathMod
    | JsonpathStartsWith
    | JsonpathLikeRegex
    | JsonpathFilter
    | JsonpathIsUnknown
    | JsonpathNot
    | JsonpathPlus
    | JsonpathMinus
    | JsonpathExists
    | JsonpathDatetime
    | JsonpathIndexArray
    | JsonpathAny;
