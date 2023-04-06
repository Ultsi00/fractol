# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tturto <tturto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 08:17:31 by tturto            #+#    #+#              #
#    Updated: 2022/09/21 20:42:42 by tturto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCLUDES =	-I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIBFT = make -C ./libft/
LIBFTA = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror
SOURCES =	main.c initialize_min_max_iter.c key_events.c \
			colour.c c_julia.c \
			mandelbrot.c julia.c tricorn.c \
			mouse_zoom.c mouse_events_julia.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): 
	@ $(LIBFT)
	@ gcc -c $(FLAGS) $(SOURCES)	
	@ gcc -o $(NAME) $(OBJECTS) $(LIBFTA) $(INCLUDES) 
	@echo "Compilation has been completed"

clean:
	@ rm -f $(OBJECTS)
	@ $(LIBFT) clean
	@ echo "'clean' has been completed"

fclean: clean
	@ rm -f $(NAME)
	@ $(LIBFT) fclean
	@ echo "'fclean' has been completed"

re: fclean all
