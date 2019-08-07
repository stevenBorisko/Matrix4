project(Matrix4)
add_library(Matrix4
	./src/Constructors.cpp
	./src/Friend.cpp
	./src/Miscellaneous.cpp
	./src/OperatorOverloads.cpp
	./src/Static.cpp
	./src/Transformations.cpp
	./src/Vector.cpp
)
target_include_directories(Matrix4 PUBLIC ./include)
