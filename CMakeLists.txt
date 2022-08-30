cmake_minimum_required(VERSION 3.5.1)

project(Red_Eye_Filter LANGUAGES CXX)	#first instance the project and the language

#find_program(CMAKE_CXX_COMPILER NAMES $ENV{CXX} g++ PATHS ENV PATH NO_DEFAULT_PATH)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
	${PROJECT_NAME} 	

	${_BASE_DIR}/utils/CommonDefines.h
	${_BASE_DIR}/utils/EyePatterns.h
	${_BASE_DIR}/utils/FileParser.h
	${_BASE_DIR}/utils/FunctionTracer.h
	${_BASE_DIR}/utils/SolutionEvaluator.h
	${_BASE_DIR}/utils/Image.h
	
	${_BASE_DIR}/utils/Image.cpp 

	
	${_BASE_DIR}/Solution.h
	${_BASE_DIR}/main.cpp
	)


set_target_properties(
	${PROJECT_NAME}
	PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED YES
		CXX_EXTENSIONS NO
)


target_compile_options(
		${PROJECT_NAME}
		PRIVATE
		-Wall
		-Wextra
		-Werror
		-Wundef
		-Wreorder
		-Wshadow
		-Wpointer-arith
		-Wcast-align
		-Wcast-qual
		-Wconversion
		-Wunused-parameter
		-Wlogical-op
		-Wdouble-promotion
		-Wuseless-cast
		-Wnon-virtual-dtor
		-Woverloaded-virtual
		-Wduplicated-cond
		-Wduplicated-branches
		-Wnull-dereference
	)


target_include_directories(
${PROJECT_NAME} 
	PUBLIC 
		${_BASE_DIR}
)

