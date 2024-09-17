	cmake_minimum_required (VERSION 3.25)
	project(main LANGUAGES C VERSION 1.0.0)
	
	add_compile_options(-lncurses)
	add_executable(main
		main.c
	)


	target_link_libraries(main


	)
