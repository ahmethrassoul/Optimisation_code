LIB_DIR = ../libstat
LIB_NAME = stat
TARGET = test 

test: test.c
	gcc $^ -o $@ -l$(LIB_NAME) -L $(LIB_DIR)
	
run: test
	LD_LIBRARY_PATH=$(LIB_DIR) ./$(TARGET)
	
clean:
	rm -f $(TARGET)

.PHONY: run clean
