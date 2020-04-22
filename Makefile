cc=g++
target = main
objects = main.cpp

$(target) : $(objects)
	$(cc) -o $(target) $(objects)

clean :
	rm $(target)
