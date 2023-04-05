#!/bin/bash
BUILDKIT_PROGRESS=plain docker build -o build .
#npx servor build jsonpath_parse.html --reload --browse