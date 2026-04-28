#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_anagram(const char *wrd1, const char *wrd2)
{
	int len1 = strlen(wrd1);
	int len2 = strlen(wrd2);
	
	int wrd1_count[26] = {0};
	int wrd2_count[26] = {0};

	for(int i = 0; i < len1; i++)
		wrd1_count[tolower(wrd1[i]) - 'a']++;
	
	for(int i = 0; i < len2; i++)
		wrd2_count[tolower(wrd2[i]) - 'a']++;

	for(int i = 0; i < 26; i++)
		if(wrd1_count[i] != wrd2_count[i])
			return false;
	
	return true;
}

int main(void)
{
	char wrd1[] = "Listen";
	char wrd2[] = "Silent";
	if (is_anagram(wrd1, wrd2))
		printf("words are anagrams\n");
	else
		printf("words are Not anagrams\n");

	return 0;
}
