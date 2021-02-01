#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct node - linked list node
 * @car_id: int data identifier
 * @laps: size_t type laps count
 * @next: struct node
 * Description: Linked list to get or add cars
 */
typedef struct node
{
	int car_id;
	size_t laps;
	struct node *next;
} car_node;

void race_state(int *id, size_t size);
void insert_car(car_node **head, int id);

#endif /* LAPS_H */
