OS = $(shell uname)

MAIN = test01.exe
main: $(MAIN)

sourcehome = .

sourcelist = $(basename $(notdir $(wildcard $(sourcehome)/*.c)))
executable = $(addsuffix .exe, $(sourcelist))

sourcelistcc = $(basename $(notdir $(wildcard $(sourcehome)/*.cc)))
executablecc = $(addsuffix .exe, $(sourcelistcc))

sourcelist11 = $(basename $(notdir $(wildcard $(sourcehome)/*.cpp)))
executable11 = $(addsuffix .exe, $(sourcelist11))

all: $(executable) $(executablecc)
a11: $(executable11)

ifeq ($(OS), Darwin)
GC = gcc
CC = g++
CL = clang++
WARN = -Weverything
else ifeq ($(OS), Linux)
GC = gcc -std=gnu99
CC = g++
CL = g++
WARN = -Wall
endif

CFLAGS = $(WARN)
C11FLAGS = -std=c++11 -stdlib=libc++ $(WARN)

%.exe: %.c
	$(GC) $(CFLAGS) -o $@ $<

%.exe: %.cc
	$(CC) $(CFLAGS) -o $@ $<

%.exe: %.cpp
	$(CL) $(C11FLAGS) -o $@ $<


.PHONY: clean

clean:
	rm -rf *.exe *.o
