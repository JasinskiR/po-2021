#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Isrc -Wall -pedantic -std=c++0x
LIBS = -lpthread

#__start__: obroty_2D
#	./obroty_2D

obroty_3D: obj obj/main.o obj/MacierzRot.o obj/Wektor.o obj/Dr3D_gnuplot_api.o #obj/Cuboid.o
	g++ -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o obj/Wektor.o\
                        obj/MacierzRot.o obj/Dr3D_gnuplot_api.o -lpthread 
##obj/Cuboid.o
obj:
	mkdir obj

obj/main.o: src/main.cpp inc/MacierzRot.hh inc/Wektor.hh inc/Dr3D_gnuplot_api.hh #inc/Cuboid.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/MacierzRot.o: src/MacierzRot.cpp inc/MacierzRot.hh 
	g++ -c -E ${CXXFLAGS} -o obj/MacierzRot.o inc/MacierzRot.hh

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh 
	g++ -c -E ${CXXFLAGS} -o obj/Wektor.o inc/Wektor.hh

#obj/Cuboid.o: src/Cuboid.cpp inc/Cuboid.hh #inc/Dr2D_gnuplot_api.hh
#	g++ -c ${CXXFLAGS} -o obj/Prostokat.o src/Cuboid.cpp ${LIBS}

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ -c ${CXXFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

clean:
	rm -f obj/*.o obroty_3D