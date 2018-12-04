LDFLAGS=-L/usr/local/opt/libressl/lib
CPPFLAGS=-I/usr/local/opt/libressl/include

a.out: day4.cpp
	g++ $(CPPFLAGS) $(LDFLAGS) -o $@ $< -lcrypto

clean:
	rm a.out
