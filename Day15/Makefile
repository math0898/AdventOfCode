day15 : main.cpp
	g++ -g main.cpp -o day15

# Runs valgrind memory checks on the build.
memcheck:
	g++ main.cpp -g -o0 -o day15
	@valgrind --leak-check=yes ./day15