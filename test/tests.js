const assert = require('node:assert/strict');
const lib = require('..');
const { InvalidJsonpathExpression } = lib;

// Valid jsonpath expression test vectors
const testVectors = [
    [
        '$.hello.world',
        '{"expr":[{"type":"$"},{"type":".key","value":"hello"},{"type":".key","value":"world"}],"lax":true}'
    ],
    [
        '$.asdf[1 to last].**.thing[*].a.b.c.d.e.f.g.double() ? ((@.leaf[7] - 12345) == 1 % 9)',
        '{"expr":[{"type":"$"},{"type":".key","value":"asdf"},{"type":"[subscript]","elems":[{"from":[{"type":"numeric","value":1}],"to":[{"type":"last"}]}]},{"type":".**","first":0,"last":4294967295},{"type":".key","value":"thing"},{"type":"[*]"},{"type":".key","value":"a"},{"type":".key","value":"b"},{"type":".key","value":"c"},{"type":".key","value":"d"},{"type":".key","value":"e"},{"type":".key","value":"f"},{"type":".key","value":"g"},{"type":"double"},{"type":"?","arg":[{"type":"==","left":[{"type":"-","left":[{"type":"@"},{"type":".key","value":"leaf"},{"type":"[subscript]","elems":[{"from":[{"type":"numeric","value":7}],"to":[]}]}],"right":[{"type":"numeric","value":12345}]}],"right":[{"type":"%","left":[{"type":"numeric","value":1}],"right":[{"type":"numeric","value":9}]}]}]}],"lax":true}'
    ],
    [
        '$.r ? (@.a == 1 || @.b == 2 || @.c == 3)',
        '{"expr":[{"type":"$"},{"type":".key","value":"r"},{"type":"?","arg":[{"type":"||","left":[{"type":"||","left":[{"type":"==","left":[{"type":"@"},{"type":".key","value":"a"}],"right":[{"type":"numeric","value":1}]}],"right":[{"type":"==","left":[{"type":"@"},{"type":".key","value":"b"}],"right":[{"type":"numeric","value":2}]}]}],"right":[{"type":"==","left":[{"type":"@"},{"type":".key","value":"c"}],"right":[{"type":"numeric","value":3}]}]}]}],"lax":true}'
    ],
    [
        '@[0][1,2,3].*[6 to 32].**',
        '{"expr":[{"type":"@"},{"type":"[subscript]","elems":[{"from":[{"type":"numeric","value":0}],"to":[]}]},{"type":"[subscript]","elems":[{"from":[{"type":"numeric","value":1}],"to":[]},{"from":[{"type":"numeric","value":2}],"to":[]},{"from":[{"type":"numeric","value":3}],"to":[]}]},{"type":".*"},{"type":"[subscript]","elems":[{"from":[{"type":"numeric","value":6}],"to":[{"type":"numeric","value":32}]}]},{"type":".**","first":0,"last":4294967295}],"lax":true}'
    ],
    [
        '$.track ? (exists(@.segments[*] ? (@.HR > 130))).segments.size()',
        '{"expr":[{"type":"$"},{"type":".key","value":"track"},{"type":"?","arg":[{"type":"exists","arg":[{"type":"@"},{"type":".key","value":"segments"},{"type":"[*]"},{"type":"?","arg":[{"type":">","left":[{"type":"@"},{"type":".key","value":"HR"}],"right":[{"type":"numeric","value":130}]}]}]}]},{"type":".key","value":"segments"},{"type":"size"}],"lax":true}'
    ],
    [
        '+ $.x',
        '{"expr":[{"type":"+unary","arg":[{"type":"$"},{"type":".key","value":"x"}]}],"lax":true}'
    ],
    [
        '- $.x',
        '{"expr":[{"type":"-unary","arg":[{"type":"$"},{"type":".key","value":"x"}]}],"lax":true}'
    ],
    [
        '+ 1',
        '{"expr":[{"type":"numeric","value":1}],"lax":true}'
    ],
    [
        '- 1',
        '{"expr":[{"type":"numeric","value":-1}],"lax":true}'
    ],
];

// Test default export
const defaultExportResult = lib(testVectors[0][0]);
assert.deepEqual(defaultExportResult, JSON.parse(testVectors[0][1]));
console.log('✅ default export test passed');

// Test named export
const namedExportResult = lib.jsonpathToAst(testVectors[0][0]);
assert.deepEqual(namedExportResult, JSON.parse(testVectors[0][1]));
console.log('✅ named export test passed');

// Test valid inputs
testVectors.forEach(([input, expected]) => {
    const result = lib.jsonpathToAst(input);
    assert.deepEqual(result, JSON.parse(expected));
    console.log(`✅ test passed for input: ${input}`);
});

// Test expression containing large scalars
const exprWithLargeScalars = '$.asdf[1 to last].**.thing.ffffffffffffffffffffffffffffffffxyz.double() ? ((@.leaf[340282366920938463463374607431768211455] - 12345) == 1 % 9)';
const largeScalarsResult = lib.jsonpathToAst(exprWithLargeScalars);
const largeScalarsExpectedResult = '{"expr":[{"type":"$"},{"type":".key","value":"asdf"},{"type":"[subscript]","elems":[{"from":[{"type":"numeric","value":1}],"to":[{"type":"last"}]}]},{"type":".**","first":0,"last":4294967295},{"type":".key","value":"thing"},{"type":".key","value":"ffffffffffffffffffffffffffffffffxyz"},{"type":"double"},{"type":"?","arg":[{"type":"==","left":[{"type":"-","left":[{"type":"@"},{"type":".key","value":"leaf"},{"type":"[subscript]","elems":[{"from":[{"type":"numeric","value":3.402823669209385e+38}],"to":[]}]}],"right":[{"type":"numeric","value":12345}]}],"right":[{"type":"%","left":[{"type":"numeric","value":1}],"right":[{"type":"numeric","value":9}]}]}]}],"lax":true}';
assert.deepEqual(largeScalarsResult, JSON.parse(largeScalarsExpectedResult));
console.log('✅ parsed expression with large scalars');

// Invalid jsonpath expressions
const invalidTestVectors = [
    '$.asdfasdf ? (@.asdf <<<<<<||||||8adsfasdfhauhweruiahefasdjkfhawejrkhtakjdhfgalksjdhgfajksdhfjk',
    '',
    '^^^^',
];

// Test invalid inputs
invalidTestVectors.forEach((input) => {
    // Assert that the function throws an error of type InvalidJsonpathExpression
    assert.throws(() => lib.jsonpathToAst(input), InvalidJsonpathExpression);
    console.log(`✅ test passed for invalid input: ${input} (throws InvalidJsonpathExpression)`);
});

// Test that throws on non-string argument
assert.throws(() => lib.jsonpathToAst(123), TypeError);
console.log('✅ test passed for non-string argument (throws TypeError)');
