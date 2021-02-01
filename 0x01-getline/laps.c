#include "laps.h"

/**
 * race_state - Entry from main
 * Desc: Function that keeps track
 * @id: Pointer int type
 * @size: Unsigned int data type
 * Return: Number of laps made by several cars in a race
 */
void race_state(int *id, size_t size)
{
	static car_node *head;
	size_t i;
	car_node *node;


	if (size == 0)
	{
		while (head != NULL)
		{
			node = head;
			head = head->next;
			free(node);
		}
		return;
	}
	i = 0;
	while (i < size)
	{
		insert_car(&head, id[i]);
		i++;
	}
	printf("Race state:\n");
	for (node = head; node != NULL; node = node->next)
		printf("Car %d [%lu laps]\n", node->car_id, node->laps);
}

/**
 * insert_car - add car
 * Desc: Function to insert a car
 * @id: int type car identifier
 * @head: pointer to head car_node
 * Return: new list of cars added
 */
void insert_car(car_node **head, int id)
{
	car_node *new, *temp;

	if (*head == NULL || id < (*head)->car_id)
	{
		new = malloc(sizeof(car_node));
		if (new == NULL)
			exit(EXIT_FAILURE);
		new->car_id = id;
		new->laps = 0;
		new->next = *head;
		*head = new;
		printf("Car %d joined the race\n", id);
		return;
	}
	for (new = *head; new->next && new->next->car_id <= id; new = new->next)
		;
	if (new->car_id == id)
	{
		new->laps++;
		return;
	}
	temp = malloc(sizeof(car_node));
	if (temp == NULL)
		exit(EXIT_FAILURE);
	temp->car_id = id;
	temp->laps = 0;
	temp->next = new->next;
	new->next = temp;
	printf("Car %d joined the race\n", id);
}
