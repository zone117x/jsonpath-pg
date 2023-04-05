const jsonpathParseInit = require('../../build/jsonpath_parse.js');

let jsonpathParseModule;

function initJsonpathParseModule() {
    if (jsonpathParseModule === undefined) {
        jsonpathParseModule = jsonpathParseInit();
    }
    return jsonpathParseModule;
}

class InvalidJsonpathExpression extends Error {
    constructor(message) {
        super(message);
        this.message = message;
        this.name = this.constructor.name;
    }
}

/**
 * 
 * @param {string} jsonpathExpression 
 * @returns 
 */
function jsonpathToAst(jsonpathExpression) {
    if (typeof jsonpathExpression !== 'string') {
        throw new TypeError('jsonpathToAst: jsonpathExpression argument must be a string');
    }

    // Ensure wasm module is initialized
    initJsonpathParseModule();

    // Call wasm jsonpath_to_ast function
    const astString = jsonpathParseModule.ccall(
        'jsonpath_to_ast', // name of C function
        'string', // return type
        ['string'], // argument types
        [jsonpathExpression] // arguments
    );

    // Ensure all memory is freed
    jsonpathParseModule._free_all_allocations();

    // Check
    if (!astString) {
        throw new InvalidJsonpathExpression('could not parse jsonpath expression');
    }

    const astJson = JSON.parse(astString);
    return astJson;
}

// Export default and named functions
module.exports = jsonpathToAst;
module.exports = Object.assign(module.exports, {
    jsonpathToAst,
    initJsonpathParseModule,
    InvalidJsonpathExpression,
    getWasmModule: () => initJsonpathParseModule(),
});
