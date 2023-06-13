Ex3.out : Exercise3.o Ex3Functions.o
	g++ -o Ex3.out Exercise3.o Ex3Functions.o
	
Exerise3.o : Exercise3.cpp Ex3Functions.h Bitmap_Image.hpp
	g++ -c -g Exercise3.cpp
	
Ex3Functions.o : Ex3Functions.cpp Ex3Functions.h Bitmap_Image.hpp
	g++ -c -g Ex3Functions.cpp

clean :
	rm -rf *.o *.out *.gch
