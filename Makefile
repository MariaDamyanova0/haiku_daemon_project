CC = gcc
CFLAGS = -Wall -Wextra -pedantic

# Executable names
EXECUTABLE_MASTER = haiku_master
EXECUTABLE_STUDENT = haiku_student
EXECUTABLE_LIBRARIAN = librarian

# Source files
MASTER_SRC = haiku_master.c
STUDENT_SRC = haiku_student.c
LIBRARIAN_SRC = librarian.c

# Object files
MASTER_OBJ = $(MASTER_SRC:.c=.o)
STUDENT_OBJ = $(STUDENT_SRC:.c=.o)
LIBRARIAN_OBJ = $(LIBRARIAN_SRC:.c=.o)

# All executable files
all: $(EXECUTABLE_MASTER) $(EXECUTABLE_STUDENT) $(EXECUTABLE_LIBRARIAN)

# Rule to compile haiku_master
$(EXECUTABLE_MASTER): $(MASTER_OBJ)
	$(CC) $(CFLAGS) -o $(EXECUTABLE_MASTER) $(MASTER_OBJ)

# Rule to compile haiku_student
$(EXECUTABLE_STUDENT): $(STUDENT_OBJ)
	$(CC) $(CFLAGS) -o $(EXECUTABLE_STUDENT) $(STUDENT_OBJ)

# Rule to compile librarian
$(EXECUTABLE_LIBRARIAN): $(LIBRARIAN_OBJ)
	$(CC) $(CFLAGS) -o $(EXECUTABLE_LIBRARIAN) $(LIBRARIAN_OBJ)

# Clean up the project directory
clean:
	rm -f $(EXECUTABLE_MASTER) $(EXECUTABLE_STUDENT) $(EXECUTABLE_LIBRARIAN) $(MASTER_OBJ) $(STUDENT_OBJ) $(LIBRARIAN_OBJ)
