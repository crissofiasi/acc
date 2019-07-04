# Application name
set(APP_NAME "tema1")


# Log message for debugging
message(STATUS "*** Parsing ${APP_NAME} ***")

	
	# Set paths
	set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
	set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/source)

	
	include_directories(${INCROOT} ${Boost_INCLUDE_DIR})

	# Get files
	file(GLOB INCS "${INCROOT}/*.h")
	file(GLOB SRCS "${SRCROOT}/*.cpp")

	# Create Executable
	add_executable(${APP_NAME} ${INCS} ${SRCS})

	# Path to Framework
	#link_directories(${PROJECT_SOURCE_DIR}/build/lib)

	# Link dependencies to current application
	#target_link_libraries(${APP_NAME} ${Boost_LIBRARIES} Framework)

# We are using C++
set_target_properties(${APP_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Path to exe
set_target_properties(${APP_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/exe)