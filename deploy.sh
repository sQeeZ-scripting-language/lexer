mkdir build
cd build
cmake ..
cmake --build .
cd build
cmake --install . --prefix "/usr/local/"
cpack