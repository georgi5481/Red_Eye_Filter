cmake_minimum_required(VERSION 3.5.1)

project(Red_Eye_Filter LANGUAGES CXX)


set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
	${PROJECT_NAME} 	
	
#the header Files only
	${_BASE_DIR}/utils/CommonDefines.h
	${_BASE_DIR}/utils/EyePatterns.h
	${_BASE_DIR}/utils/FileParser.h
	${_BASE_DIR}/utils/FunctionTracer.h
	${_BASE_DIR}/utils/SolutionEvaluator.h
	
	
	${_BASE_DIR}/utils/Image.h
	${_BASE_DIR}/utils/Image.cpp 

	${_BASE_DIR}/Solution.h
	${_BASE_DIR}/Solution.cpp
	${_BASE_DIR}/main.cpp
	)


set_target_properties(
	${PROJECT_NAME}
	PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED YES
		CXX_EXTENSIONS NO
)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()


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

