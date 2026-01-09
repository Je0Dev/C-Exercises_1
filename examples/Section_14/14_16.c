void find_min(node *p)
{
	if(p == NULL) 
		return;
	if(p->left == NULL)
	{
		printf("Min:%d\n", p->key);
		return;
	}
	find_min(p->left);
}
