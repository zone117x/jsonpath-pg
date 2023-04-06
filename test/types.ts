import * as assert from 'node:assert/strict';
import { jsonpathToAst, InvalidJsonpathExpression, JsonpathAst, JsonpathRoot } from '..';
import jsonpathToAstDefault from '..';


const exampleInput = '$.track ? (exists(@.segments[*] ? (@.HR > 130))).segments.size()';

// Test that example output conforms to the JsonpathAst interface
const exampleOutput: JsonpathAst = {
  "expr": [
    {
      "type": "$"
    },
    {
      "type": ".key",
      "value": "track"
    },
    {
      "type": "?",
      "arg": [
        {
          "type": "exists",
          "arg": [
            {
              "type": "@"
            },
            {
              "type": ".key",
              "value": "segments"
            },
            {
              "type": "[*]"
            },
            {
              "type": "?",
              "arg": [
                {
                  "type": ">",
                  "left": [
                    {
                      "type": "@"
                    },
                    {
                      "type": ".key",
                      "value": "HR"
                    }
                  ],
                  "right": [
                    {
                      "type": "numeric",
                      "value": 130
                    }
                  ]
                }
              ]
            }
          ]
        }
      ]
    },
    {
      "type": ".key",
      "value": "segments"
    },
    {
      "type": "size"
    }
  ],
  "lax": true
};
console.log('✅ Example output conforms to JsonpathAst interface');

const exampleOutput2: JsonpathAst = {
  "expr": [
    {
      "type": "@"
    },
    {
      "type": "[subscript]",
      "elems": [
        {
          "from": [
            {
              "type": "numeric",
              "value": 0
            }
          ],
          "to": []
        }
      ]
    },
    {
      "type": "[subscript]",
      "elems": [
        {
          "from": [
            {
              "type": "numeric",
              "value": 1
            }
          ],
          "to": []
        },
        {
          "from": [
            {
              "type": "numeric",
              "value": 2
            }
          ],
          "to": []
        },
        {
          "from": [
            {
              "type": "numeric",
              "value": 3
            }
          ],
          "to": []
        }
      ]
    },
    {
      "type": ".*"
    },
    {
      "type": "[subscript]",
      "elems": [
        {
          "from": [
            {
              "type": "numeric",
              "value": 6
            }
          ],
          "to": [
            {
              "type": "numeric",
              "value": 32
            }
          ]
        }
      ]
    },
    {
      "type": ".**",
      "first": 0,
      "last": 4294967295
    }
  ],
  "lax": true
};
assert.ok(exampleOutput2);
console.log('✅ Example output 2 conforms to JsonpathAst interface');

const exampleOutput3: JsonpathAst = {
  "expr": [
    {
      "type": "$"
    },
    {
      "type": ".key",
      "value": "asdf"
    },
    {
      "type": "[subscript]",
      "elems": [
        {
          "from": [
            {
              "type": "numeric",
              "value": 1
            }
          ],
          "to": [
            {
              "type": "last"
            }
          ]
        }
      ]
    },
    {
      "type": ".**",
      "first": 0,
      "last": 4294967295
    },
    {
      "type": ".key",
      "value": "thing"
    },
    {
      "type": "[*]"
    },
    {
      "type": ".key",
      "value": "a"
    },
    {
      "type": ".key",
      "value": "b"
    },
    {
      "type": ".key",
      "value": "c"
    },
    {
      "type": ".key",
      "value": "d"
    },
    {
      "type": ".key",
      "value": "e"
    },
    {
      "type": ".key",
      "value": "f"
    },
    {
      "type": ".key",
      "value": "g"
    },
    {
      "type": "double"
    },
    {
      "type": "?",
      "arg": [
        {
          "type": "==",
          "left": [
            {
              "type": "-",
              "left": [
                {
                  "type": "@"
                },
                {
                  "type": ".key",
                  "value": "leaf"
                },
                {
                  "type": "[subscript]",
                  "elems": [
                    {
                      "from": [
                        {
                          "type": "numeric",
                          "value": 7
                        }
                      ],
                      "to": []
                    }
                  ]
                }
              ],
              "right": [
                {
                  "type": "numeric",
                  "value": 12345
                }
              ]
            }
          ],
          "right": [
            {
              "type": "%",
              "left": [
                {
                  "type": "numeric",
                  "value": 1
                }
              ],
              "right": [
                {
                  "type": "numeric",
                  "value": 9
                }
              ]
            }
          ]
        }
      ]
    }
  ],
  "lax": true
};
assert.ok(exampleOutput3);
console.log('✅ Example output 3 conforms to JsonpathAst interface');

// Test default export
const defaultResult: JsonpathAst = jsonpathToAstDefault(exampleInput);
assert.deepEqual(defaultResult, exampleOutput);
console.log('✅ Default export works');

const rootElement = defaultResult.expr[0] as JsonpathRoot;
console.log('✅ Root element can cast to a JsonpathRoot');

// @ts-expect-error "Type '$' is not assignable to type 'bogus'"
const rootTypeId: 'bogus' = rootElement.type;
console.log('✅ Root element type is not assignable to a bogus type');

assert.strictEqual(rootTypeId, '$');
console.log('✅ Root element has a type of "$"');

// Test named export
let namedResult: JsonpathAst = jsonpathToAst(exampleInput);
assert.deepEqual(namedResult, exampleOutput);
console.log('✅ Named export works');

// Test that invalid input throws an error
assert.throws(() => jsonpathToAst(''), InvalidJsonpathExpression);
console.log('✅ Invalid input throws the imported error type');
