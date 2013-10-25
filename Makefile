.PHONY: all, clean, mrproper, distclean

# Implicit rules desactivation
.SUFFIXES: 

TOPDIR = $(shell pwd)
SRCDIR = $(TOPDIR)/src
INCDIR = $(TOPDIR)/include

CXX = g++
ARCH     = -m64 
# LIBS	 = -L/usr/lib32/ -lstdc++
WARNINGS = -pedantic -Wextra -Wall -Wundef -Werror=implicit-function-declaration -Wmissing-include-dirs -Wshadow

APP = cwis_camera.out

SRC = $(SRCDIR)/main.cpp	\
	  $(SRCDIR)/camera.cpp
OBJ = $(SRC:.cpp=.o)

# Build rules
all: $(APP)

$(APP): $(OBJ)
	@g++ $(ARCH) -o $@ $(OBJ)

%.o: %.cpp
	@$(CXX) $(ARCH) $(WARNINGS) -c -I$(INCDIR) -o $@ $<

clean: 
	rm -rf $(OBJ)

distclean: clean
	rm -rf $(APP)

