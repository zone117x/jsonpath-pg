const jsonpathParseInit = require('../build/jsonpath_parse.js');

const jsonpathParse = jsonpathParseInit();
const parseFn = jsonpathParse.cwrap('jsonpath_to_ast', 'string', ['string']);

for (let i = 0; i < 10; i++) {
    const input = '$.asdf[1 to last].**.thing[*].a.b.c.d.e.f.g.double() ? ((@.leaf[7] - 12345) == 1 % 9)';
    const result = parseFn(input);
    jsonpathParse._free_all_allocations();
    // console.log('parse result: ' + result);
    if (i % 100 === 0) {
        console.log(`parse result num ${i}: ${result}`);
    }
}

for (let i = 0; i < 10; i++) {
    const input = '$.asdfasdf ? (@.asdf <<<<<<||||||8adsfasdfhauhweruiahefasdjkfhawejrkhtakjdhfgalksjdhgfajksdhfjk';
    const result = parseFn(input);
    jsonpathParse._free_all_allocations();
    // console.log('parse result: ' + result);
    if (i % 100 === 0) {
        console.log(`parse invalid result num ${i}: ${result}`);
    }
}

jsonpathParse._perform_exit(0);
