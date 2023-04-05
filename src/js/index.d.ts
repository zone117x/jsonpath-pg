export interface JsonpathParseEmscriptenModule {
    _free_all_allocations: () => void;
}
export declare function initJsonpathParseModule(): JsonpathParseEmscriptenModule;
export declare class InvalidJsonpathExpression extends Error {
    constructor(message: string);
}
export interface JsonpathAst {
    lax: boolean;
    expr: {
        type: string;
        value?: any;
    }[];
}
/**
 *
 * @param jsonpathExpression The jsonpath expression to parse
 * @returns
 */
export declare function jsonpathToAst(jsonpathExpression: string): JsonpathAst;
export default jsonpathToAst;
export declare const getWasmModule: () => JsonpathParseEmscriptenModule;
