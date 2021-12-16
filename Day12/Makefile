day12 : main.c
	gcc main.c -o day12

# Runs valgrind memory checks on the build.
memcheck:
	gcc main.c -g -o0 -o day12
	@valgrind --leak-check=yes ./day12