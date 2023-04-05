# syntax=docker/dockerfile:1
FROM emscripten/emsdk:3.1.35 as builder

WORKDIR /src
COPY src/c/. .

#RUN emcmake cmake -DCMAKE_BUILD_TYPE=Release .
RUN emcmake cmake -DCMAKE_BUILD_TYPE=Debug .
RUN cmake --build . -- -j`nproc`
RUN find . -print

FROM scratch
COPY --from=builder /src/bin /