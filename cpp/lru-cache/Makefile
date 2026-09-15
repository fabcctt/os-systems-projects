CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = lru_cache
SRCS = main.cpp lru_cache.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean