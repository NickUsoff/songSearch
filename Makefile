#
# Makefile for SongSearch, Assignment 5
#
CXX = g++
FLAGS = -Wall -Wextra -Wconversion -g -std=c++11

songsearch: WordList.h Song.h WordContext.h WordList.cpp mainTest.cpp Song.cpp WordContext.cpp
	${CXX} ${FLAGS} -o songsearch WordList.cpp mainTest.cpp Song.cpp WordContext.cpp

clean:
	rm -f songsearch

provide_design:
	provide comp15 hw5_design songsearch_design.txt

provide:
	provide comp15 hw5 WordList.h Song.h WordContext.h WordList.cpp mainTest.cpp Song.cpp WordContext.cpp README.txt Makefile


