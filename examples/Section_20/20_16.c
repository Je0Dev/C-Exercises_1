#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
	char pad_ch, key_str[10], in_str[110] = {0}, out_str[110] = {0}; /* The size of the arrays is more than 100 characters, to cover the case of padding characters in the last segment. */
	int i, j, tmp, seg, key_len, max_key_dig, msg_len;

	tmp = 1;
	while(tmp) 
	{
		tmp = 0; /* The loop ends only if tmp remains 0. */
		printf("Enter 1 up to 9 different key digits: ");
		key_len = read_text(key_str, sizeof(key_str), 1);
		if(key_len < 1 || key_len > 9)
		{
			printf("Error: Length should be 1 to 9 different digits\n");
			tmp = 1;
			continue;
		}
		max_key_dig = '0'; /* This variable holds the key digit with the highest value. */
		for(i = 0; (tmp != 1) && i < key_len; i++)
		{
			if(key_str[i] < '1' || key_str[i] > '9')
			{
				printf("Error: Only digits are allowed\n");
				tmp = 1;
				break;
			}
			if(key_str[i] > max_key_dig)
				max_key_dig = key_str[i];
			/* Check if each digit appears once. */
			for(j = i+1; j < key_len; j++)
			{
				if(key_str[i] == key_str[j])
				{
					printf("Error: Digits should be different\n");
					tmp = 1;
					break;
				}
			}
		}
		if(tmp == 0)
		{
			max_key_dig -= '0';
			if(key_len != max_key_dig) /* For example, the key value 125 is not acceptable, because the value of the highest digit (i.e., 5) is not equal to the key length, which is 3. */
			{
				printf("Error: Digits should be from 1 to %d\n", key_len);
				tmp = 1;
			}
		}
	}
	printf("Enter padding character: ");
	pad_ch = getchar();

	getchar();
	while(1)
	{
		printf("Enter text: ");
		msg_len = read_text(in_str, sizeof(in_str), 1);
		if(msg_len >= key_len)
			break;
		else
			printf("Error: Text length must be greater than the key size\n");
	}
	seg = msg_len/key_len;
	tmp = msg_len - (seg*key_len);

	if(tmp != 0) /* If it is not 0, it means that the message length is not divided exactly by the length of the key and padding characters must be added. Notice that the replacement starts from the position of the null character. */
	{
		seg++;
		for(i = 0; i < key_len-tmp; i++)
			in_str[msg_len+i] = pad_ch;
	}
	for(i = 0; i < seg; i++)
	{
		for(j = 0; j < key_len; j++)
		{
			tmp = key_str[j]-'1'; /* We subtract the ASCII value of 1, in order to use tmp as an index to the original message. */
			out_str[i*key_len+j] = in_str[i*key_len+tmp];
		}
	}
	printf("Encoded text: %s\n", out_str);
	for(i = 0; i < seg; i++)
	{
		for(j = 0; j < key_len; j++)
		{
			tmp = key_str[j]-'1';
			in_str[i*key_len+tmp] = out_str[i*key_len+j];
		}
	}
	printf("Decoded text: %s\n", in_str); /* Any padding characters appear at the end of the original message. */
	return 0;
}
