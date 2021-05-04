#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Isrc -Wall -pedantic -std=c++0x
LIBS = -lpthread

#__start__: obroty_2D
#	./obroty_2D

obroty_2D: obj obj/main.o obj/MacierzRot.o obj/Wektor.o obj/Dr2D_gnuplot_api.o obj/Figure.o
	g++ -Wall -pedantic -std=c++0x -o obroty_2D obj/main.o obj/Wektor.o\
                        obj/MacierzRot.o obj/Figure.o obj/Dr2D_gnuplot_api.o -lpthread 
												
obj:
	mkdir obj

obj/main.o: src/main.cpp inc/MacierzRot.hh inc/Wektor.hh inc/Dr2D_gnuplot_api.hh inc/Figure.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/MacierzRot.o: src/MacierzRot.cpp inc/MacierzRot.hh 
	g++ -c ${CXXFLAGS} -o obj/MacierzRot.o src/MacierzRot.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh 
	g++ -c ${CXXFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/Figure.o: src/Figure.cpp inc/Figure.hh inc/Dr2D_gnuplot_api.hh
	g++ -c ${CXXFLAGS} -o obj/Figure.o src/Figure.cpp ${LIBS}

obj/Dr2D_gnuplot_api.o: src/Dr2D_gnuplot_api.cpp inc/Dr2D_gnuplot_api.hh
	g++ -c ${CXXFLAGS} -o obj/Dr2D_gnuplot_api.o src/Dr2D_gnuplot_api.cpp

clean:
	rm -f obj/*.o obroty_2D