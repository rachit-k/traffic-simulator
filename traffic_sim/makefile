INCLUDE_PATHS =  -I/usr/local/cellar/glfw/3.2.1/include 

LIBRARY_PATHS =  -L/usr/local/cellar/glfw/3.2.1/lib 

# Cocoa, IOKit, and CoreVideo are needed for static GLFW3.
LINKER_FLAGS = -framework OpenGL -lglew -lglfw

output : Traffic_simulator.o glad.o 
	g++ Traffic_simulator.o glad.o -o output $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) 

Traffic_simulator.o: Traffic_simulator.cpp glad.cpp glad.h
	g++ -c Traffic_simulator.cpp

#opengll.o: opengll.cpp opengll.h
#	g++ -c opengll.cpp	

glad.o: glad.cpp glad.h
	g++ -c glad.cpp

clean:
	rm *.o output
