main: stud.o
	g++ -o main main.cpp stud.o
fun:
	g++ -c stud.cpp
clean:
	rm *.o main