CC := g++
CFLAGS := -std=c++20

SRCS := task_1.cpp vectorV2.hpp

OBJS := $(SRCS:.cpp=.o)
TARGET := task

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
