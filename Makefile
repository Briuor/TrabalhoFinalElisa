all: Main.cpp File.cpp
	g++ Main.cpp File.cpp -lglut -lGL -lGLU && ./a.out
