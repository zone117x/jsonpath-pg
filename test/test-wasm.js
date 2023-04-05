const jsonpathParse = require('..');

for (let i = 0; i < 10000; i++) {
    const input = '$.asdf[1 to last].**.thing[*].a.b.c.d.e.f.g.double() ? ((@.leaf[7] - 12345) == 1 % 9)';
    const result = jsonpathParse(input);
    if (i % 100 === 0) {
        console.log(`parse result num ${i}: ${result}`);
    }
}

for (let i = 0; i < 10000; i++) {
    const input = '$.asdfasdf ? (@.asdf <<<<<<||||||8adsfasdfhauhweruiahefasdjkfhawejrkhtakjdhfgalksjdhgfajksdhfjk';
    try {
        jsonpathParse(input);
        throw new Error('Should have thrown for invalid jsonpath expression');
    } catch (error) {
        // ignore
    }
    if (i % 100 === 0) {
        console.log(`parse invalid result num ${i}`);
    }
}

jsonpathParse.getWasmModule()._perform_exit(0);
