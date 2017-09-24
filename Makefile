# please change the XXXX to your username eg. j453h432
STUDENT_ID=l446d901
LAB_NAME=binary-tree-lab-4
GCC=g++
GCCFLAGS=-Wall -g -pedantic --std=c++11

# PLEASE ADD THE NAME OF ALL THE FILES YOU WANT TO GET ARCHIVED
FILES=Makefile main.cpp util.hpp data.txt \
	binary-tree.hpp binary-tree.cpp \
	$(STUDENT_ID)-writeup.pdf

ARCHIVE_FOLDER=$(STUDENT_ID)-$(LAB_NAME)

install: binary-tree main
	$(GCC) $(GCC_FLAGS) -o main main.o binary-tree.o

binary-tree:node
	$(GCC) $(GCCFLAGS) -c binary-tree.cpp -o binary-tree.o

test: install
	./main

node:
	$(GCC) $(GCCFLAGS) -c node.cpp -o node.o


main:
	$(GCC) $(GCCFLAGS) -c main.cpp -o main.o

clean:
	rm -rf main *.o $(ARCHIVE_FOLDER) $(ARCHIVE_FOLDER).tar.gz

tar: clean
	mkdir $(ARCHIVE_FOLDER)
	cp -r $(FILES) $(ARCHIVE_FOLDER)
	tar cvzf $(ARCHIVE_FOLDER).tar.gz $(ARCHIVE_FOLDER)
	rm -rf $(ARCHIVE_FOLDER)
