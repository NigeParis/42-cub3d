#include "cub.h"

int detect_wall_collision_north(t_cub_data *cub_data, double get_player_radian, int player_facing)
{
	double next_x = (cub_data->map_data->player_data.speed * sin(get_player_radian)) + 2;
	double next_y = (cub_data->map_data->player_data.speed * cos(get_player_radian)) + 2;
	int check_y_val;
	int check_x_val;
	if (player_facing == 1)
	{
		printf("DETECING NORTHEAST!!!\n");
	
		check_y_val = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
		
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL %d\n", check_y_val);
			printf("GET CHECK X VAL %d\n", check_x_val);
			printf("WALL DETECTED!\n");
			return (1);
		}
			
	}
	if (player_facing == 2)
	{
		printf("DETECING NORTHWEST!!!\n");
		check_y_val = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL %d\n", check_y_val);
			printf("GET CHECK X VAL %d\n", check_x_val);
			printf("WALL DETECTED!\n");
			return (1);
		}
			
	}

	if (player_facing == 3)
	{
		printf("DETECING SOUTHWEST!!\n");
		check_y_val = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL %d\n", check_y_val);
			printf("GET CHECK X VAL %d\n", check_x_val);
			printf("WALL DETECTED!\n");
			return (1);
		}

	}

	if (player_facing == 4)
	{
		printf("DETECING SOUTHEAST!!\n");
		check_y_val = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL %d\n", check_y_val);
			printf("GET CHECK X VAL %d\n", check_x_val);
			printf("WALL DETECTED!\n");
			return (1);
		}
	}
	return (0);
}

int detect_wall_collision_south(t_cub_data *cub_data, float get_player_radian, int player_facing)
{
	double next_x = (cub_data->map_data->player_data.speed * sin(get_player_radian)) + 1;
	double next_y = (cub_data->map_data->player_data.speed * cos(get_player_radian)) + 1;
	int check_y_val;
	int check_x_val;
	if (player_facing == 1)
	{
		printf("DETECING NORTHEAST!!!\n");
	
		check_y_val = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
		
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL %d\n", check_y_val);
			printf("GET CHECK X VAL %d\n", check_x_val);
			printf("WALL DETECTED ON NORTHEAST MOVING SOUTH!\n");
			return (1);
		}
			
	}
	if (player_facing == 2)
	{
		printf("DETECING NORTHWEST!!!\n");
		check_y_val = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL MO%d\n", check_y_val);
			printf("GET CHECK X VAL %d\n", check_x_val);
			printf("WALL DETECTED ON NORTHWEST MOVING SOUTH!\n");
			return (1);
		}
			
	}

	if (player_facing == 3)
	{
		printf("DETECING SOUTHWEST!!\n");
		check_y_val = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL MOVING SOUTHWEST %d\n", check_y_val);
			printf("GET CHECK X VAL MOVING SOUTHWEST %d\n", check_x_val);
			printf("WALL DETECTED ON SOUTHWEST MOVING SOUTH!\n");
			return (1);
		}

	}

	if (player_facing == 4)
	{
		printf("DETECING SOUTHEAST!!\n");
		check_y_val = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL MOVING SOUTHEAST %d\n", check_y_val);
			printf("GET CHECK X VAL MOVING SOUTHEAST %d\n", check_x_val);
			printf("WALL DETECTED ON SOUTHEAS MOVING SOUTHT!\n");
			return (1);
		}
	}
	return (0);
}


int detect_wall_collision_west(t_cub_data *cub_data, float get_player_radian, int player_facing)
{
	double next_x = (cub_data->map_data->player_data.speed * sin(get_player_radian)) + 1;
	double next_y = (cub_data->map_data->player_data.speed * cos(get_player_radian)) + 1;
	int check_y_val;
	int check_x_val;
	if (player_facing == 1)
	{
		printf("DETECING NORTHEAST ON COLLISION WEST!!!\n");
	
		check_y_val = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
		
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION WEST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION WEST %d\n", check_x_val);
			printf("WALL DETECTED ON COLLISION WEST!\n");
			return (1);
		}
			
	}
	if (player_facing == 2)
	{
		printf("DETECING NORTHWEST ON COLLISION WEST!!!\n");
		check_y_val = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION WEST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION WEST %d\n", check_x_val);
			printf("WALL DETECTED ON COLLISION WEST!\n");
			return (1);
		}
			
	}

	if (player_facing == 3)
	{
		printf("DETECING SOUTHWEST ON COLLISION WEST!!\n");
		check_y_val = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION WEST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION WEST %d\n", check_x_val);
			printf("WALL DETECTED ON COLLISION WEST!\n");
			return (1);
		}

	}

	if (player_facing == 4)
	{
		printf("DETECING SOUTHEAST ON COLLISION WEST!!\n");
		check_y_val = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION WEST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION WEST %d\n", check_x_val);
			printf("WALL DETECTED ON COLLISION WEST!\n");
			return (1);
		}
	}
	return (0);
}