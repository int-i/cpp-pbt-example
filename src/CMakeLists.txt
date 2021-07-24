add_executable(stateless stateless.cpp)
target_link_libraries(stateless rapidcheck)

add_executable(stateful stateful.cpp)
target_link_libraries(stateful rapidcheck)

