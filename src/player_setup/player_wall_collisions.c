#include "cub.h"

int detect_wall_collision_north(t_cub_data *cub_data, double get_player_radian, int player_moving)
{
	double next_x = fabs((cub_data->map_data->player_data.speed * cos(get_player_radian)));
	double next_y = fabs((cub_data->map_data->player_data.speed * sin(get_player_radian)));
	int check_y_val;
	int check_x_val;
	if (player_moving == 1)
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
	if (player_moving == 2)
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

	if (player_moving == 3)
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

	if (player_moving == 4)
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

int detect_wall_collision_south(t_cub_data *cub_data, float get_player_radian, int player_moving)
{
	double next_x = fabs((cub_data->map_data->player_data.speed * cos(get_player_radian)));
	double next_y = fabs((cub_data->map_data->player_data.speed * sin(get_player_radian)));
	int check_y_val;
	int check_x_val;
	if (player_moving == 1)
	{
		printf("DETECING NORTHEAST 1!!!\n");
	
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
	if (player_moving == 2)
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

	if (player_moving == 3)
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

	if (player_moving == 4)
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


int detect_wall_collision_west(t_cub_data *cub_data, float get_player_radian, int player_moving)
{
	double next_x = fabs((cub_data->map_data->player_data.speed * cos(get_player_radian)));
	double next_y = fabs((cub_data->map_data->player_data.speed * sin(get_player_radian)));
	int check_y_val;
	int check_x_val;
	if (player_moving == 1)
	{
		
	
		check_y_val = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
		
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION WEST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION WEST %d\n", check_x_val);
			printf("player facing 1  - south-west WALL DETECTED ON COLLISION WEST MOVING STRAIGHT DETECT COLLISION WEST!\n");
			return (1);
		}
			
	}
	if (player_moving == 2)
	{
		
		check_y_val = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION WEST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION WEST %d\n", check_x_val);
			printf("moviung  moving south-east WALL DETECTED ON COLLISION WEST MOVING LEFT DETECT COLLISION WEST!\n");
			return (1);
		}
			
	}

	if (player_moving == 3)
	{
	
		check_y_val = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION WEST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION WEST %d\n", check_x_val);
			printf("moving north-east WALL DETECTED ON COLLISION WEST MOVING WEST DETECT COLLISION WEST!\n");
			return (1);
		}

	}

	if (player_moving == 4)
	{
	
		check_y_val = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION WEST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION WEST %d\n", check_x_val);
			printf("moving north-west WALL DETECTED ON COLLISION WEST MOVING DOWN DETECT COLLISION WEST!\n");
			return (1);
		}
	}
	return (0);
}


int detect_wall_collision_east(t_cub_data *cub_data, float get_player_radian, int player_moving)
{
	double next_x = fabs((cub_data->map_data->player_data.speed * cos(get_player_radian)));
	double next_y = fabs((cub_data->map_data->player_data.speed * sin(get_player_radian)));
	int check_y_val;
	int check_x_val;
	if (player_moving == 1) //South   Y+ X-
	{
		
	
		check_y_val = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
		
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION EAST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION EAST %d\n", check_x_val);
			printf("Quadrant 1 : south-west moving WALL DETECTED ON COLLISION EAST MOVING UP DETECT COLLISION EAST!\n");
			return (1);
		}
			
	}
	if (player_moving == 2) //South   X+ Y+
	{
		
		check_y_val = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION EAST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION EAST %d\n", check_x_val);
			printf("Quadrant 2 : moving south-east WALL DETECTED ON COLLISION EAST MOVING RIGHT DETECT COLLISION EAST!\n");
			return (1);
		}
			
	}

	if (player_moving == 3) // North Y- X+
	{
		
		check_y_val = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION EAST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION EAST %d\n", check_x_val);
			printf("Quandrant 3  moving north-east: WALL DETECTED ON COLLISION EAST MOVING RIGHT!\n");
			return (1);
		}

	}

	if (player_moving == 4) // North -y -X
	{
		
		check_y_val = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
		check_x_val = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_y_val][check_x_val]== '1')
		{
			printf("GET CHECK Y VAL ON COLLISION EAST %d\n", check_y_val);
			printf("GET CHECK X VAL ON COLLISION EAST %d\n", check_x_val);
			printf("Quadrant 4: moving norht - west WALL DETECTED ON COLLISION EAST MOVING DOWN!\n");
			return (1);
		}
	}
	return (0);
}