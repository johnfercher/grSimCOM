CCX = g++ -std=c++11 -w

INCLUDES = -IProtos -I/usr/include/qt4
LIBRARIES = `pkg-config --cflags --libs protobuf` -lpthread -lQtNetwork -lQtCore -lQtGui -w

SRC := $(shell find -name '*.cpp')
FILE_NAMES_SRC = $(SRC:.cpp=.o)

PROTOS := $(shell find -name '*.cc')
FILE_NAMES_PROTOS = $(PROTOS:.cc=.o)


EXEC = COM

.cpp.o:
	@$(CCX) $(INCLUDES) $(LIBRARIES) -Wall -Wformat -c -o $@ $< -w

.cc.o:
	@$(CCX) $(INCLUDES) $(LIBRARIES) -Wall -Wformat -c -o $@ $< -w

all: message $(EXEC)
	@echo Terminado . . .
	
message:
	@echo Compilando . . .

run:
	./COM

$(EXEC): $(FILE_NAMES_SRC) $(FILE_NAMES_PROTOS) 
	@$(CCX) -o $(EXEC) $(FILE_NAMES_SRC) $(FILE_NAMES_PROTOS) $(LIBRARIES) $(INCLUDES)

clean:
	rm $(EXEC) $(FILE_NAMES_SRC) $(FILE_NAMES_PROTOS)

proto:
	cd Protos/ && make -f protos.make

