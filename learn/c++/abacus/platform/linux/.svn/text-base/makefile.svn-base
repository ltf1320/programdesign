#
# makefile for abacus 1.0
#

GXX		= g++
CXXFLAGS	= -g -Wall
LDFLAGS		= -lm

# for linux
PROGRAM		= abacus

PREFIX		= /bin

ROOT_DIR	= ../..
SRC_DIR		= $(ROOT_DIR)/src
INC		= -I$(SRC_DIR)
LINUX_PLATFORM	= $(ROOT_DIR)/platform/linux
BIN_DIR		= $(LINUX_PLATFORM)/bin
OBJ_DIR		= $(LINUX_PLATFORM)/obj
TARGET		= $(addprefix $(BIN_DIR)/,$(PROGRAM))

vpath %.h $(SRC_DIR)
vpath %.cpp $(SRC_DIR)

.PHONY : all
all : $(TARGET)

SRC_FILE	= $(wildcard $(addprefix $(SRC_DIR)/,*.cpp))
OBJS		= $(addprefix $(OBJ_DIR)/,$(subst .cpp,.o,$(notdir $(SRC_FILE))))

$(OBJ_DIR)/%.d : %.cpp
	@$(GXX) -MM $< > $@

$(OBJ_DIR)/%.o : %.cpp $(OBJ_DIR)/%.d
	@echo compile $<.....
	@$(GXX) -c $< $(INC) $(CXXFLAGS) -o $@

$(TARGET) : $(OBJS)
	@echo linking......
	@$(GXX) -Wall $(OBJS) $(LDFLAGS) $(CXXFLAGS) -o $(TARGET) 

.PHONY : clean
clean:
	-rm $(TARGET) $(OBJS)
	-rm *.d

.PHONY : install
install:
	cp -f $(TARGET) $(PREFIX)/$(PROGRAM)

