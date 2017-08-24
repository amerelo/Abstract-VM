NAME = avm

FLAGS = -Wall -Wextra -Werror -std=c++1z

INCLUDES= -I includes/ -I templates/ -I interfaces/

CPP_DIR=src

O_DIR = .obj/

CORE =	main.cpp \
		Lexer.class.cpp\
		Instruction.class.cpp\
		Add.class.cpp Assert.class.cpp\
		Div.class.cpp\
		Push.class.cpp\
		Pop.class.cpp\
		Dump.class.cpp\
		Sub.class.cpp\
		Mul.class.cpp\
		Mod.class.cpp\
		Print.class.cpp\
		Exit.class.cpp\
		Factory.class.cpp\



SRC_CORE = $(addprefix $(CPP_DIR)/, $(CORE))

### END ###

CPP_SRC= $(SRC_CORE)
O_FILES = $(CPP_SRC:%.cpp=$(O_DIR)%.o)
LIBS =

all: prepare $(NAME)

prepare:
	@mkdir -p $(O_DIR)
	@mkdir -p $(O_DIR)$(CPP_DIR)
	@mkdir -p $(O_DIR)$(CLASS_DIR)

$(O_DIR)%.o: %.cpp
	@printf "[\033[32;1m $(NAME) \033[0m]\t\033[31;1m$<\033[0m\\n"
	@g++ $(FLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(O_FILES)
	@g++ $(FLAGS) -o $(NAME) $(O_FILES) $(LIBS)
	@printf "[\033[32;1m Run \033[0m]\033[31;1m $(NAME) \033[0m\\n"

clean:
	@rm -rf $(O_DIR)
	@printf "[\033[32;1m Delete \033[0m] $(O_FILES) \033[0m\\n"

fclean: clean
	@rm -f $(NAME)
	@printf "[\033[32;1m Delete \033[0m] $(NAME) \033[0m\\n"

re: fclean all
