# jsonpath-pg

[![npm version](https://badge.fury.io/js/jsonpath-pg.svg)](https://www.npmjs.com/package/jsonpath-pg)
[![ci](https://github.com/zone117x/jsonpath-pg/actions/workflows/ci.yml/badge.svg)](https://github.com/zone117x/jsonpath-pg/actions/workflows/ci.yml)

`jsonpath-pg` is a lightweight Node.js package that compiles the JSONPath parsing C code from the PostgreSQL source codebase into WebAssembly. It exposes an easy-to-use interface for converting JSONPath expressions into an Abstract Syntax Tree (AST).

**Note:** This package requires Node.js v16+.


## Features

- Uses PostgreSQL's JSONPath parsing code to ensure accurate and efficient parsing, notability
 the [grammar](https://github.com/postgres/postgres/blob/16dc2703c5413534d4989e08253e8f4fcb0e2aab/src/backend/utils/adt/jsonpath_gram.y) and [lexer](https://github.com/postgres/postgres/blob/16dc2703c5413534d4989e08253e8f4fcb0e2aab/src/backend/utils/adt/jsonpath_scan.l) files
- Converts the C code into WebAssembly for performance and easy integration with Node.js
- Provides a simple and user-friendly interface

## Installation

Install the package using npm:

```sh
npm install jsonpath-pg
```

## Usage
Import the jsonpathToAst function and use it to parse JSONPath expressions:

```js
import { jsonpathToAst } from 'jsonpath-pg';

const expression = '$.hello.world';
const ast = jsonpathToAst(expression);

console.log(JSON.stringify(ast, null, 2));
```

This will output the following AST:
```json
{
  "expr": [
    {
      "type": "$"
    },
    {
      "type": ".key",
      "value": "hello"
    },
    {
      "type": ".key",
      "value": "world"
    }
  ],
  "lax": true
}
```

### Example 2

```js
import { jsonpathToAst } from 'jsonpath-pg';

const expression = '$.track ? (exists(@.segments[*] ? (@.HR > 130))).segments.size()';
const ast = jsonpathToAst(expression);

console.log(JSON.stringify(ast, null, 2));
```

<details>
  <summary>Click me: AST console output</summary>
  
  ### Some Code
  ```json
  {
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
  }
  ```
</details>

## API

### jsonpathToAst(expression: string): object

Parses a JSONPath expression into an AST.

**Arguments:**

- `expression` (string): The JSONPath expression to parse.

**Returns:**

An object representing the AST of the parsed JSONPath expression.

**Errors:**

If the given string cannot be parsed as a valid JSONPath expression, then throws an `InvalidJsonpathExpression` error.
