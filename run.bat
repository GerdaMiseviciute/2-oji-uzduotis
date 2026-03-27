if not exist build (
    mkdir build
)

cd build

cmake ..

cmake --build .

Debug\Objektinis-programavimas.exe

pause