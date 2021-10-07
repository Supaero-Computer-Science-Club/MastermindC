add_executable(solverApp solverApp.c code_list.c minmax.c tools.c)
target_include_directories(solverApp PUBLIC ${PROJECT_SOURCE_DIR}/inc)

