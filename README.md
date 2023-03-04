# QT 6 Project Template

Project template for QT projects.

## Linux Build

```bash
docker build -t roomsketcher/6.5-gcc:latest ./docker/gcc
docker compose run --rm gcc bash
mkdir build
cd build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/tmp/room_sketcher ..
cmake --build . --parallel
cmake --install .
```

## Windows Build

```bash
docker build -t roomsketcher/6.5-mingw:latest ./docker/mingw
docker compose run --rm mingw bash
mkdir build
cd build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/tmp/room_sketcher ..
cmake --build . --parallel
cmake --install .
```
