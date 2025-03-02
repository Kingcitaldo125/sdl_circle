FROM vcpkg:2024.10.21

WORKDIR /app/

COPY . .

RUN apt -y install build-essential cmake autoconf automake libtool pkg-config python3-pip libxext-dev libwayland-dev libxkbcommon-dev libegl1-mesa-dev libibus-1.0-dev
RUN pip install jinja2

RUN export VCPKG_ROOT="${VCPKG_ROOT}" && export PATH="$PATH:${VCPKG_ROOT}" && vcpkg install
RUN cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake && \
    cmake --build build/ --parallel 2

WORKDIR /

CMD [ "/bin/bash" ]
