cmake_minimum_required(VERSION 3.15) 
									 
									 

set(PROJECT_NAME Game_0.1)				 		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")

add_executable("${PROJECT_NAME}" main.cpp
                                 Game.cpp
                                 Game.h
				 calibri.ttf
)
target_link_libraries("${PROJECT_NAME}" 
					    debug sfml-graphics-s-d 
						debug sfml-window-s-d
						debug sfml-system-s-d
						debug sfml-audio-s-d)
						
target_link_libraries("${PROJECT_NAME}" 
					    optimized sfml-graphics-s 
						optimized sfml-window-s
						optimized sfml-system-s
						optimized sfml-audio-s)
	
target_link_libraries("${PROJECT_NAME}" opengl32 freetype winmm gdi32 openal32 flac vorbisenc vorbisfile vorbis ogg)
										
