FILES = databaseWrapper.cpp sqlite3.o

main:
	g++ main.cpp $(FILES)

tests:
	g++ tests.cpp $(FILES)

clean:
	rm a.exe