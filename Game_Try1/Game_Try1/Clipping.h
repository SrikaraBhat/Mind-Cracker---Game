#pragma once
#include<stdlib.h>
#include "functions.h"
#define NULL 0
struct node
{
	float x;
	float y;
	node* next;
};
struct node* Clip(struct node* points, float left, float right, float top, float bottom)
{
	struct node* head = GetCopy(points);
	head = ClipLeft(head, left);
	head = ClipRight(head, right);
	head = ClipTop(head, top);
	head = ClipBottom(head, bottom);
	head = Translate(head, left, bottom);
	return head;
}
struct node* GetCopy(struct node* points)
{
	struct node *ptr = points;
	struct node* head = NULL;

	while (ptr != NULL) {
		head = insertFirst(head, ptr->x, ptr->y);
		ptr = ptr->next;
	}
	return head;
}
struct node* Translate(struct node* points, float left, float bottom)
{
	struct node *ptr = points;

	//start from the beginning
	while (ptr != NULL) {
		ptr->x -= left;
		ptr->y -= bottom;
		ptr = ptr->next;
	}
	return points;
}
struct node* ClipLeft(struct node* points, float left)
{
	node* f;
	node* first;
	node* second;
	node* head = NULL;
	struct node *ptr = points;
	if (ptr == NULL)
	{
		return NULL;
	}
	second = deleteFirst(ptr);
	f = second;
	while (ptr != NULL) {
		first = second;
		second = deleteFirst(ptr);
		if (first->x >= left&&second->x >= left)
		{
			head = insertFirst(head, second->x, second->y);
		}
		else if (first->x >= left&&second->x < left)
		{
			float  m = (second->y - first->y) / (second->x - first->x);
			float newy = m*(left - first->x) + first->y;
			head = insertFirst(head, left, newy);
		}
		else if (first->x < left&&second->x >= left)
		{
			float  m = (second->y - first->y) / (second->x - first->x);
			float newy = m*(left - first->x) + first->y;
			head = insertFirst(head, left, newy);
			head = insertFirst(head, second->x, second->y);
		}
		if (first != f)
			free(first);
		ptr = ptr->next;
	}
	first = second;
	second = f;
	if (first->x >= left&&second->x >= left)
	{
		head = insertFirst(head, second->x, second->y);
	}
	else if (first->x >= left&&second->x < left)
	{
		float  m = (second->y - first->y) / (second->x - first->x);
		float newy = m*(left - first->x) + first->y;
		head = insertFirst(head, left, newy);
	}
	else if (first->x < left&&second->x >= left)
	{
		float  m = (second->y - first->y) / (second->x - first->x);
		float newy = m*(left - first->x) + first->y;
		head = insertFirst(head, left, newy);
		head = insertFirst(head, second->x, second->y);
	}
	free(first);
	free(second);
	return head;
}
struct node* ClipRight(struct node* points, float right)
{
	node* f;
	node* first;
	node* second;
	node* head = NULL;
	struct node *ptr = points;
	if (ptr == NULL)
	{
		return NULL;
	}
	second = deleteFirst(ptr);
	f = second;
	while (ptr != NULL) {
		first = second;
		second = deleteFirst(ptr);
		if (first->x <= right&&second->x <= right)
		{
			head = insertFirst(head, second->x, second->y);
		}
		else if (first->x <= right&&second->x > right)
		{
			float  m = (second->y - first->y) / (second->x - first->x);
			float newy = m*(right - first->x) + first->y;
			head = insertFirst(head, right, newy);
		}
		else if (first->x > right&&second->x <= right)
		{
			float  m = (second->y - first->y) / (second->x - first->x);
			float newy = m*(right - first->x) + first->y;
			head = insertFirst(head, right, newy);
			head = insertFirst(head, second->x, second->y);
		}
		if (first != f)
			free(first);
		ptr = ptr->next;
	}
	first = second;
	second = f;
	if (first->x <= right&&second->x <= right)
	{
		head = insertFirst(head, second->x, second->y);
	}
	else if (first->x <= right&&second->x > right)
	{
		float  m = (second->y - first->y) / (second->x - first->x);
		float newy = m*(right - first->x) + first->y;
		head = insertFirst(head, right, newy);
	}
	else if (first->x > right&&second->x <= right)
	{
		float  m = (second->y - first->y) / (second->x - first->x);
		float newy = m*(right - first->x) + first->y;
		head = insertFirst(head, right, newy);
		head = insertFirst(head, second->x, second->y);
	}
	free(first);
	free(second);
	return head;
}
struct node* ClipTop(struct node* points, float top)
{
	node* f;
	node* first;
	node* second;
	node* head = NULL;
	struct node *ptr = points;
	if (ptr == NULL)
	{
		return NULL;
	}
	second = deleteFirst(ptr);
	f = second;
	while (ptr != NULL) {
		first = second;
		second = deleteFirst(ptr);
		if (first->y <= top&&second->y <= top)
		{
			head = insertFirst(head, second->x, second->y);
		}
		else if (first->y <= top&&second->y > top)
		{
			float  m = (second->x - first->x) / (second->y - first->y);
			float newx = m*(top - first->y) + first->x;
			head = insertFirst(head, newx, top);
		}
		else if (first->y > top&&second->y <= top)
		{
			float  m = (second->x - first->x) / (second->y - first->y);
			float newx = m*(top - first->y) + first->x;
			head = insertFirst(head, newx, top);
			head = insertFirst(head, second->x, second->y);
		}
		if (first != f)
			free(first);
		ptr = ptr->next;
	}
	first = second;
	second = f;
	if (first->y <= top&&second->y <= top)
	{
		head = insertFirst(head, second->x, second->y);
	}
	else if (first->y <= top&&second->y > top)
	{
		float  m = (second->x - first->x) / (second->y - first->y);
		float newx = m*(top - first->y) + first->x;
		head = insertFirst(head, newx, top);
	}
	else if (first->y > top&&second->y <= top)
	{
		float  m = (second->x - first->x) / (second->y - first->y);
		float newx = m*(top - first->y) + first->x;
		head = insertFirst(head, newx, top);
		head = insertFirst(head, second->x, second->y);
	}
	free(first);
	free(second);
	return head;
}
struct node* ClipBottom(struct node* points, float bottom)
{
	node* f;
	node* first;
	node* second;
	node* head = NULL;
	struct node *ptr = points;
	if (ptr == NULL)
	{
		return NULL;
	}
	second = deleteFirst(ptr);
	f = second;
	while (ptr != NULL) {
		first = second;
		second = deleteFirst(ptr);
		if (first->y >= bottom&&second->y >= bottom)
		{
			head = insertFirst(head, second->x, second->y);
		}
		else if (first->y >= bottom&&second->y < bottom)
		{
			float  m = (second->x - first->x) / (second->y - first->y);
			float newx = m*(bottom - first->y) + first->x;
			head = insertFirst(head, newx, bottom);
		}
		else if (first->y < bottom&&second->y >= bottom)
		{
			float  m = (second->x - first->x) / (second->y - first->y);
			float newx = m*(bottom - first->y) + first->x;
			head = insertFirst(head, newx, bottom);
			head = insertFirst(head, second->x, second->y);
		}
		if (first != f)
			free(first);
		ptr = ptr->next;
	}
	first = second;
	second = f;
	if (first->y >= bottom&&second->y >= bottom)
	{
		head = insertFirst(head, second->x, second->y);
	}
	else if (first->y >= bottom&&second->y < bottom)
	{
		float  m = (second->x - first->x) / (second->y - first->y);
		float newx = m*(bottom - first->y) + first->x;
		head = insertFirst(head, newx, bottom);
	}
	else if (first->y < bottom&&second->y >= bottom)
	{
		float  m = (second->x - first->x) / (second->y - first->y);
		float newx = m*(bottom - first->y) + first->x;
		head = insertFirst(head, newx, bottom);
		head = insertFirst(head, second->x, second->y);
	}
	free(first);
	free(second);
	return head;
}
struct node* insertFirst(node* head, float x1, float y1) {
	//create a link
	struct node *link = (struct node*) malloc(sizeof(struct node));

	link->x = x1;
	link->y = y1;

	//point it to old first node
	link->next = head;

	//point first to new first node
	head = link;

	return head;
}
struct node* deleteFirst(node* head) {

	struct node *tempLink = head;
	//struct node *link = (struct node*) malloc(sizeof(struct node));
//	link->x = head->x;
//	link->y = head->y;
	//mark next to first link as first 
	head = head->next;
	//free(tempLink);
	return tempLink;
}
struct node* deleteFirst1(node** head) {

	struct node *tempLink = *head;
	//mark next to first link as first 
	//struct node *link = (struct node*) malloc(sizeof(struct node));
	//link->next = NULL;
	//link->x = (*head)->x;
	//link->y = (*head)->y;
	*head = tempLink->next;
	free(tempLink);
	tempLink = tempLink->next;
	return *(head);
}