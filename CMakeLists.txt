cmake_minimum_required(VERSION 3.10)


add_executable(books 
	src/main.cpp
        include/book.hpp
        include/library.hpp
        include/csv.hpp
        include/txt.hpp
        src/book.cpp
        src/library.cpp
        src/csv.cpp
        src/txt.cpp
        src/salvajson.cpp
        include/salvajson.hpp
        include/json.hpp
        include/vinili.hpp
        src/vinili.cpp
        include/carrello.hpp
        src/carrello.cpp
        include/banconote.hpp
        src/banconote.cpp
        include/cassa.hpp
        src/cassa.cpp
)

target_include_directories(books PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
