#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int count_files(const char* dir)
{
	DIR *dp;
	int i = 0;
	struct dirent *ep;
	dp = opendir(dir);

	if (dp != NULL)
	{
		while (ep = readdir(dp))
			i++;

		closedir(dp);

		// strip current and parent handles
		i = i - 2;

		return i;
	}
	
	return -1;
}

bool check_if_name_unique(const char *f_name, char *name_to_compare)
{
	std::string stored_name;
	std::ifstream file(f_name);
	std::string s_to_compare(name_to_compare);

	while (std::getline(file, stored_name))
	{
		if (s_to_compare == stored_name)
		{
			file.close();
			return false;
		}
	}

	file.close();

	return true;
}

int gather_names_to_gender_files(const char* dir)
{
	DIR *dp;
	struct dirent *ep;
	dp = opendir(dir);

	const char *M_FILE_NAME = "american_male_names";
	const char *F_FILE_NAME = "american_female_names";

	std::ofstream gather_file_male(M_FILE_NAME, std::ios::app);
	std::ofstream gather_file_female(F_FILE_NAME, std::ios::app);

	const int line_max_size = 256;

	if (dp != NULL)
	{
		int i = 0;
		int linux_fs_handles = 2;
		std::unordered_set<std::string> unique_names;

		while (ep = readdir(dp))
		{
			char path[256];
			strcpy(path, dir);
			strcat(path, "/");
			strcat(path, ep->d_name);

			if (i > linux_fs_handles)
			{
				char line[line_max_size];

				FILE *f = fopen(path, "r");

				while ((fgets(line, line_max_size, f)) != NULL) 
				{
					char name[60];
					char *token = strtok(line, ",");

					strcpy(name, token);
					strcat(name, "\n");

					while (token)
					{
						if (strcmp(token, "F") == 0)
						{
							if ((unique_names.insert(name)).second)
							{
								gather_file_female << name;
								break;
							}
						}
						else if (strcmp(token, "M") == 0)
						{
							if ((unique_names.insert(name)).second)
							{
								gather_file_male << name;
								break;
							}
						}

						token = strtok(NULL, ",");
					}
				}

				fclose(f);
			}

			i++;
		}

		return i - linux_fs_handles;
	}

	gather_file_male.close();
	gather_file_female.close();

	return -1;
}

int main()
{
	const char* dir = "./data";
	//int file_count = count_files(dir);

	int processed_count = gather_names_to_gender_files(dir);

	std::cout << processed_count << " files processed" << "\n";

	//std::cout << "There are " << file_count << " in the " << dir << " directory" << "\n";

	//ifstream File;
}