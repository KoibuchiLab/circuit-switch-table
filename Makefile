#
# Makefile	Sep-25-2018 huyao@nii.ac.jp
#
# GNU make
#
# v1.0

#compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -Wno-sign-compare

#object files
objects = circuit-switch-table.o traffic-pattern-generator.o

all : cst.out tpg.out

cst.out : circuit-switch-table.o 
	${CXX} circuit-switch-table.o -o cst.out
clean::
	-rm -f cst.out

tpg.out : traffic-pattern-generator.o
	${CXX} traffic-pattern-generator.o -o $@
clean::
	-rm -f tpg.out

traffic-pattern-generator.o : traffic-pattern-generator.h

clean:: 
	-rm -f ${objects}

