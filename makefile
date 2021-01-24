CC = g++
PGNAME = HTTPServer
OBJS = main.o HTTPServer.o

$(PGNAME): $(OBJS)
	$(CC) -o $@ $^ -lboost_system

.cpp.o:
	$(CC) -c -o $@ $< -lboost_system

.PHONY: clean
clean:
	rm -f $(PGNAME) $(OBJS)
