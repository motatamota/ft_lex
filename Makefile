NAME		:= ft_lex
TEST_NAME	:= test_runner

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
INCLUDES	:= -Iincludes

SRCS_DIR	:= srcs
OBJS_DIR	:= objs
TESTS_DIR	:= tests

SRCS		:= $(shell find $(SRCS_DIR) -name '*.cpp')
OBJS		:= $(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

TEST_SRCS	:= $(shell find $(TESTS_DIR) -name '*.cpp' 2>/dev/null)
SRCS_NO_MAIN:= $(filter-out $(SRCS_DIR)/main.cpp,$(SRCS))
TEST_OBJS	:= $(TEST_SRCS:$(TESTS_DIR)/%.cpp=$(OBJS_DIR)/tests/%.o) \
			   $(SRCS_NO_MAIN:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

RM			:= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/tests/%.o: $(TESTS_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

test: $(TEST_NAME)
	./$(TEST_NAME)

$(TEST_NAME): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(TEST_OBJS) -o $(TEST_NAME)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test
