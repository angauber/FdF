void	perspective_projection(t_dot *dot)
{
	double alpha;
	double beta;
	double gamma;
	double w;
	t_dot new;

	alpha = 1 / tan((30 * (M_PI / 180)) / 2);
	beta = -1000.1 / -999.9;
	gamma = 200 / -999.9;
	new.x = alpha * dot->x;
	new.y = alpha * dot->y;
	new.z = beta * dot->z + gamma; // * w == 1
	w = new.z * gamma;
	new.x = new.x * 900;
	new.y = new.y * 450;

	dot->x = new.x;
	dot->y = new.y;
}


void	print_map(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->x)
	{
		j = -1;
		while (++j < map->y)
			ft_printf("%d ", map->table[i][j]);
		ft_printf("\n");
	}
}
