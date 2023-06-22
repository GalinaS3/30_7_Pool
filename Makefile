pool: main.cpp
	g++ -o pool main.cpp RequestHandler.cpp ThreadPool.cpp 
clean: 
	rm  pool