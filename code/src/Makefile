% : SatFileMe.cc %.c
	g++ -std=c++11 SatFileMe.cc $@.c -o $@
	g++ -std=c++11 coverTree.cc coverTreeMain.cc $@.c -o coverTree

clean :
	rm -rf *.dimacs
	find . -perm /100 -type f -delete
