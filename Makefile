FLAGS = -std=c++11 -Wall
SRCS = main.cpp src/data.cpp src/decisionTree.cpp src/randomForest.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = rf

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	g++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
