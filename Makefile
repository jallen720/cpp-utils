all: lib/libCpp_Utils.so bin/test
	@:

import_Cpp_Utils_libs: 
	@:

obj/src/Cpp_Utils/File.o: src/Cpp_Utils/File.cpp 
	@echo compiling $<
	@mkdir -p obj/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/Cpp_Utils/JSON.o: src/Cpp_Utils/JSON.cpp 
	@echo compiling $<
	@mkdir -p obj/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/Cpp_Utils/Errors.o: src/Cpp_Utils/Errors.cpp 
	@echo compiling $<
	@mkdir -p obj/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/Cpp_Utils/String.o: src/Cpp_Utils/String.cpp 
	@echo compiling $<
	@mkdir -p obj/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/Cpp_Utils/Test.o: src/Cpp_Utils/Test.cpp 
	@echo compiling $<
	@mkdir -p obj/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/Cpp_Utils/Validators.o: src/Cpp_Utils/Validators.cpp 
	@echo compiling $<
	@mkdir -p obj/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/Cpp_Utils/YAML.o: src/Cpp_Utils/YAML.cpp 
	@echo compiling $<
	@mkdir -p obj/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

lib/libCpp_Utils.so: obj/src/Cpp_Utils/File.o obj/src/Cpp_Utils/JSON.o obj/src/Cpp_Utils/Errors.o obj/src/Cpp_Utils/String.o obj/src/Cpp_Utils/Test.o obj/src/Cpp_Utils/Validators.o obj/src/Cpp_Utils/YAML.o
	@echo linking $@
	@mkdir -p lib
	@g++ -shared $^ -L/home/joel/Desktop/packages/yaml-cpp/build -lyaml-cpp -o $@

bin/lib/libCpp_Utils.so: lib/libCpp_Utils.so
	@echo 'copying $< -> $@'
	@mkdir -p bin/lib
	@cp lib/libCpp_Utils.so bin/lib/libCpp_Utils.so

bin/lib/libyaml-cpp.so.0.6: /home/joel/Desktop/packages/yaml-cpp/build/libyaml-cpp.so.0.6
	@echo 'copying $< -> $@'
	@mkdir -p bin/lib
	@cp /home/joel/Desktop/packages/yaml-cpp/build/libyaml-cpp.so.0.6 bin/lib/libyaml-cpp.so.0.6

import_test_libs: bin/lib/libCpp_Utils.so bin/lib/libyaml-cpp.so.0.6
	@:

obj/tests/src/Cpp_Utils/Vector.o: tests/src/Cpp_Utils/Vector.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/Cpp_Utils/Fn.o: tests/src/Cpp_Utils/Fn.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/Cpp_Utils/File.o: tests/src/Cpp_Utils/File.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/Cpp_Utils/JSON.o: tests/src/Cpp_Utils/JSON.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/Cpp_Utils/String.o: tests/src/Cpp_Utils/String.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/Cpp_Utils/Collection.o: tests/src/Cpp_Utils/Collection.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/Cpp_Utils/YAML.o: tests/src/Cpp_Utils/YAML.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/Cpp_Utils/main.o: tests/src/Cpp_Utils/main.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/Cpp_Utils/Map.o: tests/src/Cpp_Utils/Map.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/Cpp_Utils/Type.o: tests/src/Cpp_Utils/Type.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/Cpp_Utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Iinclude -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

bin/test: obj/tests/src/Cpp_Utils/Vector.o obj/tests/src/Cpp_Utils/Fn.o obj/tests/src/Cpp_Utils/File.o obj/tests/src/Cpp_Utils/JSON.o obj/tests/src/Cpp_Utils/String.o obj/tests/src/Cpp_Utils/Collection.o obj/tests/src/Cpp_Utils/YAML.o obj/tests/src/Cpp_Utils/main.o obj/tests/src/Cpp_Utils/Map.o obj/tests/src/Cpp_Utils/Type.o
	@echo linking $@
	@mkdir -p bin
	@g++ $^ -Llib -L/home/joel/Desktop/packages/yaml-cpp/build -lyaml-cpp -lCpp_Utils -Wl,-rpath,'$$ORIGIN/lib' -o $@

