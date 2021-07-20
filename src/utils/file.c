#include <kweb.h>

char *
file_read (const char *path)
{
  FILE *fp = NULL;
  fp = fopen (path, "r");

  if (fp == NULL)
    {
      printf ("`file_read': %s is an invalid path.\n", path);
      return NULL;
    }

  fseek (fp, 0, SEEK_END);
  size_t len = ftell (fp);
  fseek (fp, 0, SEEK_SET);

  char *cnt = NULL;
  cnt = calloc (sizeof (char), len + 1);

  if (cnt == NULL)
    {
      printf ("`file_read': error allocating memory for `cnt'.\n");
      return NULL;
    }

  fread (cnt, sizeof (char), len, fp);
  cnt[len] = 0;

  fclose (fp);

  return cnt;
}
