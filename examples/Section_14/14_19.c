int del_key(node **cur, int key)
{
	node *p, *prev;
	
	p = prev = *cur;
	while(p != NULL)
	{
		if(p->key == key)
		{
			if(p == *cur)
				*cur = p->next;
			else
				prev->next = p->next;

			free(p);
			return 0;
		}
		prev = p;
		p = p->next;
	}
	return -1;
}
