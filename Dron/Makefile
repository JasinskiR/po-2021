#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Isrc -Ifml -Wall -pedantic -std=c++0x
LIBS = -lpthread

# __start__: Dron
# 	./Dron

Dron: obj obj/main.o obj/MatrixRot.o obj/Vector.o obj/Dr3D_gnuplot_api.o\
												obj/CoordinateS.o obj/Cuboid.o obj/HexaPrism.o obj/Drone.o obj/Surface.o obj/Animation.o
	g++ -Wall -pedantic -std=c++0x -o Dron obj/main.o obj/Vector.o\
                        obj/MatrixRot.o obj/Dr3D_gnuplot_api.o\
												obj/CoordinateS.o obj/Cuboid.o obj/HexaPrism.o obj/Drone.o\
												obj/Surface.o obj/Animation.o -lpthread 
# obj/Figure.o obj/Scene.o
												
obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Surface.hpp inc/Drone.hpp
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/MatrixRot.o: src/MatrixRot.cpp inc/MatrixRot.hpp fml/MatrixRot.tpp
	g++ -c ${CXXFLAGS} -o obj/MatrixRot.o src/MatrixRot.cpp

obj/Vector.o: src/Vector.cpp inc/Vector.hpp fml/Vector.tpp
	g++ -c ${CXXFLAGS} -o obj/Vector.o src/Vector.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hpp
	g++ -c ${CXXFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

# obj/Scene.o: src/Scene.cpp inc/Scene.hpp
# 	g++ -c ${CXXFLAGS} -o obj/Scene.o src/Scene.cpp

obj/CoordinateS.o: src/CoordinateS.cpp inc/CoordinateS.hpp
	g++ -c ${CXXFLAGS} -o obj/CoordinateS.o src/CoordinateS.cpp

obj/Cuboid.o: src/Cuboid.cpp inc/Cuboid.hpp
	g++ -c ${CXXFLAGS} -o obj/Cuboid.o src/Cuboid.cpp

obj/HexaPrism.o: src/HexaPrism.cpp inc/HexaPrism.hpp
	g++ -c ${CXXFLAGS} -o obj/HexaPrism.o src/HexaPrism.cpp

obj/Drone.o: src/Drone.cpp inc/Drone.hpp
	g++ -c ${CXXFLAGS} -o obj/Drone.o src/Drone.cpp

obj/Surface.o: src/Surface.cpp inc/Surface.hpp
	g++ -c ${CXXFLAGS} -o obj/Surface.o src/Surface.cpp

obj/Animation.o: src/Animation.cpp inc/Animation.hpp
	g++ -c ${CXXFLAGS} -o obj/Animation.o src/Animation.cpp

clean:
	rm -f obj/*.o Dron