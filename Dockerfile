# syntax=docker/dockerfile:1
FROM emscripten/emsdk:3.1.35 as builder

WORKDIR /src
COPY src/c/. .

#RUN emcc string_function.c -Oz -s WASM=1 -s EXPORTED_FUNCTIONS="['_process_string']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap', 'ccall', 'getValue', 'writeAsciiToMemory']" -s ENVIRONMENT='node' -o string_function.js
#CMD ["cp", "string_function.wasm", "string_function.js", "/output"]

RUN emcmake cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DONLY_BUILD_WASM=ON \
    .

RUN find . -print

RUN emmake make -j`nproc`
RUN find . -print

FROM scratch
COPY --from=builder /src/bin /