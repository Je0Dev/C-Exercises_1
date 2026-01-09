node* add_node(node *p, char key[])
{
	int tmp;

	if(p == NULL)
	{
		p = (node*) malloc(sizeof(node));
		if(p == NULL)
		{
			printf("Error: Not available memory\n");
			exit(EXIT_FAILURE);
		}
		p->key = (char*) malloc(strlen(key)+1);
		if(p->key == NULL)
		{
			free(p);
			printf("Error: Not available memory\n");
			exit(EXIT_FAILURE);
		}
		strcpy(p->key, key);
		p->left = p->right = NULL;
	}
	else	
	{
		tmp = strcmp(key, p->key);
		if(tmp < 0)
			p->left = add_node(p->left, key);
		else if(tmp > 0)
			p->right = add_node(p->right, key);
		else
			printf("Error: Key(%s) exists\n", key);
	}
	return p;
}

void delete_tree(node *p)
{
	if(p == NULL)
		return;

	delete_tree(p->left);
	delete_tree(p->right);
	printf("%s\n", p->key);
	free(p->key);
	free(p);
} 
