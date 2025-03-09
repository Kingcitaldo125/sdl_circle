#!/bin/bash

docker build -t vcpkg:2024.10.21 -f ./Dockerfile.vcpkg --network host .
docker build -t sdl_circle:deps -f ./Dockerfile.deps --network host .
docker build -t sdl_circle --network host --no-cache .

cont_id=$(docker create sdl_circle)
docker cp $cont_id:/app/build .
docker stop $cont_id && docker rm $cont_id
