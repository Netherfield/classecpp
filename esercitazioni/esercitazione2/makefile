

CFLAGS := -c -Wall -Wfatal-errors

Vettori3D: Vettori3D.o DriverVettori.o
	g++ -o Vettori3D Vettori3D.o DriverVettori.o

Vettori3D.o: Vettori3D.cpp Vettori3D.hpp
	g++ $(CFLAGS) Vettori3D.cpp

DriverVettori.o: DriverVettori.cpp Vettori3D.hpp
	g++ $(CFLAGS) DriverVettori.cpp

clean:
	rm -r *.o