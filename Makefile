CC = gcc
CFlags = -g -Wall -m32
# gcc -m32 -o addresses addresses.c

# Sources = $(wildcard *.c)
# Sources = count-words.c
# Sources = addresses.c
Sources = base.c
OFiles = $(Sources:.c=.o)
Ex = lab1

all: $(Ex)

$(Ex): $(OFiles)
	$(CC) $(CFlags) $(OFiles) -o $@

%.o: %.c
	$(CC) $(CFlags) -c $< -o $@

clean:
	rm -f $(OFiles) $(Ex)