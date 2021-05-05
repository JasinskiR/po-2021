#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Isrc -Wall -pedantic -std=c++0x
LIBS = -lpthread

#__start__: obroty_2D
#	./obroty_2D

obroty_3D: obj obj/main.o obj/MacierzRot.o obj/Wektor.o obj/Dr3D_gnuplot_api.o obj/Figure.o obj/Scene.o
	g++ -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o obj/Wektor.o\
                        obj/MacierzRot.o obj/Figure.o obj/Dr3D_gnuplot_api.o obj/Scene.o -lpthread 
												
obj:
	mkdir obj

obj/main.o: src/main.cpp inc/MacierzRot.hpp inc/Wektor.hpp inc/Dr3D_gnuplot_api.hpp inc/Figure.hpp inc/Scene.hpp
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/MacierzRot.o: src/MacierzRot.cpp inc/MacierzRot.hpp 
	g++ -c ${CXXFLAGS} -o obj/MacierzRot.o src/MacierzRot.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hpp 
	g++ -c ${CXXFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/Figure.o: src/Figure.cpp inc/Figure.hpp inc/Dr3D_gnuplot_api.hpp
	g++ -c ${CXXFLAGS} -o obj/Figure.o src/Figure.cpp ${LIBS}

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hpp
	g++ -c ${CXXFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

obj/Scene.o: src/Scene.cpp inc/Scene.hpp
	g++ -c ${CXXFLAGS} -o obj/Scene.o src/Scene.cpp

clean:
	rm -f obj/*.o obroty_3D