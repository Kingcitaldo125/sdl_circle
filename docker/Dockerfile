FROM sdl_circle:deps

WORKDIR /app/

COPY . .

RUN cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake && \
    cmake --build build/ --parallel 2

WORKDIR /

CMD [ "/bin/bash" ]
