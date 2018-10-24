MATRIX4_PATH := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
MATRIX4_MAIN_OBJ := $(MATRIX4_PATH)Matrix4.o
MATRIX4_CFLAGS := -std=c++11 -O3
MATRIX4_LFLAGS :=

MATRIX4_OBJDIR := $(MATRIX4_PATH).ObjectFiles/
Matrix4ObjectDirectory:
	mkdir $(MATRIX4_OBJDIR)
	mkdir $(MATRIX4_OBJDIR)src/

_MATRIX4_DEPS := src/Matrix.hpp
MATRIX4_DEPS := $(foreach OBJ,$(_MATRIX4_DEPS),$(MATRIX4_PATH)$(OBJ))

_MATRIX4_SUB_OBJS := \
	src/Constructors.cpp \
	src/Friend.cpp \
	src/Miscellaneous.cpp \
	src/OperatorOverloads.cpp \
	src/Static.cpp \
	src/Transformations.cpp \
	src/Vector.cpp
MATRIX4_SUB_OBJS := \
	$(foreach OBJ,$(_MATRIX4_SUB_OBJS),$(MATRIX4_OBJDIR)$(OBJ))


# --- Rules ---

# Main object
$(MATRIX4_MAIN_OBJ): $(MATRIX4_DEPS) $(MATRIX4_SUB_OBJS)
	@echo "- - - - BigInteger compiled - - - -"
	$(LD) -r $(MATRIX4_LFLAGS) $(MATRIX4_SUB_OBJS) -o $@
	@echo "- - - - BigInteger linked - - - -"

# Sub objects
$(MATRIX4_OBJDIR)%.o: $(MATRIX4_PATH)%.cpp
	$(CC) -c $(MATRIX4_CFLAGS) $< -o $@

# Clean
Matrix4Clean:
	rm -f $(MATRIX4_SUB_OBJS) $(MATRIX4_MAIN_OBJ)
