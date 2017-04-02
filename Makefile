CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra 
LDFLAGS  = -g3

#
# Here are the rules!  Each rule has a "target" followed by a colon.
# After the colon, is a list of "dependencies" (also called
# "prerequisites") all on one line.  These are files that must already
# exist and be up-to-date before you can make the target.  So, the
# first rule below says that you'd like define how to make a thing
# called "charLinkedList," and that depends on 4 .o files.  You may follow
# that line with a recipe as a series of one line commands indented
# with a tab character (yes, it must be a tab character!).  In this
# first rule, if you have all the .o files up-to-date, you make a
# hookbook by running clang++ with the flags specified above giving it
# all the .o files and producing leaving the executable output in a
# file named "charLinkedList".
# 
#
sorter: sorter.o sortAlgs.o 
	${CXX} ${LDFLAGS} -o sorter sorter.o sortAlgs.o


#
# The following rules don't have recipes.  The make program has a ton
# of built-in rules, and it knows that if you want a X.o file and you
# have an X.cpp, it can compile the .cpp file to make a .o file.
# Furthermore, if the conventionally known variables CXX and CXXFLAGS
# are defined, it will use them!  What it doesn't know is what files
# besides the .cpp file the program module might depend on.  So, we
# only specify the target and dependencies here.
#
sorter.o: sorter.cpp  sortAlgs.h
sortAlgs.o:     sortAlgs.cpp      sortAlgs.h


#
# The following rules show how you can use make to automate things
# besides program building.
#
# Makefiles traditionally have a "clean" target.  The purpose is to
# clean up everything that is automatically built by make.  It's
# useful for when you want to save disk space and also when you've
# messed things up and just want to rebuild everything from scratch.
# The clean target doesn't have an prerequisites, because you don't
# need anything to be there in order to clean up!
#
# .dSYM directories are something that gets make in the Mac
# environment for debugging data, and so I delete them when cleaning
# up. 
#
clean:
	rm -rf rPNCalc *.o *.dSYM

#
# You can even have a rule that turns your work in for you!
# You can make rules for running tests, too.
#
provide:
	provide comp15 hw3 DoubleStack.h DoubleStack.cpp \
                           testDoubleStack.cpp \
                           RPNCalc.cpp \
                           RPNCalc.h \
                           testRPNCalc.cpp \
                           Makefile \