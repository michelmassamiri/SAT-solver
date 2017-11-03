coverTree : coverTree.cc coverTreeMain.cc
	g++ -std=c++11 coverTree.cc coverTreeMain.cc -o coverTree

% : SatFileMe.cc %.c
	g++ -std=c++11 SatFileMe.cc $@.c -o $@

clean :
	rm -rf *.dimacs
	find . -perm /100 -type f -delete
