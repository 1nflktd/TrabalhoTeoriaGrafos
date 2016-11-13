main:
	g++ src/*.cpp src/algorithms/*.cpp -o trabalho -Wall -std=c++14 -O3
	# x86_64-w64-mingw32-g++ src/*.cpp src/algorithms/*.cpp -o trabalho.exe -Wall -std=c++14 -O3 -s -static-libstdc++ -static-libgcc -static