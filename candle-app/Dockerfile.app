FROM gcc:12.3.0 AS builder

RUN apt-get update && \
    apt-get install -y cmake libgtest-dev

WORKDIR /app
COPY . .

RUN mkdir build && \
    cd build && \
    cmake .. && \
    cmake --build .

FROM gcc:12.3.0
COPY --from=builder /app/build/testproj /app/

CMD ["/app/testproj"]