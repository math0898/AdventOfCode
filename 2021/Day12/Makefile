day12 : main.c Stack.h Stack.c
	gcc main.c Stack.c -o day12

# Runs valgrind memory checks on the build.
memcheck:
	gcc main.c Stack.c -g -o0 -o day12
	@valgrind --leak-check=yes ./day12