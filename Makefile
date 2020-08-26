lib-ob:	main.o Book.o Control.o Library.o List.o Logger.o View.o
	g++ -o lib-ob main.o Book.o Control.o Library.o List.o Logger.o View.o

main.o:	main.cc Book.h
	g++ -c main.cc

Book.o:	Book.cc Book.h
	g++ -c Book.cc

Control.o:	Control.cc Control.h Library.h View.h
	g++ -c Control.cc

Library.o:	Library.cc Library.h Book.h List.h Logger.h
	g++ -c Library.cc

List.o:	List.cc List.h Book.h
	g++ -c List.cc

Logger.o:	Logger.cc Logger.h Book.h List.h
	g++ -c Logger.cc

View.o:	View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o lib-ob
