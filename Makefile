CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
CXXXFLAGS = -Wall -Werror -Wextra -lncurses
NAME = ft_gkrellm

SRC = CPUModule.cpp DataStorageModule.cpp Display.cpp HostnameModule.cpp NcursesModul.cpp NetworkModule.cpp   OSInfoModule.cpp RAMModule.cpp TimeModule.cpp main.cpp


OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all