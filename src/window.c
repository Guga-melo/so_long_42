

#include "../minilibx/mlx.h"
#include <unistd.h>

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long) n;
	if (nb < 0)
	{
		ft_putchar('-', fd);
		nb = nb * (-1);
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar(nb % 10 + '0', fd);
}

int	del_wd(int key, void *param)
{
	static int	input_count;
	input_count++;
	ft_putnbr_fd(input_count, 1);
	ft_putchar('\n', 1);
	(void) param;
	return(key);
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		mlx_pixel;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500,  "ME MATA NÂO AGUENTO MAIS VIVER D:");
	mlx_key_hook(win_ptr, del_wd, (void *) 0);
	mlx_pixel = mlx_pixel_put(mlx_ptr, win_ptr, 200, 255, 765);
	mlx_clear_window(mlx_ptr, win_ptr);
	//mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
}
