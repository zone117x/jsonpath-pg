const jsonpathParseInit = require('../build/jsonpath_parse.js');

const jsonpathParse = jsonpathParseInit();
const parseFn = jsonpathParse.cwrap('jsonpath_to_ast', 'string', ['string']);

const forever = false;
do {
    const input = '$.asdf[1 to last].**.thing.double() ? ((@.leaf[7] - 12345) == 1 % 9)';
    // const input = '$.asdf';
    // const input = '<<<<<<||||||';
    const result = parseFn(input);
    console.log('parse result: ' + result);
} while (forever);

jsonpathParse._perform_exit(0);
