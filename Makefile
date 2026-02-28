# Makefile for Student Data Processing Project

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c99 -g
TARGET = bin/student_program

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
DATADIR = data
DOCSDIR = docs

# Source files
SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/student.c \
       $(SRCDIR)/file_handler.c \
       $(SRCDIR)/processor.c

# Object files
OBJS = $(OBJDIR)/main.o \
       $(OBJDIR)/student.o \
       $(OBJDIR)/file_handler.o \
       $(OBJDIR)/processor.o

all: $(TARGET)

# Create directories
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(DATADIR):
	mkdir -p $(DATADIR)

bin:
	mkdir -p bin

# Link the executable
$(TARGET): $(OBJS) | bin
	$(CC) -o $(TARGET) $(OBJS)

# Compile source files
$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/student.h $(INCDIR)/file_handler.h $(INCDIR)/processor.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/student.o: $(SRCDIR)/student.c $(INCDIR)/student.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/file_handler.o: $(SRCDIR)/file_handler.c $(INCDIR)/file_handler.h $(INCDIR)/student.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/processor.o: $(SRCDIR)/processor.c $(INCDIR)/processor.h $(INCDIR)/student.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(TARGET) bin

# Run the program
run: $(TARGET) | $(DATADIR)
	./$(TARGET)

# Create test data
test-data: | $(DATADIR)
	@echo "Creating test data file..."
	@cp data/students.txt $(DATADIR)/ 2>/dev/null || echo "Please create students.txt manually"

.PHONY: all clean run test-data
