4-D Matrix and Vector library mainly used for graphics and physics

Yes, I know how to use a for loop.
They are all unrolled in source for performance consistency.

## Compiling

In your project's CMakeLists.txt

```
add_subdirectory(Matrix4)
target_include_directories(your_target PUBLIC Matrix4/include)
target_link_libraries(your_target Matrix4)
```
