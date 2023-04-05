const jsonpathParseInit = require('../build/jsonpath_parse.js');

function run() {
    const jsonpathParse = jsonpathParseInit();
    const parseFn = jsonpathParse.cwrap('jsonpath_to_ast', 'string', ['string']);

    while (true) {
        const input = '$.asdf[1 to last].**.thing.double() ? ((@.leaf[7] - 12345) == 1 % 9)';
        const result = parseFn(input);
        console.log(result);
    }
}

run();
