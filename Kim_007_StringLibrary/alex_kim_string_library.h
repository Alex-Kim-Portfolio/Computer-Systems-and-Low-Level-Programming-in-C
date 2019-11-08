//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library (Header File)
//No issues/problems

#ifndef alex_kim_string_library_h
#define alex_kim_string_library_h

int all_letters(char *s);
int num_in_range(char *s1, char b, char t);
int diff(char *s1, char *s2);
void shorten(char *s, int new_len);
int len_diff(char *s1, char *s2);
void rm_left_space(char *s);
void rm_right_space(char *s);
void rm_space(char *s);
int find(char *h, char *n);
char *ptr_to(char *h, char *n);
int is_empty(char *s);
char *str_zip(char *s1, char *s2);
void capitalize(char *s);
int strcmp_ign_case(char *s1, char *s2);
void take_last(char *s, int n);
char *dedup(char *s);
char *pad(char *s, int d);
int ends_with_ignore_case(char *s, char *suff);
char *repeat(char *s, int x, char sep);
char *replace(char *s, char *pat, char *rep);
char *str_connect(char **strs, int n, char c);
void rm_empties(char **words);
char **str_chop_all(char *s, char c);

#endif /* alex_kim_string_library_h */
