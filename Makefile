CC = gcc
CFLAGS = -Wall -Wextra

TARGET = mypreprocessor

SOURCES = main.c comment_removal.c file_inclusion.c macro_handler.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) temp_file.c temp_include.c *.i test
