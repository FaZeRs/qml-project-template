# QT 6 Project Template

Project template for QT projects.

## Co,

```bash
docker build -t roomsketcher/6.5-gcc:latest ./docker/gcc
docker compose run --rm gcc bash
cmake -E make_directory build
cd build
cmake -G Ninja .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/tmp/room_sketcher -DUSE_CCACHE=ON -DCPM_SOURCE_CACHE=~/.cache/CPM
cmake --build . --parallel --config Release
ctest -C Release --output-on-failure --output-junit test-results.xml
cmake --install .
cmake --build . --config Release --target package
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
