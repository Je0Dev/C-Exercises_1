void tree_nodes(node *p)
{
	if(p == NULL) 
		return;
	cnt++;
	tree_nodes(p->left);
	tree_nodes(p->right);
}
